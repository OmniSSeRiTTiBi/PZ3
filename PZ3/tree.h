#pragma once

#include<stdio.h>
#include<windows.h>

struct tree
{
   char el;
   tree *left, *right;

   tree( char _el = 0, tree *_left = NULL, tree *_right = NULL ) :
      el( _el ), left( _left ), right( _right ) { }
};

tree *copy_tree( tree *root );

void open_brackets( tree *root );

void PreOrder( tree *root, FILE **fout );

void InOrder( tree *root, FILE **fout );

void PostOrder( tree *root, FILE **fout );

struct stack
{
   tree *el;
   stack *next;
   int mark;

   stack( tree *_el = NULL, stack *_stack = NULL, int _mark = 0 ) :
      el( _el ), next( _stack ), mark( _mark ) {}
};

stack *push( tree *x, stack *st, UCHAR mark = 0 );

bool push( tree **x, stack **st, UCHAR *mark = NULL );