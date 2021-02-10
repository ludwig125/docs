Windowsで特定のアプリがすでに動いていたら最前面に、動いていなかったら起動させるショートカットキー

# 概要

ただの小ネタ

Windows Terminalをショートカットキーで最前面に持ってきたかった

# 背景

Macのターミナルアプリ iTerm2には HotKeyという機能があって、任意の指定したショートカットキーを打つだけで、ターミナルを最前面に持ってくることができる。
最前面の状態でHotKeyを押すと隠すこともできるのでとても便利だった


参考：[https://iterm2.com/documentation-hotkey.html:title]


Windowsで開発するときのWindows Terminalを起動したり最前面に持ってきたりできないか考えて、一番簡単な方法だと思ったことをメモする

# やったこと

Windowsのアプリはタスクバーの左から順にアプリ番号が割り当てられているのを利用した

以下の並びだと、以下のように番号が割り当てられているので、

- Windows Terminal: `1`
- Google Chrome: `2`
- Explorer: `3`


![image](https://user-images.githubusercontent.com/18366858/107575807-a73f2f80-6c33-11eb-9b2c-fa897314d20b.png)


WindowsTerminalは`Win+1`で起動できる。すでに起動している場合は最前面に出てくる

さすがにiTerm2のHotKeyと異なり最前面のアプリを後ろに隠すことはできなかったけど、一旦はこれで十分
