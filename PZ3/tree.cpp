#pragma once

#include<windows.h>
#include"tree.h"
#include "queue.h"

enum place { LEFT = 0, RIGHT, ROOT };

tree *BuildTree( FILE *f )
{
   char *c = new char( '0' );
   tree *t = new tree;
   fscanf_s( f, "%c", c, 1);
   switch ( *c )
   {
      case '(':
         fscanf_s( f, "%c", c, 1 );
         t->elem = *c;
         t->left = BuildTree( f );
         t->right = BuildTree( f );
         fscanf_s( f, "%c", c, 1 );
         return t;
      case ',': return BuildTree( f );
      case '0': return NULL;
      default: 
         t->elem = *c;
         return t;
   }
   fclose( f );
   delete c;
}

void tree::bracketing ( )
{
   queue q;
   tree *t;
   if ( this != NULL )
   {
      q.push( this );
      do
      {
         t = q.top( );
         if ( t->left != NULL && t->right != NULL )
         {
            if ( t->elem == '+' && t->left->elem == '*' && '*' == t->right->elem )
            {
               printf_s( "Õóé: %c, %c", t->left->elem, t->right->elem );
            }
            q.push( t->left );
            q.push( t->right );
         }
         q.pop( );
      } while ( !q.empty() );
   }
}