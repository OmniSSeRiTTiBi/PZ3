#include "tree.h"
#include <stdio.h>
#include <windows.h>

enum place { LEFT = 0, ROOT, RIGHT };

int main( )
{
   tree *t = NULL;
   FILE *f = NULL;
   if ( fopen_s( &f, "C:/Users/egovl/Source/Repos/OmniSSeRiTTiBi/PZ3/PZ3/in.txt", "r" ) )
      perror( "in.txt" ), exit( -1 );
   t = BuildTree(f);
   delete f;
   t->bracketing( );

   return 0;
}