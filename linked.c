#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {int i; struct node *next;};


void print_list(struct node *n){
  if(n->i == NULL && n->next == NULL){
    printf("[]");
    return;
  }
  struct node *temp;
  temp = (struct node *) malloc(sizeof(struct node));
  temp = n;
  printf("[ ");
  printf("%d, ", (*n).i);
  while((*temp).next != NULL){
    temp = (*temp).next;
    printf("%d, ", (*temp).i);
  }
  printf("]\n");
}

struct node * insert_front(struct node *n, int i){
  struct node *temp;
  temp = (struct node *) malloc(sizeof(struct node));
  temp->i = i;
  temp->next = n;
  return temp;
}
 
struct node * free_list(struct node *n){
  struct node *temp;
  temp = (struct node *) malloc(sizeof(struct node));
  //struct node *ret;
  //ret = (struct node *) malloc(sizeof(struct node));
  temp = n;
  free((n->i));
  while((*temp).next != NULL){
    struct node *temp1;
    temp1 = (struct node *) malloc(sizeof(struct node));
    temp = (*temp).next;
    free((*temp1).next);
    free((*temp).i);
  }
  n->i = NULL;
  n->next = NULL;
  
  return n;
}



int main(){
  struct node *f;
  f = (struct node *) malloc(sizeof(struct node));
  f->i = 4;
  print_list(f);
  insert_front(f, 6);
  struct node *g;
  g = (struct node *) malloc(sizeof(struct node));
  g = insert_front(f, 6);
  print_list(g);
  print_list(g);
  g = insert_front(g, 16);
  print_list(g);
  print_list(free_list(g));  
  return 0;
}
