# 一言

Microsoft の人がわかりやすい資料を出していたのでシェアします

Kubernetes のしくみ やさしく学ぶ 内部構造とアーキテクチャー
https://www.slideshare.net/ToruMakabe/kubernetes-120907020

# 一言

同一 Lan 内の別のデバイスに複数のファイルを共有するときに、
適当なディレクトリ以下にファイルを置いて圧縮してサーバを立てるだけでまとめてダウンロードできます

```
$ zip -r sampledir.zip sampledir
$ python3 -m http.server --cgi 8181
```

メールなどで送るのめんどくさい
Dropbox などのラウドサービスを使いたくない
USB メモリとかで受け渡ししたくない

ときに便利なので、家で妻に複数の写真を共有するときに使っています。便

2019/08/19

## 一言

これ面白いです
[algorithm - 動的時間ワーピングの紹介 \| algorithm Tutorial](https://riptutorial.com/ja/algorithm/example/24981/%E5%8B%95%E7%9A%84%E6%99%82%E9%96%93%E3%83%AF%E3%83%BC%E3%83%94%E3%83%B3%E3%82%B0)

2019/08/23

## 一言

社内の睡眠改善セミナーに参加したのでシェアします

印象に残った点を抜粋すると、

- 睡眠の前半は脳の休息、後半はこころの休息
  -> なので睡眠時間を増やすとストレスやうつにつながる
- 睡眠圧はバネのようなもので、起きている時間が長いほど寝る力が強まる
  -> そのため、夜に近い時間帯に仮眠をとってしまうと睡眠圧が低くなる

いい睡眠を取るための行動指針として、

- 日中適度な運動をする
- 寝る一時間前にお風呂に入って深部体温を上げる
- 起きたら太陽光または蛍光灯でもいいので光を目に届ける
  などありました

2019/08/27

## 一言

https://github.com/golang/go/issues/31857
go 1.13 について
デフォルトの挙動はいままで通り auto、go module を使う際には GO111MODULE=on の設定が必要

> We have set GO111MODULE=on by default in the Go 1.13 development branch,

ただし 1.13 の auto では、GOPATH/src 以下であっても、go コマンドを実行したディレクトリまたはその親ディレクトリに go.mod が存在する場合は
Go module を使う挙動になるらしいです

> I suggest we ship Go 1.13 with the GO111MODULE default set back to “auto”, but with the GOPATH/src restriction removed.
> The effect would be that in Go 1.13, if you run go commands in a directory tree where someone has created a go.mod (that is, either you put the go.mod there, or the project you are contributing to has decided to switch to module-based development), then you get module mode, regardless of whether you happened to check it out inside or outside GOPATH/src.

2019/09/11

## 一言

Docker の一般的なガイドラインとアドバイス
公式ドキュメントがとてもわかり易いので定期的に読み直したいです。
http://docs.docker.jp/engine/userguide/eng-image/dockerfile_best-practice.html#id2

Google のガイドライン
コンテナ構築のおすすめの方法
https://cloud.google.com/solutions/best-practices-for-building-containers

2019/09/12

## 一言

プログラミング言語の速度目安
https://twitter.com/tanakh/status/1171312613394792448
Tier1(最速): C/C++, Rust

Tier2(最速から 2~5 倍遅い): C#, Java, Swift, F#, OCaml, Lisp, Go など

Go versus C++とか色々あって面白いです
https://benchmarksgame-team.pages.debian.net/benchmarksgame/fastest/go-gpp.html

2019/09/20

## 一言

"なぜ Rust じゃなくて Go なの？" https://kristoff.it/blog/why-go-and-not-rust/
＜以下超意訳です＞

- Rust の方が Go より速いし
- Rust でも並行処理はできる
- Go は効率的なガベージコレクションがある。 でも Rust には static memory 管理ができる
- Go は Interface がある。でも Rust には trait もある

それでも Go のシンプルさ、go fmt などによるフォーマットの厳格性、不要な package を import できないなどの特性は、企業で大規模なソースコードを作り保守する上では非常に重要なものとなる。
読みやすく、習得しやすい、これは大事
など書いてありました。

これを断言しているのが批判を生みそうですが、面白かったのでシェア

> Go is a better Java / C#, while Rust is not

2019/09/26

## 一言

go 言語による並行処理
Chapter 4. Concurrency Patterns in Go
https://www.oreilly.com/library/view/concurrency-in-go/9781491941294/ch04.html

fanin-fanout の良い例を見つけたのでシェア
https://austburn.me/blog/a-better-fan-in-fan-out-example.html

2019/09/30

## 一言

signal を受け取ると context を cancel する自作 context を見つけて面白かったです。
https://gist.github.com/SpeedyCoder/59911301eea4d91e42feafccaa9bcaf7#file-newctx-go

2019/10/02

2019/10/04

## 一言

bash cheatsheet & vim cheatsheet
https://devhints.io/bash
https://devhints.io/vim

2019/10/08

## 一言

Google のまとめた IPv6 採用状況 → 現在 30%程です
https://www.google.com/intl/ja/ipv6/statistics.html#tab=ipv6-adoption

ついでに NTT Commu の 2018 年のインターネット運用動向 PDF
https://www.nic.ad.jp/ja/materials/iw/2018/proceedings/d4/d4-yoshida.pdf
→ Nagios のグラフがいっぱい出てきて懐かしいです

甲子園 の LIVE 配信とか面白いですね。昼ピーク、夜ピーク、地震など、
傾向は広告と同じですね

2019/10/09

## 一言

昨日の投稿は以下に関係するものでした

- IPv6 が IPv4 よりも速い理由
  https://www.geekpage.jp/blog/?id=2019-10-7-1
  > モバイルキャリアでの IPv6 でのパフォーマンスは最大 40%良い事例があることが紹介されています。
  > IPv4 アドレス在庫枯渇問題による弊害が徐々に通信速度の変化という形で多くのユーザの通信に影響を与え始めているのかも知れません。
  > ARIN の記事も、「IPv6 が速い」というタイトルであるものの、実際には「IPv4 が遅くなりつつある」ことを示唆する内容です。

2019/10/10

## 一言

Bad Go: not sizing slices
https://medium.com/swlh/bad-go-not-sizing-slices-aed1b01cff83

自分の Mac でもやってみました。
https://play.golang.org/p/SsUUJICED8l

- ４回ずつ以下を実行
  BenchmarkTest1: 単純な append
  BenchmarkTest2: 事前に追加するデータの個数分長さを確保してから append
  BenchmarkTest3: 事前に追加するデータの個数分要領を確保してから append
  BenchmarkTest4: 事前に追加するデータの個数分長さを確保してから要素を指定して代入
  -> 4 が最も速い

2019/10/17

## 一言

かわいい gopher たち
https://github.com/MariaLetta/free-gophers-pack

2019/10/23

## 一言

kube-prompt を使ってみます
https://github.com/c-bata/kube-prompt

2019/10/24

## 一言

https://ja.m.wikipedia.org/wiki/UNIX%E5%93%B2%E5%AD%A6
go 言語の開発にも携わっているロブ・パイクのプログラムの格言。
Go の考え方もこれに根ざしているようにみえます。

```
ルール1: プログラムがどこで時間を消費することになるか知ることはできない。ボトルネックは驚くべき箇所で起こるものである。したがって、どこがボトルネックなのかをはっきりさせるまでは、推測を行ったり、スピードハックをしてはならない。
ルール2: 計測すべし。計測するまでは速度のための調整をしてはならない。コードの一部が残りを圧倒しないのであれば、なおさらである。
ルール3: 凝った(Fancy)アルゴリズムはnが小さいときには遅く、nはしばしば小さい。凝ったアルゴリズムは大きな定数を持っている[2]。nが頻繁に大きくなることがわかっていないなら、凝ってはいけない（nが大きくなるときでさえ、ルール2が最初に適用される）。
ルール4: 凝ったアルゴリズムはシンプルなそれよりバグを含みやすく、実装するのも難しい。シンプルなアルゴリズムとシンプルなデータ構造を使うべし。
ルール5: データはすべてを決定づける。もし、正しいデータ構造を選び、ものごとをうまく構成すれば、アルゴリズムはほとんどいつも自明のものになるだろう。プログラミングの中心は、アルゴリズムではなくデータ構造にある。
ルール6: ルール6は存在しない。
```

＞ ルール 6 は存在しない。

かっこいいですね

2019/10/25

# 一言

最近の Slack の新機能
https://slackhq.com/intl-ja-jp-automate-tasks-in-slack-with-workflow-builder

それを使って見た人たちの活用集
https://seleck.cc/1356
https://seleck.cc/1357

2019/10/28

# 一言

CircleCI API v2 で自由自在に業務ワークフローのタスクを実行する
https://techblog.kayac.com/circleci-api-v2
circleci は v2.1 で色々便利な書き方ができるのですが、API やドキュメントなどが 2.0 までしか対応していないなどの問題もあります。

2019/10/29

## 一言

Kubernetes、独自のコンテナランタイム「cri-o」（ちょっと古い記事なので実際はもうありますが、日本語でわかりやすいので）
https://www.publickey1.jp/blog/16/kubernetescri-odocker.html
コンテナランタイムの動向を整理してみた件
https://qiita.com/mamomamo/items/ed5db2ab1555078f8a24
Docker Swarm
http://docs.docker.jp/swarm/overview.html

このチームでは Docker-Kubernetes という組み合わせを使っていますが、
CRI によって、Kubernetes ->Docker だけでなく様々なコンテナランタイムが選択できるようになったことで、
Docker も Swarm というオーケストレーションを作って対抗（？）し、
いろいろなバリエーションが生まれてきたのが最近の動向なので面白いです。
でもやっぱり Docker & Kubernetes がやはりいちばんポピュラーなんですかね。わかりません

2019/10/30

## 一言

The Top 10 Most Common Mistakes I’ve Seen in Go Projects
https://itnext.io/the-top-10-most-common-mistakes-ive-seen-in-go-projects-4b79d4f6cd65

上のリンクで特に好きだったところ２つ

Benchmarking
以下のような Benchmark は正しく計測できません
clear 関数は外部になんの影響も及ぼさないので、コンパイラによって無視されてしまいます。

```
func BenchmarkWrong(b *testing.B) {
	for i := 0; i < b.N; i++ {
		clear(1221892080809121, 10, 63)
	}
}
```

正しく測るためには、clear 関数が外部に影響を及ぼす(side-effect)
とコンパイラに認識させることが必要で、以下のようにすればいいです

```
var result uint64

func BenchmarkCorrect(b *testing.B) {
	var r uint64
	for i := 0; i < b.N; i++ {
		r = clear(1221892080809121, 10, 63)
	}
	result = r
}
```

Pointers! Pointers Everywhere!
Go のコンパイラは、pointer を stack ではなく heap に格納します。（訳注：全部が全部かはきちんと確認してないです）
※heap はグローバル変数などを置く場所、stack は一時的な変数の置き場所
そして、heap の変数は stack より遅いです！
stack の方が速いのは stack が GC や複数 goroutine の操作の同期が不要（一回呼び出したらその変数は不要なので）という理由があります

そのため、一般に関数に pointer 渡しをすると、値渡しよりも遅くなります。

私が自分の Ubuntu で試したらたしかに pointer の方が少し遅くなりました

Benchmark 用のソースコード
https://gist.github.com/teivah/a32a8e9039314a48f03538f3f9535537

```
BenchmarkByValue        37670398                31.5 ns/op             0 B/op          0 allocs/op
BenchmarkByPointer      16895854                72.1 ns/op           288 B/op          1 allocs/op
```

2019/10/31

## 一言

お前の Docker イメージはまだ重い
https://speakerdeck.com/stormcat24/oqian-falsedockerimezihamadazhong-i?slide=11

- scratch, busybox, alpine などがわかりやすくまとまっています

https://blog.codeship.com/building-minimal-docker-containers-for-go-applications/

- scratch イメージを go でどう使うかを具体的に紹介しています。
- SSL 接続のために ca-certificates.crt が必要とか、ないとどうなるかとか具体例とともに理由を書いてあっていいです

効率的に安全な Dockerfile を作るには
https://qiita.com/pottava/items/452bf80e334bc1fee69a

- 毎回 Docker build しつつ検証しなくても、もっと効率的なやり方あると紹介しています。

最近 Dockerfile を目にする機会があったので、自分でももっときちんと理解したいです。

2019/11/1

## 一言

【インスタ、エアビー、Slack 等】人気サービスの初期ユーザー獲得方法
https://blog.btrax.com/jp/first-users/
元記事
https://earlyusergrowth.com/startups#github
人脈って重要だなと思いました

2019/11/2

## 一言

golang で最小（かつ secured な）docker image を scratch ベースで作る（訳）
https://medium.com/@chemidy/create-the-smallest-and-secured-golang-docker-image-based-on-scratch-4752223b7324
１．空の golang image size（FROM golang）は 774MB もある

- > Ouch 774 MB just for an empty image … this is crazy

2. FROM golang:alpine にすると 350MB

   > This is smaller but too large for a production image with nothing

3. FROM scratch （multi stage build）にすると 13.6MB
   go 1.10 の場合はこれが良い
   > RUN GOOS=linux GOARCH=amd64 go build -ldflags="-w -s" -o /go/bin/hello

他色々ノウハウが書いてあります

2019/11/6

## 一言

人気プログラミング言語の推移
https://twitter.com/knsmr/status/1190423045166391296/video/1

- 70 年代から 80 年代初頭 fortrun が圧倒的優勢
- 80 年代に c 言語が出現、徐々にランクを伸ばして最上位となり、その後 20 年近く首位
- 2000 年代、java の天下
- ひっそりとしていた python がじわじわと伸ばしてきて 2019 年ついにトップに

ソースがわかりませんが面白いです

> Data source: aggregated statistics from several indexes, GitHub repository access, multiple surveys

2019/11/7

## 一言

container とか generator とか書く時に、-er で終わるのか-or で終わるのかしょっちゅうわからなくなります。
ちょっと調べた中ではこれが詳しかったのですが、詳しすぎて簡単じゃないのでざっくり以下にまとめ
https://www.thefreedictionary.com/Commonly-Confused-Suffixes-er-or-ar.htm
１．-ate で終わる動詞は -or
２．上以外の drive などの 無声音の-e で終わる動詞、play などの-y で終わる動詞は -er
３．conduct などの -ct で終わる動詞は -or がほとんど
たまに -ar もある
ということでやっぱりよくわからない・・・？

2019/11/8

## 一言

A．errors パッケージとエラーハンドリングについて
https://deeeet.com/writing/2016/04/25/go-pkg-errors/

B．上のブログの原典：errors パッケージの考え方とエラーハンドリングについて
https://dave.cheney.net/tag/error-handling
C．上の作者の追記
https://dave.cheney.net/2019/01/27/eliminate-error-handling-by-eliminating-errors

自分の理解のために簡単にまとめると
エラーハンドリングの際に、これらの方法は良くないという内容です
１．エラー文をそのまま if err.Error() = "hoge" みたいに分岐処理するのは一番だめ

- 途中に関数が挟まれて、fmt.Errorf("fuga: %v", err) とかされた瞬間に通用しなくなる
  ２．センチネルエラー io.EOF などの判定もあまり良くない
- パッケージ間の依存関係が複雑になる
- 上のブログ B の「Sentinel errors create a dependency between two packages」が詳しいです
  ３．switch err := err.(type) みたいな型の判定も良くない。１，２よりは良い
- もしある interface で特定の error type を返すように決めていたら、その実装も全部同じ type を返す必要が生じる
- 「Problems with error types」

結論：type ではなく interface を満たしているかを判別するのが一番いい
こんな感じに型アサーションで判定すると良いよ。と書いています

```
func IsTemporary(err error) bool {
   te, ok := err.(temporary)
   return ok && te.Temporary()
}
```

この人は errors パッケージを使って、Wrap でエラーをラップして、Cause でエラーの原因をハンドリングするという手法を提案しています。
自分なりに Wrap と Cause の挙動を見てみました
https://play.golang.org/p/FJD2MHgcKfj

2019/11/11

## 一言

Kubernetes の自前運用はやっぱりツライらしい
https://www.orangeitems.com/entry/2019/11/08/183232

2019/11/13

## 一言

Go 言語らしく Go コードを実装するための手法と思想
https://kaneshin.booth.pm/items/1061168
上の本の作者がいま以下で内容を無料公開しています。
https://twitter.com/kaneshin0120/status/1193860216942542848

eureka の金子さんという方です。
Come On!! Go Fan!!（前編）～各社のエキスパートが語る、Go 言語活用の最前線とは？～
https://flxy.jp/article/3696

2019/11/14

## 一言

マイクロサービス化が生むサービスメッシュによる相互関係は、大企業になると凄いものになります。
その様子を形容して death star と皮肉まじりに呼ばれるそうです。
https://contiv.io/articles/2016/03/06/scaling-microservices.html
https://www.plugandplaytechcenter.com/resources/what-service-mesh-and-why-should-you-care-about-it/

2019/11/15

## 一言

入門、Kubernetes Persistent Volume
https://speakerdeck.com/ysakashita/ru-men-kubernetes-persistent-volume

- Zlab の坂下さんの書いた資料を昨日見ました

2019/11/18

## 一言

go のテストで事前に Database などを作って終わったら削除する方法として、
以下のようにすると、「defer setupDB()()」を書くだけで、
テスト前の作成とテスト後の削除ができるという方法を学んで、きれいだなと思いました。

```
func TestHoge() {
    defer setupDB()()
}

func setupDB() func() {
    // create database
    return func() { deleteDB() }
}
func deleteDB() {
    // delete database
}
```

2019/11/19

## 一言

k9s：UI が結構格好良いです
https://github.com/derailed/k9s
https://okadato623.hatenablog.com/entry/2019/11/11/075700

2019/11/20

## 一言

Go style guide

- 多くの方が気をつけていることで既知かも知れませんが、見かけたので
  https://about.sourcegraph.com/handbook/engineering/go_style_guide

2019/11/21

## 一言

Erich Gamma さん（日本ではエリック・ガンマで名前が知られている）
作った（関わった）ツール

- JUnit
- Eclipse
- VS Code

私は知りませんでした。すごいですね。多くの開発者の母ですね。

2019/11/26

## 一言

Go の開発者の一人 Dave cheney のシンガポールでのプレゼン
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_design_apis_that_are_hard_to_misuse
最近これ読んでいました。
長いので、気になったところだけ書きます

超訳なので、誤訳は許してください

1. Guiding principles

- Go 言語の長所である Clarity、Simplicity、Productivity について熱意をもって説明しています
- シンプルでわかりやすいことは、コードの信頼性を高める
- 簡潔なコードよりもわかりやすいコードに重きを置きましょう
  など

2. Identifiers
   主に変数の長さやコードの書き方について説明

#### 2.2. Identifier length

変数の長さ

_コード中で、変数が定義されてから最後に使われるまでの距離が長いほど、変数の名前も長くする_

`for _, p := range people { ` の時の p はこのループの中でしか使わないので、一文字で十分

- index とかの名前は読む人を逆に混乱させる
  `people`は関数の中の数行で使われるので、省略せず people とする

#### 2.3. A variable’s name should describe its contents

型を変数名に含めない

ペットに dog とか cat とかつけないのと同じように、変数名に usersMap のように `Map` などの型名をつけるのはやめましょう。
Go は型が厳格なので、Map を Slice として使ってしまうようなことはありません。
自明なものはつけないようにしましょう。
usersMap は users で十分です

#### 2.5. Use a consistent declaration style

Go の変数宣言の方法は色々あります。
（宣言の仕方が多すぎるのは失敗でしたが、気づいたときには手遅れでした）

基本はこの２つで十分です

１．変数を後で使う目的で宣言し初期化しないときは `var things []thing` の形

- var things = nil はだめ
- var thing = new(Thing) もだめ
- var things = make([]Thing, 0)も別の意味なのでだめ
  ２．変数を初期化するときは `:=` の形にする

例外

```
var min int
max := 1000
```

みたいに不自然になってしまう場合は以下の方法でいいです
`min, max := 0, 1000`

2019/11/27

## 一言

https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_commentary
昨日の続き

3. Commentary
   コメントは以下の３つのどれかであるべきです

1. それが何をするものなのか what

- 以下のようなコメント。公開メソッドなどの上に書いてあるやつ
  `// Open opens the named file for reading.`

2. あることをするのにどうやって実現しているか how

- メソッドの中にあるといいコメント
  `// queue all dependant actions`
  （訳注：ここ文字変なので https://dave.cheney.net/practical-go/presentations/qcon-china.html 見たほうがいいです）

3. なぜそれがあるのか？

- 外部要因だったり、ぱっと見では理由がわからないものついて書くと良いコメント

例
`const randomNumber = 6 // determined from an unbiased die`

上の例では、なぜランダムな数字として６が使われているのか、その由来はなにかが書いてあります

#### 3.2.2. Rather than commenting a block of code, refactor it

```
優れたコードはそれ自体が最高の資料です。コメントを追加しようとする前に、
そのコードをもっと良くできないか自問しましょう。
コードを良くすればコメントもより明確になります
```

（訳注：心がいたい）

2019/11/29

## 一言

Dave Cheney のシンガポールでの Go のプレゼン続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_package_design

4. Package Design

#### 4.3. Avoid package names like base, common, or util

`utils` `helpers` `common` `base` などは目的を反映していないことがしばしばです。
目的にあわせて適切なパッケージに移しましょう。

io/ioutil と net/http/httputil パッケージはだめな例です（意訳）

**間違った抽象化をするくらいなら、コードが重複する方がよっぽど安上がりです。**

たとえば、net/http パッケージでは、`client` や `server` などのサブパッケージを持ちません。
client.go, server.go というファイルが存在します。これらはそれぞれ必要な type を持っています

#### 4.4. Return early rather than nesting deeply

ガード構文を使って深いループを避けましょう

Go 言語では例外処理がありません。
関数の中では異常を見つけ次第そのエラーを返す、ガード構文を採用するといいです。

異常が発生しない限りは抜けない作りになっていれば、
関数を上から順に見ていくとそれがそのまま処理が成功しているルートになります。
Mat Ryer はこのスタイルを `line of sight` 照準線と呼んでいます。

2019/12/2

## 一言

Dave Cheney のシンガポールでの Go のプレゼン続きです
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_package_design

#### 4.5. Make the zero value useful

未初期化の変数を効果的に使いましょう

slice には未初期化の値が nil であるという特性があります。
len, cap も 0。したがって、未初期化の slice の内容はメモリ上でも nil です。
したがって、slice を定義してそれに値を追加するのは単純にこう書けるのです

```
var s []string
s = append(s, "Hello")
s = append(s, "world")
```

var s1 = []string{} と var s2 []string は違うので注意しましょう
（訳注：前者はゼロの長さのスライス、後者は nil です。[]string{}と []string(nil)の違い）

#### 4.6. Avoid package level state

パッケージレベルの変数を避けましょう。

グローバル変数はあなたのソースコードの全関数の目に見えないパラメータとして存在します！
グローバル変数をちょっと変えたらこれらは破綻します

コード間の相互依存を減らすために、以下の２つがおすすめです

１．グローバル変数は避けましょう。変数はそれを必要とするコード内の struct の field に入れましょう
２．interface を使って振る舞いと実装を分けましょう

2019/12/3

## 一言

Dave Cheney のシンガポールでの Go のプレゼン続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_project_structure

5. Project Structure

あなたの project（git repository の単位と同義）がライブラリなら、それは１つのことだけを担うべきです。
（XML をパースするとか、ロギングするとか）
（訳注：これはマキルロイの UNIX 哲学：「一つのことを行い、またそれをうまくやるプログラムを書け」と同じだと思いました）

複数の目的を担当するのはやめましょう。恐るべき `common` ライブラリ誕生を防止しましょう！

TIPS：

```
私の経験では、 `common` リポジトリを作ると、それを使った依存部分がとても大きくなります。
それによりbackport 修正が困難になります。
もし修正するとなったら、`common` に加えて利用者側にも更新の必要が生じます。
更新の際には、利用者には関係のない変更やAPIのIFのずれの問題なども発生します。

```

#### 5.1. Consider fewer, larger packages

package の不適切な使い方は Go において多く見られる失敗の一つです。（これはプログラマーが
何かをカテゴライズしたいと思ってしまう気質が影響しているのだろうと私は考えています）

Go では、他の言語と異なり、ある識別子（変数、関数、メソッド）の参照方法として、
public か private の２種類しかありません。（protected とか default とかありません）
識別子の最初の文字が大文字ならパッケージ外に公開、小文字なら非公開、という違いだけです。

ではこの２種類しか修飾子がないという前提で、
package の依存関係を複雑にしないようにするためには何を心がけるべきでしょうか？

私のアドバイスは以下の通りです、
_package はなるべく数を少なくし、一つの中身は大きくする_
（訳注： "prefer fewer, larger packages" の訳）

基本的には、新しいパッケージは作らないスタンスで行きましょう。
これにより、package 内の識別子へのアクセスは広く、浅く、になります。
詳細はこのあとのセクションで細かく説明します。

2019/12/4

## 一言

Dave Cheney のシンガポールでの Go のプレゼン続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_project_structure

#### 5.1.1. Arrange code into files by import statements

`.go` ファイルをどのタイミングで分割すべきでしょうか？
また、どんなときに１つにまとめたほうがいいでしょうか？

私のガイドラインは以下のとおりです

１．それぞれの package につき、一つの　`.go` ファイルから始めましょう。
それぞれのファイルは package 名と同じにしましょう。たとえば `http` package には `http.go`を置きましょう

２．package が大きくなって分割したくなったら、「責任範囲」ごとにファイルを分けましょう
例えば、 `message.go`には `Request` と `Response` type が含まれるべきですし、
`client.go`には `Client`が、 `server.go` には `Server` type が含まれるべきです

３．複数のファイルで同じような import をしている場合は、１つにまとめるか、
共通部分の type/ function/ method をくくりだして別のファイルに置きましょう

４．別々のファイルは、それぞれ package 内で別々の役割を担うべきです。
`messages.go`は HTTP リクエストやレスポンスの marshal をするかも知れません。（以下略）

TIP：ファイル名はソースコードの入れ物（containers）なので、名詞がふさわしいです

NOTE: go のコンパイラはそれぞれのパッケージを並列でコンパイルします。それぞれのパッケージではそれぞれの関数も並列でコンパイルされます。
したがって、パッケージのレイアウト変更はコンパイル速度に影響しません

2019/12/6

## 一言

Dave Cheney のシンガポールでの Go のプレゼン続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_project_structure

#### 5.1.2. Use internal packages to reduce your public API surface

自分のプロジェクト内では public にしたい、でもプロジェクト外からは private にしたい、
というときは internal ディレクトリを作りましょう

（訳注：internal についての説明は以下が詳しいです）
公式の説明
https://github.com/golang-standards/project-layout#internal
日本語の紹介記事
https://text.baldanders.info/golang/internal-packages/

#### 5.2. Keep package main as small as possible

_main 関数と main package はできる限り小さくしましょう_

main.main はシングルトンです。
main.main が呼び出されるには多くの前提となる条件が必要とされます。そして一度きりしか実行されません。
このため、main.main はユニットテストをしづらくします。

main パッケージは、しばしばシングルトンを作成します。また、コマンドラインフラグをパースしたりもします。
ディスクのある場所にファイルがないと実行できないこともあります。
さらに、同時並行で実行されることも想定されていません。
main.main は単体テストから呼び出すこともできません。

それ故に、ビジネスロジックはなるべく main 関数から別のところに移したほうがいいです。
可能であれば main パッケージからも他へ移すべきです。

`func main()` はフラグをパースしたり、database や logger とのコネクションを開いたりそういったことだけをすべきです。
そして実際に起動するのは 別の高レベルの object に任せましょう。

（訳注：シングルトンの弊害は以下がわかりやすかったです）
https://xn--97-273ae6a4irb6e2hsoiozc2g4b8082p.com/%E3%82%A8%E3%83%83%E3%82%BB%E3%82%A4/%E3%82%B7%E3%83%B3%E3%82%B0%E3%83%AB%E3%83%88%E3%83%B3%E3%83%91%E3%82%BF%E3%83%BC%E3%83%B3%E3%81%AE%E8%AA%98%E6%83%91%E3%81%AB%E8%B2%A0%E3%81%91%E3%81%AA%E3%81%84/

（訳注：シングルトンの弊害を簡潔にまとめたページも見つけました）
https://tech.a-listers.jp/2011/05/06/i-am-adam/

```
依存関係を見えにくくし、コードが読みづらくなる。
ユニットテストを難しくする。外部から渡せないオブジェクトはモックにする事が難しい。
プログラムの再利用性が低下する。一度しか使わないからとシングルトンで作ってしまうと複数のユーザーから利用されるような場合に対応できなくなる。
```

2019/12/9

## 一言

Dave Cheney のシンガポールでの Go のプレゼン続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_api_design

6. API Design

デザインに関する最後のアドバイスは、私が最も重要だと思うものです。
これまでの私のデザインに関するアドバイスはただの「提案」ですので、人に強要するものではありません。
が、後方互換性に関しては話が別です。

パッケージの公開 API については、最初のデザインについては熟考するべきです。
あとから変えるのは非常に多くの人に迷惑を与えます。（意訳）

（訳注：ここでいう API とは、関数やメソッドも含んでいるようです）

#### 6.1. Design APIs that are hard to misuse.

`APIは簡単に使えて、誤用しにくいものにすること` Josh Bloch

##### 6.1.1. Be wary of functions which take several parameters of the same type

`func Max(a, b int) int` この関数は使うのは簡単。
引数 a と b の順番が入れ替わっても結果は変わらない

```
Max(8, 10) // 10
Max(10, 8) // 10
```

一方 `func CopyFile(to, from string) error` この関数はどうでしょうか？
もし引数の順序を間違えると、成果物が先週に戻ってしまうかも！

```
CopyFile("/tmp/backup", "presentation.md")
CopyFile("presentation.md", "/tmp/backup")
```

いい解決策は以下のような方法です

```
type Source string

func (src Source) CopyTo(dest string) error {
	return CopyFile(dest, string(src))
}

func main() {
	var from Source = "presentation.md"
	from.CopyTo("/tmp/backup")
}
```

こうすれば誤用が防げます。CopyTo を小文字にして private にすればさらにリスクを減らせるでしょう。

TIP 同じ型の複数のパラメータを受け取る API は、正しく使うことが難しいことを覚えておきましょう

2019/12/9

## 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_api_design

#### 6.2.1. Discourage the use of nil as a parameter

API（関数やメソッドなど）の引数として nil を渡す仕様は推奨しません。

ここでは「デフォルトユースケース」について話します。
API を使う人にとって意味のない引数を必須にするのはやめましょう。
例として、net/http を見てみましょう

https://github.com/golang/go/blob/bbbc6589dfbc05be2bfa59f51c20f9eaa8d0c531/src/net/http/server.go#L3083-L3087

```
// ListenAndServe always returns a non-nil error.
func ListenAndServe(addr string, handler Handler) error {
```

この関数は２つの引数を取ります。
listen 用の TCP アドレスと、HTTP リクエストのハンドラ http.Handler です。

Handler が nil のときは、http.DefaultServeMux をが使われます。
（訳注： https://github.com/golang/go/blob/daaab44f3124aff61937fa7e118f02d4ff82166c/src/net/http/server.go#L2801-L2803 ）

つまり以下の２つは同じ意味です。

```
http.ListenAndServe("0.0.0.0:8080", nil)
http.ListenAndServe("0.0.0.0:8080", http.DefaultServeMux)
```

ただし、２つめの引数は nil にできますが、１つ目の引数については nil にはできません。

TIP： nil にできる引数とできない引数を混ぜるのはやめましょう

http.ListenAndServe の作成者は、API を簡単に使えるようにしたかったのでしょう。
しかしそのことで、むしろ安全に使いにくくなってしまいました。

```
const root = http.Dir("/htdocs")
mux := http.NewServeMux()  // ここ
mux.Handle("/", http.FileServer(root))
http.ListenAndServe("0.0.0.0:8080", mux)
```

この２行目を節約する価値は本当にあったのでしょうか？

TIP: helper 関数があれば使う人にとってとても役に立ちます。
（訳注：helper 関数というのは、上の例では NewServeMux を指している？）
簡潔さよりも明瞭さの方が重要です

TIP: 公開 API にはテストでしか使わない引数を渡すのはやめましょう
ラッパーを作ってそれらの引数を隠しましょう

2019/12/11

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_api_design

#### 6.2.2. Prefer var args to []T parameters

```
func ShutdownVMs(ids []string) error
```

こんな関数を考えてみましょう。
この引数は slice なので、空の slice や nil も入る可能性があります。（それでもコンパイラは異常を検知しません）
そのため、そういった場合を考えてテストケースを用意する必要があります。

引き数として与えられた slice の中身が全部正であることを確認するために、以下のようなチェックを入れるのは長くなって嫌です。

```
if svc.MaxConnections > 0 || svc.MaxPendingRequests > 0 || svc.MaxRequests > 0 || svc.MaxRetries > 0 {
	// apply the non zero parameters
}
```

そのため、以下のような関数を事前に呼ぶと良さそうです。

```
// anyPostive indicates if any value is greater than zero.
func anyPositive(values ...int) bool {
	for _, v := range values {
		if v > 0 {
			return true
		}
	}
	return false
}
```

ただこれでも足りない点があって、一つも引き数がないときに問題になります。
そのため、私が考えた方法は以下の解決策です。これなら、引数を最低１つは指定するように強制できます。

```
// anyPostive indicates if any value is greater than zero.
func anyPositive(first int, rest ...int) bool {
	if first > 0 {
		return true
	}
	for _, v := range rest {
		if v > 0 {
			return true
		}
	}
	return false
}
```

2019/12/12

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_let_functions_define_the_behaviour_they_require

#### 6.3. Let functions define the behaviour they require（関数は必要な振る舞いを考えて定義しましょう）

こんな感じのドキュメントをディスクに書き込むメソッドを考えてみましょう

```
type Document struct {
        // mo' state
}
// Save writes the contents of the Document to the file f.
func (d *Document) Save(f *os.File) error
```

このメソッドの引数は `*os.File` ですが、これにはいくつか問題があります。

データをネットワーク上のどこかに書き込むことには対応していません。（lambda とか）

- そのため修正が必要になったらこの関数を呼ぶすべてのところに影響します

test もしづらいです。ディスクに書き込まなければいけないので、然るべきファイルを test 前に用意して、
test 後にそれを消さなければいけません

さらに、 `*os.File` は Save メソッドには無関係の多くのメソッドも含んでいます。
（例えばディレクトリを読んだり、パスが symlink かどうかチェックするなどです）

そのため、`Save` メソッドが、 `*os.File` のうち必要な部分だけ渡す仕組みになっていれば都合が良さそうです。

```
// Save writes the contents of d to the supplied ReadWriterCloser.
func (d *Document) Save(rwc io.ReadWriteCloser) error
```

`*os.File` の代わりに、 `io.ReadWriteCloser` を渡すことにすれば、interface 分離の原則を守れます。
これにより、File 以外の多くに対応できるようになります。
ただし、interface 分離の原則をもっと推し進めることもできます。

（訳注：ちょっと長いので意訳したのが以下）

以下のように引数の型を制限しました。

```
// Save writes the contents of d to the supplied Writer.
func (d *Document) Save(w io.Writer) error
```

１．単一責任の原則を考えて read を削る

- ファイルの read（中身を確認するとかの作業）は別のコードに任せます
- このため io.ReadWriteCloser の Read は削りました

２．Close も別処理にする

- `wc io.WriteCloser` を与えると、Save が成功したら Close するのか、成功しなくても Close するのか良くわかりません
- 関数を使う人が混乱しないように、Save は Write のみを担当するようにさせました

interface 分離の原則を適用したことで、Save には io.Writer だけを渡せば済むようになりました。
こうなるともはや `Save` よりも `WriteTo` の方がメソッドの名前として正確だと言えます

最終的にはこうなりました。
`func (d *Document) WriteTo(w io.Writer) error`

（訳注：interface 分離の原則などの日本語記事として以下見つけたものを貼っておきます）
https://note.com/erukiti/n/n913e571e8207
https://qiita.com/shunp/items/646c86bb3cc149f7cff9

2019/12/13

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_understanding_nil

#### 6.4. Understanding nil

nil は不思議な特性を持っています
後述の通り、nil は定数です。しかし nil で定数を定義することはできません。

nil で変数を定義することはできます。しかし、nil 同士を比較することはできません

```
package main

import "fmt"

const T = nil != nil // (1)

func main() {
	fmt.Println(nil == nil) // (2)

	if nil == new(int) {
		fmt.Println("hmm") // (3)
	}
}
```

(1) nil は nil と !=で比較できない（訳注： `!= nil` を消しても const T を初期化することはできません）
(2) nil は nil と ==で比較できない
(3) nil は比較演算子のどちら側にもかける
https://play.golang.org/p/Knh1br_HZ9m

これらを見ると、nil は通常の Go とは別の世界の存在のようですが、この特性のおかげで Go をシンプルなものにしています。

- pointer を nil にすると、pointer は何者も参照しない
- interface を nil にすると、interface は何も含まない
- slice を nil にすると、slice は長さゼロ、容量ゼロ、何の配列も参照しない

nil の型は割り当てられた変数の型によって決まります。

```
var s []string
if s == nil {
  // ...
}
```

このように書いたとき、nil の型は（s が[]string だと自明なので） []string として比較評価されます。

NOTE
以下のような場合は注意が必要です

```
func Open(path string) io.Writer {
	var f *os.File
	f, _ = os.Open(path)
	return f
}

func main() {
	f := Open("/missing")
	fmt.Println(f == nil) // false
}
```

上で、f == nil は false になります。
なぜなら、 `return f` で返される f は `*os.File` 型で定義されているからです。

関数（メソッド）で nil を返したい場合は明示的に `return nil` としましょう

（訳注：go の nil の特性を調べるといくつか出てきますので興味深いリンクを載せます）
https://www.calhoun.io/when-nil-isnt-equal-to-nil/
https://golang.org/doc/faq#nil_error

（訳注：個人的には interface 型に別の型付きで nil となった変数を代入すると、型アサーションが必要だというのがハマりそうだと思いました）
https://play.golang.org/p/qZLojLsmsgB

```
var a *int = nil
var b interface{} = a

fmt.Println("a == nil:", a == nil) // true
fmt.Println("b == nil:", b == nil) // false
fmt.Println("b.(*int) == nil:", b.(*int) == nil) // true
```

2019/12/13

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_error_handling

2019/12/16

# 一言

Dave Cheney の Go のプレゼンは前回までで６章で切りが良いので、一旦休憩。

Kubernetes 関係の資料をシェアします。

Kubernetes 完全ガイドの作者の発表資料
https://speakerdeck.com/masayaaoyama/jtf2019-k8s-amsy810?slide=45
「Kubernetes による Cloud Native な開発」と「VM 時代の開発」
ステートフルな構成はまだまだ Kubernetes 難しいよねという意見でした。

コロプラの Kubernetes の導入事例の資料
https://speakerdeck.com/govargo/production-ready-kubernetes-15-rules?slide=60

2019/12/17

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_error_handling

６章まで個人的に初めて見る話が多かったのでやや逐語訳気味にしていましたが、
７章はみなさんも知っていることが多いと思うので、意訳の度合いを少し強めます。

#### 7. Error handling

エラーハンドリングは超重要です。
あなたのコードの他の部分と同様に重要です。境界値のテストなどと同じくらい重要です。

#### 7.1. Errors are just values

`Errors are just values.` エラーは値

この言葉はとっても有名ですが、正しく理解できているでしょうか？

一旦 panic と recover を見てみましょう。この２つの keyword の目的は _たった１つです_
defer の中で使う。これだけ。他の目的では使ってはいけません

（訳注：以下のようなケースだと思います）
https://blog.golang.org/defer-panic-and-recover

```
defer func() {
    if r := recover(); r != nil {
        fmt.Println("Recovered in f", r)
    }
}()
```

#### 7.2. Errors should be opaque

エラーは関数の呼び出し側にとって「不明瞭（opaque）」なものであるべきです。
API の呼び出し元は、（nil かどうかという判定は除きますが、）
そのエラーの内容を見て処理を変えるようなことをしてはいけません。
関数と呼び出し元の間に依存関係が生まれてしまうからです。

例外は io.EOF です。これは上のルールが適用されません。

（訳注: dave cheney は io.EOF の判定を好ましいものと分類していないようです）

2019/12/18

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_error_handling

#### 7.3. Assert errors for behaviour, not type

詳細は以下がわかりやすいです。
Dave Cheney 本人のブログ

- https://dave.cheney.net/2016/04/27/dont-just-check-errors-handle-them-gracefully
  日本語の紹介
- https://deeeet.com/writing/2016/04/25/go-pkg-errors/

要点は、 `エラーを受け取った時の分岐は、そのエラーが実装しているinterfaceで判断しましょう` ということです。

（訳注：Dave Cheney の記事を参考に作ってみたサンプル ↓）
https://play.golang.org/p/U_pIN9-RSBF

2019/12/19

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_error_handling

（訳注：前回の補足）
「7.3. Assert errors for behaviour, not type」
でエラーの型ではなくて実装している interface で判断するとした件ですが、
最新の Go 1.13 には errors に As が追加されているのでこれが使えます。
紹介記事
https://blog.golang.org/go1.13-errors
https://text.baldanders.info/golang/error-handling-in-go-1_3/
https://qiita.com/shibukawa/items/e633e426a6e67ea2e830

でも Go の中でも、Unwrap より Dave Cheney 作の Cause 使ったほうがいいんじゃないみたいな議論も見つけました。
https://github.com/golang/go/issues/31778
意見が完全に固まってくれるのでしょうか

2019/12/20

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_error_handling

### 7.4. Never use nil to indicate failure

```
type Bar struct{}

func (b *Bar) Whoa() {
	fmt.Println("whaaaaaat?")
}

func main() {
	var b *Bar // (1)
	b.Whoa()   // (2)
}
```

この、何の値も初期化していない b の method Whoa は異常なく動作します。
その理由は、Go における method というのは、関数の第一引数をレシーバとした、
シンタックスシュガーだからです（！）
つまり上の method は下の関数と同じ

```
func Whoa(b *Bar) {
	fmt.Println("whaaaaaat?")
}
```

以下のように、b または b のフィールドにアクセスしようとすると panic を起こします

```
func (b *Bar) Whoops() {
	fmt.Println(b.message) // (1)
}
```

これを防ぐためには様々な方法が取りえます。
メソッドの作成者としてできることはこれです

```
func (b *Bar) Whoops() {
	if b != nil { // (1)
		fmt.Println(b.message)
	}
}
```

でもこれだとメソッドの中でしか判定できません。
（メソッドを呼んだときには手遅れかも）

メソッドを呼ぶ前に判断するとしたらこんな方法が考えられます。

```
func main() {
	var b *Bar
	if b != nil {
		b.Whoops() // (1)
	}
}
```

ただこの方法だと、メソッドを呼ぶすべての部分にこの判定を入れなければいけません。

（訳注：ということで、このあといくつか考えられる方法を書いていますが、長いので以下の結論だけ書きます）

nil レシーバの存在を完全に防ぐことはできません。あなたのコードのどこにでも存在しえます。
最も発生しやすいのは、メソッドを呼び出す前に別の関数を呼び出したときに error チェックを忘れて結果の nil を渡してしまう場合です。
あなたがコードを書くときに注意する部分はこのエラーチェックの部分です。

これに絡んで気をつけなければいけないこととしては、
API（関数）を作るときは、（error を除いて)nil を返す関数を作ってはいけません！
Go 以外で、複数値を返せない言語では、失敗を表す場合に nil（または null）を返すことがありますが、
そういったことはしないようにしましょう。

