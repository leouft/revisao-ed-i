#include "TLList.h"
#include <stdio.h>

void main() {
    TLList* lista = TLList_create();
    int v[] = {1, 2, 8, 8, 9, 11, 2, 14, 11};

    for (int i = 0; i < 9; i++) {
        if (!TLList_insert_end(lista, v[i]))
            printf("Não foi possível inserir v[%i] = %d", i, v[i]);
    }

    printf("Lista 1:\n");
    TLList_print(lista);

    TLList* lista_even = TLList_even(lista);
    printf("Lista apenas com os pares:\n");
    TLList_print(lista_even);
}