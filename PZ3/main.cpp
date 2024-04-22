#include "tree.h"
#include <stdio.h>
#include <windows.h>

int main( )
{
   tree *t = NULL;
   FILE *f = NULL;
   if ( fopen_s( &f, "C:/Users/egovl/Source/Repos/OmniSSeRiTTiBi/PZ3/PZ3/in.txt", "r" ) )
      perror( "in.txt" ), exit( -1 );

   t = t->build_tree( f );
   fclose( f );

   if ( !t )
      printf_s( "Tree is Empty!" ), exit( -1 );
   t->bracketing( );

   if ( fopen_s( &f, "C:/Users/egovl/Source/Repos/OmniSSeRiTTiBi/PZ3/PZ3/out.txt", "w" ) )
      perror( "out.txt" ), exit( -1 );
   fprintf_s( f, "PREORDER: " );
   t->pre_order( f );
   fprintf_s( f, "\nINORDER: " );
   t->in_order( f );
   fprintf_s( f, "\nPOSTORDER: " );
   t->post_order( f );
   fclose( f );
   return 0;
}