TIP: nil レシーバのチェックはやめましょう。
test カバレッジを上げましょう。vet/lint ツールを使って nil レシーバになるような条件を見つけましょう。

go vet の説明
http://tsujitaku50.hatenablog.com/entry/2017/01/07/121825
https://qiita.com/marnie_ms4/items/b343165efb4235906db7

以下端折ったところ

以下のように、nil の場合は error を返す方法が良いです。

```
func (b *Bar) GetMessage() (string, error) {
	if b == nil {
		return "", errors.New("b is nil") // (1)
	}
	return message, nil
}
```

関数の呼び出し元にとってわかりやすい内容のエラーを返さなければいけません

１．すべてのメソッドはエラーを返すべきです 「すべてのメソッドです」
２．関数呼び出し元はすべて必ずエラーチェックをするべきです
３．interface を定義するときは、nil レシーバを受け取ったときのエラーを返せるようにしましょう
４．実装するすべての inteface はエラー戻り値を持たなければいけません
（訳注：3,4 が良くわかりませんでしたが、私が先日投稿したような例かなと思いました）
https://play.golang.org/p/U_pIN9-RSBF

2019/12/23

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_dont_panic

#### 7.5. Don’t panic

panic をしないようにしましょう。go には確かに panic 関数が存在します。
しかしこれは runtime の `throw` 関数の副産物です
（訳注： thow 関数ってこれですかね）
https://github.com/golang/go/blob/ba66797392da2b6538ce014a4f7e13c490e74d59/src/runtime/panic.go#L1102

