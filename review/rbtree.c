#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ElementType char

typedef enum ColorType { Red, Black } ColorType;

struct RBNode;
typedef struct RBNode* RBTree;
typedef struct RBNode* RBNode;

struct RBNode 
{
  RBTree left, right;
  ColorType color;
  ElementType element;
};

RBNode newRBNode(ElementType value, ColorType color)
{
  RBNode node;

  node = malloc(sizeof(struct RBNode));
  node -> left = node -> right = NULL;
  node -> color = color;
  node -> element = value;

  return node;
}

ColorType color(RBTree tree)
{
  if (tree == NULL)
    return Black;

  return tree -> color;
}

RBTree rotateLeft(RBTree tree)
{
  RBTree node;

  node = tree -> left;
  tree -> left = node -> right;
  node -> right = tree;

  return node;
}

RBTree rotateRight(RBTree tree)
{
  RBTree node;

  node = tree -> right;
  tree -> right = node -> left;
  node -> left = tree;

  return node;
}

RBTree rbInsert(RBTree tree, ElementType value, int sw)
{
  if (tree == NULL)
  {
    return newRBNode(value, Red);
  }

  if (color(tree -> left) == Red && color(tree -> right) == Red)
  {
    tree -> color = Red;
    tree -> left -> color = tree -> right -> color = Black;
  }

  if (tree -> element > value)
  {
    tree -> left = rbInsert(tree -> left, value, 0);

    if (sw == 1 && (color(tree) == Red) && (color(tree -> left) == Red))
      tree = rotateLeft(tree);

    if (color(tree -> left) == Red && color(tree -> left -> left) == Red)
    {
      tree = rotateLeft(tree);
      tree -> right -> color = Red;
      tree -> color = Black;
    }
  }
  else if (tree -> element < value)
  {
    tree -> right = rbInsert(tree -> right, value, 1);

    if (sw == 0 && (color(tree) == Red) && (color(tree -> right) == Red))
      tree = rotateRight(tree);

    if (color(tree -> right) == Red && color(tree -> right -> right) == Red)
    {
      tree = rotateRight(tree);
      tree -> color = Black;
      tree -> left -> color = Red;
    }
  }

  return tree;
}

RBTree insert(RBTree tree, ElementType value)
{
  if (tree == NULL)
  {
    return newRBNode(value, Black);
  }
  else
  {
    return rbInsert(tree, value, 0);
  }
}

void inorderTraverse(RBTree tree)
{
  if (tree == NULL)
    return;

  inorderTraverse(tree -> left);
  printf("%c(%s) ", tree -> element, tree -> color == Red ? "Red" : "Black");
  inorderTraverse(tree -> right);
}

void postorderTraverse(RBTree tree)
{
  if (tree == NULL)
    return;

  postorderTraverse(tree -> left);
  postorderTraverse(tree -> right);
  printf("%c(%s) ", tree -> element, tree -> color == Red ? "Red" : "Black");
}

void preorderTraverse(RBTree tree)
{
  if (tree == NULL)
    return;

  printf("%c(%s) ", tree -> element, tree -> color == Red ? "Red" : "Black");
  preorderTraverse(tree -> left);
  preorderTraverse(tree -> right);
}

int main(int argc, char const *argv[])
{
  char *string = "ASERCHINGX";
  RBTree tree;
  int i, len;

  tree = NULL;
  len = strlen(string);

  for (i = 0; i < len; ++i)
    tree = insert(tree, string[i]);
  
  preorderTraverse(tree);
  printf("\n");

  inorderTraverse(tree);
  printf("\n");

  postorderTraverse(tree);
  printf("\n");
  return 0;
}