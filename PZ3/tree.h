#pragma once
#include <stdio.h>
#include <windows.h>

struct tree
{
   char elem;
   tree *left, *right;

   tree( char _elem = 0, tree *_right = NULL, tree *_left = NULL ) :
      elem( _elem ), left( _left ), right( _right ) { }

   void move_brack( tree *head, tree *tot_multi, tree *mult1, tree mult2 );
   void bracketing( );
   tree *build_tree( FILE *f );
   void pre_order( FILE *f );
   void in_order( FILE *f );
   void post_order( FILE *f );
   bool compare( tree *other );
};