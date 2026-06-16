#include "TGList.h"
#include <stdio.h>

void print_int(void* info) {
    int *valor = (int*)info;
    printf("%d -> ", *valor);
}

void print_float(void* info) {
    float *valor = (float*)info;
    printf("%.2f -> ", *valor);
}

void print_str(void* info) {
    char *str = (char*)info;
    printf("\"%s\" - ", str);
}

void main() {
    // Lista com inserção no inicio e com ints
    TGList* lista = TGList_create(NO_INICIO, print_int);

    int v[] = {5, 3, 1, 2, 4};
    for (int i = 0; i < 5; i++)
        TGList_insert(lista, &v[i]);

    printf("Lista 1:\n");
    TGList_print(lista);


    // Lista com inserção no fim e com floats
    float v2[] = {1.24, 4.32, 5.34, 7.80, 9.12};
    TGList* lista2 = TGList_create(NO_FIM, print_float);
    for (int i = 0; i < 5; i++)
        TGList_insert(lista2, &v2[i]);

    printf("Lista 2:\n");
    TGList_print(lista2);

    // Lista com inserção no fim e com strings
    char strings[][64] = {"Maria Vitória", "Clara", "Vinicius"};
    TGList* lista3 = TGList_create(NO_FIM, print_str);
    for (int i = 0; i < 3; i++)
        TGList_insert(lista3, &strings[i]);

    printf("Lista 3:\n");
    TGList_print(lista3);
}