# gitのメールアドレスを非公開にする

## 参考にさせていただいたページ

https://ryoichi0102.hatenablog.com/entry/2017/10/12/000713

https://note.dokeep.jp/post/git-filter-branch-env-filter/

https://qiita.com/reikkk/items/aaff2b6656467de14a5e

https://tkhs0604.hatenablog.com/entry/github-email-exposure

https://stackoverflow.com/questions/59315277/will-changing-my-github-username-update-remove-attributions-using-the-noreply-em


## 自分のメールを確認

自分のアカウント設定 -> Settings -> メニューのEmails
から確認


![image](https://user-images.githubusercontent.com/18366858/106804668-08ea2180-66a9-11eb-8861-e5f9dfcfa3db.png)

Primary email addressにある自分のEmailアドレスの横の、「ID+username@users.noreply.github.com」を確認

例： `12345678+ludwig125@users.noreply.github.com`


![image](https://user-images.githubusercontent.com/18366858/106804699-16071080-66a9-11eb-8ff3-3b1ce22ad637.png)

自分の本来のEmailはPrivateにしておく

![image](https://user-images.githubusercontent.com/18366858/106804733-215a3c00-66a9-11eb-9473-c2765c467828.png)

## gitの設定を変更

```
[~] $git config --global --add user.email 12345678+ludwig125@users.noreply.github.com
[~] $git config --global --list | grep email
user.email=12345678+ludwig125@users.noreply.github.com
[~] $
```

これをすると、`~/.gitconfig` の設定も以下のように反映される

```
[user]
        name = ludwig125
        email = 18366858+ludwig125@users.noreply.github.com
```

## 過去のコミットログを編集

masterブランチで行う必要がある

例１： `GitHub` 以外がCommitしたコミットログ（＝自分）をすべて上記のEmailで書き換える
```
git filter-branch --force --env-filter 'if test "$GIT_COMMITTER_NAME" != "GitHub"; then GIT_COMMITTER_EMAIL="12345678+ludwig125@users.noreply.github.com"; fi; if test "$GIT_AUTHOR_NAME" != "GitHub"; then GIT_AUTHOR_EMAIL="12345678+ludwig125@users.noreply.github.com"; fi' --tag-name-filter cat -- --all
```


例２：問答無用で全部書き換える
```
git filter-branch --force --env-filter "GIT_AUTHOR_EMAIL='12345678+ludwig125@users.noreply.github.com'; GIT_COMMITTER_EMAIL='12345678+ludwig125@users.noreply.github.com';" --tag-name-filter cat -- --all
```

成功したらは以下のようにEmailが置き換わっているはず

```
[~/go/src/github.com/ludwig125/docs] $git log --pretty=full
commit 0e8db1b67403498d87a4089a6c74485af0ef5f0c (HEAD -> master, origin/master)
Author: ludwig125 <18366858+ludwig125@users.noreply.github.com>
Commit: ludwig125 <18366858+ludwig125@users.noreply.github.com>

    add

commit 8d5c400a1bd5f99061ff4b35f646bd04e14bd41f
Author: ludwig125 <18366858+ludwig125@users.noreply.github.com>
Commit: ludwig125 <18366858+ludwig125@users.noreply.github.com>
```

おわったらForce Push

```
git push --force origin --all
```
