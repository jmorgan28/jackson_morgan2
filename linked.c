#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {int i; struct node *next;};


void print_list(struct node *n){
  printf("[ ");
  printf("%d, ", (*n).i);
  while((*n).next != NULL){
    printf("%d, ", (*n).i);
  }
  printf("]");
}

struct node insert_front(struct node *n, int i){

}

struct node free_list(struct node *n){

}

int main(){
  struct node *f;
  f = (struct node *) malloc(sizeof(struct node));
  f->i = 4;
  print_list(f);

  return 0;
}
