#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  // Add your code for exercise 1
  // There is NO testcode for this
  // It wil continue to print until = NULL

  // Basecase
  if(p == NULL)
  {
    return;
  }
  // Recursive
  else
 {
    printf("%d", p->value);
    print_list(p->next);
    return;
  }
}

int sum_squares(node *p) {
  // Add your code for excercise 2
  // You can find the tests in tests.cpp
  int sum = 0;

// we time the number togehter two time, and then put it together to have number squares.
// this number is added to the sum.
  
// Basecase
  if(p == NULL)
  {
    return 0;
  }
// Recursive
    else 
  { 
    sum = square(p->value) + sum_squares(p->next);
    return sum;
  }   
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  // Add your code for excercise 3
  
  int r;

// Basecase
  if(p == NULL)
  {
    return NULL;
  }
// Recursive
  else
  {
    r = f(p->value);
    return make_node(r, map(p->next,f));
  }
}
  


int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