recover を使った例は確かにありますが、用法は限られています。例外キャッチのためのものではありません。
（ローカルで行った変更を戻すためなど）

プログラムはいろいろな場面で panic を吐きます。
(メモリ不足だったり、プロセスマネージャーに kill されたり)
プログラムを書くときは失敗を予期したものにしましょう。
panic は避けましょう。recover も避けましょう。
これらはあなたが求めているツールではありません！

#### 7.5.1. Avoid selfish panics

panic はプログラムを継続できない時の最後の手段です。
ライブラリの中で panic するのは最後の最後の手段です。
使う人にとっては、危険この上ないものになります。

panic が呼ばれると defer が実行されますが、それはその goroutine の中だけです。
他の goroutine の defer 文は実行されません。
ライブラリ中で panic を起こすと、全プログラムを停止させます。絶対にやめましょう。

TIP: ライブラリ中で panic させるのは絶対にやめましょう！

#### 7.5.2. Avoid log.Fatal

log.Fatal と log.Panic も panic と同様の影響を与えます。
使うのを避けましょう。
log.Fatal の一行で Log を出せて crash もできるという利便性が、誤用を招くもとになってしまいました。
（訳注：log.Fatal は os.Exit(1) で強制終了されて
defer も効かないので panic より扱いに注意が必要だと私は思っています）

2019/12/24

# 一言

https://isidore.co/calibre/get/pdf/6127/CalibreLibrary
プログラミング言語 Go の英語は PDF でただで見られます

2019/12/24

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_eliminate_error_handling_by_eliminating_errors

7.6. Eliminate error handling by eliminating errors

エラー自体をなくし、エラーハンドリングの数を減らしましょう
（エラーを無視するという意味ではありません）

#### 7.6.1. Counting lines

ファイルの行数をカウントする例を見てみます。

```
func CountLines(r io.Reader) (int, error) {
	var (
		br    = bufio.NewReader(r)
		lines int
		err   error
	)

	for {
		_, err = br.ReadString('\n')
		lines++
		if err != nil {
			break
		}
	}

	if err != io.EOF {
		return 0, err
	}
	return lines, nil
}
```

以前の話の通り、r には `*os.File` を渡すのではなく `io.Reader` のみを絞って渡していることに注意です。

（訳注：NewReader）
https://golang.org/pkg/bufio/#NewReader

（訳注：この章長いので以下意訳します）

NewReader を使う方法には問題があります。
ファイルの最後に達すると `io.EOF` をエラーとして返すので、それを判定する必要があるのです。

これは、以下のように `NewReader` の代わりに、 `NewScanner` を使うことによって避けることができます。

```
func CountLines(r io.Reader) (int, error) {
	sc := bufio.NewScanner(r)
	lines := 0

	for sc.Scan() {
		lines++
	}
	return lines, sc.Err()
}
```

（訳注：NewScanner）
https://golang.org/pkg/bufio/#NewScanner

実は bufio.Scanner は中で bufio.Reader を使っているのですが、
`sc.Err()` はエラーが無く読み込みが終わったら、 `io.EOF` を nil に変換するという働きをしてくれます。

