# WSL 環境の構築メモ

WSL で開発環境を構築したときのメモ
詳しい導入手順はいくらでもあるので自分なりに気になった点だけ載せる

## WSL インストール

https://docs.microsoft.com/ja-jp/windows/wsl/install-win10

- 公式

## Ubuntu

### 最初のインストール

基本的に以下に従う
https://www.atmarkit.co.jp/ait/articles/1608/08/news039.html

=> 2021/02/11 追記。この記事会員限定になってた

<details><summary>
18.04Versionの確認</summary><div>

version は 18.04

```
$cat /etc/os-release
NAME="Ubuntu"
VERSION="18.04.4 LTS (Bionic Beaver)"
ID=ubuntu
ID_LIKE=debian
PRETTY_NAME="Ubuntu 18.04.4 LTS"
VERSION_ID="18.04"
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
VERSION_CODENAME=bionic
UBUNTU_CODENAME=bionic
```

</div></details>

<details><summary>
18.04から20.04.2 LTSにアップデートしたときのメモ</summary><div>

変更前の version は 18.04

```
$cat /etc/os-release
NAME="Ubuntu"
VERSION="18.04.4 LTS (Bionic Beaver)"
ID=ubuntu
ID_LIKE=debian
PRETTY_NAME="Ubuntu 18.04.4 LTS"
VERSION_ID="18.04"
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
VERSION_CODENAME=bionic
UBUNTU_CODENAME=bionic
```

参考にさせていただいた記事

- https://qiita.com/hitobb/items/2ee9b1c2c49760976e0f

#### 1. リポジトリ一覧の更新、パッケージの更新

```
sudo apt update
sudo apt upgrade
```

#### トラブル

以下のエラーが出たので grafana のパッケージ２つを再設定した

```
dpkg: パッケージ grafana の処理中にエラーが発生しました (--configure):
 installed grafana package post-installation script subprocess returned error exit status 1
man-db (2.8.3-2ubuntu0.1) のトリガを処理しています ...
ERROR: Cannot create report: [Errno 17] File exists: '/var/crash/grafana.0.crash'

略
処理中にエラーが発生しました:
 grafana-enterprise
 grafana

```

以下の記事を参考に再設定した

- https://qiita.com/yukari-n/items/d1b17bd37036f120153c

##### grafana の再設定（grafana-enterprise も同様にした）

```
[~] $sudo dpkg --audit grafana
以下のパッケージは最初の設定中に問題が発生したため、設定が終了していません。
dpkg --configure <パッケージ> か dselect で設定 (configure) メニューオプショ
ンを使って設定作業を再試行しなければなりません:
 grafana              Grafana
```

設定できない

```
[~] $sudo dpkg --configure grafana
grafana (7.4.0) を設定しています ...
Restarting grafana-server service...System has not been booted with systemd as init system (PID 1). Can't operate.
dpkg: パッケージ grafana の処理中にエラーが発生しました (--configure):
 installed grafana package post-installation script subprocess returned error exit status 1
処理中にエラーが発生しました:
 grafana
```

設定ファイルを消すと問題なく再設定できた

```
[~] $ls /var/lib/dpkg/info/grafana.postinst
/var/lib/dpkg/info/grafana.postinst*
[~] $sudo rm /var/lib/dpkg/info/grafana.postinst
rm: 通常ファイル '/var/lib/dpkg/info/grafana.postinst' を削除しますか? y
[~] $sudo dpkg --configure grafana
grafana (7.4.0) を設定しています ...
[~] $
[~] $sudo dpkg --audit grafana
[~] $
```

#### 2. Ubuntu のバージョンアップ

```
sudo apt install update-manager
sudo apt dist-upgrade
```

これでバージョン更新

```
sudo do-release-upgrade -d
```

> Checking for a new Ubuntu release
> You have not rebooted after updating a package which requires a reboot. Please reboot before upgrading.

と出たので、powerShell を起動して、WSL を再起動

PowerShell で以下を実行

Ubuntu ディストリビューションの確認

```
PS C:\WINDOWS\system32> wsl -l
Linux 用 Windows サブシステム ディストリビューション:
Ubuntu (既定)
docker-desktop-data
docker-desktop
```

