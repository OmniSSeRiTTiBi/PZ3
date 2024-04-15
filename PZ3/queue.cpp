#pragma once
#include <windows.h>
#include <stdio.h>
#include "queue.h"

void queue::push( tree *v )
{
   if ( empty( ) )
      end = beg = new list( v );
   else
   {
      end = new list( v, NULL, end );
      end->prev->next = end;
   }
   ++count;
}

int queue::pop( )
{
   if ( empty( ) )
      return 1;
   else
   {
      if ( count == 1 )
         delete end, end = beg = NULL;
      else
      {
         beg = beg->next;
         delete beg->prev;
         beg->prev = NULL;
      }
      --count;
   }
}