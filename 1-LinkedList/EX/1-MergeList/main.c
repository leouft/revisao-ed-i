#include "TLList.h"
#include <stdio.h>

void main() {
    TLList* lista = TLList_create();
    int v[] = {1, 2, 4, 8, 9, 11};

    for (int i = 0; i < 6; i++) {
        if (!TLList_insert_end(lista, v[i]))
            printf("Não foi possível inserir v[%i] = %d", i, v[i]);
    }

    int v2[] = {0, 2, 3, 6, 8, 10};
    TLList* lista2 = TLList_create();
    for (int i = 0; i < 6; i++) {
        if (!TLList_insert_end(lista2, v2[i]))
            printf("Não foi possível inserir v2[%i] = %d", i, v2[i]);
    }

    printf("Lista 1:\n");
    TLList_print(lista);
    printf("Lista 2:\n");
    TLList_print(lista2);

    TLList* merge_lista = TLList_merge(lista, lista2);
    printf("Lista merged:\n");
    TLList_print(merge_lista);
}