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
        printf("\n");
    }
    else
        printf("A lista está vazia.\n");
}

TLList* TLList_merge(TLList* lista1, TLList* lista2) {
    TLList* new = TLList_create();
    if (!new) return NULL;
    TNo* aux = lista1->inicio;
    // Inserindo a primeira lista:
    while (aux != NULL) {
        TLList_insert_end(new, aux->info);
        aux = aux->prox;
    }

    aux = lista2->inicio;
    while (aux) {
        if (aux->info < new->inicio->info) {
            TNo* newNo = TNo_createNFill(aux->info);
            if (!newNo) return NULL;
            newNo->prox = new->inicio;
            new->inicio = newNo;
        }
        else {
            TNo* aux2 = new->inicio;
            TNo* newNo = TNo_createNFill(aux->info);
            bool foundEqual = false;
            while (aux2->prox) {
                if (aux2->info == newNo->info || aux2->prox->info == newNo->info) {
                    foundEqual = true;
                    break;
                }
                if (aux2->prox->info > newNo->info)
                    break;
                aux2 = aux2->prox;
            }

            if (!foundEqual) {
                newNo->prox = aux2->prox;
                aux2->prox = newNo;
            }
            else {
                free(newNo);
            }
        }
        aux = aux->prox;
    }
    return new;
}