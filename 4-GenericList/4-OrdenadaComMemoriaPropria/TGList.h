#ifndef TGLIST_H
#define TGLIST_H
#include <stdbool.h>

// Defininmos os três tipos de políticas de inserção que poderemos usar em uma lista
#define NO_INICIO 0
#define NO_FIM 1
#define ORDENADA 2

typedef struct _list TGList;

TGList* TGList_create(char, void (*func_print)(void*), unsigned int, int (*func_cmp)(const void*, const void*));

// Como a lista vai ser genérica, só precisamos de uma função insert no .h, e lá no C chamamos a função de acordo com a política.
bool TGList_insert(TGList*, void*);

void TGList_print(TGList*);

#endif