#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int number;
  struct node *next;
  struct node *previous;
}node;