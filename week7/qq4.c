#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *prev, *next;
};
typedef struct Node node;
struct Stock {
  node *head;
  node *tail;
};
typedef struct Stock stock;
node *create(int i);
void input(node **head, node **tail, int size);
void calc_stock_span(stock s, int *stock_span, int size);
void print_stock_span(int *stock_span, int size);
int main() {
  int size;
  printf("Enter the size:");
  scanf("%d", &size);
  int *stock_span = (int *)calloc(size, sizeof(int));
  stock s;
  s.head = NULL;
  s.tail = NULL;
  // s.head = create(0);
  // s.tail = s.head;
  input(&(s.head), &(s.tail), size);
  calc_stock_span(s, stock_span, size);
  print_stock_span(stock_span, size);
  return 1;
}
node *create(int i) {
  node *n = (node *)calloc(1, sizeof(node));
  printf("\nEnter the price of stock at day %d:", i);
  scanf("%d", &(n->data));
  n->prev = NULL;
  n->next = NULL;
  printf("nn %p %d \n", n, i);
  return n;
}
void input(node **head, node **tail, int size) {
  *head = create(1);
  *tail = *head;
  int i = 1;
  printf("before");
  while (i < size) {
    printf("\n%p\n", *tail);
    (*tail)->next = create(i + 1);
    printf("1");
    (*tail)->next->prev = *tail;
    printf("2");

    (*tail) = (*tail)->next;
    printf("3");
    printf("\n%p\n", *tail);
    i++;
    printf("%d", i);
  }
  printf("after");
}
void calc_stock_span(stock s, int *stock_span, int size) {
  int count = 1;
  printf("kk");
  node *current = s.head;
  node *go_back = current;
  int i = 0;
  while (i < size) {
    int count = 1;
    printf("hi");
    while (go_back->prev != NULL && go_back->prev->data <= current->data) {
      /* if () {
         break;
       }*/
      printf("%d %d\n", current->data, go_back->prev->data);
      count++;
      go_back = go_back->prev;
    }
    *(stock_span + i) = count;
    current = current->next;
    go_back = current;
    i++;
  }
}
void print_stock_span(int *stock_span, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d,", *(stock_span + i));
  }
  printf("\b]\n");
}
