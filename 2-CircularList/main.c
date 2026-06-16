#include "TCList.h"
#include <stdio.h>

void main() {
    TCList* lista = TCList_create();
    printf("Lista criada\n");
    int v[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        if (!TCList_insert_end(lista, v[i]))
            printf("Não foi possível inserir V[%i] = %d", i, v[i]);
        TCList_print(lista);
    }
    printf("\n");

    TCList* lista2 = TCList_create();
    printf("Lista 2 criada\n");
    for (int i = 0; i < 5; i++) {
        if (!TCList_insert_begin(lista2, v[i]))
            printf("Não foi possível inserir V[%i] = %d", i, v[i]);
        TCList_print(lista2);
    }
    printf("\n");

    int temp;
    TCList_remove_end(lista, &temp);
    TCList_print(lista);
    printf("\n");
    TCList_remove_begin(lista2, &temp);
    TCList_print(lista2);
}