TIP: もしエラーハンドリングだらけになってしまったら、一部の処理を抜き出して helper type にすることを考えてみましょう
（訳注：ここで言う helper type とは、上の例のように余計なエラーを変換するとかそういう意味ですね）

2019/12/26

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_eliminate_error_handling_by_eliminating_errors

#### 7.6.2. WriteResponse

２つ目の例はエラーは値、という以下のブログにインスパイアされたものです。
https://blog.golang.org/errors-are-values

```
type Header struct {
	Key, Value string
}

type Status struct {
	Code   int
	Reason string
}

func WriteResponse(w io.Writer, st Status, headers []Header, body io.Reader) error {
	_, err := fmt.Fprintf(w, "HTTP/1.1 %d %s\r\n", st.Code, st.Reason)
	if err != nil {
		return err
	}

	for _, h := range headers {
		_, err := fmt.Fprintf(w, "%s: %s\r\n", h.Key, h.Value)
		if err != nil {
			return err
		}
	}

	if _, err := fmt.Fprint(w, "\r\n"); err != nil {
		return err
	}

	_, err = io.Copy(w, body)
	return err
}
```

このような、HTTP レスポンスを返すサーバを考えてみましょう。

エラーハンドリングがいっぱいあって読みにくいものになっています。
ここで、io.Writer interface を満たすメソッドを持つ、 `errWriter` という構造体を定義してみましょう

（訳注：Write メソッドさえあれば interface を満たします）
https://golang.org/pkg/io/#Writer

```
type errWriter struct {
	io.Writer
	err error
}

func (e *errWriter) Write(buf []byte) (int, error) {
	if e.err != nil {
		return 0, e.err
	}
	var n int
	n, e.err = e.Writer.Write(buf)
	return n, nil
}
```

この構造体を使うことで、最初のエラーハンドリングは以下のように書き直すことができます。

```
func WriteResponse(w io.Writer, st Status, headers []Header, body io.Reader) error {
	ew := &errWriter{Writer: w}
	fmt.Fprintf(ew, "HTTP/1.1 %d %s\r\n", st.Code, st.Reason)

	for _, h := range headers {
		fmt.Fprintf(ew, "%s: %s\r\n", h.Key, h.Value)
	}

	fmt.Fprint(ew, "\r\n")
	io.Copy(ew, body)
	return ew.err
}
```

（訳注：私が色々書くよりも、以下の資料を見たほうがわかりやすいです）
http://jxck.hatenablog.com/category/go
https://blog.golang.org/errors-are-values

（訳注：Write メソッドはエラーがすでに有る場合はそれをそのまま返し、ない場合は実行して e.err にエラーを保存する関数となっています）
（訳注：でも個人的にはこの手法はパッと見ではわかりにくい気がしましたが好みの問題もありそうです）

2019/12/27

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_only_handle_an_error_once

#### 7.7. Only handle an error once

最後に言及したいこととしてはこれです。
エラーハンドリングは１度だけにしましょう。

エラーハンドリングというのは、エラーの中身を評価することを指します。
そしてエラーを見てすることは 「たった一つ」にしましょう

「一つ未満のエラーハンドリング」、というのはつまりエラーを無視することです
以下のような場合は Write の結果のエラーは捨てられます

```
// WriteAll writes the contents of buf to the supplied writer.
func WriteAll(w io.Writer, buf []byte) {
        w.Write(buf)
}
```

一方で、「一つより多く」エラーハンドリングするというのも、それはそれで問題です。
以下のような書き方をよく見ます。

```
func WriteAll(w io.Writer, buf []byte) error {
	_, err := w.Write(buf)
	if err != nil {
		log.Println("unable to write:", err) // annotated error goes to log file
		return err                           // unannotated error returned to caller
	}
	return nil
}
```

この書き方をすると、log にエラーが出力されます。
また、関数の呼び出し元にもエラーが返されることになります。

もし関数の呼び出し元で以下のようなエラーハンドリングをすると、

```
func WriteConfig(w io.Writer, conf *Config) error {
	buf, err := json.Marshal(conf)
	if err != nil {
		log.Printf("could not marshal config: %v", err)
		return err
	}
	if err := WriteAll(w, buf); err != nil {
		log.Println("could not write config: %v", err)
		return err
	}
	return nil
}
```

Log には以下のように出力されます。冗長ですね。

```
unable to write: io.EOF
could not write config: io.EOF
```

一方で、WriteConfig 関数の呼び出し元はどうでしょうか？
以下のようにエラーを見ても `io.EOF` が出力されるだけです。
（どの関数で失敗したか、という情報はここにはありません）

```
err := WriteConfig(f, &conf)
fmt.Println(err) // io.EOF
```

さらなる問題は、エラーを log に出すと、以下のように err を return するのを忘れてしまうことがあり得ることです。

```
if err != nil {
		log.Printf("could not marshal config: %v", err)
		// oops, forgot to return
	}
```

この場合、エラーを評価し、Log にも出したのに、エラーは返していないので、深刻なバグに繋がります。

（訳注：ちょっと長いので、以下まとめます）

- ガード構文にしたがって、エラーがあったらその場でエラーを返す
- エラーにはちゃんと `could not marshal config: ` のような説明を付与する
- エラーハンドリングは１度だけにする
- 関数の途中で Log に書くのは、エラーを戻すのを忘れたり、エラーの説明を忘れたり、Log が冗長になる原因になる

2020/1/8

# 一言

GitHub Actions ことはじめ
https://tech.guitarrapc.com/entry/2020/01/06/071911
いままで見た中でかなりまとまっている資料だと思いました。

2020/1/8

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_testing

（訳注：この章は知っている内容が多いと思うので飛ばし飛ばしで行きます）

### 8. Testing

よく test と coding にはそれぞれどのくらい時間配分をしていますかと質問されますが、
私はこれを２つの理由で興味深い質問だと感じます。

１つ目は、質問者が test と coding を別々に考えている点です。
質問されている方は、ひょっとしたら手順書に従ったテストをしているのかもしれません。
私はテストを自動化することに取り組んでいるので、私にとっての test は coding の延長です。

２つ目は、私が普段どれだけテストについて考えているかを気づかせてくれる点です。
私は普段、どうやったらコードがテストしやすくなるか考えています。
自動でテストできないようなデザインになっていないかも考えています。

ということで、最初の質問の答えとしては、「私はテストのためのデザインについて多大な時間を費やしています」です

テストを QA チームに任せる時代は 90 年代で終わりました。
開発チームがプロダクトの品質を担保すべき時代になったのです。

そして、テストは必ず自動化するべきです。
なぜなら、手順書に従ったテストは実行時間がテストの量にそって線形（O(n)）に増えていくからです。
そして、99.9%のテストは以前と同じように動作します。
となるとどうなるか、人間はテストを省略するようになります。
マニュアルテストは時間がかかるし退屈だからです。そうやって、重要だと思われるテストだけするようになって ���� まいます。

まとめ、
あなたがバグ fix や改善に取り組むとき、最初にすべきことは「失敗する場合のテスト(failing test)」を最初に作ることです。
（訳注：バグ fix や改善が機能していないと失敗してしまうテスト、という意味だと思われます）
これは単体テストである必要はありませんが、自動テストにするべきです。
最初に failing test を作ってしまって、あとは実際のバグ fix や機能改善をしてうまくいくか確認しましょう

2020/1/10

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_testing

#### 8.1. Tests lock in behaviour

あるパッケージに関する unit test は、package 内に閉じた範囲を扱うようにしましょう。
コードの挙動はドキュメントよりもコードに書くべき（訳注：test 含む）です。
`go test` だけで動作が保証できるからです。
これにより、コードの変更後にもちゃんと動くという信頼性が高まります。

#### 8.2. Table driven testing

#### 8.2.1. Test scope

（訳注：この辺は皆さんご存知だと思いますのでさらっと）
Table driven testing はこういうものです。

```
func TestSplit(t *testing.T) {
	type test struct {
		input string
		sep   string
		want  []string
	}

	tests := []test{
		{input: "a/b/c", sep: "/", want: []string{"a", "b", "c"}},
		{input: "a/b/c", sep: ",", want: []string{"a/b/c"}},
		{input: "abc", sep: "/", want: []string{"abc"}},
	}

	for _, tc := range tests {
		got := Split(tc.input, tc.sep)
		if !reflect.DeepEqual(tc.want, got) {
			t.Fatalf("expected: %v, got: %v", tc.want, got)
		}
	}
}
```

上では test という struct を用意していますが以下のように構造体を最初に宣言しないようにも書けます

```
tests := []struct {
  input string
  sep   string
  want  []string
}{
```

2020/1/14

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_name_your_tests

#### 8.2.2. Code coverage

（訳注：前回触れ忘れたので coverage について記載します）

package の branch coverage）は以下で確認できます

```
% go test -coverprofile=c.out
PASS
coverage: 100.0% of statements
ok      split   0.010s
```

この場合は、coverage が 100%であることがわかります。

以下のように-func=c.out で、関数ごとの coverage をわかりやすく見ることもできます

```
% go tool cover -func=c.out
split/split.go:8:       Split          100.0%
total:                  (statements)   100.0%
```

（訳注：go test の coverage などについては以下のリンクがものすごくわかりやすいです。
test 以外の様々な tool の使い方と結果が解説されています。おすすめです）

An Overview of Go's Tooling
https://www.alexedwards.net/blog/an-overview-of-go-tooling

2020/1/15

# 一言

いろいろなアルゴリズムを golang、python 実装している人の github リポジトリ
https://github.com/yukirin/algo
興味がある方には面白そうです

2020/1/16

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_name_your_tests

（訳注：みんな知っていることが多いのでさらっと書き出します）

#### 8.2.3. Enumerating test cases

テストに番号をつける
https://play.golang.org/p/6_UltZnA1sm

実行結果

```
=== RUN   TestSplit
--- FAIL: TestSplit (0.00s)
    prog.go:37: test 4: expected: [a b c], got: [a b c ]
FAIL
```

#### 8.2.4. Name your tests

テストに名前をつける
https://play.golang.org/p/P3KPXFYx8RM

実行結果

```
=== RUN   TestSplit
--- FAIL: TestSplit (0.00s)
    prog.go:38: trailing sep: expected: [a b c], got: [a b c ]
FAIL
```

上の改良。test ケースを map にすることで実行順序をランダムにする

- ランダムにすることで、test 間の依存によるバグを発見しやすい
  - 前のテストで全体に関わる状態の変化を行っていたとしても、それに気づかせてくれる、など
    https://play.golang.org/p/0kUaYDWYgPI

#### 8.2.5. Sub tests

サブテスト
https://play.golang.org/p/i3OHgI4ho2J

- サブテストには名前がついているので、以下のように個別にテストを実行することが可能です

```
% go test -run=.*/trailing -v
=== RUN   TestSplit
=== RUN   TestSplit/trailing_sep
--- FAIL: TestSplit (0.00s)
    --- FAIL: TestSplit/trailing_sep (0.00s)
        split_test.go:25: expected: [a b c], got: [a b c ]
FAIL
exit status 1
```

2020/1/20

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_comparing_expected_an_actual

#### 8.2.6. Comparing expected an actual

前述までのテストコードでは、エラー時のメッセージは以下のようなものでした

```
--- FAIL: TestSplit (0.00s)
    --- FAIL: TestSplit/trailing_sep (0.00s)
        split_test.go:25: expected: [a b c], got: [a b c ]
```

この問題箇所は `%#v` を使うとわかりやすくなります。

```
t.Fatalf("expected: %#v, got: %#v", tc.want, got)
```

結果はこのように、空があることがわかります。

```
% go test
--- FAIL: TestSplit (0.00s)
    --- FAIL: TestSplit/trailing_sep (0.00s)
        split_test.go:25: expected: []string{"a", "b", "c"}, got: []string{"a", "b", "c", ""}
FAIL
exit status 1
FAIL    split   0.005s
```

ただ、 `%#v` でもわかりにくい時もあります。

```
func main() {
	type T struct {
		I int
	}
	x := []*T{{1}, {2}, {3}}
	y := []*T{{1}, {2}, {4}}

	fmt.Printf("%v %v\n", x, y) // (1)
	fmt.Printf("%#v %#v\n", x, y) // (2)
}
```

結果

1. [0xc000096000 0xc000096008 0xc000096010] [0xc000096018 0xc000096020 0xc000096028]
2. []*main.T{(*main.T)(0xc000096000), (*main.T)(0xc000096008), (*main.T)(0xc000096010)} []*main.T{(*main.T)(0xc000096018), (*main.T)(0xc000096020), (*main.T)(0xc000096028)}

こういう場合は、https://github.com/google/go-cmp というパッケージの利用を提案します。
例えば以下のようにすると、cmp.Equal は false を返します。

```
x := []*T{{1}, {2}, {3}}
y := []*T{{1}, {2}, {4}}
fmt.Println(cmp.Equal(x, y)) // false
```

cmp.Diff は以下のように見やすくなります。

```
diff := cmp.Diff(x, y)
fmt.Printf(diff) // (1)
```

```
% go run .
{[]*main.T}[2].I:
        -: 3
        +: 4
```

前述の Split 関数のテストを cmp パッケージで一部書き換えると以下のようになります。
https://play.golang.org/p/fMeoZTmFDWv

2020/1/21

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_prefer_internal_tests_to_external_tests

#### 8.3. Prefer internal tests to external tests

go で test をする際には二種類の方法があります。
あなたが http2 というパッケージを作成したとして、http2_test.go というテストファイルを作ったとします。
このとき、テストファイルのパッケージ名を `http2` とすることで、
`http2_test.go` は http2 パッケージの一部だとコンパイル時にみなされます。
いわゆる internal test です。
（訳注：これにより http2 内の小文字始まりの非公開の関数のテストができます）

go はテスト用に `test` で終わるパッケージ名を使うこともできます。
例えば、 `package http_test` のような  パッケージ名です。
この名前のパッケージ名のテストファイルを、コードと同一パッケージ内に置くと、
コンパイル時には、コードとテストは別のパッケージだとみなされます。
いわゆる external test です

単体テストを書くときは、internal test として書くことをおすすめします。
external test の bureaucracy （訳注：面倒な事前準備を意味していると解釈しました）をすることなく、
コード内の各関数、メソッドを直接テストすることができるからです。

ただし、 `Example` test 関数は external test ファイルに書きましょう。
こうすることで、godoc で見たときに、examples が適切なパッケージの prefix を持ち、コピペも容易になります。
（訳注：以下が詳しいです）
https://blog.golang.org/examples

TIP: ドット import を避けて、internal test を使いましょう

（訳注：ドット import や test のパッケージ名については以下が参考になります）
https://stackoverflow.com/questions/19998250/proper-package-naming-for-testing-with-the-go-language

2020/1/22

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_tests_give_you_the_power_to_release_any_day_of_the_week

#### 8.4. Tests give you the power to release any day of the week

テストをすることはソフトウェア開発中に役立つだけでなく、いつでも master ブランチにマージできるという保証を与えてくれます。
これはつまり、いつでもリリースできるということです。
「我々は重要なリファクタリングの最中だからいまリリースはよそう、数週間後ならできるさきっと」
などと言うような事態は避けるべきです。
テストが通れば、あなたの開発物がどんなときでも期待通りに動くという保証が与えられるのです！
（訳注：凄まじい自信・・・）

#### 8.5. Tests give you confidence to change someone else’s code

テストのカバレッジを十分にすることで、おそらく最も良い点は、
自分が書いたものではないコードの修正を自信をもって修正できることです。

これはチーム開発において重要なことです。

2020/1/23

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_concurrency

### 9. Concurrency

多くの本で concurrency 並行処理が最後の章で取り上げられているように、このプレゼンでも concurrency は最後に扱います。
Go はその並行処理の容易さゆえに多くのプロジェクトで採用されていることが多いのですが、
並行処理を扱うのは簡単ではありません。そのため最後に取り上げています。

#### 9.1. Channel Axioms

#### 9.1.1. A send to a nil channel blocks forever

この章では、channel のどちらかといえばあまり知られていない特徴について取り上げます。

`nil` channel へ送信しようとすると永久にブロックされます。

```
func main() {
	var c chan string
	c <- "let's get started" // (1)
}
```

