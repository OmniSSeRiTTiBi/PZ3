#include<windows.h>
#include"tree.h"


enum place { LEFT = 0, RIGHT, ROOT };

int tree::input( FILE *f )
{
   tree *root = NULL;

   if ( fopen_s( &f, "in.txt", "r" ) )
   {
      perror( "in.txt" );
      errno = 0;
      return 1;
   }


}

void copy_tree( tree *t, tree *copy )
{
   if ( !t  ) copy = NULL;
   else
   {
      copy->elem = t->elem;
      copy_tree( t->left, copy->left );
      copy_tree( t->right, copy->right );
   }
}

//tree *tree::copy( )
//{
//   tree *t = NULL;
//   if ( this == NULL ) return NULL;
//   t->elem = elem;
//   t->left = left.copy( );
//   t->right = right.copy( );
//}

//void tree::bracketing( tree *root )
//{
//   if ( root )
//   {
//      stack *s = NULL;
//      s = push( root, s );
//      char z = 0;
//      for ( ; s; )
//      {
//         push( &root, &s );
//         z = root->elem;
//         if ( z == '+' || z == '-' )
//         {
//            if ( root->left->elem == '*' && root->right->elem == '*' )
//               if ( root->left->left->elem == root->right->left->elem )
//               {
//                  root->right = new tree( z, root->left->right, root->right->right );
//                  root->elem = '*';
//                  root->left = root->left->left;
//               }
//               elemse if ( root->left->right->elem == root->right->right->elem )
//               {
//                  root->left = new tree( z, root->left->left, root->right->left );
//                  root->elem = '*';
//                  root->right = root->left->right;
//               }
//            s = push( root->right, push( root->left, s ) );
//         }
//         elemse if ( root->elem == '*' )
//            s = push( root->right, push( root->left, s ) );
//      }
//   }
//}
//
//void tree::pre_order( tree *root, FILE **fout )
//{
//   if ( root )
//   {
//      stack *s = new stack( root );
//      for ( ; s; )
//      {
//         push( &root, &s );
//         if ( fout ) fprintf_s( *fout, "%c ", root->elem );
//         if ( root->right ) s = push( root->right, s );
//         if ( root->left ) s = push( root->left, s );
//      }
//   }
//}
//
//void tree::in_order( tree *root, FILE **fout )
//{
//   if ( root )
//   {
//      bool IsProcessed = true;
//      stack *s = NULL;
//      for ( ; IsProcessed; )
//      {
//         for ( ; root; s = push( root, s ), root = root->left );
//         if ( push( &root, &s ) )
//         {
//            if ( fout ) fprintf_s( *fout, "%c ", root->elem );
//            root = root->right;
//         }
//         elemse
//            IsProcessed = false;
//      }
//   }
//}
//
//void tree::post_order( tree *root, FILE **fout )
//{
//   int count = 0;
//   if ( root )
//   {
//      UCHAR flag = 0;
//      stack *s = NULL;
//      do
//      {
//         for ( ; root; )
//         {
//            s = push( root, s, 0 );
//            root = root->left;
//         }
//         if ( s )
//         {
//            do
//            {
//               if ( push( &root, &s, &flag ) && flag )
//                  if ( fout ) fprintf_s( *fout, "%c ", root->elem );
//            } while ( flag && s );
//            if ( !flag )
//            {
//               s = push( root, s, 1 );
//               root = root->right;
//            }
//         }
//      } while ( s );
//   }
//}
//
//stack *push( tree *x, stack *st, UCHAR mark )
//{
//   return new stack( x, st, mark );
//}
//
//bool push( tree **x, stack **st, UCHAR *mark )
//{
//   if ( *st )
//   {
//      if ( x ) *x = (*st)->elem;
//      if ( mark ) *mark = (*st)->mark;
//      *st = (*st)->next;
//      return true;
//   }
//   return false;
//}