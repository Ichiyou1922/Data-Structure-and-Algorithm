/*
push:
1. mallocでノードを作る
->関数の中で宣言された変数は関数が終わるとメモリから消去される．
->main関数に戻った時topが指すのはメモリ解放後の跡地．
->関数が終わっても消えないメモリがヒープ領域でありmalloc
Node *new_node = (Node *)malloc(sizeof(Node));では何をしている？
->sizeof(Node)で必要なメモリサイズを計算する．
->malloc(...)でヒープ領域からメモリを確保するよう要求．freeされるまで解放されない．
->mallocで返されるのはvoid * だからこれを(Node *)でキャスト(型変換)する．
2. 新ノードのnextに現在のトップ(*top)を入れる
3. (*top)を新ノードに書き換える

pop:
1. 空チェック(*top == NULL)
2. 現在のトップ(*top)を一時変数tempに保存
3. データを取り出す(int val = temp->data)
4. トップ(*top)をtemp->nextに進める
5. free(temp)する
6. データを返す

なぜポインタのポインタ？
関数の戻り値がintとして埋まっているため，関数内で変数の変更を行いたいから．
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

bool push(Node **top, int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    printf("Something is wrong...\n");
    return false;
  }

  new_node->data = data;

  new_node->next = *top;
  *top = new_node; // 代入の向きが逆だった．修正．new_nodeが参照されるべきところ．
  return true;
}

int pop(Node **top) {
  if (*top == NULL) {
    printf("Stack is empty...\n");
    return -1;
  }
  Node *temp = *top;
  int val = temp->data;
  *top = temp->next;
  free(temp);
  return (val);
}

int peek(Node *top) {
  if (top == NULL) {
    printf("Not exist the value...\n");
    return -1;
  }
  printf("Top value is %d\n", top->data);
  return 0;
}

void free_stack(Node **top) {
    Node *current = *top; // 現在位置記録
    Node *temp_next; // 次の位置を仮に取っておく
    
    while (current != NULL) {
      temp_next = current->next; //仮に取っておく
      free(current); // 現在位置を解放
      current = temp_next; // 現在位置を更新
    }
    *top = NULL;
}
