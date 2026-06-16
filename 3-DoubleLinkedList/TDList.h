#ifndef TDLIST_H
#define TDLIST_H
#include <stdbool.h>

typedef struct _list TDList;

TDList* TDList_create();

bool TDList_insert_begin(TDList*, int);

bool TDList_insert_end(TDList*, int);

bool TDList_remove_begin(TDList*, int*);

bool TDList_remove_end(TDList*, int*);

void TDList_print(TDList*);

#endif