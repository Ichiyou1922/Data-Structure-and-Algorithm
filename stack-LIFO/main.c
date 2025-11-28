#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, const char *argv[]) {
  Node stack = (Node *)malloc(sizeof(Node));
  if (argc < 1) {
    printf("Usage: ./app pop | push [value]\n")
  }
  
  if (strcmp(argv[1], "push") == 0) {
    if (argc < 2) {
      printf("Usage: ./app push [value]\n");
    }
    
  }
}

