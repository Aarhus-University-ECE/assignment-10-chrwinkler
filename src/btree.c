#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t

// Basecase
  if(t == NULL)
  {
    t = malloc(sizeof(struct tree_node));
    t->item = x;
    t->left=NULL;
    t->right=NULL;
  }
  // Recursive
  else
  {
    if(t->item > x)
    {
      t->left = Insert(x, t->left);
    }
    else if(t->item <= x)
    {
      t->right = Insert(x, t->right);
      
    }
  }

  return t;
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t
struct tree_node *tmp; 

// if their or not
if(Contains(x,t))
{
if ( x== t->item)
{
  // if it has no childs
  if(t->left == NULL && t->right == NULL)
  {
    free(t);
    return NULL;
  }
  // if it has only left child
  else if(t->left != NULL && t->right == NULL)
  {
    tmp = t->left;
    free(t);
    return tmp;
  }
  // if it has only right child
  else if(t->left == NULL && t->right != NULL)
  {
    tmp = t->right;
    free(t);
    return tmp;
  }
  // if it has both childs 
  else if(t->left != NULL && t->right != NULL)
  {
    tmp = t->right;
    while(tmp->left != NULL)
    {
      tmp=tmp->left;
    }
    t->item = tmp->item;

    Remove(tmp->item, t->right);
  }
}
// if x is smaller then item move left
else if(x < t->item)
{
 t->left = Remove(x, t->left);
}
// if x is smaller then item move right
else if(x > t->item)
{
  t->right = Remove(x, t->right);
}
  return t;
}
else 
{
  return t;
}
}

int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.


  // Basecase
  if(t == NULL)
  {
    return 0;
  }
  else if(x==t->item)
  {
    return 1;
  }
  // Recursive
  else if(x>t->item)
  {
    return Contains(x,t->right);
  }
  else
  {
   return Contains(x,t->left); 
  }
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree
  // begining is NULL
  t=NULL;

  return t;
}

int Empty(struct tree_node *t) {
  // Test if empty
  // if it is the same as Initialize.
  if(t == NULL)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}

int Full(struct tree_node *t) {
  // Test if full
  // it can never be empty
  return 0;
}

// testing for mistakes.
void print_tree(struct tree_node *p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf(" ");
  printf("| ");

  if (p == NULL)
    printf("NULL\n");
  else
    printf("[%d]\n", p->item);

  if (p->left)
  {
    print_tree(p->left, depth + 1);
  }

  if (p->right)
    print_tree(p->right, depth + 1);
}
