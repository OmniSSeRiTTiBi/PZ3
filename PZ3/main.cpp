#include "tree.h"
#include <stdio.h>
#include <windows.h>

enum place { LEFT = 0, ROOT, RIGHT };
//xyu
int main( )
{
   tree *t = NULL;
   FILE *f = NULL;
   if ( fopen_s( &f, "in.txt", "r" ) )
      perror( "in.txt" ), exit( -1 );
   t = BuildTree(f);
   delete f;
   t->bracketing( );
   tree *tcopy = NULL;

   return 0;
}