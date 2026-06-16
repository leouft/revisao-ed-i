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

TLList* TLList_intersection(TLList* lista1, TLList* lista2) {
    TLList* new = TLList_create();
    TNo* aux = lista1->inicio;
    TNo* aux2;
    while (aux) { // Percorre a lista 1
        aux2 = lista2->inicio;
        while (aux2) { // Percorre a lista 2
            if (aux->info == aux2->info) { // Inicia se encontrar dois elementos iguais em ambas listas
                TNo* aux3 = new->inicio;
                bool found = false;
                while (aux3) { // Percorre a lista de interseção
                    if (aux->info == aux3->info) { // Sai do loop se essa interseção já estiver na lista de interseção
                        found = true;
                        break;
                    }
                    aux3 = aux3->prox;
                }

                if (!found) { // Se o valor já não estiver inserido, insere na lista nova
                    TLList_insert_end(new, aux->info);
                }
                break;
            }
            aux2 = aux2->prox;
        }
        aux = aux->prox;
    }

    return new;
}