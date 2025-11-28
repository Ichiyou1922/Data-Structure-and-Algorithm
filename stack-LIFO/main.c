#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
  Node *curr_stack = (Node *)malloc(sizeof(Node));
  push(&curr_stack, 100);
  printf("init: %d", curr_stack->data);

  push(&curr_stack, 200);
  peek(curr_stack);

  pop(&curr_stack);
  peek(curr_stack);
  return 0;
}

