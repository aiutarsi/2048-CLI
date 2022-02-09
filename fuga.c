#include <stdio.h>

#define SIZE 5

void init(int *head, int *tail) {
  *head = *tail = 0;
}

int isEmpty(int *head, int *tail) {
  return *head == *tail;
}

int isFull(int *head, int *tail) {
  return *head == (*tail + 1) % SIZE;
}

void push_back(int deque[], int *head, int *tail, int x) {
  deque[*tail] = x;
  *tail = (*tail + 1) % SIZE;
}

int pop_front(int deque[], int *head, int *tail) {
  if(isEmpty(head, tail)) return -1;
  int x = deque[*head];
  deque[*head] = -1;
  *head = (*head + 1) % SIZE;
  return x;
}

int size(int *head, int *tail) {
  return ( (*tail - *head >= 0)? *tail - *head  : SIZE - (*tail - *head) );
}

int pop_back(int deque[], int *head, int *tail) {
  if(isEmpty(head, tail)) return -1;
  int x = deque[((*tail == 0)? SIZE-1 : *tail-1)];
  deque[((*tail == 0)? SIZE-1 : *tail-1)] = -1;
  *tail = ((*tail == 0)? SIZE-1 : *tail-1);
  return x;
}

void printall(int deque[]) {
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", deque[i]);
  }
  printf("\n");
}

int main() {
  int deque[SIZE] = {-1,-1,-1,-1,-1};
  int head = 0; /* queue pop */
  int tail = 0; /* queue push */
  push_back(deque, &head, &tail, 1);
  printall(deque);
  printf("%d\n", size(&head, &tail));
  push_back(deque, &head, &tail, 2);
  printall(deque);
  printf("%d\n", size(&head, &tail));
  push_back(deque, &head, &tail, 3);
  printall(deque);
  printf("%d\n", size(&head, &tail));
  push_back(deque, &head, &tail, 4);
  printall(deque);
  printf("%d\n", size(&head, &tail));
  push_back(deque, &head, &tail, 5);
  printall(deque);
  printf("%d\n", size(&head, &tail));
  push_back(deque, &head, &tail, 6);
  printall(deque);
  printf("%d\n", size(&head, &tail));
  pop_front(deque, &head, &tail);
  printall(deque);
  printf("%d\n", size(&head, &tail));
  pop_back(deque, &head, &tail);
  printall(deque);
  printf("%d\n", size(&head, &tail));
  pop_back(deque, &head, &tail);
  printall(deque);
  printf("%d\n", size(&head, &tail));
  pop_back(deque, &head, &tail);
  printall(deque);
  printf("%d\n", size(&head, &tail));
  pop_back(deque, &head, &tail);
  printall(deque);
  printf("%d\n", size(&head, &tail));
  pop_back(deque, &head, &tail);
  printall(deque);
  printf("%d\n", size(&head, &tail));
}
