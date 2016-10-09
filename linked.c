#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {int i; struct node *next;};


void print_list(struct node *n){
  if(n == NULL){
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
  temp = n;
  while((*temp).next != NULL){
    struct node *temp1;
    temp1 = (struct node *) malloc(sizeof(struct node));
    temp = (*temp).next;
    free(temp1);
    temp1 = NULL;
  }
  n= NULL;
  return n;
}



int main(){
  struct node *f;
  f = (struct node *) malloc(sizeof(struct node));
  f->i = 4;
  printf("new struct node f made with value 4\n");
  printf("the result of print_list(f): ");
  print_list(f);
  printf("stuct node g = insert_front(f,6)\n");
  printf("the result of print_list(g): ");
  insert_front(f, 6);
  struct node *g;
  g = (struct node *) malloc(sizeof(struct node));
  g = insert_front(f, 6);
  print_list(g);
  printf("stuct node g = insert_front(g,16)\n");
  g = insert_front(g, 16);
  printf("the result of print_list(g): ");
  print_list(g);
  g = insert_front(g, -504);
  printf("stuct node g = insert_front(g,-504)\n");
  printf("the result of print_list(g): ");
  print_list(g);
  printf("print_list(free_list(g)) is called and we get: ");
  print_list(free_list(g));
  return 0;
}