上のコードは(1)の部分で deadlock します。
未初期化の channel は `nil` なので、送信できません。

#### 9.1.2. A receive from a nil channel blocks forever

同様に、nil channel を受信しようとすると deadlock します。

```
func main() {
	var c chan string
	fmt.Println(<-c) // (1)
}
```

この説明は以下の通りです。

- チャネルの型宣言をしただけでは、バッファーのサイズは設定されません。
  チャネルのサイズは、チャネルの値の一部だからです
- チャネルが初期化されていない場合、そのバッファサイズはゼロになります
- チャネルのバッファのサイズがゼロの場合、バッファなしチャネルとなります
- バッファなしチャネルの場合、別のゴルーチンが受信可能になるまで送信はブロックされます
- チャネルが nil の場合、送信側と受信側は互いに関与し合いません。
  そのため、互いに独立したチャネルを待ってブロックし合い、そのブロックが解除されることはありません

2020/1/24

# 一言

いまさら聞けない select あれこれ
https://www.slideshare.net/lestrrat/select-66633666
みんなの Go 言語共著者の一人の牧大輔さんの資料。
わかりやすいのでためになります。

2020/1/27

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_a_send_to_a_closed_channel_panics

#### 9.1.3. A send to a closed channel panics

（訳注：この章の説明どう考えてもおかしい気がするので、真剣に見ないほうが良いかも知れません）

以下のプログラムは最初の goroutine が close した時点で、他の goroutine が close 済みの channel に
値を送れなくて panic になります。

```
func main() {
        var c = make(chan int, 100)
        for i := 0; i < 10; i++ {
                go func() {
                        for j := 0; j < 10; j++ {
                                c <- j
                        }
                        close(c)
                }()
        }
        for i := range c {
                fmt.Println(i)
        }
}
```

（訳注：このプログラムは playground で実行すると panic を起こさず終了します
goroutine 内に i が渡っていないので、実際 goroutine として処理されるのは最後の i だけというバグもあります。
これは dave cheney が説明のために書いた例と考えるべきです。
ちなみにこのバグは go vet で確認できます）

```
$go vet sample.go
# command-line-arguments
./sample.go:13:32: loop variable i captured by func literal
```

では、close 済みかどうかを確認するための関数を用意するという案はどうでしょうか？
例えばこんな感じのものです。

```
if !isClosed(c) {
        // c isn't closed, send the value
        c <- v
}
```

この関数でチェックして OK だったとしても、c<-v を処理する前に他の goroutine が c を close してしまう可能性があります。
それぞれの goroutine は全く同じタイミングで動いているかも知れませんし、バラバラかも知れないのです。
goroutine 同士は、（チャネルなどで）コミュニケーションしないといけません。

（訳注：ということで、この後解決策として以下のコードが出てくるのですが、実はこれでもだめです。
結局 closed の判定がスレッドセーフではないように見えます。
ちょっと変えるだけでうまくいくかなと思ったのですが、だめでした。
waitGroup を使うのがいいと思います）
https://play.golang.org/p/TfakbrJSMnk

2020/1/31

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_a_receive_from_a_closed_channel_returns_the_zero_value_immediately

#### 9.1.4. A receive from a closed channel returns the zero value immediately

close された channel は zero を返します。

```
func main() {
	c := make(chan int, 3)
	c <- 1
	c <- 2
	c <- 3
	close(c)
	for i := 0; i < 4; i++ {
		fmt.Printf("%d ", <-c) // prints 1 2 3 0
	}
}
```

このプログラムは c に 3 を送ったあとに close されているので、print した結果は 3 以降は 0 となります。
https://play.golang.org/p/aJb4DV8ZMCb

NOTE:
channel が close されるまでその値を取り続けたい（consume したい）ときは `for range` 文を使うのが良い方法です。

```
for v := range c {
	// do something with v
}
```

これは下のプログラムのシンタックスシュガーとなっており動作は同じです。
for range 文は以下のプログラムを簡略化したものなのです。

```
for v, ok := <- c; ok ; v, ok = <- c {
        // do something with v
}
```

2020/2/3

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_prefer_channels_with_a_size_of_zero_or_one

#### 9.2. Prefer channels with a size of zero or one

未知の producer や consumer を扱うとき、バッファサイズとしてはゼロまたは 1 が選ばれます。
バッファサイズ 0 は producer と consumer が同時に動く場合、
バッファサイズ 1 は送信側がブロックされること無く１つは値として channel にためておける状態です。

channel の値が受信されるまでにどれだけ溜めておきたいかの正確な数を知っているときは、
バッファサイズを１より上げることが有効です。
最も好ましい channel サイズは大抵 0 か 1 です。それ以外は見積り次第です。
見積もりが間違っていた場合、プログラムは正しく動かない可能性があります。

2020/2/4

# 一言

What's new since Go 1.12
https://speakerdeck.com/campoy/the-state-of-go-2020

1.14 で defer や json 処理などが速くなるらしいです。

2020/2/5

# 一言

sleep と ticker どう違うの？
https://stackoverflow.com/questions/53315716/which-one-of-the-two-is-idiomatic-way-time-sleep-or-ticker/53315789

- sleep：

  - 10 秒かかる処理＋ sleep60 秒の場合、最初の実行後に次の実行がされるのは 70 秒後
  - 10 秒の処理が 11 秒になったら 71 秒後になるし、タイミングは確定しない

- ticker:
  - 10 秒かかる処理＋ 60 秒ごとの ticker の場合、最初の実行後に次の実行がされるのは 60 秒後
  - 10 秒の処理が 11 秒になっても 60 秒後、常に実行タイミングは同じ

当然といえば当然の話しです。
ticker の方がわかりやすいというメリットなども書いてあって個人的に、そうだねたしかにねと思いました

2020/2/6

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_keep_yourself_busy_or_do_the_work_yourself

#### 9.3. Keep yourself busy or do the work yourself

このプログラムの問題点はなんでしょうか？

```
func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintln(w, "Hello, GopherCon SG")
	})
	go func() {
		if err := http.ListenAndServe(":8080", nil); err != nil {
			log.Fatal(err)
		}
	}()

	for {
	}
}
```

（訳注：皆さんおわかりだと思いますが、goroutine 内で ListenAndServe を使って web サーバを起動させ、
無限 for ループによって main の goroutine を終了させないようにすることでサーバを止めないようにしています）

この方法では、無限ループによって CPU を無駄にします。
最後の`for{}`　が main goroutine をブロックすることで、何の IO も生まれません。
シングル CPU を使った状態でライブロックされています。

最後の `for{}` を以下のようにしてみるとどうでしょうか？

```
for {
  runtime.Gosched()
}
```

これも良くない方法に見えますが、私はよく目にします。
プログラムの裏側についての理解が足りていません。

少し go の経験がある人はこんな書き方をするかもしれません。
`for{}` を `select {}` にしてみます。
コード全文
https://play.golang.org/p/VBoym70Oerp

空の select 文は永久にブロックします。
これなら CPU をフルに使って `runtime.GoSched()` だけをさせ続ける必要はありません。

しかしもっといい方法があります。
`http.ListenAndServe` を別の goroutine ではなく main goroutine の中で実行すればいいのです。

TIP: main.main 関数は、別の goroutine が起動している最中であっても無条件に終了します。

改修後のコード

```
package main

import (
	"fmt"
	"log"
	"net/http"
)

func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintln(w, "Hello, GopherCon SG")
	})
	if err := http.ListenAndServe(":8080", nil); err != nil {
		log.Fatal(err)
	}
}
```

ということで、私からの助言は以下の通りです。
あなたの goroutine が外部の何らかの処理の結果を受け取らない限り何も進まないのであれば、その「何らかの処理」は
別の goroutine に任せるのではなく自分自身が請け負ったほうがシンプルです。

これによって、（外部の goroutine の）状態を追ったり channel 操作をしたりして、
結果を（goroutine の）呼び出し元に伝えるようなことをしなくてすみます。

TIP: 多くの Go プログラマーは gorouine を使いすぎています。
人生全てに言えることですが、節制、節度は成功への鍵です。

2020/2/7

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_leave_concurrency_to_the_caller

#### 9.4. Leave concurrency to the caller

この２つの違いは何でしょうか？

```
// ListDirectory returns the contents of dir.
func ListDirectory(dir string) ([]string, error)

// ListDirectory returns a channel over which
// directory entries will be published. When the list
// of entries is exhausted, the channel will be closed.
func ListDirectory(dir string) chan string
```

１つ目は、得られたディレクトリを slice として返します。何か問題があればエラーを返します。
これは同期処理なので、`ListDirectory` は全ディレクトリを読み込むまで呼び出し元をブロックします。
ディレクトリの大きさに依存して、ブロックされる時間も長くなりますし、メモリを大量に食う可能性もあります。

２つ目を見てみましょう。ちょっと Go っぽいです。
`ListDirectory` は読み込んだディレクトリを channel で返します。
関数の呼び出し元は、channel が close されたらもうディレクトリが無いことがわかります。
channel は `ListDirectory` の「呼び出し後」から中身を持ちます。
`ListDirectory` はおそらく goroutine で channel を扱っているのでしょう。

２つ目の channel を使った `ListDirectory` には２つ課題があります。

課題１．
channel の close という方法だけでは、
ListDirectory 内でエラーが生じて channel の中身が不十分だったときに、それを呼び出し元に伝える手段がありません。
呼び出し元はディレクトリが 空だったのか読み込み時にエラーがあったのか確認する方法がないのです。
どちらの場合であっても、 `ListDirectory` の channel はすぐに close されます。

課題２．
呼び出し元は、channel が close されるまで読み込み続けなければいけません。
なぜなら、close されるまで読み続けることしか、goroutine が終了したことを確認するすべがないからです。
これは `ListDirectory` を使う上で重大な制限です。
呼び出し元は、すでに欲しい結果が得られた後も channel の読み込みに時間を費やす必要があるからです。
大きなディレクトリを扱うときのメモリ使用は効率的になりそうですが、
この方法では１つ目の slice を使った方法に比べて速くなっていません。

この２つの課題の解決法は、コールバック関数を返すことです。

```
func ListDirectory(dir string, fn func(string))
```

驚くことではありませんが、 `filepath.WalkDir` 関数も同様の手法を取っています。
（訳注：この名前の関数は見つからなかったので、おそらく filepath.Walk のことだと思われます）
https://github.com/golang/go/blob/ab7c174183b05e36dabe0aa1943a0a4302b940d0/src/path/filepath/path.go#L395-L412

TIP: goroutine を使う関数は、呼び出し元からそれを止められるような方法を提供することが必要です。
非同期で関数を実行しやすくなります。

（訳注：なんとコールバック関数で具体的にどうやっているのかはここでは説明されていません）

2020/2/10

# 一言

Go1.13 の errors の Is, As の使用例
使用例がとてもわかりやすいです
https://peter.bourgon.org/blog/2019/09/11/programming-with-errors.html
https://play.golang.org/p/GorSR6HTWzf

2020/2/12

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_never_start_a_goroutine_without_knowing_when_it_will_stop

（訳注：以下訳しましたが、go の server の停止では gracefull shutdown が最近は使われていますので、
こんな考え方もあるんだなあと、色々工夫を考えることができれば良いのかなと思います。）

（訳注：gracefull shutdown)
https://stackoverflow.com/questions/57166480/golang-http-server-graceful-shutdown-after-a-signal
https://marcofranssen.nl/go-webserver-with-graceful-shutdown/

#### 9.5. Never start a goroutine without knowing when it will stop

もしかしたら今回のプレゼンの最後にふさわしい話をします。停止の話です。

前回の例では、本当は必要ではない goroutine を取り上げました。
しかし、Go を使う理由が、基本的な操作（first class）として並行処理を提供しているから、という方もいるでしょう。
ハードウェアを生かして並行処理をしたいときもあるでしょう。
必要なら goroutine を使うべきです。

２つ別々の port を提供するサーバを作るとします。
片方はアプリケーション用の 8080、もう片方は /debug/pprof 用の 8001 です。

```
package main

import (
	"fmt"
	"net/http"
	_ "net/http/pprof"
)

func main() {
	mux := http.NewServeMux()
	mux.HandleFunc("/", func(resp http.ResponseWriter, req *http.Request) {
		fmt.Fprintln(resp, "Hello, QCon!")
	})
	go http.ListenAndServe("127.0.0.1:8001", http.DefaultServeMux) // debug
	http.ListenAndServe("0.0.0.0:8080", mux)                       // app traffic
}
```

上のコードを `serveApp` と `serveDebug` に分けるとこうなります。

```
func serveApp() {
	mux := http.NewServeMux()
	mux.HandleFunc("/", func(resp http.ResponseWriter, req *http.Request) {
		fmt.Fprintln(resp, "Hello, QCon!")
	})
	http.ListenAndServe("0.0.0.0:8080", mux)
}

func serveDebug() {
	http.ListenAndServe("127.0.0.1:8001", http.DefaultServeMux)
}

func main() {
	go serveDebug()
	serveApp()
}
```

前述のアドバイスに従って、`serveApp` と `serveDebug` を並行処理にするかどうかは main（呼び出し元）に任せています。

しかしこれだと、 `serveApp` が終わると `main.main` も終わってしまうという問題があります。
一方、 `serveDebug` は別の goroutine なので、これが終わっても全体のプログラムは動き続けます。
「運用で debug を確認しようとしたけど、 `/debug` はずっと前に終了していました」、というのは避けたいことです。

以下のように改良してみます。

```
func serveApp() {
	mux := http.NewServeMux()
	mux.HandleFunc("/", func(resp http.ResponseWriter, req *http.Request) {
		fmt.Fprintln(resp, "Hello, QCon!")
	})
	if err := http.ListenAndServe("0.0.0.0:8080", mux); err != nil {
		log.Fatal(err)
	}
}

func serveDebug() {
	if err := http.ListenAndServe("127.0.0.1:8001", http.DefaultServeMux); err != nil {
		log.Fatal(err)
	}
}

func main() {
	go serveDebug()
	go serveApp()
	select {}
}
```

こうすれば、 `ListenAndServe` がエラーとなった時点で `log.Fatal` を出して main 関数が終わるので、
察知ができます。

main goroutine 内は `select{}` で永久に待たせます。

このアプローチには多くの問題があります。
１． `ListenAndServer` が `nil` エラーを返したとき、 `log.Fatal` は呼ばれず、サーバだけが落ちます。
２． `log.Fatal` は `os.Exit` を呼ぶので無条件にプログラムを停止させます。defer も呼ばれません。
別の goroutine は shut down に気づかず、プログラムが単に終了します。
これだとテストを書きにくいです。

TIP: `log.Fatal` は `main.main` か `init` 関数内でのみ使いましょう

（訳注：長いのでこれの解決策は明日書きます）

2020/2/13

# 一言

Dave Cheney のシンガポールでの Go のプレゼン（意訳） 続き
https://dave.cheney.net/practical-go/presentations/gophercon-singapore-2019.html#_never_start_a_goroutine_without_knowing_when_it_will_stop

goroutine で発生したエラーを呼び出し元に伝えて、「なぜ」 goroutine が停止したのかを確認し、
プロセスをきれいに停止させるためにはどうすればいいのでしょうか？

```
func serveApp() error {
	mux := http.NewServeMux()
	mux.HandleFunc("/", func(resp http.ResponseWriter, req *http.Request) {
		fmt.Fprintln(resp, "Hello, QCon!")
	})
	return http.ListenAndServe("0.0.0.0:8080", mux)
}

func serveDebug() error {
	return http.ListenAndServe("127.0.0.1:8001", http.DefaultServeMux)
}

func main() {
	done := make(chan error, 2)
	go func() {
		done <- serveDebug()
	}()
	go func() {
		done <- serveApp()
	}()

	for i := 0; i < cap(done); i++ {
		if err := <-done; err != nil {
			fmt.Println("error: %v", err)
		}
	}
}
```

上では、goroutine のステータスを収集することができています。
channel のサイズは `done` channel がブロックされないように、起動する goroutine と同じ数だけ用意しています。
これにより、goroutine の停止と leak を防ぐことができます。

`done` channel を安全に停止する方法が無いので、 `for range` は使えません。
その代わり、 channel の容量の数（= 起動する goroutine の数）だけ for 文を回しています。

