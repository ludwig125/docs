# 概要

MySQLのデータをgrafanaで表示させてみた


# 環境

- WSL2
- Ubuntu: 18.04.4 LTS
- MySQL: 5.7.30-0ubuntu0.18.04.1

# 前提

MySQL自体はインストール済みの前提で書く

# grafana install

- https://grafana.com/docs/grafana/latest/installation/debian/
- latest OSS releaseのインストール手順に従って進める

```
sudo apt-get install -y apt-transport-https
sudo apt-get install -y software-properties-common wget
wget -q -O - https://packages.grafana.com/gpg.key | sudo apt-key add -
```

stable releaseがほしい場合は以下の設定でリポジトリを追加

```
echo "deb https://packages.grafana.com/oss/deb stable main" | sudo tee -a /etc/apt/sources.list.d/grafana.list
```

install

```
sudo apt-get update
sudo apt-get install grafana
```

起動

wsl なのでinit.dの起動手順

```
[~] $sudo service grafana-server start
server status * Starting Grafana Server         [ OK ]
[~] $sudo service grafana-server status
 * grafana is running
[~] $
```

#### grafanaのログ

grafanaのログは以下にあるので、接続などで問題があったら確認するといい

```
[~] $sudo cat /var/log/grafana/grafana.log
```

# grafana をUI上で確認・設定

手順

- https://grafana.com/docs/grafana/latest/getting-started/getting-started/

問題なければ以下にアクセスすれば見られる

```
http://localhost:3000/
```


# MySQL側のデータベースとテーブルを用意

mysqldの起動とMySQLへの接続

```
[~] $sudo service mysql start
 * Starting MySQL database server mysqld                                                                         [ OK ]
[~] $
[~] $mysql -u root --host 127.0.0.1 --port 3306
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 40
Server version: 5.7.30-0ubuntu0.18.04.1 (Ubuntu)

Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql>
```

## データベース作成

```
CREATE DATABASE IF NOT EXISTS grafana_db;
```

## サンプルのテーブル作成

```
CREATE TABLE IF NOT EXISTS grafana_db.sample_table (
	id VARCHAR(10),
	data_time DATETIME,
	data_value int(10),
	PRIMARY KEY( id, data_time )
);
```

試しに以下のようなテストデータを入れる

```
use grafana_db;

INSERT INTO `sample_table` VALUES ('1001','2020-12-02 15:00:00', 1211);
INSERT INTO `sample_table` VALUES ('1001','2020-12-02 16:00:00', 1220);
INSERT INTO `sample_table` VALUES ('1001','2020-12-02 17:00:00', 1234);
INSERT INTO `sample_table` VALUES ('1001','2020-12-02 18:00:00', 1240);
INSERT INTO `sample_table` VALUES ('1002','2020-12-02 15:00:00', 1310);
INSERT INTO `sample_table` VALUES ('1002','2020-12-02 16:00:00', 1305);
INSERT INTO `sample_table` VALUES ('1002','2020-12-02 17:00:00', 1275);
INSERT INTO `sample_table` VALUES ('1002','2020-12-02 18:00:00', 1100);
```

データの確認

```
mysql> select * from grafana_db.sample_table;
+------+---------------------+------------+
| id   | data_time           | data_value |
+------+---------------------+------------+
| 1001 | 2020-12-02 15:00:00 |       1211 |
| 1001 | 2020-12-02 16:00:00 |       1220 |
| 1001 | 2020-12-02 17:00:00 |       1234 |
| 1001 | 2020-12-02 18:00:00 |       1240 |
| 1002 | 2020-12-02 15:00:00 |       1310 |
| 1002 | 2020-12-02 16:00:00 |       1305 |
| 1002 | 2020-12-02 17:00:00 |       1275 |
| 1002 | 2020-12-02 18:00:00 |       1100 |
+------+---------------------+------------+
8 rows in set (0.00 sec)
```

## grafana用のユーザ作成


Grafanaからアクセスするためのユーザーを作成

