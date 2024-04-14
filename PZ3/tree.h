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

   

   
   //void push( char c, bool place);

};

tree *BuildTree( FILE *f );
void copy_tree( tree *t, tree *copy );
