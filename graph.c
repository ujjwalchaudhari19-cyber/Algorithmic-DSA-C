#include <stdio.h>

int main(void){
  int graph[4][4];
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      graph[i][j]=0;
    }
  }

  graph[0][1] = 1;
  graph[1][0] = 1;
  graph[1][2] = 1;
  graph[2][1] = 1;
  graph[2][3] = 1;
  graph[3][2] = 1;

  for(int i =0; i<4; i++){
    for(int j = 0; j<4; j++){
      printf("%i", graph[i][j]);
    }
    printf("\n");
  }
}