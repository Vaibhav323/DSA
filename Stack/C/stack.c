#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100

struct stack {
  int top;
  int items[STACKSIZE];
};

int isEmpty(struct stack *);
int pop(struct stack *);
int push(struct stack *, int);
int stackTop(struct stack *);

int main(void) {
  struct stack *s;

  printf("%d\n", push(s, 2));
  printf("%d\n", push(s, 3));
  printf("%d\n", push(s, 4));
  printf("%d\n", isEmpty(s));
  printf("%d\n", pop(s));
  printf("%d\n", stackTop(s));

  return EXIT_SUCCESS;
}

int isEmpty(struct stack *ps) { return (ps->top == -1); }

int pop(struct stack *ps) {
  if (isEmpty(ps)) {
    printf("STACK UNDERFLOW\n");
    return INT_MIN;
  }
  return (ps->items[ps->top--]);
}

int push(struct stack *ps, int data) {
  if (ps->top == STACKSIZE - 1) {
    printf("STACK OVERFLOW\n");
    return INT_MAX;
  }
  return (ps->items[++(ps->top)] = data);
}

int stackTop(struct stack *ps) {
  if (isEmpty(ps)) {
    printf("STACK UNDERFLOW\n");
    return INT_MIN;
  }
  return (ps->items[ps->top]);
}
