#include "TCList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    int info;
    struct _no* prox;
} TNo;

struct _list {
    TNo* inicio;
};

TNo* TNo_createNFill(int info) {
    TNo* new = malloc(sizeof(TNo));
    new->info = info;
    new->prox = new;
    return new;
}

TCList* TCList_create() {
    TCList* new = malloc(sizeof(TCList));
    if (!new) return NULL;
    new->inicio = NULL;
    return new;
}

bool TCList_insert_begin(TCList* lista, int info) {
    TNo* new = TNo_createNFill(info);
    if (!new) return false;
    if (lista->inicio != NULL)
    {
        new->prox = lista->inicio;
        TNo* aux = lista->inicio;
        while (aux->prox != lista->inicio) {
            aux = aux->prox;
        }
        aux->prox = new;
    }
    lista->inicio = new;
    return true;
}

bool TCList_insert_end(TCList* lista, int info) {
    TNo* new = TNo_createNFill(info);
    if (!new) return false;
    if (lista->inicio == NULL) {
        lista->inicio = new;
    }
    else {
        TNo* aux = lista->inicio;
        while (aux->prox != lista->inicio) {
            aux = aux->prox;
        }
        aux->prox = new;
        new->prox = lista->inicio;
    }
    return true;
}

bool TCList_remove_end(TCList* lista, int* pinfo) {
    if (lista->inicio != NULL) {
        TNo* aux = lista->inicio;
        if (aux->prox == lista->inicio) {
            *pinfo = aux->info;
            free(aux);
            lista->inicio = NULL;
        }
        else  {
            while (aux->prox->prox != lista->inicio)
                aux = aux->prox;
            TNo* temp = aux->prox;
            aux->prox = lista->inicio;
            *pinfo = temp->info;
            free(temp);
        }
        return true;
    }
    return false;
}

bool TCList_remove_begin(TCList* lista, int* pinfo) {
    if (lista->inicio != NULL) {
        TNo* aux = lista->inicio;
        if (aux->prox == lista->inicio) {
            *pinfo = aux->info;
            free(aux);
            lista->inicio = NULL;
        }
        else {
            while (aux->prox != lista->inicio)
                aux = aux->prox;
            aux->prox = lista->inicio->prox;
            aux = lista->inicio;
            lista->inicio = aux->prox;
            *pinfo = aux->info;
            free(aux);
        }
        return true;
    }
    return false;
}

void TCList_print(TCList* lista) {
    if (lista->inicio != NULL) {
        TNo* aux = lista->inicio;
        while (aux->prox != lista->inicio) {
            printf("%d -> ", aux->info);
            aux = aux->prox;
        }
        printf("%d\n", aux->info);
    }
    else {
        printf("A lista está vazia.\n");
    }
}