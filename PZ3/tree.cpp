#pragma once
#include <windows.h>
#include "tree.h"
#include "queue.h"

tree *tree::build_tree( FILE *f )
{
   char c = 0;
   fscanf_s( f, "%c", &c );
   switch ( c )
   {
      case '(':
      {
         fscanf_s( f, "%c", &c );
         tree *t = new tree( c, build_tree( f ), build_tree( f ) );
         fscanf_s( f, "%c", &c );
         return t;
      }
      case ',': return build_tree( f );
      case '0': return NULL;
      default:
         return new tree( c );
   }
   fclose( f );
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
   tree *t = NULL;
   UCHAR fl = 0;
   q.push( this );
   do
   {
      t = q.top( );
      if ( t->left != NULL && t->right )
      {
         if ( (t->elem == '+' || t->elem == '-') && t->left->elem == '*'
              && '*' == t->right->elem )
         {
            if ( t->left->left->compare( t->right->left ) )
               move_brack( t, t->left->left, t->left->right, *(t->right->right) );
            else if ( t->left->left->compare( t->right->right ) )
               move_brack( t, t->left->left, t->left->right, *(t->right->left) );
            else if ( t->left->right->compare( t->right->left ) )
               move_brack( t, t->left->right, t->left->left, *(t->right->right) );
            else if ( t->left->right->compare( t->right->right ) )
               move_brack( t, t->left->right, t->left->left, *(t->right->left) );
         }
         q.push( t->left );
         q.push( t->right );
      }
      q.pop( );
   } while ( !q.empty( ) );
}

void tree::pre_order( FILE *f )
{
   if ( this )
   {
      fprintf_s( f, "%c ", elem );
      left->pre_order( f );
      right->pre_order( f );
   }
}

void tree::in_order( FILE *f )
{
   if ( this )
   {
      left->in_order( f );
      fprintf_s( f, "%c ", elem );
      right->in_order( f );
   }
}

void tree::post_order( FILE *f )
{
   if ( this )
   {
      left->post_order( f );
      right->post_order( f );
      fprintf_s( f, "%c ", elem );
   }
}

bool tree::compare( tree *t )
{
   return !this || t && left->compare( t->left )
      && right->compare( t->right ) && elem == t->elem;
}