これにより、全ての goroutine が停止するまで待って生じたエラーを log に書き出すこともできるようになりました。

このロジックをもう少し拡張して、 呼び出し元から `http.Server` の shut down をできるようにしてみましょう。
以下では、 `serve` 関数を用意して、中で `http.ListenAndServe` と同様に address と `http.Handler` を引数に持たせます。
また、 `stop` channel を受け取ったら `Shutdown` メソッドを呼べるようにします。

```
func serve(addr string, handler http.Handler, stop <-chan struct{}) error {
	s := http.Server{
		Addr:    addr,
		Handler: handler,
	}

	go func() {
		<-stop // wait for stop signal
		s.Shutdown(context.Background())
	}()

	return s.ListenAndServe()
}

func serveApp(stop <-chan struct{}) error {
	mux := http.NewServeMux()
	mux.HandleFunc("/", func(resp http.ResponseWriter, req *http.Request) {
		fmt.Fprintln(resp, "Hello, QCon!")
	})
	return serve("0.0.0.0:8080", mux, stop)
}

func serveDebug(stop <-chan struct{}) error {
	return serve("127.0.0.1:8001", http.DefaultServeMux, stop)
}

func main() {
	done := make(chan error, 2)
	stop := make(chan struct{})
	go func() {
		done <- serveDebug(stop)
	}()
	go func() {
		done <- serveApp(stop)
	}()

	var stopped bool
	for i := 0; i < cap(done); i++ {
		if err := <-done; err != nil {
			fmt.Println("error: %v", err)
		}
		if !stopped {
			stopped = true
			close(stop)
		}
	}
}
```

これにより、 `done` channel を受け取ったら `stop` channel を close して、
すべての goroutine が `http.Server` を shut down するまで待つようになりました。

全ての goroutine が停止したら、 `main.main` が return して、全てのプロセスがきれいに停止されます。

---

```
以上、長かった、Dave Cheneyのプレゼンの意訳が終わりました。
Slackの画面を埋め尽くす文を大量に投稿しまくってご迷惑おかけしたかも知れません。
正直「この書き方おかしいかも」とか「最新のはもっといいやり方が確立されている気が」
と思う部分もあったのですが、学ぶことが非常に多かったです。
原文をなんとなく読んでいたときは気づかなかったことも、
訳そうとして深く考えるとなるほど、と気付かされる点も多々ありました。
６月に育休から戻って業務でGoを初めて使うことになって、なんとなく書いてみて、
指針となる書き方が欲しいなーと思っていたので良い教材でした。
```

2020/2/20

# 一言

Building Web Server with Go - Part 1
https://www.gophersumit.com/series/web-1/?utm_source=share&utm_medium=ios_app&utm_name=iossmf

Go で web server を作る方法を紹介しています。
全 15 回あるらしいです。1~2 しかまだ読んでないですが。

# 一言

Go で database の driver を使うときに、`_ "github.com/go-sql-driver/mysql"`
のように blank import するのが一見意味不明なのですが、
説明が一番わかりやすかったのがこれでした。
https://www.calhoun.io/why-we-import-sql-drivers-with-the-blank-identifier/

2020/2/25

# 一言

Go1.14 の context は何が変わるのか
https://qiita.com/tutuz/items/963a6118cec63a4cd2f3

2020/2/26

# 一言

Dave Cheney の 2020 イスラエルのプレゼンを元にした資料
https://dave.cheney.net/2020/02/23/the-zen-of-go

Zen Of Go なので、心得的な話が多く、内容は以前シェアしたこととかぶるものが多いです。
要点は、

- シンプルイズベスト
- シンプル = 簡単、ではない
- ガード構文使ってネストを減らそう
- Goroutine は使いすぎない、使うときは停止方法を常に意識する

などです。

2020/2/27

# 一言

Go 1.14 Release Note
https://golang.org/doc/go1.14
↑ の日本語訳 ↓
https://qiita.com/c-yan/items/3dd0c63ea4c3041728cc

良さそうな点

- test の Cleanup
  - テストデータ、設定の削除が簡単になるらしい
    https://ieftimov.com/post/testing-in-go-clean-tests-using-t-cleanup/
- defer が速くなる（ただし８個までといううわさ）
  - https://qiita.com/yaegashi/items/bbb88cefcaf313532ba6

2020/3/3

# 一言

Go で Linux の Terminal, tty, pty, shell を理解する
https://dev.to/napicella/linux-terminals-tty-pty-and-shell-192e

2020/3/10

# 一言

Go の並行処理に使える便利なパッケージなど
https://encore.dev/blog/advanced-go-concurrency

- singleflight
  - 同時に重複したリクエストが来たときに、関数の呼び出しを一度に抑える
  - 使ったことないですが、サーバで便利そうですね。
- errgroup
  - 開発３内でも多く使っているやつ
  - 並行処理でのエラーの扱いを便利に
- 並列数の上限設定
  - パッケージではなくテクニック
  - これもチーム内でたまに見るやつ
  - 同時並行処理数を制限する

2020/3/12

# 一言

Go1.14 から追加されたテスト用のサポート関数、Cleanup
https://twitter.com/mitchellh/status/1237423194878832646?s=12
今まではテストデータなどの後片付け用の関数を defer で呼び出していたような部分がきれいになるという例

2020/3/13

# 一言

Go の String
https://commaok.xyz/post/intern-strings/
https://medium.com/kokster/mutable-strings-in-golang-298d422d01bc

- Go では string は immutable
- 同じ文字列に見えても pointer の指し示す先は異なる
- string interning:
  - 毎回文字列をコピーするのではなく同じ文字列を共有することで実行時間やメモリ消費量などを有利にすることができるか
    などのお話

2020/3/16

# 一言

Go の標準ライブラリのコードリーディングのすすめ
https://future-architect.github.io/articles/20200310/
io, errors, context, net/http など、勉強したいことがあります

2020/3/17

# 一言

Go 1.14 から、t.Log はテスト終了後ではなく逐次的に出力されるようになります
https://dave.cheney.net/2020/03/10/go-test-v-streaming-output

# 一言

Go の標準ライブラリのコードリーディングのすすめ
https://future-architect.github.io/articles/20200310/
io, errors, context, net/http など、勉強したいことがあります

2020/3/24

# 一言

1. 人気のプログラミング言語の調査で知られる TIOBE index で 2020 3 月で Go が 10 位になりました
   （昨年３月 18 位）
   https://www.tiobe.com/tiobe-index/

2020/3/25

# 一言

Go のサーハサイト実装におけるレイヤ設計とレイヤ内実装について考える
https://www.slideshare.net/pospome/go-80591000?from_m_app=ios

- DDD とかクリーンアーキテクチャとかを考えたい人向けの資料
- 書いた人は最近メルペイから DMM に転職したという pospome 氏
- 抽象的な内容が多め

2020/3/27

# 一言

コロプラの GKE 使用事例
https://www.slideshare.net/GoogleCloudPlatformJP/gke-cloud-spanner-9-google-cloud-inside-game-apps?from_m_app=ios

- kubernetes のマルチクラスタの話
- Victoria metrics によるモニタリング
  など業種は異なっていても似たような課題があるみたいですね

2020/3/30

# 一言

Google AI の ML コミック第 2 回が公開。ニューラルネットや CNN の仕組み、そしてディープラーニングの発展や課題
https://twitter.com/kazunori_279/status/1243686724795904000?s=20

- スマホで見るときついかもです

2020/3/31

# 一言

Go の学習サイト（英語）
https://tutorialedge.net/course/golang/
https://gophercises.com/

2020/4/1

# 一言

1. Go の学習サイトその２（英語）
   https://github.com/enocom/gopher-reading-list
   https://exercism.io/tracks/go/exercises

2020/4/10

# 一言

go-prompt を使ったリッチなコマンドラインツールの作り方
https://qiita.com/c-bata/items/8c40e7030f9e2d9f5da4

kube-prompt 便利でした。あんなものを作れたら良いよねって話です。

2020/4/13

# 一言

オンライン飲み会の良い点

- 行き帰りにかかる時間が不要
- 終わったらすぐ寝られる
- 複数の人と席の場所に関係なく平等に話せる
- コストが安い
- 準備すれば自分の好きなものだけ、好きな分だけ飲食できる
- 感染リスクがない
- 眠くなってボーッとしていても突っ込まれにくい

悪い点

- 準備の手間が面倒
- 料理や酒は勝手にやって来ない
- メンバーが４，５人を超えると発言が衝突しやすい
- 家族に配慮する必要がある
- 片付けは自分でしないといけない
- パソコンが汚れるリスク
- 臨場感がない

2020/4/14

# 一言

fzf を使えるようになりたいです
https://qiita.com/kompiro/items/a09c0b44e7c741724c80
https://qiita.com/kamykn/items/aa9920f07487559c0c7e

2020/4/16

# 一言

Go のレビューで気をつけること
https://github.com/golang/go/wiki/CodeReviewComments

2020/4/17

# 一言

キーボードから手を離さずに VS Code で開発したいという気持ちを大切にしています
https://insider.10bace.com/2019/02/22/vs-code%E3%81%A8%E3%81%8B%E3%81%AE%E3%82%B7%E3%83%A7%E3%83%BC%E3%83%88%E3%82%AB%E3%83%83%E3%83%88%E3%81%AE%E3%81%AF%E3%81%AA%E3%81%97/

2020/4/20

# 一言

vs code の拡張機能を色々探して使ってみています
https://qiita.com/sensuikan1973/items/74cf5383c02dbcd82234?utm_content=buffer448e3&utm_medium=social&utm_source=twitter.com&utm_campaign=buffer

2020/4/21

# 一言

kustomize はまだ全然わからないです。。
https://www.mirantis.com/blog/introduction-to-kustomize-part-1-creating-a-kubernetes-app-out-of-multiple-pieces/

2020/4/23

# 一言

Google home で 学校のチャイムを流す
https://note.com/atsushicafek/n/n9efd502a001d
やってみた

2020/4/24

# 一言

Kubernetes-native なアーキテクチャ導入の手引き 先進的なクラウド環境を最強テストベッドで体験
https://employment.en-japan.com/engineerhub/entry/2020/04/16/103000

2020/4/27

# 一言

Ubuntu20.04 が LTS でリリースされましたね
https://japan.zdnet.com/article/35152867/
https://qiita.com/outou_hakutou/items/ce06cb3c8c355d5fd87c

以前 18.04 を 19 系にあげたらエラーが起きて起動できなくなってトラウマですが試してみたいです

2020/4/30

# 一言

VSCode でエディタ画面とターミナル間のフォーカスを楽して移動したい
https://qiita.com/hassaku_63/items/4d14d949c3ce9edd9909

- 地味に便利なので使っています

2020/5/8

# 一言

Macbook の充電ケーブルのさし方について注意
https://www.lifehacker.jp/2020/05/are-you-charging-your-macbook-on-the-wrong-side.html

2020/5/11

# 一言

２日連続ですが Apple 関係の話
iPhone のライトニングケーブルのそれぞれのピンの役割
https://twitter.com/tdualdir/status/1259073018724184064
この役割分担が理由で、iphone の充電ケーブルの端子は真ん中の部分だけ劣化しやすいらしいです

2020/5/15

そういえば先週 AOJ のこの問題をなんとなく全部やりました
http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1

2020/5/18

# 一言

jsonpath を使って特定の要素を取る方法、全然わかっていないです
https://zaki-hmkc.hatenablog.com/entry/2020/01/26/213701
https://qiita.com/oke-py/items/a1d708766ba845a2d3a0

2020/5/21

# 一言

WSL2 とても気になります
https://japanese.engadget.com/jp-2020-05-19-windows-10-wsl-2-linux-gui-gpu.html

2020/5/22

# 一言

いろいろな人のリモートワークの環境
https://www.e-aidem.com/ch/listen/entry/2020/05/20/103000

2020/5/25

# 一言

Building Web Server with Go
https://www.gophersumit.com/series/web/

2020/5/28

# 一言

vs code の Bookmarks をきちんと使うと長いコードを読むときには捗りそうです
https://infoteck-life.com/a0337-vscode-bookmarks/

2020/5/29

# 一言

Godoc の読み方
https://future-architect.github.io/articles/20200521/

- 新しい GoDoc：https://pkg.go.dev/
- 以前の GoDoc：https://godoc.org/
  という違いがあるそうです

2020/6/2

# 一言

Mac の発熱がひどいので、冷却台を買いました。
どう見てもドローンにしか見えません。飛びそうです。
ただこれを使ってもまだ熱いです。
https://www.amazon.co.jp/PRANCE-Laptop-Cooling-Cooler-Connection/dp/B013QRN40G/ref=sr_1_4?dchild=1&keywords=macbook+pro+%E5%86%B7%E5%8D%B4&qid=1590718436&sr=8-4

2020/6/3

# 一言

git switch と restore を使ってみるようにしたいです
https://dev.to/dyoshimitsu/git-2-23-0-switch-restore-1h82

2020/6/4

# 一言

zsh 使いの人へ
https://thorsten-hans.com/5-types-of-zsh-aliases
そういえば Mac の Catalina でデフォルトシェルが zsh になったそうですね知りませんでした

2020/6/8

# 一言

Mac 上で Go のサンプルプログラムでサーバを起動させたいときに、
毎回「アプリケーション 〇〇へのネットワーク受信接続を許可しますか？」というポップアップがでて
うっとうしかったのですが、

ListenAndServe の port 番号の前に"127.0.0.1"または"localhost"を書くと、
localhost からのみのアクセスとなるので、ファイアウォールがブロックしないようになることがわかって便利だと思いました。
（みんな知っているんですかね？）
`http.ListenAndServe("127.0.0.1:8000", nil)`
https://stackoverflow.com/posts/41034423/revisions

2020/6/10

# 一言

Script 言語としての Go
https://www.infoq.com/jp/news/2020/06/go-scripting-language/

2020/6/11

# 一言

昨日お話しした vimium と quicktabs
https://laboradian.com/vimium/
https://nldot.info/quicktabs-chrome/

なれるととても便利です

2020/6/16

# 一言

Kubernetes でのよくある失敗１０選
https://itnews.org/news_contents/2020-05-04-most-common-mistakes-k8s-1

2020/6/17

# 一言

kustomize の公式リファレンスができてました
https://kubernetes-sigs.github.io/kustomize/installation/source/
go get で簡単に kustomize がインストール出来るようになったそうです。

reference もまとまっています
https://kubernetes-sigs.github.io/kustomize/api-reference/

2. 超高解像度なので、すごい拡大できます。ただページがとても重いのがネックです。
   https://www.haltadefinizione.com/en/image-bank/

2020/6/18

# 一言

https://speakerdeck.com/ryysud/lets-use-the-kubectl-plugin
この際色々 kubectl プラグインを入れました

2020/6/22

recording rule の例
https://medium.com/prometheus-tutorials/creating-recording-rules-in-prometheus-a4b3b35ff919

- 見た中で一番簡単な例でした

2020/6/24

# 一言

新しい Mac は CPU 使用率に問題はないものの何故か発熱がひどいです。

- Mac がおかしいのか、使い方がおかしいのか、私の手がおかしいのかわかりませんが常に低温やけど気味です

諦めて Mac Fan Control というファンを制御するアプリを入れました
https://apple-relationship.com/mac/mac%ef%bc%9a%e5%83%95%e3%81%8c%e4%bd%bf%e3%81%a3%e3%81%a6%e3%81%84%e3%82%8b%e7%86%b1%e5%af%be%e7%ad%96%e3%82%a2%e3%83%97%e3%83%aafan-control%e3%81%a8macbook%e3%82%b9%e3%82%bf%e3%83%b3%e3%83%89/

2020/6/25

# 一言

CPU キャッシュが Go のコードに与える影響（翻訳）
https://techracho.bpsinc.jp/hachi8833/2020_06_24/93115

2020/6/26

# 一言

go server の止め方（channel, context, syncGroup それぞれの違い）
https://www.gollahalli.com/blog/stopping-http-server-gracefully-context-vs-channels-vs-syncgroup/

2020/6/29

# 一言

大規模ソースコードの読み方
https://www.slideshare.net/satorutakeuchi18/viewing-source-code

- まだ読んでないですが読みたいです

