
#### docker daemon

WSLでは普通のinit.dやsystemdは使っていないみたい

https://www.reddit.com/r/bashonubuntuonwindows/comments/ftkoxp/wsl2_systemd_service_rc_initd/
```
Both WSL 1 & 2 do not have a typical init or service manager like systemd. Instead they have a Microsoft-proprietary init which is designed for fast start-up and Windows integration, and does not handle service management. It runs when you start a WSL instance, and shuts down shortly after the last WSL process (for a given distro) exits.
```

daemonの起動にはsystemctlではなくserviceコマンドを使う

#### serviceコマンド

https://xtech.nikkei.com/it/article/COLUMN/20070605/273739/

serviceコマンド

```
指定されたLinuxデーモン（サービス）の起動や停止，ステータスの確認を実行する。実際はシェル・スクリプトであり，/sbin/serviceをテキスト・エディタなどで開くとスクリプトの中身を確認できる
```


# Dockerの構成

https://docs.docker.jp/engine/introduction/understanding-docker.html

![image](https://user-images.githubusercontent.com/18366858/93005942-6adaab00-f591-11ea-9af6-c68eb4d0527f.png)


```
Docker はクライアント・サーバ型のアーキテクチャです。Docker クライアント は Docker デーモン と通信することで、Docker コンテナの構築・実行・配布といった力仕事をします。
```

Docker デーモン
```
先ほどの図で見たように、Docker デーモンはホストマシン上で動きます。ユーザは直接デーモンと通信せず、Docker クライアントを通して行います。
```
Docker クライアント
```
Docker クライアントは docker バイナリの形式です。これは主にユーザが Docker との通信に使います。ユーザからのコマンドを受け付けると、その先にある Docker デーモンと通信し返します。
```

# Docker for Windows

公式の設定手順
https://docs.docker.com/docker-for-windows/

https://matsuand.github.io/docs.docker.jp.onthefly/docker-for-windows/

公式のdemonについての注意
https://docs.docker.jp/docker-for-windows/index.html
```
Expose daemon on tcp://localhost:2357 without TLS - レガシー（古い）クライアントが Docker デーモンに接続できるようにするには、このオプションを有効化します。このオプションを使う場合は注意が必要です。TLS なしでデーモンを公開する場合は、リモートからのコード実行攻撃をもたらす可能性があるためです。
```


https://paiza.hatenablog.com/entry/docker_intro
```
Windows上でDockerを利用するインストーラです。VirtualBox不要でWindowsと密に統合されています。VirtualBoxと同時には利用できません
```

https://techinfoofmicrosofttech.osscons.jp/index.php?Docker%20for%20Windows#z5c41a4e
```
Docker Desktop for Windows †
2.0.0.2から Docker Desktop for Windows にリネームされた。
以下が可能になる。
Windows Serverコンテナ自体を実行可能
WSL2上でDockerを実行可能
```

https://www.gwtcenter.com/how-docker-works
```
Docker for Windows
したがって、従来的には、Dockerというのは「Linux上でLinuxコンテナを扱うもの」だったらしいのだが、ここにMicrosoftも協力しだしたらしく、Docker for Windowsというものが出てきた。これはいかなるものかと言えば、

Windows上でLinuxカーネルを動作させ、その上でLinuxコンテナを動作させる。
Linuxコンテナではなく「Windowsコンテナ」なるものも動作させることができる。
Microsoftとしては当然だろう。世の中がLinuxコンテナだけになってしまっては困るため、協力する代わりに「Windowsコンテナ」もデビューさせたというわけだ。

もちろん、こちらとしては「Windowsコンテナ」などはどうでも良い。重要なことは、Windows上でもLinuxコンテナを扱うことができるという点である。これはありがたい
```

MicroSoft公式

https://docs.microsoft.com/ja-jp/virtualization/windowscontainers/deploy-containers/linux-containers

```
Docker では、Hyper-V で動作する LinuxKit ベースの仮想マシンを使用することにより、2016 年の最初のリリースの時点 (Windows で Hyper-V による分離や Linux コンテナーが使用可能になる前) から、Windows デスクトップ上で Linux コンテナーを実行できました。
このモデルでは、Docker クライアントは Windows デスクトップ上で実行されますが、Linux VM 上の Docker デーモンを呼び出します。
```
![image](https://user-images.githubusercontent.com/18366858/93006030-50550180-f592-11ea-9972-067a2f126ab7.png)



https://www.atmarkit.co.jp/ait/articles/1609/01/news053_2.html
```
Dockerは基本的にはCUIで操作／管理するツールである。後述するようにGUIの管理ツールも存在するけれど、「docker.exe」というコマンドラインコマンドにパラメーターを付けて操作するのが標準といえる。

　Docker for Windowsをインストールすると、「C:\Program Files\Docker」フォルダ以下にDocker関係のツールがインストールされ、PATH環境変数もセットされる。そのため、インストール後にコマンドプロンプトやPowerShellコンソールを開けば、すぐにdockerコマンドを実行できる。
```


#### usermod

https://eng-entrance.com/linux-command-usermod#-G--groups_GROUPS

コンピュータに登録されているユーザーの設定を変更するコマンド

```
$ usermod -aG グループ名またはグループ番号(GID) ユーザー名

ユーザーFernandezの副所属グループに「Designer」を追加する場合は、次のコマンドだ。

$ usermod -aG Designer Fernandez
```
