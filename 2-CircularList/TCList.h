#ifndef TCLIST_H
#define TCLIST_H
#include <stdbool.h>

typedef struct _list TCList;

TCList* TCList_create();

bool TCList_insert_begin(TCList*, int);

bool TCList_insert_end(TCList*, int);

bool TCList_remove_end(TCList*, int*);

bool TCList_remove_begin(TCList*, int*);

void TCList_print(TCList*);

#endif