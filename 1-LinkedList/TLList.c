#include "TLList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    int info;
    struct _no *prox;
} TNo;

struct _list{
    TNo* inicio;
};

TLList* TLList_create() {
    TLList* new = malloc(sizeof(TLList));
    if (!new) return NULL;
    new->inicio = NULL;
    return new;
}

TNo* TNo_createNFill(int info) {
    TNo* new = malloc(sizeof(TNo));
    if (!new) return NULL;
    new->info = info;
    new->prox = NULL;
    return new;
}

bool TLList_insert_begin(TLList* lista, int info) {
    TNo* new = TNo_createNFill(info);
    if (!new) return false;
    if (lista->inicio != NULL) {
        new->prox = lista->inicio;
    }
    lista->inicio = new;
    return true;
}

bool TLList_insert_end(TLList* lista, int info) {
    TNo* new = TNo_createNFill(info);
    if (!new) return false;
    TNo* aux = lista->inicio;
    if (lista->inicio == NULL) {
        lista->inicio = new;
    }
    else {
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = new;
    }
    return true;
}

bool TLList_remove_end(TLList* lista, int* pinfo) {
    if (lista->inicio != NULL) {
        TNo** aux = &lista->inicio;
        while ((*aux)->prox != NULL) {
            aux = &(*aux)->prox;
        }
        *pinfo = (*aux)->info;
        free((*aux));
        (*aux) = NULL;
        return true;
    }
    return false;
}

bool TLList_remove_begin(TLList* lista, int* pinfo) {
    if (lista->inicio != NULL) {
        TNo* aux = lista->inicio;
        *pinfo = aux->info;
        lista->inicio = aux->prox;
        free(aux);
        return true;
    }
    return false;
}

void TLList_print(TLList* lista) {
    if (lista->inicio != NULL) {
        TNo* aux = lista->inicio;
        while (aux != NULL) {
            printf("%d -> ", aux->info);
            aux = aux->prox;
        }
    }
    else
        printf("A lista está vazia.\n");
}