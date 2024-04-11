#include"tree.h"
#include<stdio.h>
#include<windows.h>

enum place { LEFT = 0, ROOT, RIGHT };

tree *input( FILE *f )
{
   tree *root = NULL;
   if ( f )
   {
      char c = '0';
      stack *s = NULL;
      fscanf_s( f, "%c ", &c, 1 );
      root = new tree( );
      if ( c != '(' )
         root->el = c;
      else
         s = new stack( root, s, 0 );
      for ( tree *buf = NULL; !feof( f ) && s; )
      {
         //UCHAR flag = 0;// 0 - ввод в левое поддерево; 1 - ввод в корень; 2 - ввод в правое поддерево
         push( &cur, &s, &flag );
         fscanf_s( f, "%c ", &c, 1 );
         if ( c != '(' && c != ')' )
         {
            if ( flag == 0 ) cur->left = new tree( c );
            else if ( flag == 1 )
               cur->el = c;
            else if ( flag == 2 )
               cur->right = new tree( c );
            s = new stack( cur, s, ++flag );
         }
         else if ( c == '(' )
         {
            s = new stack( cur, s, flag + 1 );
            if ( flag == 0 )
            {
               cur->left = new tree( );
               s = new stack( cur->left, s, 0 );
            }
            else if ( flag == 2 )
            {
               cur->right = new tree( );
               s = new stack( cur->right, s, 0 );
            }
         }
      }
   }
   return root;
}

int main( )
{
   UINT iCp = GetConsoleCP( ), oCp = GetConsoleOutputCP( );
   SetConsoleCP( 1251 );
   SetConsoleOutputCP( 1251 );

   FILE *f;
   fopen_s( &f, "in.txt", "r" );
   if ( f )
   {
      tree *tree = input( f );
      open_brackets( tree );
      fclose( f );
      fopen_s( &f, "out.txt", "w" );
      if ( f )
      {
         fprintf_s( f, "Прямойобход: " );
         PreOrder( tree, &f );
         fprintf_s( f, "\nОбратныйобход: " );
         InOrder( tree, &f );
         fprintf_s( f, "\nКонцевой обход: " );
         PostOrder( tree, &f );
         fclose( f );
      }
      else
         printf_s( "Ошибка при открытии файлов.\n" );
   }
   else
      printf_s( "Ошибка при открытии файлов.\n" );

   SetConsoleCP( iCp );
   SetConsoleOutputCP( oCp );
   return 0;
}
