#pragma once
#include "windows.h"
#include "tree.h"

struct list
{
   tree *elem = NULL;
   list *next = NULL, *prev = NULL;
   list( tree *a = 0, list *_next = NULL, list *_prev = NULL ) :
      elem( a ), next( _next ), prev( _prev ) { }
};

struct queue
{
   UINT count = 0;
   list *beg = NULL, *end = NULL;

   void push( tree *v );
   int pop( );
   inline tree *top( ) const { return beg->elem; }

   inline bool empty( ) const { return !beg; }
};