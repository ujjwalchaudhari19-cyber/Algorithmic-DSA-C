#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
  int number;
  struct node *next;
}node;

int main(void){
  node *head = NULL;
  int n;
  printf("Number of nodes: ");
  scanf("%i", &n);
  for(int i = 0; i<n; i++){
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL){
      return 1;
    }

    printf("Number%i: ", i+1);
    scanf("%i", &new_node->number);
    new_node -> next = NULL;

    new_node -> next = head;
    head = new_node;
  }

  node *ptr = head;
  while(ptr != NULL){
    printf("%i ", ptr -> number);
    ptr = ptr -> next;
  }
  printf("\n");

  return 0;
}