```
PS C:\WINDOWS\system32> wsl -t Ubuntu
PS C:\WINDOWS\system32>
```

これで WSL が再起動する

#### 2.つづき

あらためて実行

```
sudo do-release-upgrade -d
```

#### 3. ファイルの更新確認

![image](https://user-images.githubusercontent.com/18366858/107575018-afe33600-6c32-11eb-9066-241a035fbd18.png)

のような画面が出たので、一応元のファイルをバックアップしておいて、最新にした
（あとでバックアップ使わなくても問題なかった）

#### 4. バージョン確認

全部終わったのでバージョン確認

```
[~] $cat  /etc/os-release
NAME="Ubuntu"
VERSION="20.04.2 LTS (Focal Fossa)"
ID=ubuntu
ID_LIKE=debian
PRETTY_NAME="Ubuntu 20.04.2 LTS"
VERSION_ID="20.04"
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
VERSION_CODENAME=focal
UBUNTU_CODENAME=focal
[~] $
```

</div></details>

### wsltty のインストール

<details><summary>自分は後で結局wslttyからWindowsTerminalに変えたので折り畳み</summary><div>

https://www.atmarkit.co.jp/ait/articles/1812/13/news031.html

wsltty のオプション

![image](https://user-images.githubusercontent.com/18366858/83340538-6e189680-a314-11ea-9d2e-aa1bb0e74ebb.png)

![image](https://user-images.githubusercontent.com/18366858/83340580-00b93580-a315-11ea-917a-baa12280aff7.png)

- 「Ctrl+Shift+文字ショートカット」にチェックを入れることで、「Ctrl+Shift+C」でコピペ、「Ctrl+Shift+V」でペーストできるようになる

</div></details>

## WSL のホームディレクトリ変更

**WSL のホームディレクトリを以下の方法で/mnt/c 以下にしていたが、WSL2 では読み込み保存が遅くなるみたいなので/home/USER 以下に戻した**

そのため以下の方法は WSL2 以降ではしないほうが良さそう

<details><summary>WindowsTerminal設定</summary><div>

WSL のホームディレクトリは最初は`/home/<user名>` にあってわかりにくいので、C ドライブ直下に変更する

事前に Windows 側で C ドライブ直下に`wsl` という名前でフォルダを作っておいて、(`C:\wsl`)
WSL 側で `/etc/passwd` を編集して

```
ludwig125:x:1000:1000:,,,:/home/ludwig125:/bin/bash
```

を以下のように変更

```
ludwig125:x:1000:1000:,,,:/mnt/c/wsl:/bin/bash
```

WSL を開きなおすと、次回以降は`/mnt/c`がホームディレクトリになる

参考

- https://ascii.jp/elem/000/001/250/1250797/
- https://kazmax.zpp.jp/linux_beginner/etc_passwd.html
- https://qiita.com/funacchi/items/c3bb78a546cf2605205d

</div></details>

## Windows Terminal

https://qiita.com/whim0321/items/6a6b11dea54642bd6724

https://qiita.com/hideki0145/items/04582a26baf3d81632c1

https://qiita.com/rubytomato@github/items/e88cab84f36e44797cf2

<details><summary>WindowsTerminal設定</summary><div>

```
// This file was initially generated by Windows Terminal 1.0.1401.0
// It should still be usable in newer versions, but newer versions might have additional
// settings, help text, or changes that you will not see unless you clear this file
// and let us generate a new one for you.

// To view the default settings, hold "alt" while clicking on the "Settings" button.
// For documentation on these settings, see: https://aka.ms/terminal-documentation
{
    "$schema": "https://aka.ms/terminal-profiles-schema",

    // defaultをubuntuにする(ludwig125)
    "defaultProfile": "{2c4de342-38b7-51cf-b940-2309a097f518}",

    // You can add more global application settings here.
    // To learn more about global settings, visit https://aka.ms/terminal-global-settings

    // If enabled, selections are automatically copied to your clipboard.
    "copyOnSelect": true,

    // If enabled, formatted data is also copied to your clipboard
    "copyFormatting": false, // 選択した部分をクリップボードにコピー

    // A profile specifies a command to execute paired with information about how it should look and feel.
    // Each one of them will appear in the 'New Tab' dropdown,
    //   and can be invoked from the commandline with `wt.exe -p xxx`
    // To learn more about profiles, visit https://aka.ms/terminal-profile-settings
    "profiles":
    {
        "defaults":
        {
            // Put settings here that you want to apply to all profiles.
        },
        "list":
        [
            {
                "guid": "{2c4de342-38b7-51cf-b940-2309a097f518}",
                "hidden": false,
                "name": "Ubuntu",
                "source": "Windows.Terminal.Wsl",
                "commandline": "wsl.exe ~ -d Ubuntu", // ホームディレクトリを開く(ludwig125)
                "colorScheme": "One Half Dark", // ★カラースキーム名を指定★
                "useAcrylic": false // ★ウィンドウ背後にあるコンテンツが透過するかどうか★
            },
            {
                // Make changes here to the powershell.exe profile.
                "guid": "{61c54bbd-c2c6-5271-96e7-009a87ff44bf}",
                "name": "Windows PowerShell",
                "commandline": "powershell.exe",
                "hidden": false
            },
            {
                // Make changes here to the cmd.exe profile.
                "guid": "{0caa0dad-35be-5f56-a8ff-afceeeaa6101}",
                "name": "コマンド プロンプト",
                "commandline": "cmd.exe",
                "hidden": false
            },
            {
                "guid": "{b453ae62-4e3d-5e58-b989-0a998ec441b8}",
                "hidden": false,
                "name": "Azure Cloud Shell",
                "source": "Windows.Terminal.Azure"
            }
        ]
    },

    // Add custom color schemes to this array.
    // To learn more about color schemes, visit https://aka.ms/terminal-color-schemes
    "schemes": [],

    // Add custom keybindings to this array.
    // To unbind a key combination from your defaults.json, set the command to "unbound".
    // To learn more about keybindings, visit https://aka.ms/terminal-keybindings
    "keybindings":
    [
        // Copy and paste are bound to Ctrl+Shift+C and Ctrl+Shift+V in your defaults.json.
        // These two lines additionally bind them to Ctrl+C and Ctrl+V.
        // To learn more about selection, visit https://aka.ms/terminal-selection
        { "command": {"action": "copy", "singleLine": false }, "keys": "ctrl+c" },
        { "command": "paste", "keys": "ctrl+v" },

        // Press Ctrl+Shift+F to open the search box
        { "command": "find", "keys": "ctrl+shift+f" },

        // Press Alt+Shift+D to open a new pane.
        // - "split": "auto" makes this pane open in the direction that provides the most surface area.
        // - "splitMode": "duplicate" makes the new pane use the focused pane's profile.
        // To learn more about panes, visit https://aka.ms/terminal-panes
        { "command": { "action": "splitPane", "split": "auto", "splitMode": "duplicate" }, "keys": "alt+shift+d" }
    ]
}

```

</div></details>

## シェルを bash から zsh に変更

```
sudo apt install zsh
```

その他

参考

- https://qiita.com/mu_tomoya/items/4c9cf14a48af27907f86

## git 設定

git 自体はデフォルトで入っていたが 2.17.1 だった

一応インストール手順記載

```
sudo apt-get update
sudo apt-get install git
```

```
$git version
git version 2.17.1
```

これだと最新の switch, restore オプションが使えないのでアップグレードする

PPA (Personal Package Archive) で最新バージョンを提供されている方がいるらしいのでそれを使わせていただく

```
$ sudo add-apt-repository ppa:git-core/ppa
$ sudo apt update
$ sudo apt install git
```

version

```
$git version
git version 2.27.0
```

自分の情報は以下で初期設定

- これがないとコミット情報に名前が出ない
- メール登録しておけば万が一 Git に秘密鍵を Upload してしまったときに「秘密鍵っぽいよ危ないぞ」って連絡くれる

```
git config --global user.name [名前]
git config --global user.email [メールアドレス]
```

参考

- https://help.github.com/ja/github/using-git/setting-your-username-in-git

自分は gitconfig に alias と一緒にまとめて書いている

### github と連携するために ssh 鍵の登録

#### 鍵の作成

自分はすでに鍵を持っていたので必要なかったけど、鍵を作るとしたらこれ

```
ssh-keygen -t rsa -C <メールアドレス>
```

#### 鍵の場所

**鍵を置く場所がちょっと困った点だった**

**以下、前述の WSL のホームディレクトリを変えたために生じた問題なので、WSL2 以降は問題ない**

ssh の秘密鍵は前述の設定で、パーミッションを 400(`-r--------`)などにしないと SSH の際に怒られる

~~自分の場合、前述の設定でホームディレクトリを`/mnt/c`以下にしていたので、chmod でパーミッション変更ができなかった~~

なので、一旦デフォルトのホームディレクトリである、
`/home/<user名>`に移って、そこに `.ssh`　ディレクトリを置いて、その中に秘密鍵および公開鍵を置くことにした

```
$ls -l /home/ludwig125/.ssh
total 4
-r-------- 1 ludwig125 ludwig125 1680 May 31 05:57 id_rsa
-rwxrwxrwx 1 ludwig125 ludwig125  406 May 31 05:57 id_rsa.pub*
```

ここであれば`chmod 400 id_rsa`　コマンドが正しく実行できた

#### 鍵の自動読み込み設定

上で作った鍵を使って github とやり取りをするには、
ssh-agent を立ち上げた後に ssh-add で鍵を登録すればいいのだけど、毎回やりたくないので、`.bashrc`もしくは `.zshrc`に以下を追加する

.zshrc

```
#SSH
eval `ssh-agent` > /dev/null
ssh-add /home/ユーザ名/.ssh/id_rsa >& /dev/null
```

これで読み込みなおすと SSH が通る

```
$ source .zshrc
$ ssh -T git@github.com

Hi ludwig125! You've successfully authenticated, but GitHub does not provide shell access.
[~] $
```

参考

- https://qiita.com/satto_sann/items/9d95241af81dc4466ee1
- https://qiita.com/sshojiro/items/60982f06c1a0ba88c160
- https://qiita.com/yoshioms/items/6e2039d58fe19ab61b5f

## default の Python を Python3 に変更

```
$python3 --version
Python 3.6.9
```

python3.7 を入れたかったら以下

```
$sudo apt update
$sudo apt install python3.7

$python3.7 --version
Python 3.7.5
```

.zshrc(または.bashrc)に以下の alias を追加

- ここでは python3.6 を使う例を書く

```
alias python=/usr/bin/python3.6
```

.zshrc の再読み込み

```
source ~/.zshrc
```

## Go 言語の環境構築

apt install では 1.10 が入った

```
$apt-get install golang
```

```
$go version
go version go1.10.4 linux/amd64
```

最新は 1.14.4(2020/6/3 時点)なので、これにしたい

公式

- https://golang.org/dl/

download

```
$wget https://dl.google.com/go/go1.14.4.linux-amd64.tar.gz
```

`-C`で`/usr/local`以下に解凍

```
$which go
/usr/bin/go
$sudo tar -C /usr/local -xzf go1.14.4.linux-amd64.tar.gz
```

パスを通す

- 自分の環境では GOPATH を C ドライブ直下に作っている

```
$export GOROOT=/usr/local/go
$export GOPATH=/home/ludwig125/go
$echo $GOPATH
/home/ludwig125/go
$export PATH=$GOPATH/bin:$GOROOT/bin:$PATH
```

バージョン確認

```
$go version
go version go1.14.4 linux/amd64
```

後片付け

```
$rm -rf go1.14.4.linux-amd64.tar.gz
```

参考

- https://ludwig125.hatenablog.com/entry/2019/08/16/055234
- https://xn--go-hh0g6u.com/doc/code.html

## Docker のインストールと実行

#### install 手順

- [Install Docker Engine on Ubuntu](https://docs.docker.com/engine/install/ubuntu/) に従う

#### 実行するコマンド

```
$ sudo apt-get remove docker docker-engine docker.io containerd runc

$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

$ sudo apt-key fingerprint 0EBFCD88

$ sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable"

$ sudo apt-get install docker-ce docker-ce-cli containerd.io
```

#### WSL で Docker を起動させる時の注意点

普通に WindowsTerminal で以下を実行しても起動してくれない

- `Cannot connect to the Docker daemon at unix:///var/run/docker.sock. Is the docker daemon running?`が出る

```
$ sudo service docker start
 * Starting Docker: docker                                                                                       [ OK ]
$sudo service docker status
 * Docker is not running
$sudo docker ps
Cannot connect to the Docker daemon at unix:///var/run/docker.sock. Is the docker daemon running?
```

そこで、以下のように、Windows キーから「管理者として実行」で起動して、

![image](https://user-images.githubusercontent.com/18366858/92527936-d73c6e00-f262-11ea-992e-6425a2e3610c.png)

以下のコマンドで実行できる

```
$sudo cgroupfs-mount
$sudo service docker start
 * Starting Docker: docker                                                                                       [ OK ]
$sudo service docker status
 * Docker is running
 [~] $sudo docker version
Client:
 Version:           18.06.1-ce
 API version:       1.38
 Go version:        go1.10.3
 Git commit:        e68fc7a
 Built:             Tue Aug 21 17:24:51 2018
 OS/Arch:           linux/amd64
 Experimental:      false

Server:
 Engine:
  Version:          18.06.1-ce
  API version:      1.38 (minimum version 1.12)
  Go version:       go1.10.3
  Git commit:       e68fc7a
  Built:            Tue Aug 21 17:23:15 2018
  OS/Arch:          linux/amd64
  Experimental:     false
[~] $
[~] $sudo docker info
Containers: 0
 Running: 0
 Paused: 0
 Stopped: 0
Images: 3
Server Version: 18.06.1-ce
Storage Driver: overlay2
 Backing Filesystem: extfs
 Supports d_type: true
 Native Overlay Diff: true
Logging Driver: json-file
Cgroup Driver: cgroupfs
Plugins:
 Volume: local
 Network: bridge host macvlan null overlay
 Log: awslogs fluentd gcplogs gelf journald json-file logentries splunk syslog
Swarm: inactive
Runtimes: runc
Default Runtime: runc
Init Binary: docker-init
containerd version: 468a545b9edcd5932818eb9de8e72413e616e86e
runc version: 69663f0bd4b60df09991c08812a60108003fa340
init version: fec3683
Security Options:
 seccomp
  Profile: default
Kernel Version: 4.19.128-microsoft-standard
Operating System: Ubuntu 18.04.4 LTS
OSType: linux
Architecture: x86_64
CPUs: 8
Total Memory: 18.68GiB
Name: DESKTOP-4ND5CO6
ID: T2GO:FLNU:7V54:BBUR:Z73C:6PBD:IDSU:626F:3GPH:KP6A:AN4N:KHD2
Docker Root Dir: /var/lib/docker
Debug Mode (client): false
Debug Mode (server): false
Registry: https://index.docker.io/v1/
Labels:
Experimental: false
Insecure Registries:
 127.0.0.0/8
Live Restore Enabled: false

[~] $
```

```
[~] $sudo docker container ls --all
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
[~] $sudo docker run --rm -it golang
Unable to find image 'golang:latest' locally
latest: Pulling from library/golang
57df1a1f1ad8: Pull complete
71e126169501: Pull complete
1af28a55c3f3: Pull complete
03f1c9932170: Pull complete
f4773b341423: Pull complete
fb320882041b: Pull complete
24b0ad6f9416: Pull complete
Digest: sha256:02a77fbfbc4ec0e2d14e9583b955ff1c7282eafa6b0ed883dd92bc08613f5d64
Status: Downloaded newer image for golang:latest
root@e81e1c28abe6:/go#
root@e81e1c28abe6:/go# uname -a
Linux e81e1c28abe6 4.19.128-microsoft-standard #1 SMP Tue Jun 23 12:58:10 UTC 2020 x86_64 GNU/Linux
root@e81e1c28abe6:/go#
```

#### 参考

docker を WSL で動かす

- https://www.reddit.com/r/bashonubuntuonwindows/comments/8cvr27/docker_is_running_natively_on_wsl/

cgroupfs-mount

- http://manpages.ubuntu.com/manpages/bionic/man8/cgroupfs-mount.8.html
- https://launchpad.net/ubuntu/xenial/amd64/cgroupfs-mount/1.2

cgroup

- https://gihyo.jp/admin/serial/01/linux_containers/0003?page=2
- https://man7.org/linux/man-pages/man7/cgroups.7.html
- https://thinkit.co.jp/article/17269

## Visual Studio Code(vs code)のインストール

https://code.visualstudio.com/docs/remote/wsl

- 公式ドキュメント

https://qiita.com/nj_ryoo0/items/a42c47436b77310f5430

などを参考に入れた。

#### VSCode インストール

1. windows 側に VSCode インストール

- https://code.visualstudio.com/

2. vs code を開いて、Remote Development の拡張機能をインストール

- https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack

3. WSL 側で `/mnt/c(Cドライブ直下)` にいって、以下で VSCode を開く

```
code .
```

初回だけ時間がかかるけど、次回以降は速い

VSCode で `Ctrl+Shift+p` で「Remote-WSL: New Window using Distro 」を選んで default が Ubuntu になっていることを確認しておく

#### VSCode ショートカットキー追加

`Ctrl+Shift+P`でコマンドパレットを表示して、「shortcuts」で検索して「基本設定: キーボードショートカットを開く」を選択
![image](https://user-images.githubusercontent.com/18366858/83568109-a2cb5e80-a55d-11ea-85b4-6800be27d288.png)

自分の好みで以下のような設定を追加

参考：https://github.com/microsoft/vscode-docs-archive/blob/master/docs/editor/integrated-terminal.md

https://code.visualstudio.com/docs/getstarted/keybindings#_basic-editing

```
// 既定値を上書きするには、このファイル内にキー バインドを挿入しますauto[]
[
    {
        "key": "win+oem_3",
        "command": "workbench.action.terminal.focus",
        "when": "editorFocus"
    },
    {
        "key": "win+oem_3",
        "command": "workbench.action.focusActiveEditorGroup",
        "when": "terminalFocus"
    },
    {
        "key": "ctrl+shift+n",
        "command": "explorer.newFolder"
    },
    {
        "key": "ctrl+n",
        "command": "explorer.newFile"
    }
]
```

- `win+oem_3` は `` Win+`  ``を押すたびにエディタとターミナルを切り替えるという意味
  - これは当初 `` Ctrl+`  `` にしてみたけど、後述の理由によりうまくいかないので「Win ＋`」に変更した
- `ctrl+shift+n` で新しいフォルダを作成
- `ctrl+n` で新しいファイルを作成

UI でキーボードショートカットを見ると以下のようになっている
![image](https://user-images.githubusercontent.com/18366858/83567763-102abf80-a55d-11ea-9205-e15ac3ad9a19.png)

#### VSCode で 「Ctrl+ `」（Ctrl ＋バッククオート）が機能しない問題について

<details><summary>詳細は折り畳み</summary><div>

自分は日本語環境で US 配列のキーボードを使っているのだけど、ショートカットキーとして、
`` ctrl+`  ``が他のキーに割り当てられていて機能しないことがわかった（正確には「`` ` ``」が機能しない）

- バッククオートは全角半角に割り当てられているっぽい

参考

- https://github.com/Microsoft/vscode/issues/63659
- https://qiita.com/uraxurax/items/c95936595cffd9cb85b0

対応方法

以下を参考に英語入力ができるようにしてみた

https://support.microsoft.com/ja-jp/help/4496404/windows-10-manage-the-input-and-display-language#input_language

> [スタート] ボタンを選択し、[設定] > [時刻と言語] > [言語] の順に選択します。
> [優先する言語] で、目的のキーボードが含まれる言語を選択し、[オプション] を選択します。
> [キーボードの追加] を選択し、追加するキーボードを選択します。目的のキーボードが表示されない場合は、新しい言語を追加して追加のオプションを取得する必要があります。この場合は、手順 4 に進みます。
> [言語の設定] ページに戻り、[言語の追加] を選択します。

こんな感じ
![image](https://user-images.githubusercontent.com/18366858/83569373-52550080-a55f-11ea-84b0-270301f1c275.png)

こう設定して一度サインアウトしなおすと、英語入力ができるようになる

こうすると、普段の入力については、Windows の右下に以下のように表示される
![image](https://user-images.githubusercontent.com/18366858/83569682-d3ac9300-a55f-11ea-99c5-d6bb35f87ea6.png)

ここで「Win + Space」を押すと、こんな感じに切り替わるので、

![image](https://user-images.githubusercontent.com/18366858/83569807-08b8e580-a560-11ea-954c-aace3835dc70.png)

この状態であれば Visual Studio で「Ctrl+`」が認識されるようになった。。

（がちょっとめんどくさいので結局 `` Ctrl+` ``は挫折して`` Win+`  ``に変更した）

</div></details>

#### git の PATH が通っていないといわれる

VS Code で以下のエラーが出た

![image](https://user-images.githubusercontent.com/18366858/85337900-518b0b00-b51c-11ea-94a4-c4a5fb48d236.png)

https://va2577.github.io/post/83/
https://github.com/Microsoft/vscode/issues/28315

こちらを参考に以下をした

Windows のホームディレクトリ以下に以下を追加

```
$pwd
/mnt/c/wsl
$cat git.bat
@echo off
bash -c 'git %*'
```

このファイルを読み込むために VS Code の settings.json に以下を追加

```
    "terminal.integrated.shell.windows": "C:\\WINDOWS\\System32\\wsl.exe", ← これはもともとあった設定だけど必要
    "git.path": "C:\\wsl\\git.bat"
```

#### Go のパスがおかしいと言われた

![image](https://user-images.githubusercontent.com/18366858/85465398-b78e9580-b5e3-11ea-8116-5204f5fc1e0e.png)

> Failed to Run "go env" to find GOPATH as the "go"binary

これは WSL ではなくて Windows を見ている。。？

- `Ctrl+Shift+P` で`Remote-WSL: New Window using Distro` から `Ubuntu` を選択
- WSL： Ubuntu としてフォルダを開きなおせば解決した

一応 settings.json にも以下を追加しておく

```
    "go.gopath": "/mnt/c/wsl/go",  // GOPATH
    "go.goroot": "/usr/local/go",  // GOROOT
```

#### tag が解決できない

自分の Go コードでは、test ファイルのタグに

```
// +build integration
```

や

```
// +build !integration
```

を使用している

このままだときちんと認識してくれずインテリセンスなどが効かないことがあったので、

settings.json を以下のように設定している

- もっと簡単にできるかも知れないけどこれでうまくいっているからこのまま

```
    "go.toolsEnvVars": {
        "GOBIN": "/home/ludwig125/go/bin",
        "GOFLAGS": "-tags=integration"
    },
    "gopls": {
        "buildFlags": ["-tags=!integration"]
    },
```

起きたエラー

```
No packages found for open file ＜該当の_test.goファイル＞: <nil>.
If this file contains build tags, try adding "-tags=<build tag>" to your gopls "buildFlag" configuration (see (https://github.com/golang/tools/blob/master/gopls/doc/settings.md#buildflags-string).
Otherwise, see the troubleshooting guidelines for help investigating (https://github.com/golang/tools/blob/master/gopls/doc/troubleshooting.md).
```

参考 https://github.com/microsoft/vscode-go/issues/2808

## VSCode に入れている拡張機能

#### html

Prettier
https://marketplace.visualstudio.com/items?itemName=esbenp.prettier-vscode

https://rfs.jp/sb/vsc/vsc-prettier.html
https://qiita.com/rubytomato@github/items/d4716c41a2d15c64f791

拡張機能のフォーマッターを使うのでこちらは無効にしておく
![image](https://user-images.githubusercontent.com/18366858/141540290-9b23f6fd-5fee-4644-96e5-136fdcb3b702.png)
