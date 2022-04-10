#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcao que cria uma lista
ListaEnc2Plus* criaLista() {
    ListaEnc2Plus* lista = (ListaEnc2Plus*)malloc(sizeof(ListaEnc2Plus));
    lista->prim = NULL;
    lista->tamanho = 0;
    return lista;
}

// Funcao que destroi uma lista
void destroiLista(ListaEnc2Plus* lista) {
    NodoLEnc2* aux = lista->prim;
    while (aux != NULL) {
        NodoLEnc2* tmp = aux->prox;
        free(aux); // Cuidar ordem do free
        aux = tmp;
    }
    free(lista);
}

// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaEnc2Plus* lista) {
    NodoLEnc2* aux;
    printf("-----------------------------------------\n");
    for (aux = lista->prim; aux != NULL; aux = aux->prox)
        printf("(%s)\n", aux->palavra);
    printf("-----------------------------------------\n");
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoLista(ListaEnc2Plus* lista, char* palavra) {
    NodoLEnc2* aux;
    for (aux = lista->prim; aux != NULL; aux = aux->prox)
        if (strcmp(aux->palavra, palavra))
            return aux;
    return NULL;
}

// Funcao que insere um nodo no inicio de uma lista
void insereInicioLista(ListaEnc2Plus* lista, char* palavra) {
    NodoLEnc2* novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
    strcpy(novo->palavra, palavra);
    novo->ant = NULL;
    novo->prox = lista->prim;
    if (lista->prim != NULL)
        lista->prim->ant = novo;
    lista->prim = novo;
    lista->tamanho += 1;
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEnc2Plus* lista, char* palavra) {
    NodoLEnc2* aux = lista->prim;
    while (aux != NULL && !(strcmp(aux->palavra, palavra))) {
        aux = aux->prox;
    }
    if (aux != NULL) {
        if (aux->ant == NULL) {
            lista->prim = aux->prox;
            if (aux->prox != NULL)
                aux->prox->ant = NULL;
        }
        else {
            aux->ant->prox = aux->prox;
            if (aux->prox != NULL)
                aux->prox->ant = aux->ant;
        }
        free(aux);
        lista->tamanho -= 1;              // Removemos um elemento na lista, logo atualizamos o valor de tamanho
        return 1;
    }
    return 0; // Nao encontrou
}


// Funcao que fornece o tamanho da lista, que é armazenado na variável "tamanho" da lista passada como argumento
int tamanhoLista(ListaEnc2Plus* lista) {
    return lista->tamanho;
}
