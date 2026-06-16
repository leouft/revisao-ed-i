#include "TLList.h"
#include <stdio.h>

void main() {
    TLList* lista = TLList_create();
    int v[] = {1, 2, 4, 8, 9, 11};

    for (int i = 0; i < 6; i++) {
        if (!TLList_insert_end(lista, v[i]))
            printf("Não foi possível inserir v[%i] = %d", i, v[i]);
    }

    printf("Lista 1:\n");
    TLList_print(lista);

    TLList* inverted_list = TLList_invert(lista);

    printf("Lista inversa:\n");
    TLList_print(inverted_list);
}