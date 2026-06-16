#include "TDList.h"
#include <stdio.h>

void main() {
    TDList* lista = TDList_create();
    int v[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        TDList_insert_begin(lista, v[i]);
    }
    printf("Lista criada, e elementos inseridos\n");

    TDList* lista2 = TDList_create();
    for (int i = 0; i < 5; i++) {
        TDList_insert_end(lista2, v[i]);
    }
    printf("Lista 2 criada, e elementos inseridos\n");


    TDList_print(lista);
    TDList_print(lista2);

    int temp;
    while(TDList_remove_begin(lista2, &temp));
    TDList_print(lista2);

    while(TDList_remove_end(lista, &temp));
    TDList_print(lista);
}