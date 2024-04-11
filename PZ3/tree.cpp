#include<windows.h>
#include"tree.h"

tree *copy_tree( tree *root )
{
   tree *t = NULL;
   if ( root )
   {
      t = new tree( root->el );
      stack *s1 = push( root, s1 ), *s2 = push( t, s2 );
      for ( ; s1; )
      {
         tree *cur;
         push( &cur, &s2 );
         push( &root, &s1 );
         if ( root->left )
         {
            cur->left = new tree( root->left->el );
            s1 = push( root->left, s1 );
            s2 = push( cur->left, s2 );
         }
         if ( root->right )
         {
            cur->right = new tree( root->right->el );
            s1 = push( root->right, s1 );
            s2 = push( cur->right, s2 );
         }
      }
   }
   return t;
}

void open_brackets( tree *root )
{
   if ( root )
   {
      stack *s = NULL;
      s = push( root, s );
      char z = 0;
      for ( ; s; )
      {
         push( &root, &s );
         z = root->el;
         if ( z == '+' || z == '-' )
         {
            if ( root->left->el == '*' && root->right->el == '*' )
               if ( root->left->left->el == root->right->left->el )
               {
                  root->right = new tree( z, root->left->right, root->right->right );
                  root->el = '*';
                  root->left = root->left->left;
               }
               else if ( root->left->right->el == root->right->right->el )
               {
                  root->left = new tree( z, root->left->left, root->right->left );
                  root->el = '*';
                  root->right = root->left->right;
               }
            s = push( root->right, push( root->left, s ) );
         }
         else if ( root->el == '*' )
            s = push( root->right, push( root->left, s ) );
      }
   }
}

void PreOrder( tree *root, FILE **fout )
{
   if ( root )
   {
      stack *s = new stack( root );
      for ( ; s; )
      {
         push( &root, &s );
         if ( fout ) fprintf_s( *fout, "%c ", root->el );
         if ( root->right ) s = push( root->right, s );
         if ( root->left ) s = push( root->left, s );
      }
   }
}

void InOrder( tree *root, FILE **fout )
{
   if ( root )
   {
      bool IsProcessed = true;
      stack *s = NULL;
      for ( ; IsProcessed; )
      {
         for ( ; root; s = push( root, s ), root = root->left );
         if ( push( &root, &s ) )
         {
            if ( fout ) fprintf_s( *fout, "%c ", root->el );
            root = root->right;
         }
         else
            IsProcessed = false;
      }
   }
}

void PostOrder( tree *root, FILE **fout )
{
   int count = 0;
   if ( root )
   {
      UCHAR flag = 0;
      stack *s = NULL;
      do
      {
         for ( ; root; )
         {
            s = push( root, s, 0 );
            root = root->left;
         }
         if ( s )
         {
            do
            {
               if ( push( &root, &s, &flag ) && flag )
                  if ( fout ) fprintf_s( *fout, "%c ", root->el );
            } while ( flag && s );
            if ( !flag )
            {
               s = push( root, s, 1 );
               root = root->right;
            }
         }
      } while ( s );
   }
}

stack *push( tree *x, stack *st, UCHAR mark )
{
   return new stack( x, st, mark );
}

bool push( tree **x, stack **st, UCHAR *mark )
{
   if ( *st )
   {
      if ( x ) *x = (*st)->el;
      if ( mark ) *mark = (*st)->mark;
      *st = (*st)->next;
      return true;
   }
   return false;
}