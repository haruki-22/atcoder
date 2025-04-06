### 事前準備
- homebrew, python(3.12), pipxインストール推奨

- [online judge tools](https://github.com/online-judge-tools/oj/blob/master/README.ja.md)をインストール
```
$ pip3 install --user online-judge-tools
```
- ojがAtCoderにログイン
`oj login https://atcoder.jp/` or `make login`

### 試合中
1. `make init`で古いコード・テストケースを削除
2. main.cpp に　C++のコードを書く
3. `oj d <URL>`で公式のテストケースをDL
4. `make`コマンドでコンパイル＋テスト実行＋通ってたら提出もしてくれる。

#### チートシート
- 「絶対誤差あるいは相対誤差で 10⁻⁶ 以内の出力を正答とします」
`make e 1e-6`

- ターミナルと対話式
`oj t/r`コマンドがあるが、テストケースをAtCoder側で用意していなければ使用不可。代わりにサンプルテストケースを`/self_testcases`で定義し、`make self`でコンパイル＋実行結果を見る。大丈夫なら手動で提出。
