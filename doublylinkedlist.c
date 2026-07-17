#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int number;
  struct node *next;
  struct node *previous;
}node;

node* insert(node *list, int value);

int main(void){
  node *head =NULL ;
  node *previous;

  int n;
  printf("Number of nodes: ");
  scanf("%i", &n);

  for(int i=0; i<n; i++){
    int value;
    printf("Number%i: ", i+1);
    scanf("%i", &value);
    head = insert(head, value);
  }

  node *ptr = head;
  while(ptr != NULL){
    printf("%i ", ptr -> number);
    ptr = ptr -> next;
  }
  printf("\n");

  ptr = head;
  while(ptr != NULL){
    node *next = ptr -> next;
    free(ptr);
    ptr = next;
  }
}

node* insert(node *list, int value){
  node *tmp = malloc(sizeof(node));
  if(tmp == NULL){
    return NULL;
  }
  tmp -> previous = NULL;
  tmp -> number = value;
  tmp -> next = list;

  if(list != NULL){
    list -> previous = tmp;
  }
  return tmp;
}