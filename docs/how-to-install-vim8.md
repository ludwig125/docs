# vim8のインストール方法

OSのバージョン：Ubuntu 14.04
※ Ubuntu 16.04でも以下と同じ方法でできるっぽい

## 現在のvimの確認

現在のvimのバージョンは以下で確認できる

#### 方法１．vim --version

自分が実行したときの出力結果
```
[~] $vim --version                                
VIM - Vi IMproved 7.4 (2013 Aug 10, compiled Dec 18 2015 21:31:31)
適用済パッチ: 1-882
Modified by pkg-vim-maintainers@lists.alioth.debian.org
Compiled by buildd@
以下省略
```

#### 方法２．dpkg -l vim

自分が実行したときの出力結果
```
[~] $dpkg -l vim
要望=(U)不明/(I)インストール/(R)削除/(P)完全削除/(H)保持
| 状態=(N)無/(I)インストール済/(C)設定/(U)展開/(F)設定失敗/(H)半インストール/(W)トリガ待ち/(T)トリガ保留
|/ エラー?=(空欄)無/(R)要再インストール (状態,エラーの大文字=異常)
||/ 名前                バージョン     アーキテクチャ 説明
+++-===================-==============-==============-===========================================
ii  vim                 2:7.4.826-1+da amd64          Vi IMproved - enhanced vi editor
[~] $
```
## 最新のvimのインストール

以下の３つのコマンドをさえすればOK
参考：http://tipsonubuntu.com/2016/09/13/vim-8-0-released-install-ubuntu-16-04/
```
sudo add-apt-repository ppa:jonathonf/vim
sudo apt update
sudo apt install vim
```

#### 上のコマンドの意味

###### add-apt-repository

UbuntuではPPA（Personal Package Archives）というUbuntu非公式のソフトウェアを管理しているアーカイブをPPAというらしい
参考：https://allabout.co.jp/gm/gc/438675/

sudo add-apt-repository ppa:jonathonf/vim コマンドによって、PPAのvimのリポジトリをこのUbuntuに認識させる

###### sudo apt update

パッケージの一覧を更新
リポジトリ追加・削除時には必ず実行するべきコマンド


###### sudo apt install vim
これで最新のvimをインストールすることができる


## vimのバージョン確認
```
[~] $vim --version                                

VIM - Vi IMproved 8.1 (2018 May 17, compiled May 23 2018 13:04:51)
適用済パッチ: 1-20
Modified by pkg-vim-maintainers@lists.alioth.debian.org
Compiled by pkg-vim-maintainers@lists.alioth.debian.org
以下省略
```

```
[~] $dpkg -l vim
要望=(U)不明/(I)インストール/(R)削除/(P)完全削除/(H)保持
| 状態=(N)無/(I)インストール済/(C)設定/(U)展開/(F)設定失敗/(H)半インストール/(W)トリガ待ち/(T)トリガ保留
|/ エラー?=(空欄)無/(R)要再インストール (状態,エラーの大文字=異常)
||/ 名前                バージョン     アーキテクチャ 説明
+++-===================-==============-==============-===========================================
ii  vim                 2:8.1.0020-0yo amd64          Vi IMproved - enhanced vi editor
[~] $
```

おわり
