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
node* find_min(node *root);
node* delete(node *root, int value);

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

  int dlte;
  printf("Number to be deleted: ");
  scanf("%i", &dlte);
  root = delete(root, dlte);
  inorder(root);
  printf("\n"); 

  free_tree(root);
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

node* find_min(node *root){
  while(root -> left != NULL ){
    root = root -> left;
  }
  return root;
}

node *delete(node *root, int value){
  if(root == NULL){
    printf("Not found\n");
    return NULL;
  }

  if(value < root->value){
    root -> left = delete(root -> left, value);
    return root;
  }

  else if(value > root -> value){
    root -> right = delete(root -> right, value);
    return root;
  }

  else{
    if(root -> left == NULL && root -> right == NULL){
      free(root);
      return NULL;
    }

    else if(root -> left == NULL && root -> right != NULL){
     node *tmp = root -> right;
     free(root);
     return tmp; 
    }

    else if(root -> left != NULL && root -> right == NULL){
      node *tmp = root -> left;
      free(root);
      return tmp;
    }

    else{
      node *succssor = find_min(root -> right);
      root -> value = succssor -> value;
      root -> right = delete(root -> right, succssor->value);
      return root;
    }
  }
}

void free_tree(node *root){
  if(root == NULL){
    return;
  }
  free_tree(root ->left);
  free_tree(root -> right);

  free(root);
}