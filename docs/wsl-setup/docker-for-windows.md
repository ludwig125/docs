## 参考

[https://qiita.com/yoichiwo7/items/0b2aaa3a8c26ce8e87fe:title]

[https://docs.docker.jp/docker-for-windows/index.html:title]

[https://docs.docker.jp/docker-for-windows/install.html:title]



この辺を参考にDocker for WindowsをインストールしたけどうまくHyper-Vが立ち上がってくれなかったので対応したこと

**WSLのセットアップ後に,WSL２でもセットアップしたので両方書いてある**

# Docker for Windowsの設定（WSL1）

## 前提

- PCはWindows10のProである必要がある
- WSLは1

ちなみにWSLのバージョンはPowerShellなどを開いて以下で確認できる

`wsl -l -v`


## インストーラのダウンロードとインストール

[https://hub.docker.com/editions/community/docker-ce-desktop-windows/]

インストーラをクリックしてインストールする

## アプリを起動

Docker Desktopアプリを起動

デスクトップ上にショートカットのアイコンがあればそれをクリック
またはWindowsキーで検索する

自分の場合はここで `Cannnot enable Hyper-V service` と出てしまった（対応は後述）

![image](https://user-images.githubusercontent.com/18366858/92656432-ffdd6a00-f32d-11ea-8817-1d48c48408a5.png)

上のポップアップを消してしまうとDockerアプリも閉じてしまうみたいなのでここではわきにどけてそのまま続けた

## 設定画面

[https://superuser.com/questions/1326814/how-open-docker-settings-on-windows:title]

アプリの設定は上のリンク先にも書いてある通り、起動中はWindowsの右下の「上向きの三角っぽい矢印の中」に隠れている

![image](https://user-images.githubusercontent.com/18366858/92656614-49c65000-f32e-11ea-8a51-db8cb92fe85e.png)

これを押して「Settings」を押す

![image](https://user-images.githubusercontent.com/18366858/92656834-b3def500-f32e-11ea-9b60-2a386a7d25e3.png)

この「Expose daemon on tcp://localhost:2375 without TLS」チェックを入れて「Apply＆Restart」する

## WSL上でDockerインストール



[https://docs.docker.com/engine/install/ubuntu/:title]


```
# 事前パッケージインストール
$ sudo apt-get update

$ sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    gnupg-agent \
    software-properties-common

# DockerのGPG鍵を追加,確認
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
$ sudo apt-key fingerprint 0EBFCD88

# Docker Stableレポジトリを追加
$ sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"

# Dockerインストール
 $ sudo apt-get update
 $ sudo apt-get install docker-ce docker-ce-cli containerd.io
```

## WSL上のDocker設定

自分の場合はzshを使っているので、.zshrcを編集する。bashの人は.bashrcにする
```
echo "export DOCKER_HOST='tcp://0.0.0.0:2375'" >> ~/.zshrc
source ~/.zshrc
```

## 確認

`docker version ` をターミナルで実行すると、おかしい

`Cannot connect to the Docker daemon at tcp://0.0.0.0:2375. Is the docker daemon running?` というメッセージが出た

Serverは表示されない

```
$docker version
Client: Docker Engine - Community
 Version:           19.03.12
 API version:       1.40
 Go version:        go1.13.10
 Git commit:        48a66213fe
 Built:             Mon Jun 22 15:45:36 2020
 OS/Arch:           linux/amd64
 Experimental:      false
Cannot connect to the Docker daemon at unix:///var/run/docker.sock. Is the docker daemon running?
```

参考

- 同様の現象：[https://github.com/docker/for-linux/issues/535:title]


## Hyper-Vが立ち上がってくれない問題対応

[https://docs.microsoft.com/ja-jp/virtualization/hyper-v-on-windows/quick-start/enable-hyper-v:title]

を参考にやってみたがうまくいかない

自分の場合は事前に「Hyper-V」がチェックが入っていた
![image](https://user-images.githubusercontent.com/18366858/92657510-edfcc680-f32f-11ea-97bc-68d704e1b8d8.png)


## 調べた結果


[https://forums.docker.com/t/cannot-enable-hyper-v-service/94086/9:title]

```
got to ‘Apps and Features’.
Select Programs and Features on the right under related settings.
Select Turn Windows Features on or off.
Unselect Hyper-V and click OK. (So I disable it)
Restart computer

After restart I go to:
‘Apps and Features’.
Select Programs and Features on the right under related settings.
Select Turn Windows Features on or off.
select Hyper-V and click OK. (So I enable it)
Computer restart
```

という記述を見つけて、いったんチェックを外して再起動、もう一度チェックを入れて再起動したら、今度はHyper-Vが立ち上がったらしい（DockerDesktopアプリを起動してもエラーが出なかった！）

## 再度確認

```
$docker version
Client: Docker Engine - Community
 Version:           19.03.12
 API version:       1.40
 Go version:        go1.13.10
 Git commit:        48a66213fe
 Built:             Mon Jun 22 15:45:36 2020
 OS/Arch:           linux/amd64
 Experimental:      false

Server: Docker Engine - Community
 Engine:
  Version:          19.03.12
  API version:      1.40 (minimum version 1.12)
  Go version:       go1.13.10
  Git commit:       48a66213fe
  Built:            Mon Jun 22 15:49:27 2020
  OS/Arch:          linux/amd64
  Experimental:     false
 containerd:
  Version:          v1.2.13
  GitCommit:        7ad184331fa3e55e52b890ea95e65ba581ae3429
 runc:
  Version:          1.0.0-rc10
  GitCommit:        dc9208a3303feef5b3839f4323d9beb36df0a9dd
 docker-init:
  Version:          0.18.0
  GitCommit:        fec3683
```

ようやく表示された。
ふー

### dockerをsudoなしで実行する

最初の設定ではdockerコマンドに毎回sudoが必要なので、以下のコマンドでsudoなしで実行できるようにする

ユーザー自身の副所属グループに「docker 」を追加する

```
$ sudo usermod -a -G docker $USER
```

参考：

- [Install and run Docker on Ubuntu 18.04 at Infomaniak (or anywhere else) \| by Samuel Pouyt | Medium](https://medium.com/@samuelpouyt/install-and-run-docker-at-infomaniak-on-ubuntu-18-04-f8e59ee9471a)


# Docker for Windowsの設定（WSL2）

## wsl2へ変更

以下を参考にWSL2に更新する

- [Windows Subsystem for Linux (WSL) を Windows 10 にインストールする \| Microsoft Docs](https://docs.microsoft.com/ja-jp/windows/wsl/install-win10)


WSL1と2の違いは以下などを見るといい

- [WSL 2 と WSL 1 の比較 \| Microsoft Docs](https://docs.microsoft.com/ja-jp/windows/wsl/compare-versions)

バージョンの確認

```
> wsl -l -v
  NAME                   STATE           VERSION
* Ubuntu                 Running         2
  docker-desktop         Running         2
  docker-desktop-data    Running         2
```

=> wsl2になっている

## Docker for WindowsをWSL2に対応させる

[Docker Desktop WSL 2 backend \| Docker Documentation](https://docs.docker.com/docker-for-windows/wsl/)

[Docker DesktopをWSL2に対応させる \| kawadeblog](https://kawadev.net/wsl2-docker-desktop/)

<https://github.com/docker/for-win/issues/5096>

[Cannot connect to the Docker daemon on bash on Ubuntu windows](https://www.thetopsites.net/article/56051167.shtml)

この辺を参考に以下のようにする

### 最新のDocker for Windowsをインストール

https://docs.docker.com/docker-for-windows/edge-release-notes/

からDocker Desktop Community 2.3.6.2 をDownloadしてインストール

![image](https://user-images.githubusercontent.com/18366858/93724085-0a75ea00-fbdf-11ea-8545-5d288c6a7e94.png)

![image](https://user-images.githubusercontent.com/18366858/93724087-13ff5200-fbdf-11ea-85ac-c2d6b028fe1a.png)

![image](https://user-images.githubusercontent.com/18366858/93724098-26798b80-fbdf-11ea-8e81-0f54106638f2.png)


### 再度ユーザグループの追加

自分だけかな。。WSL2にして、Docker for Windowsをそれに対応させたあとで、再びdockerコマンドにsudoが必要になってしまったので以下のコマンドを実行

```
$ sudo usermod -a -G docker $USER
```

# Dockerを使う

#### docker でコンテナを作って入る

- `golang:1.15.1-alpine` imageをもとにしたコンテナを作成してその中に入るのは以下のコマンドでできる
- alpineなのでbashではなくashを指定
- `--rm`を指定することでコンテナから出たら自動的にコンテナを削除する

```
$ docker run --rm -it golang:1.15.1-alpine ash
Unable to find image 'golang:1.15.1-alpine' locally
1.15.1-alpine: Pulling from library/golang
df20fa9351a1: Pull complete
ed8968b2872e: Pull complete
a92cc7c5fd73: Pull complete
d484aaef8981: Pull complete
1021cfc6e55c: Pull complete
Digest: sha256:bc6f2b94340ed84ec22dab364505b0d1a339ecff99b583a63372ecf966129be2
Status: Downloaded newer image for golang:1.15.1-alpine
/go #
```

- image が見つからない場合は上のようにPullが行われるが、2回目以降はすぐ入れる

```
$ docker run --rm -it golang:1.15.1-alpine ash
/go #
```
