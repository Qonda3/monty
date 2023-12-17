#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char *montyLine;
  FILE *fptr;
  stack_t *stack;
  int line_number;
  char *byteToken;
  size_t len;
  int linegot;
  int i;
  int numPushes = 0;

  if (argc != 2) {
    printf("Usage: ./push filename\n");
    exit(EXIT_FAILURE);
  }

  fptr = fopen(argv[1], "r");
  if (fptr == NULL) {
    printf("Error: could not open file\n");
    exit(EXIT_FAILURE);
  }

  while (!feof(fptr)) {
    montyLine = '\0';
    len = 0;
    linegot = getline(&montyLine, &len, fptr);
    if (linegot == -1) {
      break;
    }

    byteToken = strtok(montyLine, " ");
    if (byteToken != NULL && strcmp(byteToken, "push") == 0) {
      numPushes++;
    }
  }

  rewind(fptr);

  stack = malloc(sizeof(stack_t) * numPushes);
  if (stack == NULL) {
    printf("Error: malloc failed\n");
    exit(EXIT_FAILURE);
  }

  line_number = 1;

  while (!feof(fptr)) {
    montyLine = '\0';
    len = 0;
    linegot = getline(&montyLine, &len, fptr);
    if (linegot == -1) {
      break;
    }

    byteToken = strtok(montyLine, " ");

for (i = 0; i < numPushes; i++) {
  if (byteToken != NULL && strcmp(byteToken, "push") == 0) {
    montyPush(&stack[i], line_number);
    break;
  }
}
  line_number++;
  }

  free(stack);

  fclose(fptr);

  return 0;
}

