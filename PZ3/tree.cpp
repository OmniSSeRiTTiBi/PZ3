#pragma once

#include <windows.h>
#include "tree.h"
#include "queue.h"

enum place { LEFT = 0, RIGHT, ROOT };

tree *BuildTree( FILE *f )
{
   char *c = new char( '0' );
   tree *t = new tree;
   fscanf_s( f, "%c", c, 1 );
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
         fclose( f );
         delete c;
   }
}

void tree::move_brack( tree *head, tree *tot_multi, tree *mult1, tree mult2 )
{
   head->right->elem = head->elem, head->elem = '*';
   delete head->right->right;
   delete head->right->left;
   head->left = tot_multi;
   head->right->left = mult1;
   head->right->right = new tree( mult2.elem );
}

void tree::bracketing( )
{
   queue q;
   tree *t;
   UCHAR fl = 0;
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
               if ( t->left->left->elem == t->right->left->elem )
                  move_brack( t, t->left->left, t->left->right, *(t->right->right) );
               else if ( t->left->left->elem == t->right->right->elem )
                  move_brack( t, t->left->left, t->left->right, *(t->right->left) );
               else if ( t->left->right->elem == t->right->left->elem )
                  move_brack( t, t->left->right, t->left->left, *(t->right->right) );
               else if ( t->left->right->elem == t->right->right->elem )
                  move_brack( t, t->left->right, t->left->left, *(t->right->left) );
            }
            q.push( t->left );
            q.push( t->right );
         }
         q.pop( );
      } while ( !q.empty( ) );
   }
}