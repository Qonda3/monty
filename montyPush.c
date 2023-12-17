#include "monty.h"

/**
 * montyPush - add node to the stack
 * @head: stack head
 * @lineNumber: line number in file
 * Return: no return
*/

void montyPush(stack_t* stack, unsigned int line_number) {
char *buffer; 
  size_t len = 0;
  int value = 0;
  int sign = 1;
  FILE *fptr;
  char* mToken = strtok(buffer, " ");

  stack_t* new_node = malloc(sizeof(stack_t));
  if (!new_node) {
    printf("Error: malloc failed at line %u\n", line_number);
    exit(EXIT_FAILURE);
  }

  if (getline(&buffer, &len, fptr) == -1) {
    printf("Error: could not read line at line %u\n", line_number);
    exit(EXIT_FAILURE);
  }

  if (!mToken) {
    printf("Error: could not find integer at line %u\n", line_number);
    exit(EXIT_FAILURE);
  }

  if (*mToken == '-') {
    sign = -1;
    mToken++; 
  }

  while (*mToken != '\0' && *mToken != '\n') {
    if (*mToken < '0' || *mToken > '9') {
      printf("Error: invalid character in integer at line %u\n", line_number);
      exit(EXIT_FAILURE);
    }
    value = value * 10 + (*mToken - '0'); 
    mToken++;
  }

  value *= sign; 

  new_node->n = value;
  new_node->prev = NULL;
  new_node->next = stack;

  stack = new_node;
}

