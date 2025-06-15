# このリポジトリについて
個人的に使用しているAtCoder用環境を公開しています。
特に理由はないですが、online judge toolsやmakefileをベースに動かしています。
エディターはVS Codeを使用しています。
WSL2(bash)、Mac(zsh)の両方でも使えるようにしたいです。
まだまだ改善点があると思いますので、詳しい方ぜひissue/PRいただけると嬉しいです！

## 使用方法
### 事前準備
- homebrew, python(3.12), pipxインストール推奨

- [online judge tools](https://github.com/online-judge-tools/oj/blob/master/README.ja.md)をインストール
```
$ pip3 install --user online-judge-tools
```
- ojがAtCoderにログイン
`oj login https://atcoder.jp/` or `make login`

### コンテスト中
1. `make init`で古いコード・テストケースを削除
2. main.cpp に　C++のコードを書く
3. `oj d <URL>`で公式のテストケースをDL
4. `make`コマンドでコンパイル＋テスト実行＋通ってたら提出もしてくれる。

#### チートシート
- 「絶対誤差あるいは相対誤差で 10⁻⁶ 以内の出力を正答とします」
`make e 1e-6`

- ターミナルと対話式
`oj t/r`コマンドがあるが、テストケースをAtCoder側で用意していなければ使用不可。代わりにサンプルテストケースを`/self_testcases`で定義し、`make self`でコンパイル＋実行結果を見る。大丈夫なら手動で提出。


## 参考記事
[【VScode + WSL / Windows】C++ 用の AtCoder 向け環境構築をしてみた。(WSL導入からGitによるソースコード管理まで)](https://yuulis.hatenablog.com/entry/atcoder-cpp-env-build#%E3%81%8A%E3%81%BE%E3%81%91WSL-%E3%81%AE%E3%83%87%E3%82%A3%E3%82%B9%E3%83%88%E3%83%AA%E3%83%93%E3%83%A5%E3%83%BC%E3%82%B7%E3%83%A7%E3%83%B3%E3%82%92%E5%89%8A%E9%99%A4%E3%81%97%E3%81%A6%E3%82%84%E3%82%8A%E7%9B%B4%E3%81%99%E5%A0%B4%E5%90%88)
[VSCodeで競技プログラミング環境（C++）を構築してみた](https://zenn.dev/gnz/articles/361773e44fcc41)