- root権限でアクセスさせてしまうと、grafana上で操作したクエリでDBを書き換えることができてしまうので強く推奨されている！

参考：https://grafana.com/docs/grafana/latest/datasources/mysql/#database-user-permissions-important

ここでは適当にpasswordは「password」とした

```
CREATE USER 'grafanaReader' IDENTIFIED BY 'password';
GRANT SELECT ON grafana_db.sample_table TO 'grafanaReader';
```

# grafanaとmysql連携

Data Sourcesを選択

![image](https://user-images.githubusercontent.com/18366858/100930082-ec582e80-352b-11eb-8f01-be340a9879a1.png)

「MySQL」を選んで上で作成したデータベースを登録

- Userは事前に設定したgranadaReaderにする
- Passwordは上で設定した「password」にする（すでにconfiguredになっていたらResetすると再度設定できる）

![image](https://user-images.githubusercontent.com/18366858/100931950-89b46200-352e-11eb-8dc2-375b8f0b9ed0.png)


「Save＆Test」ボタンを押して、うまく接続できていればOKが出る

![image](https://user-images.githubusercontent.com/18366858/100930260-2f1a0680-352c-11eb-842e-eeb247666e34.png)


# ダッシュボードの作成

![image](https://user-images.githubusercontent.com/18366858/100930331-4822b780-352c-11eb-9926-7b81bf520adc.png)

Add New Panelを押して、ダッシュボードを設定する

公式ドキュメントは以下が一番詳しいはずなので以下基本的にこのページを参考にする

- https://grafana.com/docs/grafana/latest/datasources/mysql/

![image](https://user-images.githubusercontent.com/18366858/100930603-aa7bb800-352c-11eb-9f58-5c4ac4034a8f.png)

このままUIからできなくはなさそうなんだけど、右上のペン「🖊」をクリックして直接SQLを書いたほうが確かなので自分は以下のようにした

以下を記入

```
SELECT
  UNIX_TIMESTAMP(data_time) AS "time",
  id AS metric,
  data_value
FROM sample_table
WHERE
  $__timeFilter(data_time)
ORDER BY data_time
```

一旦欄外のどこかを押すと、書いたクエリが反映されてグラフが描画される

![image](https://user-images.githubusercontent.com/18366858/100930895-12320300-352d-11eb-9cc9-f00e1eea9e18.png)

上の意味について以下に簡単な説明を書く

## グラフに必要な項目

grafanaで時系列データとして描画するためには、最低でも以下の３項目が必要らしい

- time：横軸となるUnixエポック時
  - datetime, timestamp, date型などのMySQLの型の形であれば文字列でもいい
- metric：グラフ表示名
  - データによってIDだったりNameだったりCategoryだったりそういうものを項目名として使う
- value：グラフの縦軸の数値
  - 数値である必要がある

## クエリの意味

- UNIX_TIMESTAMP(data_time) で、MySQLのテーブルのデータ`data_time`をgrafanaの横軸（時系列）として使用するため、`AS "time"` としている
- idをグラフの項目名として扱うため `AS metric` としている
- data_valueをvalueとしている。明示的に`AS value` としてもいい


# MySQLのデータをgrafanaで描画する上での注意点

## 1. UNIX_TIMESTAMPを設定しないとMySQLの日付データをJSTとして扱ってくれない

UNIX_TIMESTAMPをつけないと、データベースに日本時間JSTで登録したつもりでも、grafanaに描画するときにGMTだと判断されて＋９時間ずれてしまう

![image](https://user-images.githubusercontent.com/18366858/100932420-3262c180-352f-11eb-8e84-ae3653744e85.png)

- 元の「2020-12-02 15:00:00」などの時刻からきっかり９時間ずれていることがわかる

参考

- https://community.grafana.com/t/how-to-add-time-series-queries-with-grafana-and-mysql/3170


## 2. valueに数値型以外の項目を設定すると表示されない

以下のようにテーブルを一旦削除して、data_valueをVARCHARとして定義してみる

```
drop table sample_table;
CREATE TABLE IF NOT EXISTS grafana_db.sample_table (
  id VARCHAR(10),
  data_time DATETIME,
  data_value VARCHAR(10),
  PRIMARY KEY( id, data_time )
);


INSERT INTO `sample_table` VALUES ('1001','2020-11-30 15:00:00', '1211');
INSERT INTO `sample_table` VALUES ('1001','2020-11-30 16:00:00', '1220');
INSERT INTO `sample_table` VALUES ('1001','2020-11-30 17:00:00', '1234');
INSERT INTO `sample_table` VALUES ('1001','2020-11-30 18:00:00', '1240');
INSERT INTO `sample_table` VALUES ('1002','2020-11-30 15:00:00', '1310');
INSERT INTO `sample_table` VALUES ('1002','2020-11-30 16:00:00', '1305');
INSERT INTO `sample_table` VALUES ('1002','2020-11-30 17:00:00', '1275');
INSERT INTO `sample_table` VALUES ('1002','2020-11-30 18:00:00', '1100');
```

すると、valueが数値として認識できずに以下のようなエラーが出て描画できなくなる

- `Value column must have numeric datatype, column: data_value type: string value: 1211`

![image](https://user-images.githubusercontent.com/18366858/101090510-1bd56c80-35fa-11eb-82e8-3a80aef431f8.png)


文字列を数値型として扱うためには以下のようにCAST関数を使う

- `CAST(data_value AS UNSIGNED) `

- 参考: https://stackoverflow.com/questions/12126991/cast-from-varchar-to-int-mysql


![image](https://user-images.githubusercontent.com/18366858/101090793-8be3f280-35fa-11eb-9180-57b263601e77.png)

## 3. 横軸の時間が時刻型でないと表示されない

上と同様に、横軸は時刻型でないと表示されない

以下のようにテーブルを一旦削除して、data_timeをVARCHARとして定義してみる

```
drop table sample_table;
CREATE TABLE IF NOT EXISTS grafana_db.sample_table (
  id VARCHAR(10),
  data_time VARCHAR(20),
  data_value VARCHAR(10),
  PRIMARY KEY( id, data_time )
);


INSERT INTO `sample_table` VALUES ('1001','2020-11-30 15:00:00', '1211');
INSERT INTO `sample_table` VALUES ('1001','2020-11-30 16:00:00', '1220');
INSERT INTO `sample_table` VALUES ('1001','2020-11-30 17:00:00', '1234');
INSERT INTO `sample_table` VALUES ('1001','2020-11-30 18:00:00', '1240');
INSERT INTO `sample_table` VALUES ('1002','2020-11-30 15:00:00', '1310');
INSERT INTO `sample_table` VALUES ('1002','2020-11-30 16:00:00', '1305');
INSERT INTO `sample_table` VALUES ('1002','2020-11-30 17:00:00', '1275');
INSERT INTO `sample_table` VALUES ('1002','2020-11-30 18:00:00', '1100');
```

以下のようなエラーが出る
- `invalid type for column time, must be of type timestamp or unix timestamp, got: string 2020-11-30 15:00:00`

![image](https://user-images.githubusercontent.com/18366858/101091080-044ab380-35fb-11eb-83ef-c62bf5d1e3af.png)

ただ、これは実は先ほどの `UNIX_TIMESTAMP` を使えば日付として認識される問題ない

![image](https://user-images.githubusercontent.com/18366858/101091367-66a3b400-35fb-11eb-8612-6febc0d6521f.png)

基本的には以下の公式ページを見ると解決できそうだった

- https://grafana.com/docs/grafana/latest/datasources/mysql/
- https://community.grafana.com/t/how-to-add-time-series-queries-with-grafana-and-mysql/3170

## 4. データベース上でDOUBLE型の数値をグラフ化するとガタガタになる

MySQL上で、DOUBLE型で定義している数値を上と同様に
`CAST(doublevalue AS UNSIGNED) AS "value1"`のようにして描画すると、以下のように小数点が切り捨てられてガタガタのグラフになってしまった。

![image](https://user-images.githubusercontent.com/18366858/102663752-cd60ca00-41c4-11eb-9104-94a35851bfe0.png)

以下のようにDECIMALとして扱うと滑らかになる
```
CAST(doublevalue AS DECIMAL(10,1)) AS "value1"
```

ついでに、Y軸の `Decimals` を以下のように１以上の値にすると、グラフ上も小数点単位で表示されるようになる

![image](https://user-images.githubusercontent.com/18366858/102664096-6db6ee80-41c5-11eb-8063-90a389c7c5dc.png)

![image](https://user-images.githubusercontent.com/18366858/102664125-7c9da100-41c5-11eb-91e1-1982e66e1d3d.png)

# その他のTips

## variablesを使ったフィルタリング

以下のように複数データがある時に、一つに絞りたいときはvariablesを使ったフィルタリングができる

![image](https://user-images.githubusercontent.com/18366858/102665619-7e1c9880-41c8-11eb-97d7-0ab2c0bb73f3.png)

右上の歯車マークの設定ボタンを押して、
![image](https://user-images.githubusercontent.com/18366858/102665806-d94e8b00-41c8-11eb-8d23-9369cb62f345.png)

Variablesを選んで以下のように設定する

- 以下は、dailyというテーブルに `code` というカラムがあるという前提で、この `code` でフィルターしたいときの設定方法

![image](https://user-images.githubusercontent.com/18366858/102665861-000cc180-41c9-11eb-9284-922f214f1efb.png)

General

- Name: フィルター項目名

Query Options

- Data source: MySQL
- Query: `SELECT code FROM daily`

Selection Options

- Multi-value: ONにすると複数選択ができる
- Include All option：ONにするとAll選択ができる


ここまですると、`Preview of values` にフィルター項目が列挙される

もとのグラフに戻ると以下のようなフィルター設定が追加されて、見たい項目だけ選択することができる

![image](https://user-images.githubusercontent.com/18366858/102700196-b2f32300-428e-11eb-817f-3efab29e7b6d.png)


このフィルターをMySQLで使うためにはSQLのWHERE句で以下のようにフィルター項目を使えばいい

```sql
WHERE
  $__timeFilter(`date`)
  AND code in ($code)
```

- `($code)` でフィルター項目が使える

参考：https://grafana.com/docs/grafana/latest/datasources/mysql/#query-variable


## 特定の項目を右軸表示にする

サーバのリクエスト数とDBへの更新数のように、まったく別の項目を一つのグラフで並べて関連を見たいという場合に、
同じY軸を共有できないという問題がある

そういう場合、左のY軸はサーバのリクエスト数（RPS）にして、
右のY軸をDBへの更新数（short）のように分けることができる

そういう場合は、以下のようなグラフの項目の左側の線「ー」を押すと、

![image](https://user-images.githubusercontent.com/18366858/102700312-acb17680-428f-11eb-9ac1-58967f72eddb.png)

以下のようにY-Axisを選ぶことができるので、

![image](https://user-images.githubusercontent.com/18366858/102700332-d23e8000-428f-11eb-9ef9-cac78a8cc8a8.png)

これをONにすると選んだ項目が右側のY軸に表示される

![image](https://user-images.githubusercontent.com/18366858/102700346-eda98b00-428f-11eb-9083-22bf8bcb966f.png)


### 右Y軸に複数の項目を表示したい場合

上のケースで、サーバが複数ある場合、例えば「server1-update」, 「server2-update」...
のようにたくさん項目がある場合に全部を一律で右のY軸にするのには以下のように正規表現を使えば、「〇〇update」という項目が一律で右Y軸になる


![image](https://user-images.githubusercontent.com/18366858/102700370-247fa100-4290-11eb-89ef-f59c37046880.png)

- `Series overrides` 項目を設定する
- 正規表現を使うときは `/` で囲えばいい






# 公式以外に参考にさせていただいたページ

- https://www.s-style.co.jp/blog/2018/02/1538/
- https://tech-lab.sios.jp/archives/16905
- https://www.sqlshack.com/overview-of-the-grafana-dashboard-with-sql/
