#pragma once

#include<stdio.h>
#include<windows.h>


struct tree
{
   char elem;
   tree *left, *right;

   tree( char _elem = 0, tree *_left = NULL, tree *_right = NULL ) :
      elem( _elem ), left( _left ), right( _right ) { }

   void bracketing( );
   void pre_order( FILE *f );
   void in_order( FILE *f );
   void post_order( FILE *f );
};

void bracketing( tree *t );
tree *BuildTree( FILE *f );
