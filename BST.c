#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  struct node *left;
  struct node *right;
}node;

node *insert(node *root, int value);
void inorder(node *root);
void free_tree(node *root);

int main(void){
  node *root = NULL;

  int n;
  printf("No. of elements: ");
  scanf("%i", &n);

  for(int i=0; i<n; i++){
    int value;
    printf("Number%i: ", i+1);
    scanf("%i", &value);
    root = insert(root, value);
  }

  inorder(root);
  printf("\n");

}

node *insert(node *root, int value){

  if(root == NULL){
    node *tmp = malloc(sizeof(node));
    tmp->value = value;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
  }

  if(value < root->value){
    root -> left = insert(root -> left, value);
    return root;
  }

  else if(value > root -> value){
    root -> right = insert(root -> right, value);
    return root;
  }

  else{
    return root;
  }
}

void inorder(node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%i ", root->value);
    inorder(root->right);
}

void free_tree(node *root){
  if(root == NULL){
    return;
  }
  free_tree(root ->left);
  free_tree(root -> right);

  free(root);
}