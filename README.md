# Data-Structure-and-Algorithm
データ構造とアルゴリズムについてC言語を用いて理解するためのリポジトリ

## stack-LIFO
### push:
1. mallocでノードを作る
- 関数の中で宣言された変数は関数が終わるとメモリから消去される．
- main関数に戻った時topが指すのはメモリ解放後の跡地．
- 関数が終わっても消えないメモリがヒープ領域でりmalloc．
- Node *new_node = (Node *)malloc(sizeof(Node));では何をしている？  
  - sizeof(Node)で必要なメモリサイズを計算する．
  - malloc(...)でヒープ領域からメモリを確保するよう要求．freeされるまで解放されない．
  - mallocで返されるのはvoid * だからこれを(Node *)でキャスト(型変換)する．
2. 新ノードのnextに現在のトップ(*top)を入れる
3. (*top)を新ノードに書き換える

### pop:
1. 空チェック(*top == NULL)↲
2. 現在のトップ(*top)を一時変数tempに保存 
3. データを取り出す(int val = temp->data)
4. トップ(*top)をtemp->nextに進める                 
5. free(temp)する 
6. データを返す
### なぜポインタのポインタ？
関数の戻り値がintとして埋まっているため，関数内で変数の変更を行いたいから．










