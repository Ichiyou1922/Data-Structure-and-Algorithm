#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// ノードの定義
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// スタック操作関数

// 新しい値をスタックの頂上に積む
// 成功したら true, メモリ不足などで失敗したら false を返す
bool push(Node **top, int data);

// スタックの頂上から値を取り出す
// 成功したらその値を返し、スタックから削除する
// スタックが空の場合は -1 (エラー値) を返し、標準エラー出力にメッセージを出す
int pop(Node **top);

// スタックの頂上の値を見る（削除はしない）
// 空なら -1 を返す
int peek(Node *top);

// スタックを全て解放する
void free_stack(Node **top);

#endif
