#include "TDList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    int info;
    struct _no *prox, *ant;
} TNo;

struct _list {
    TNo* inicio;
};

TNo* TNo_createNFill(int info) {
    TNo* new = malloc(sizeof(TNo));
    if (!new) return NULL;
    new->info = info;
    new->ant = NULL;
    new->prox = NULL;
    return new;
}

TDList* TDList_create() {
    TDList* new = malloc(sizeof(TDList));
    if (!new) return NULL;
    new->inicio = NULL;
    return new;
}

bool TDList_insert_begin(TDList* lista, int info) {
    TNo* new = TNo_createNFill(info);
    if (!new) return false;
    if (lista->inicio != NULL) {
        new->prox = lista->inicio;
        lista->inicio->ant = new;
    }
    lista->inicio = new;
    return true;
}

bool TDList_insert_end(TDList* lista, int info) {
    TNo* new = TNo_createNFill(info);
    if (!new) return false;
    if (lista->inicio == NULL) {
        lista->inicio = new;
    }
    else {
        TNo* aux = lista->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = new;
        new->ant = aux;
    }
    return true;
}

bool TDList_remove_begin(TDList* lista, int* pinfo) {
    if (lista->inicio != NULL) {
        TNo* aux = lista->inicio;
        if (aux->prox == NULL) {
            *pinfo = aux->info;
            free(aux);
            lista->inicio = NULL;
        }
        else {
            aux->prox->ant = NULL;
            lista->inicio = aux->prox;
            *pinfo = aux->info;
            free(aux);
        }
        return true;
    }
    return false;
}

bool TDList_remove_end(TDList* lista, int* pinfo) {
    if (lista->inicio != NULL) {
        TNo* aux = lista->inicio;
        if (aux->prox == NULL) {
            *pinfo = aux->info;
            free(aux);
            lista->inicio = NULL;
        }
        else {
            while (aux->prox->prox != NULL)
                aux = aux->prox;
            TNo* temp = aux->prox;
            aux->prox = NULL;
            *pinfo = temp->info;
            free(temp);
        }
        return true;
    }
    return false;
}

void TDList_print(TDList* lista) {
    if (lista->inicio != NULL) {
        TNo* aux = lista->inicio;
        while (aux != NULL) {
            printf("<- %d -> ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
    else {
        printf("A lista está vazia.\n");
    }
}