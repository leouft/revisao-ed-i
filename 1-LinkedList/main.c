#include "TLList.h"
#include <stdio.h>

void main() {
    TLList* lista = TLList_create();
    printf("Lista criada\n");
    int v[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        if (!TLList_insert_end(lista, v[i]))
            printf("Não foi possível inserir V[%i] = %d", i, v[i]);
    }

    TLList* lista2 = TLList_create();
    printf("Lista 2 criada\n");
    for (int i = 0; i < 5; i++) {
        if (!TLList_insert_begin(lista2, v[i]))
            printf("Não foi possível inserir V[%i] = %d", i, v[i]);
    }

    TLList_print(lista);
    printf("\n");
    TLList_print(lista2);
    printf("\n");

    int temp;
    while (TLList_remove_begin(lista, &temp));
    TLList_print(lista);
    printf("\n");
}