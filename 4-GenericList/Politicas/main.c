#include "TGList.h"
#include <stdio.h>

void main() {
    // Lista com inserção no inicio
    TGList* lista = TGList_create(NO_INICIO);

    int v[] = {5, 3, 1, 2, 4};
    for (int i = 0; i < 5; i++)
        TGList_insert(lista, v[i]);

    printf("Lista 1:\n");
    TGList_print(lista);

    // Lista com inserção no fim
    TGList* lista2 = TGList_create(NO_FIM);
    for (int i = 0; i < 5; i++)
        TGList_insert(lista2, v[i]);

    printf("Lista 2:\n");
    TGList_print(lista2);

    // Lista com inserção ordenada
    TGList* lista3 = TGList_create(ORDENADA);
    for (int i = 0; i < 5; i++)
        TGList_insert(lista3, v[i]);

    printf("Lista 3:\n");
    TGList_print(lista3);
}