# Push_swap - スタックソートプログラム

## 概要
**Push_swap** は、42Tokyoの課題の一つで、2つのスタックを用いて数値のリストをソートするアルゴリズムを設計・実装するプロジェクトです。この課題では、制約条件下で効率的なソートアルゴリズムを構築し、プログラムの最適化を図ります。

---

## プロジェクトの目的
1. **データ構造とアルゴリズムの理解**：
   - スタック操作を通じたソートアルゴリズムの構築。
2. **最適化と効率化**：
   - 操作回数を最小限に抑える最適化手法の学習。
3. **C言語の実践力強化**：
   - 動的メモリ管理やエラーハンドリングを駆使した設計。
4. **テストとデバッグのスキル向上**：
   - コーナーケースへの対応とデバッグ手法の習得。

---

## 実装要件
1. **データ構造**：
   - スタックAとスタックBの2つを使用。
2. **操作制約**：
   - 与えられた操作セットのみでソートを実行。
3. **効率性の追求**：
   - 最小手数でのソートアルゴリズムを実装。
4. **コード規約の遵守**：
   - 42のノーム規約に準拠すること。

---

## 使用方法
### 必要環境
- LinuxまたはmacOS。
- `make` コマンドと `gcc` コンパイラがインストールされていること。

### コンパイル
```
make
```
### 実行
```
./push_swap <リスト>
```
例：
```
./push_swap 5 2 1 4 3
```

### チェッカー
```
./checker <リスト>
```
例：
```
ARG="5 2 1 4 3"; ./push_swap $ARG | ./checker_OS $ARG
```

---

## 使用可能な操作
| 操作           | 説明                                          |
|----------------|----------------------------------------------|
| sa             | スタックAの先頭2つの要素を交換します           |
| sb             | スタックBの先頭2つの要素を交換します           |
| ss             | saとsbを同時に実行します                      |
| pa             | スタックBからスタックAへ先頭要素を移動します   |
| pb             | スタックAからスタックBへ先頭要素を移動します   |
| ra             | スタックAを1つ上方向に回転します               |
| rb             | スタックBを1つ上方向に回転します               |
| rr             | raとrbを同時に実行します                      |
| rra            | スタックAを1つ下方向に回転します               |
| rrb            | スタックBを1つ下方向に回転します               |
| rrr            | rraとrrbを同時に実行します                     |

---

## 課題の学びポイント
- **アルゴリズム設計**：
  効率的なソートアルゴリズムの構築と最適化。
- **データ構造の操作**：
  スタックを使用した動的データ処理の理解。
- **最小操作数の追求**：
  実行ステップを最小限に抑えるアルゴリズムの分析と改善。
- **デバッグとテスト技術**：
  入力エラーや境界条件への対応力強化。

---