2020/6/30

# 一言

fgprof Pprof 結果を視覚化するツールらしいです
https://github.com/felixge/fgprof

2020/7/1

# 一言

「近いマンガ」がわかるマンガ新検索
https://alu.jp/MangaNearestMap/

2020/7/3

# 一言

https://dev.classmethod.jp/articles/vscode-awesome-things/

2020/7/8

# 一言

https://blog.golang.org/module-compatibility

- Go で拡張性の高い API の作り方
- interface のうまい使い方、拡張性の高い struct の定義の仕方など書いてあって勉強になります

2020/7/15

# 一言

Go で Web アプリ開発時にあるあるだったレビューコメント
https://future-architect.github.io/articles/20200709/
go-retryablehttp が気になりました

2020/7/16

# 一言

Helm 気になっています。サンプルくらいは使ってみたいなと思いつつ
https://helm.sh/blog/helm-3-released/

2020/7/21

# 一言

URL のエンコードとデコードが面倒だったので alias を作りました。

```
alias urlencode='python -c "import urllib, sys; print urllib.quote_plus(sys.argv[1])"'
alias urldecode='python -c "import urllib, sys; print urllib.unquote_plus(sys.argv[1])”’v
```

- python は 2 です

2020/7/22

# 一言

How to Gracefully Close Channels
https://go101.org/article/channel-closing.html
Golang の channel の閉じ方、だめな例、いい例がわかりやすいです

2020/7/27

# 一言

Go の race について
https://www.sohamkamani.com/blog/2018/02/18/golang-data-race-and-how-to-fix-it/

- 結構わかりやすい例が書いてあります

2020/7/29

# 一言

https://xn--go-hh0g6u.com/pkg/runtime/debug/#Stack
で Go の実行結果の stack trace が得られるので、
なにか関数を実行するときに、以下のような関数を噛ませれば、もし途中で panic が起きてもスタックトレースの結果を含めてエラーとして伝搬できそうだなと思いました。

```
func receivePanic(fn func() error) (err error) {
	defer func() {
		if e := recover(); e != nil {
			err = fmt.Errorf("recovered in function : %v\nstacktrace: %s", e, string(debug.Stack()))
		}
	}()
	return fn()
}

func main() {
	if err := receivePanic(func() error { // myFunction内でpanicしたらキャッチしてerror扱い
			return myFunction(ctx)
	}); err != nil {
		log.Println("failed to myFunction:”, err)
	}
}
```

2020/7/31

# 一言

Go 関連の比較的新しい Tips
https://blog.lufia.org/entry/2020/07/28/215746

2020/8/4

# 一言

go のいろいろな json encoder decoder
https://yalantis.com/blog/speed-up-json-encoding-decoding/

小さな object であれば encoding/json (the standard package)で十分
Object が大きい場合（10 MB 以上とか）は easyjson が速い

2020/8/11

# 一言

Go の Stream は Stream のまま扱いましょうという話
https://christina04.hatenablog.com/entry/2017/01/06/190000

2020/8/12

# 一言

https://yshibata.blog.ss-blog.jp/2018-06-10
プログラミング言語 Go の翻訳者 柴田さんのブログ

> 手作業で一回動作したとか 100 回動作したからと言って、プログラムの正しさは保証されない
> 機能を確認するためのテスト設計がきちんとされていること

> ハングしたらその場で徹底して調査
> ログを入れてもう一度再現させるという対応は避けて、その場で徹底的に調査す
> る

> 朝、出社してテストが停止していたら、調査を最優先業務とする
> 二度と発生しないかもしれないので、最優先で調査させる

2020/8/13

# 一言

Go の gzip と gunzip
https://gist.github.com/alex-ant/aeaaf497055590dacba760af24839b8d
https://text.baldanders.info/golang/gzip-operation/

たまに忘れて検索しているのですが、この２つが例としてよかったです。

Io.Reader とか byte.Buffer とか、低レイヤーの操作をもっと調べたいなと思いました

2020/8/17

# 一言

Vs code の拡張機能世論調査
https://developer.hatenastaff.com/entry/2020/08/14/093000

2020/8/18

# 一言

Kubernetes-native なアーキテクチャ導入の手引き 先進的なクラウド環境を最強テストベッドで体験
https://employment.en-japan.com/engineerhub/entry/2020/04/16/103000

2020/8/21

# 一言

Go で mock
https://dmv.myhatchpad.com/insight/mocking-techniques-for-go/
モンキーパッチ、interface を使ったものなど例がいいです

2020/8/24

# 一言

Go のインターフェース抽象度を美しく保つ為の思考
https://po3rin.com/blog/go-interface

先週と同じ、interface について。
先週は interface の実装例でしたがこちらは設計方法、という感じです

2020/8/26

# 一言

grafana の syntax
https://grafana.com/docs/grafana/latest/variables/templates-and-variables/
`[[varname]]` は deprecated らしいので今後見つけたら直します。

2020/8/31

# 一言

https://www.slideshare.net/MoriharuOhzu/ss-14083300
結構極端ですがオブジェクト指向のルール
全然理解が足りないなと思いました

2020/9/1

# 一言

https://medium.com/codezillas/uh-ohs-in-go-slice-of-pointers-c0a30669feee

- slice の扱いは注意が必要だなあと思います。たまにドツボにはまります。

https://play.golang.org/p/7qLBFLoK__r
サンプル作ってみましたが１つ目の出力結果は想定と異なった出力になります

2020/9/3

# 一言

go の constructor は Struct の pointer を返すのが一般的
https://golang.org/doc/effective_go.html#composite_literals

constructor の引数にベターッとフィールド名を並べるとわかりにくい、というのであれば、confg 用の struct を用意するといい
などなど参考になりました
https://dave.cheney.net/2014/10/17/functional-options-for-friendly-apis

2020/9/7

# 一言

go の clean architecture
https://threedots.tech/post/introducing-clean-architecture/

- どうも大げさな構成になって好きになれないです。

2020/9/15

# 一言

コード内で「現時刻」を気軽に取得してはいけない

http://nekoya.github.io/blog/2013/07/09/what-time-is-it/

2020/9/16

# 一言

https://www.nytimes.com/interactive/2020/09/09/world/middleeast/beirut-explosion.html
この記事の表現に感動しました。
スマホスクロールに最適化された感じです。

2020/9/17

# 一言

自分の shell が何なのか判定する方法、知らないのがいっぱいありました
https://stackoverflow.com/questions/3327013/how-to-determine-the-current-shell-im-working-on/11097703

- `echo $SHELL` // 使えないことも多い
- `ps -p $$ | awk '$1 == PP {print $4}' PP=$$` alpine とかの busybox では-p オプションが使えないかも
- `cat /proc/$$/cmdline` // Mac は/proc ないので対応できない
- `ls la /bin/sh` // 結構どこでも使えそう
  といろいろ知らないものがありました

2020/9/18

# 一言

世界で活躍するルートサーバ（ほぼアメリカ）。
こういう地図面白いです
https://root-servers.org/
https://ja.wikipedia.org/wiki/%E3%83%AB%E3%83%BC%E3%83%88%E3%82%B5%E3%83%BC%E3%83%90

2020/9/24

# 一言

組織にテストを書く文化を根付かせる戦略と戦術
https://speakerdeck.com/twada/strategy-and-tactics-of-building-automated-testing-culture-into-organization-2019-summer-edition

2020/9/25

# 一言

go 文字列結合 benchmark
https://gist.github.com/dtjm/c6ebc86abe7515c988ec

私の Mac（CPU8、go 1.14.4）で実行した結果を見ると
速い順に 1~3 位まで並べると

1. BenchmarkBufferWithReset（buf.Reset()と buf.WriteString()を使用）
2. BenchmarkConcatOneLine（ string + string のように＋記号で一気に結合）
3. BenchmarkJoin（strings.Join を使用）
   で、
   意外にも+記号での結合はかなり速かったです

可読性を考えると、処理速度が求められる箇所では+記号は積極的に使ったほうがいいと言えそうです。
ただし、＋記号が良いのは一行でまとめて+で結合する場合（BenchmarkConcatOneLine）で、
+=のように複数行に分けて結合する（BenchmarkConcat）やり方だと一気に悪化するので注意が必要でした

ちなみに一番遅いのは fmt.Sprintf での結合でした。

2020/9/28

# 一言

動きが気持ちいい！Web 制作の参考 UI インタラクション、アニメーション 60 個まとめ
http://photoshopvip.net/124667
ページが重いですが面白いです

2020/9/29

# 一言

以前 golang の文字列結合の Benchmark について投稿しましたが、
Benchmark の計測は注意が必要です。
以下を精読するのが一番だと思いつつ、さらっとしか見られていないです。
https://dave.cheney.net/high-performance-go-workshop/dotgo-paris.html#benchmarking

2020/9/30

# 一言

【コードレビュー】レビュアーの心構え
https://qiita.com/hinora/items/266fbfb62fd3d4c45edd?utm_content=buffer23821&utm_medium=social&utm_source=twitter.com&utm_campaign=buffer
以下が好きです

```
感情を表現するツールを使う
テキストコミュニケーションは感情が伝わりにくく冷淡に受け取られやすいため、無自覚に相手にネガティブな印象を与えてしまっていることがあります

感情の受け取られ方に気を払うことで、それを未然に防ぐことができます
感嘆符（！）、絵文字、顔文字は感情を表現する強力なツールなので、ぜひ活用しましょう！！
```

2020/10/1

# 一言

https://www.slideshare.net/ota42y/goroutine-103278063

2020/10/5

# 一言

go の interface を用いた dependency injection
https://appliedgo.net/di/
わかりやすかったです

2020/10/7

# 一言

https://engineering.mercari.com/blog/entry/2020-03-17-120137/
PDF はまだダウンロードできました

2020/10/8

# 一言

洗濯機の排水溝から盛大に水漏れしていて直前まで対応していました

2020/10/9

# 一言

pprof を使って nodejs アプリケーションのプロファイルを取る

- 面白いです
  https://moznion.hatenadiary.com/entry/2020/10/05/121259

2020/10/12

# 一言

10 Easy Ways to Tune Up Your Mac for Best Performance

1. https://www.makeuseof.com/tag/quick-ways-to-tune-up-your-mac/

- 突然死を防ぎたいですね

2020/10/13

# 一言

入門書を終えた人に捧げる、社会人のための Git 中級編
https://qiita.com/yamamoto7/items/fe15a1e7e360b4015fae

Stash ではなく commit で退避するのは勉強になりました

2020/10/14

# 一言

先週 GoCon がありましたね
HTTP クライアントを作ろうとして学ぶ、使いやすいインタフェース
https://speakerdeck.com/izumin5210/number-gocon-sendai-2020

2020/10/20

# 一言

コードレビューの目的と考え方
https://osak.hatenablog.jp/entry/code-review-objectives-and-howto

2020/10/21

# 一言

計算量について
https://qiita.com/drken/items/872ebc3a2b5caaa4a0d0
計算量オーダーとかアルゴリズムについてこのひとのブログよりわかりやすい Web 記事見たことないです

2020/10/22

# 一言

この前紹介した Go の資料の上級者編？ エキスパート Go の資料を見つけました
https://www.slideshare.net/takuyaueda967/go-77689475
書いている人はもとメルカリの上田拓也さん(@ tenntenn)。
みんなの Go 言語の著者の一人でもあります

2020/10/26

# 一言

https://www.slideshare.net/KoheiTokunaga/ss-123664087

2020/10/27

# 一言

https://budougumi0617.github.io/2020/10/23/think_go_way/

2020/10/28

# 一言

https://practical-scheme.net/trans/early-j.html
Lisp エンジニア Paul Graham のブログ
以下の部分が好きです

```
何か野心的なプロジェクトに取り組んでいる人を見ると、まわりの人は意識的にせよ無意識にせよ、 失敗することを期待してしまうんだ。
中略
 シリコンバレーがこの衝動を乗り越えられたのは、モラルが優れていたからだ、なんて言うつもりはないよ[1]。 多くの人が野心的なアイディアを持つ人を応援するのは、一緒に登っていけるからだ。 投資家にとってはこのインセンティブは特に明白だ。 あなたが成功してくれれば、その過程で彼らも儲かる。 でもそれ以外の人も、あなたの成功によって、何らかの形で恩恵を受ける。 少なくとも、あなたが有名になった後で、昔から知っていたと自慢できるわけだしね。
```

2020/10/29

# 一言

ネットワーク／サーバー／セキュリティを学ぶなら読んでおきたいおすすめの書籍
https://www.seshop.com/campaign/network?utm_source=seshop_spot_20201027

2020/10/30

# 一言

Go の Null 安全について
https://zenn.dev/nobonobo/articles/f49dd93073fdd3c6c663

```
例えば「typed-nilを格納したinterface型はnil判定できない」というものがありますが、
コアメンバーの一人からは「==nilで比較可能にするほうが初心者の誤解を招かないと思う」という主張もありましたが、最終的には「理解して使ってくれ」に落ち着きました。
Goコアメンバーのコメントから読み取れるのはあちこちに「理解して使ってくれ」「理解しやすさのためだけに言語仕様を変えたくない」、「理解が必要なところはドキュメントでカバーする」という考え方が見え隠れしています
```

面白いですね

> panic が上がるとしたら使い方を間違っているか実装にミスがあるか、致命的な何かが起こったということなのでそういう時は素直にプロセスを落とす方が状況を悪化させないことが多いです。

共感しました。

2020/11/2

# 一言

Go のスライスと Rust のスライス
https://www.wantedly.com/companies/wantedly/post_articles/290761
Go のスライスの仕様について参考になる話でした。
Rust は知りません

2020/11/5

# 一言

Golang の Slice を関数の引数に渡した時の挙動
https://christina04.hatenablog.com/entry/2017/09/26/190000

配列の要素の値を書き換えると呼び出し元の slice にも影響することは知っていましたが、
サイズが変わると配列の再配列が行われて別物になる
-> 関数内で append した場合は呼び出し元の slice が見ている配列とは違うものになる

というのが知らなかった点でした。

2020/11/9

# 一言

golang の mutex はポインタで渡すようにしよう
http://tsujitaku50.hatenablog.com/entry/2017/08/20/211559

2020/11/10

# 一言

サーバレスの次は「ストレージレス」の実現へ。NetApp がストレージレスを実現する新サービス「Spot Storage」を発表
https://www.publickey1.jp/blog/20/netappspot_storage.html

```
サーバレスでアプリケーションの負荷に合わせてサーバ数が増減するように、Spot Storageでもストレージがアタッチされる仮想マシンやコンテナが要求されるストレージ性能とストレージ容量に応じて、自動的にストレージの性能と容量が増減するようになっています。
```

2020/11/11

# 一言

Go の slice の後ろに要素を追加するのは append ですが、
前方に要素を追加する pretend には注意が必要です。

よく例として出てくる以下の方法だと、毎回新しい Slice を作成しているのでメモリアロケーションが多く、実行速度も遅いです。
`data = append([]int{i}, data…)` ・・・１

よりよい方法は、ちょっとわかりにくいですが、以下のやり方です。

２

```
data = append(data, 0)
copy(data[1:], data)
data[0] = i
```

ただ、単にループで全要素を逆順に詰めていきたいだけなら以下が最速です。

３

```
data := make([]int, 0, size)
for i := len(data) - 1; i >= 0; i-- {
	data[i] = i
}
```

ベンチマークをとってみると
https://play.golang.org/p/UiWJU8jWaRo
１，２，３の順に以下の Benchmark 結果となりました。

```
BenchmarkPrependSimple-8          439086              2337 ns/op            4848 B/op         64 allocs/op
BenchmarkPrependWithCopy-8       2855065               402 ns/op             256 B/op          1 allocs/op
BenchmarkPrepend2-8             19601550                57.9 ns/op           256 B/op          1 allocs/op
```

速度やメモリ効率で数十倍の差があります。

2020/11/12

# 一言

開発者たちが慣れ親しんだ「scp」コマンドはなぜ「時代遅れで柔軟性がなくすぐに修正できない」のか？
https://gigazine.net/news/20201111-deprecating-scp/
Scp は古い設計で脆弱性も多いらしいのですが、ふさわしい代替コマンドがないですね。

2020/11/17

# 一言

