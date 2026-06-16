#include "TGList.h"
#include <stdio.h>
#include <string.h>

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

int cmp_int(const void* info, const void* info2) {
    int* p1 = (int*)info;
    int* p2 = (int*)info2;

    return (*p1 < *p2) ? -1 : (*p1 > *p2) ? 1 : 0;
}

int cmp_float(const void* info, const void* info2) {
    float* p1 = (float*)info;
    float* p2 = (float*)info2;

    return (*p1 < *p2) ? -1 : (*p1 > *p2) ? 1 : 0;
}

int cmp_str(const void* info, const void* info2) {
    char* p1 = (char*)info;
    char* p2 = (char*)info2;

    return strcmp(p1, p2);
}

void main() {
    // Lista com ints
    TGList* lista = TGList_create(ORDENADA, print_int, sizeof(int), cmp_int);

    int v[] = {5, 5, 4, 3, 2, 1};
    for (int i = 0; i < 6; i++)
        TGList_insert(lista, &v[i]);

    printf("Lista 1:\n");
    TGList_print(lista);

    // Lista com floats
    float v2[] = {4.32, 7.80, 1.24, 5.34, 9.12};
    TGList* lista2 = TGList_create(ORDENADA, print_float, sizeof(float), cmp_float);
    for (int i = 0; i < 5; i++)
        TGList_insert(lista2, &v2[i]);

    printf("Lista 2:\n");
    TGList_print(lista2);

    // Lista com strings
    char strings[][64] = {"Maria Vitória", "Clara", "Vinicius"};
    TGList* lista3 = TGList_create(ORDENADA, print_str, 64, cmp_str);
    for (int i = 0; i < 3; i++)
        TGList_insert(lista3, &strings[i]);

    printf("Lista 3:\n");
    TGList_print(lista3);
}