## 参考リンク
- [42Tokyo公式ページ](https://42tokyo.jp/)
- [Push_swap課題仕様書](https://github.com/42tokyo/push_swap)

---

## ライセンス
このプロジェクトは42Tokyoの課題の一部であり、教育目的で使用されます。再配布や商用利用は制限される場合があります。

# Push_swap テストケース

## 基本的なテストケース
# 5個の数字のテスト
```bash
ARG="5 2 1 4 3"; ./push_swap $ARG | ./checker_OS $ARG
```

# 3個の数字のテスト
```bash
ARG="3 1 2"; ./push_swap $ARG | ./checker_OS $ARG
```

# 4個の数字のテスト
```bash
ARG="4 1 3 2"; ./push_swap $ARG | ./checker_OS $ARG
```

## より複雑なテストケース
# 10個の数字のテスト
```bash
ARG="10 7 5 3 8 2 9 1 6 4"; ./push_swap $ARG | ./checker_OS $ARG
```

# 重複を含まないランダムな数字のテスト（シェル関数を使用）
```bash
ARG=`seq 1 100 | sort -R | head -n 20 | tr '\n' ' '`; ./push_swap $ARG | ./checker_OS $ARG
```

## エッジケース
# 既にソートされている配列
```bash
ARG="1 2 3 4 5"; ./push_swap $ARG | ./checker_OS $ARG
```

# 逆順の配列
```bash
ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker_OS $ARG
```

# 負の数を含む配列
```bash
ARG="-5 -2 0 3 1"; ./push_swap $ARG | ./checker_OS $ARG
```

# 大きな数値を含む配列
```bash
ARG="2147483647 -2147483648 0 42 -42"; ./push_swap $ARG | ./checker_OS $ARG
```

# 同じような数値が近接している配列
```bash
ARG="10000 10001 10002 9999 10003"; ./push_swap $ARG | ./checker_OS $ARG
```

# 大きな数値の差がある配列
```bash
ARG="1000000 1 5000000 2 9999999"; ./push_swap $ARG | ./checker_OS $ARG
```

# 全て負の数の配列
```bash
ARG="-5 -1 -4 -2 -3"; ./push_swap $ARG | ./checker_OS $ARG
```

# 2つの要素のみの配列
```bash
ARG="2 1"; ./push_swap $ARG | ./checker_OS $ARG
```

# 1つの要素のみの配列
```bash
ARG="42"; ./push_swap $ARG | ./checker_OS $ARG
```

# 大量の要素（100個）のテスト
```bash
ARG=`seq 1 100 | sort -R | tr '\n' ' '`; ./push_swap $ARG | ./checker_OS $ARG
```

# 大量の要素の操作回数確認
```bash
ARG=`seq 1 100 | sort -R | tr '\n' ' '`; ./push_swap $ARG | wc -l
```

# 特殊なパターン：交互に大小が並ぶ配列
```bash
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG
```

# 特殊なパターン：ほぼソート済みの配列（1要素のみ異なる）
```bash
ARG="1 2 3 5 4"; ./push_swap $ARG | ./checker_OS $ARG
```

# 特殊なパターン：最大値が真ん中にある配列
```bash
ARG="1 2 5 3 4"; ./push_swap $ARG | ./checker_OS $ARG
```

# 特殊なパターン：最小値が真ん中にある配列
```bash
ARG="2 3 1 4 5"; ./push_swap $ARG | ./checker_OS $ARG
```

## 中規模テストケース
# 15個の数字のテスト
```bash
ARG="15 7 3 12 19 4 8 11 1 13 5 17 9 2 6"; ./push_swap $ARG | ./checker_OS $ARG
```

# 20個の数字のテスト
```bash
ARG="20 15 7 3 12 19 4 8 11 1 13 5 17 9 2 6 16 14 10 18"; ./push_swap $ARG | ./checker_OS $ARG
```

## 特殊パターンテスト
# フィボナッチ数列を含む配列
```bash
ARG="1 1 2 3 5 8 13 21 34 55"; ./push_swap $ARG | ./checker_OS $ARG
```

# 素数のみの配列
```bash
ARG="2 3 5 7 11 13 17 19 23 29"; ./push_swap $ARG | ./checker_OS $ARG
```

# 2の累乗の配列
```bash
ARG="1 2 4 8 16 32 64 128 256 512"; ./push_swap $ARG | ./checker_OS $ARG
```

## サイズ別テスト
# 50個の要素テスト
```bash
ARG=`seq 1 50 | sort -R | tr '\n' ' '`; ./push_swap $ARG | ./checker_OS $ARG
```

# 75個の要素テスト
```bash
ARG=`seq 1 75 | sort -R | tr '\n' ' '`; ./push_swap $ARG | ./checker_OS $ARG
```

## パフォーマンステスト
# 50個の要素の操作回数
```bash
ARG=`seq 1 50 | sort -R | tr '\n' ' '`; ./push_swap $ARG | wc -l
```

# 75個の要素の操作回数
```bash
ARG=`seq 1 75 | sort -R | tr '\n' ' '`; ./push_swap $ARG | wc -l
```

## 追加エッジケース
# 3つおきに並んだ数列
```bash
ARG="1 4 7 2 5 8 3 6 9"; ./push_swap $ARG | ./checker_OS $ARG
```

# 5つおきに並んだ数列
```bash
ARG="1 6 11 16 2 7 12 17 3 8 13 18 4 9 14 19 5 10 15 20"; ./push_swap $ARG | ./checker_OS $ARG
```

# 前半昇順・後半降順の配列
```bash
ARG="1 3 5 7 9 10 8 6 4 2"; ./push_swap $ARG | ./checker_OS $ARG
```

# 前半降順・後半昇順の配列
```bash
ARG="9 7 5 3 1 2 4 6 8 10"; ./push_swap $ARG | ./checker_OS $ARG
```

# 真ん中を軸に対称な配列
```bash
ARG="1 5 9 13 15 15 13 9 5 1"; ./push_swap $ARG | ./checker_OS $ARG
```

# 等差数列の配列
```bash
ARG="2 4 6 8 10 12 14 16 18 20"; ./push_swap $ARG | ./checker_OS $ARG
```

# 等比数列の配列
```bash
ARG="1 3 9 27 81 243 729 2187"; ./push_swap $ARG | ./checker_OS $ARG
```