軽量でインストールも簡単なシングルバイナリの Kubernetes ディストリビューション「k0s」、Mirantis がオープンソースでリリース。Linux と Windows に対応
https://www.publickey1.jp/blog/20/kubernetesk0smirantislinuxwindows.html
気になりますね。minikube で十分なのか、違いが分かっていないです

2020/11/19

# 一言

Go の Web アプリ開発でフラットパッケージにした話
https://future-architect.github.io/articles/20201109/

- 多くのファイルを root ディレクトリ直下に置く
- db インターフェースを作らない mock を作らない
- Usecase 層を無くした

などの点で、クリーンアーキテクチャとは真逆の方針となっており、
それによるメリットとデメリットを紹介しています。

完全にフラットにしすぎるとそれはそれで辛いことも多そうですが、幾重にもディレクトリがあるのも好きではないという個人的な好みと結構近かったです

2020/11/20

# 一言

意外と知らない VSCode 上で Go を爆速開発するための Tips5 選
https://qiita.com/yagi_eng/items/9e599913605625809d9c

Generate tests 知らなかったので今度使ってみようと思います

2020/11/25

# 一言

Mac は「こちら側」のコンピューターではなくなった
https://portalshit.net/2020/11/24/the-computer-is-no-longer-for-the-rest-of-us

M1 の性能はめちゃめちゃ高評価ですね

2020/11/26

# 一言

Go のバイナリには -ldflags '-w -s' でコンパイルしてもたくさんパスが埋め込まれていた
https://qiita.com/kitsuyui/items/d03a9de90330d8c275c8

2020/11/27

# 一言

alias ghe='open -a "Google Chrome.app" $(git config remote.origin.url | tr ":" / | sed "s/git@/https:\/\//g"| sed "s/.git//g")'

これを zshrc や bashrc に書いておくと、
今いる git リポジトリに対応する github の web ページが開けて便利です。

2020/12/1

# 一言

git でうっかり master ブランチで作業しててコミットまでしてしまったときは、

`git branch -m ＜別のブランチ名＞` で master を別ブランチに改名して、
`git checkout -b master origin/master` で新しく master を作り直すのが一番早いです

2020/12/2

# 一言

人気順検索の Solr はスケールのためにディスクを捨てた
https://techlife.cookpad.com/entry/2020/11/25/080000
クックパッドがステートレスにできたのは更新頻度や SLO の問題だなと思い噛み締めました

2020/12/7

# 一言

Go 用の slackAPI
https://github.com/slack-go/slack

2020/12/8

# 一言

https://stefafafan.hatenablog.com/entry/iterm2

2020/12/9

# 一言

[発表資料] 今改めて読み直したい Go 基礎情報 その 1 #golangtokyo
https://budougumi0617.github.io/2019/06/20/golangtokyo25-read-again-awesome-go-article/
とても良くまとまっていて参考になりました。

2020/12/10

# 一言

defaults write -g KeyRepeat -int 1
Mac でカーソルの移動速度を最速にするために絶対やっている設定です

2020/12/11

# 一言

大規模リポジトリで高速に git clone するテクニック - DeNA Testing Blog
https://swet.dena.com/entry/2020/12/10/100000
depth を指定したりするやつです

2020/12/14

# 一言

WEB アプリケーション設計入門
https://speakerdeck.com/nrslib/introduction-to-web-application-design?slide=123
PHP の話でしたが他の言語にも通じる話だなと思いました

2020/12/15

# 一言

How I write HTTP services after eight years.
https://pace.dev/blog/2018/05/09/how-I-write-http-services-after-eight-years.html
Gopher の Mat Ryer が書いた記事

# 一言

長時間ランニングテストの勧め ～開発用ノート PC の活用～
https://engineering.mercari.com/blog/entry/20201215-running-tests/

```
テストコードは、各人のデスクトップPCだけではなく、マルチプロセッサーのサーバやCI用のサーバで実行されていました。それに加えて、開発者全員のデスクトップPCを活用して、夜間および週末も繰り返しテストコードを実行していました。
```

すごいですね。。

2020/12/18

# 一言

The best Golang Learning Resources on the Web
https://golangresources.com/
いろいろな Go についての Youtube 集
英語と Go をいっぺんに学びたい人向け（大量すぎて時間が取れない）

2020/12/21

# 一言

https://note.com/kyuns/n/n00d467243857
ZOZO のテックカンパニーへの変遷、CTO としての取り組みを振り返る

判断と行動力すごいですね。

2020/12/23

# 一言

If Python is slow, why is it so widely used for things like science and data analysis? Wouldn't languages like C++ be much faster?
https://www.quora.com/If-Python-is-slow-why-is-it-so-widely-used-for-things-like-science-and-data-analysis-Wouldnt-languages-like-C-be-much-faster-1

python はただのインターフェースで、裏は C++だぜと書いてます

2020/12/24

# 一言

Tunein
https://apps.apple.com/jp/app/tunein-radio/id418987775
このアプリは非常に使い勝手が良いです。
音楽、ニュースなど大量の pod cast や FM 放送がただで聞けるし広告も全然鬱陶しくありません

2020/12/25

# 一言

https://qiita.com/shibukawa/items/962e9a8f2bd684bc5a07
Go の準々標準ライブラリの探索
渋川よしきさんウルトラマン好きなんですね

2020/12/28

# 一言

「コーヒー後の昼寝」が脳を劇的に回復させる訳
https://toyokeizai.net/articles/-/398268

- なるべくコーヒー飲んですぐに 10 分くらい昼寝するようにしています

2021/1/6

2021/1/7

# 一言

「なんでこの機能、Windows に標準で入ってないの？」という神機能が特盛！Microsoft 公式ツール「Powertoys」を解説
https://smhn.info/202101-how-to-use-microsoft-windows-powertoys
Windows ユーザとして気になります

2021/1/8

# 一言

ジムケラーはこれから何をするのでしょうね
https://gigazine.net/news/20210107-jim-keller-tenstorrent/

2021/1/12

# 一言

週末 Cloud SQL（Google のクラウドの MySQL）を grafana で見られないか挑戦していてようやくできました。
grafana 便利です

2021/1/13

# 一言

https://ueokande.github.io/go-slice-tricks/
かつてないほどわかりやすいスライスの図解
https://github.com/golang/go/wiki/SliceTricks
これを図示したものらしいので解説はこちらのほうが詳しいです

2021/1/18

# 一言

メルカリの go-circuitbreaker（障害を検知して遮断する方法）の実装
https://speakerdeck.com/matope/mercari-dot-go-number-12-go-circuitbreakerfalsegoshao-jie?slide=10

2021/1/20

# 一言

Go で時刻のゼロ値が変になった話
https://www.m3tech.blog/entry/2020/12/29/120000
初期値の time.Time{}が IsZero()が True と判定されない話です
うちのシステムをいじっていて出くわすことはまずないと思います

2021/1/21

# 一言

https://hnakamur.github.io/blog/2018/01/30/go-heap-allocations/
go で書いたコードがヒープ割り当てになるかを確認する方法

2021/1/27

# 一言

Vs Code 拡張 Top10 for 2021
https://blog.logrocket.com/top-10-vs-code-extensions-2021/

2021/1/28

# 一言

Go の抽象化の例（WebServer）
https://jonahwintergolang.medium.com/a-beginners-guide-to-sensible-abstractions-using-golang-4faabbabb838

2021/1/29

# 一言

https://nowokay.hatenablog.com/entry/2021/01/26/134015
M1 Mac が欲しくなりますね

2021/2/1

# 一言

データベースを遅くするための８つの方法
https://zenn.dev/koduki/articles/d3e8984f420b370681f9
仕事では使わないですがわかりやすくて面白いです

2021/2/2

# 一言

https://twitter.com/davecheney/status/1353906656778752001
次のプログラムの結果はなんでしょうクイズ
defer がスタックとして機能することを考えるとわかりやすいです。

```
package main

import (
    "fmt"
)

func main() {
    fn := func() { fmt.Print(1) }
    defer fn()
    fn = func() { fmt.Print(2) }
    defer fn()
}
```

ちなみにこれは別の結果になります

```
func main() {
    a := 1
    fn := func() { fmt.Print(a) }
    defer fn()
    a = 2
    fn = func() { fmt.Print(a) }
    defer fn()
}
```

# 一言

CHANGELOG の修正を忘れてそれを指摘されるというのを少しでも減らすために以下の方法を考えてみました。

`~/.gitconfig` の alias に以下の設定をしました。

```
[alias]
    cm = !"if test $(git config remote.origin.url | grep -c <repository>) = 1; then echo '==================================================\n[Warning] CHANGELOGを更新しましたか？ (゜Д゜ )アラヤダ!!\n=================================================='; fi && git commit -m"

```

これでの commit をすると以下のように出力されます

```
$ g cm 'fix' 〇〇
=======================================
[Warning] CHANGELOGを更新しましたか？ (゜Д゜ )アラヤダ!!
=======================================
```

ここで気づいたら修正して git rebase できそうです

pre-commit を使う手もありそうですが、これなら１行ですむかなと思いました。

2021/2/5

# 一言

グーグルクラウドは年間 5900 億円の赤字、アマゾンの AWS に大敗
https://forbesjapan.com/articles/detail/39637

売上は伸びているので Stadia みたいに撤退しないでほしいですね

2021/2/9

# 一言

https://qiita.com/cocoa-maemae/items/2e729ed438c3db878956
いつか ansible のテストしたいですね。

2021/2/10

# 一言

なぜもっとたくさんのコアを搭載した CPU を作らないのでしょうか？2000 コアの GPU なんかそこら辺にありますが、なぜ CPU では同じようにできないのでしょうか？
https://jp.quora.com/%E3%81%AA%E3%81%9C%E3%82%82%E3%81%A3%E3%81%A8%E3%81%9F%E3%81%8F%E3%81%95%E3%82%93%E3%81%AE%E3%82%B3%E3%82%A2%E3%82%92%E6%90%AD%E8%BC%89%E3%81%97%E3%81%9FCPU%E3%82%92%E4%BD%9C%E3%82%89%E3%81%AA%E3%81%84%E3%81%AE
回答が詳しいですね。

2021/2/17

# 一言

Git の alias 機能で超効率的に作業する
https://medium.com/eureka-engineering/git%E3%81%AEalias%E6%A9%9F%E8%83%BD%E3%81%A7%E8%B6%85%E5%8A%B9%E7%8E%87%E7%9A%84%E3%81%AB%E4%BD%9C%E6%A5%AD%E3%81%99%E3%82%8B-b9129b4ecf0f

2021/2/18

# 一言

vs code 上から該当の github ファイルをブラウザで開ける拡張
便利でした
https://marketplace.visualstudio.com/items?itemName=sysoev.vscode-open-in-github#:~:text=Usage,%22Open%20In%20GitHub%3A%20File%22

2021/2/22

# 一言

シェルスクリプトを書くときにいつもやるやつ
https://please-sleep.cou929.nu/bash-strict-mode.html
-o オプション知りませんでした。

2021/2/24

# 一言

Kubernetes 入門 - 自作の Docker イメージを minikube で動かす方法
https://tech.andpad.co.jp/entry/2021/02/18/170000

2021/2/25

Golang context と struct
https://blog.golang.org/context-and-structs
context を struct のフィールドとして持つと良くないよ、とよく言われる理由の説明です
New()に context を渡してフィールド変数として持ってしまうと、そのコンストラクタで作ったインスタンスのメソッドにも引数として context を与えた場合どちらが優先されるかわからないので混乱する、context の生存期間が分からなくなる、
などのことが書いてあります

2021/2/26

# 一言

こんなコードは嫌だ、古い書き方のコード駆逐したい（とりあえず９つ）
https://qiita.com/yuu_j/items/d6e6fc4476ab1dc35cdc

2021/3/1

# 一言

Elasticsearch で日本語の全文検索の機能を実装する
https://www.elastic.co/jp/blog/how-to-implement-japanese-full-text-search-in-elasticsearch- 日本語は英語に比べて全文検索が難しい理由

> 欧米の言語では、単語がホワイトスペースによって分割されるので、文章を単語に分解することが容易にできます。
> しかしながら、日本語の場合、単語の切れ目をホワイトスペースでは判断できません。

2021/3/2

# 一言

Go の言語仕様書精読のススメ & 英語彙集
https://zenn.dev/hsaki/articles/gospecdictionary
詳しくて、知らないこともたくさんありました

2021/3/3

# 一言

Go のリトライ処理で考慮すること
https://zenn.dev/imamura_sh/articles/retry-46aa586aeb5c3c28244e
想像より深い内容について書いてありました

2021/3/4

# 一言

一銭も払わずにクラウド上で Web サービスを公開する
https://qiita.com/okazu_dm/items/87003109067348e9b7bf

heroku は過去に使ってみましたが他のサービスとの連携を考えると GCP が楽で今も使っています
AWS はやってません

2021/3/8

# 一言

JSON を go の struct に変換する Web ツール
https://mholt.github.io/json-to-go/

紹介記事
https://www.reddit.com/r/golang/comments/lziw3y/how_to_make_complex_json_data_with_go_struct/

社内データの扱いには注意が必要そう

2021/3/9

# 一言

Go1.15 からは make して copy するのが Slice のコピーでは最速だそうです
https://github.com/go101/go101/wiki/How-to-efficiently-clone-a-slice%3F

2021/3/10

# 一言

Go のテストに使える手作りモックパターン
https://moneyforward.com/engineers_blog/2021/03/08/go-test-mock/

2021/3/11

# 一言

軽量 Docker イメージに安易に Alpine を使うのはやめたほうがいいという話
https://blog.inductor.me/entry/alpine-not-recommended

2021/3/12

# 一言

Dockerfile のベストプラクティス Top 20
https://sysdig.jp/blog/dockerfile-best-practices/
セキュリティよりの話です。
不必要な特権を避ける、などの参考になりそうな話がありました

2021/3/16

# 一言

システム思考とプロダクトマネジメント
https://speakerdeck.com/yusukehisatsu/sisutemusi-kao-topurodakutomanezimento
エンジニア視点で考えると、最新の言語使ってフルスクラッチしようってなったりしますが、
こういう考え方でマネジメント層に対して掘り下げて説明する（またはするつもりで考えてみる）ことで、
結局エンジニアにとっても落ち着いて設計・開発できてプラスになるのかもと思いました

2021/3/17

# 一言

Go 言語の記述の迷いどころについて
https://zenn.dev/nobonobo/articles/19c84c231aff46
大体知っていることが多いですが復習です

2021/3/18

# 一言

go の semaphore のやり方２通り
https://medium.com/@deckarep/gos-extended-concurrency-semaphores-part-1-5eeabfa351ce

1. <-sem みたいな channel を使ったやり方
2. golang.org/x/sync/semaphore package を使ったやり方

2021/3/22

# 一言

オブジェクト指向と 10 年戦ってわかったこと
https://qiita.com/tutinoco/items/6952b01e5fc38914ec4e

2021/3/23

# 一言

インターネットイニシアティブの IT 用語集。わかりやすいです
https://www.iij.ad.jp/ir/gloss/

2021/3/25

# 一言

問題解決、計画の際に役立つラバーダッキング法
https://and-engineer.com/articles/YFLlIRAAACMAp2X_

2021/3/30

# 一言

Comment Only What the Code Cannot Say
https://kevlinhenney.medium.com/comment-only-what-the-code-cannot-say-dfdb7b8595ac

- 間違った内容のコメントの価値はゼロか、または負の効果すらある
- だめなコードをコメントで補わないでコードを書き直して！
  など

Go の大文字の関数とか struct とか、役割が自明のものでもコメントを求められる仕様はどうにかならないですかね。
`Config is struct for configration` みたいな意味のないコメント書くの辛いですね

2021/3/31

# 一言

pip と pipenv と poetry の技術的・歴史的背景とその展望
https://vaaaaaanquish.hatenablog.com/entry/2021/03/29/221715
poetry 使ったことないですが使いやすいという噂でした

2021/4/1

# 一言

「クリーンアーキテクチャ完全に理解した」人の話
https://gist.github.com/mpppk/609d592f25cab9312654b39f1b357c60

2021/4/2

# 一言

Golang のエラーの比較について
https://zenn.dev/kskumgk63/articles/550dc9d42078d968beac
