#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
  Node *curr_stack = NULL;
  push(&curr_stack, 100);
  peek(curr_stack);

  push(&curr_stack, 200);
  peek(curr_stack);

  pop(&curr_stack);
  peek(curr_stack);

  push(&curr_stack, 300);
  peek(curr_stack);
  free_stack(&curr_stack);
  peek(curr_stack);
  return 0;
}

