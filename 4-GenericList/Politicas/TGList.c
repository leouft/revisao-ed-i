#include "TGList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    int info;
    struct _no *prox;
} TNo;

struct _list {
    TNo* inicio;
    char policy;
};

TNo* TNo_createNFill(int info) {
    TNo* new = malloc(sizeof(TNo));
    if (!new) return NULL;
    new->info = info;
    new->prox = NULL;
    return new;
}

TGList* TGList_create(char policy) {
    TGList* new = malloc(sizeof(TGList));
    if (!new) return NULL;
    new->inicio = NULL;
    new->policy = policy;
    return new;
}

// Cabeçalho das funções de inserção
bool TGList_insert_begin(TGList*, int);
bool TGList_insert_end(TGList*, int);
bool TGList_insert_ordenado(TGList*, int);

// Como a lista vai ser genérica, só precisamos de uma função insert no .h, e lá no C chamamos a função de acordo com a política.
bool TGList_insert(TGList* lista, int info) {
    switch (lista->policy) {
        case NO_INICIO: return TGList_insert_begin(lista, info); break;
        case NO_FIM: return TGList_insert_end(lista, info); break;
        case ORDENADA: return TGList_insert_ordenado(lista, info); break;
        default: return false; break;
    }
}

bool TGList_insert_begin(TGList* lista, int info) {
    TNo* new = TNo_createNFill(info);
    if (!new) return false;
    if (lista->inicio != NULL)
        new->prox = lista->inicio;
    lista->inicio = new;
    return true;
}

bool TGList_insert_end(TGList* lista, int info) {
    TNo* new = TNo_createNFill(info);
    if (!new) return false;
    if (lista->inicio == NULL) {
        lista->inicio = new;
    }
    else {
        TNo* aux = lista->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = new;
    }
    return true;
}

bool TGList_insert_ordenado(TGList* lista, int info) {
    TNo* new = TNo_createNFill(info);
    if (!new) return false;
    if (lista->inicio == NULL) {
        lista->inicio = new;
    }
    else {
        if (lista->inicio->info >= new->info) {
            new->prox = lista->inicio;
            lista->inicio = new;
        }
        else {
            TNo* aux = lista->inicio;
            while (aux->prox != NULL) {
                if (aux->prox->info > new->info)
                        break;
                aux = aux->prox;
            }
            
            new->prox = aux->prox;
            aux->prox = new;
        }
    }
    return true;
}

void TGList_print(TGList* lista) {
    if (lista->inicio != NULL) {
        TNo* aux = lista->inicio;
        while (aux != NULL) {
            printf("%d -> ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
    else {
        printf("A lista está vazia.\n");
    }
}