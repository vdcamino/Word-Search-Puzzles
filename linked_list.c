#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

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
        printf("%d | %s (%s)\n", aux->info,
            aux->info,
            aux->info);
    printf("-----------------------------------------\n");
}

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoLista(ListaEnc2Plus* lista, int codigo) {
    NodoLEnc2* aux;
    for (aux = lista->prim; aux != NULL; aux = aux->prox)
        if (aux->info == codigo)
            return aux;
    return NULL;
}

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEnc2Plus* lista, char info) {
    NodoLEnc2* novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
    novo->info = info;
    novo->ant = NULL;
    novo->prox = lista->prim;
    if (lista->prim != NULL)
        lista->prim->ant = novo;
    lista->prim = novo;
    return 1;
}

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEnc2Plus* lista, int codigo) {
    NodoLEnc2* aux = lista->prim;
    while (aux != NULL && aux->info != codigo) {
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

// Funcao que adiciona um livro em uma posicao especifica da lista
int insereEmPosicaoLista(ListaEnc2Plus* lista, char info, int posicao) {
    NodoLEnc2* aux = lista->prim;
    if (posicao <= tamanhoLista(lista)) {
        int count = 0;

        // Caso a posicao for igual a zero, inserimos no inicio com a ajuda da funcao insereInicioLista
        if (lista->prim == NULL) {
            int retornoAux = insereInicioLista(lista, info);
            lista->tamanho += 1;        // Adicionamos mais um elemento na lista, logo atualizamos o valor de tamanho
            return retornoAux;
        }

        // Caso for em outra posicao qualquer, procuramos o livro que está atualmente na posicao em que queremos inserir
        else {
            NodoLEnc2* novo = (NodoLEnc2*)malloc(sizeof(NodoLEnc2));
            novo->info = info;
            while (aux->prox != NULL && count < posicao - 1) {
                aux = aux->prox;
                count++;
            }

            // Fazemos a insercao na posicao resultante do while acima
            novo->prox = aux->prox;     // O proximo de novo é o proximo do nodo que está ocupando a posicao atualmente
            novo->ant = aux;            // O anterior de novo é o nodo que está ocupando a posicao atualmente
            if (aux->prox != NULL)      // Verificamos se estamos inserino no final da lista ou nao
                aux->prox->ant = novo;  // Atualizamos o ponteiro ant do nodo seguinte para que ele aponte para o novo nodo
            aux->prox = novo;           // Atualizamos o ponteiro prox do nodo anterior para que ele aponte para o novo nodo

            lista->tamanho += 1;        // Adicionamos mais um elemento na lista, logo atualizamos o valor de tamanho
            return 1;
        }
    }
    else {
        return 0;   // Retorna uma flag de erro caso a posicao estiver fora da lista, ou seja, posicao maior que tamanhoLista
    }

}

// Funcao que imprime uma lista comecando pelo final
void imprimeInversoLista(ListaEnc2Plus* lista) {
    NodoLEnc2* aux;
    printf("-----------------------------------------\n");
    for (aux = lista->prim; aux->prox != NULL; aux = aux->prox); // Percorre toda a lista até o final
    while (aux != NULL) {
        imprimeLivro(aux->info);
        aux = aux->ant;
    }
    printf("-----------------------------------------\n");
}

// Funcao que inverte uma lista duplamente encadeada
void inverteLista(ListaEnc2Plus* lista) {
    NodoLEnc2* atual = lista->prim;     // Começaramos a inversao pelo inicio
    NodoLEnc2* aux;
    // Basicamente, para cada nodo do meio da lista, invertemos os ponteiros ant e prox
    while (aux != NULL) {                 // Percorremos toda a lista
        aux = atual->prox;              // aux sempre atua como o proximo nodo na lista (proximo do atual)
        atual->prox = atual->ant;       // O proximo de cada nodo passa a ser seu anterior
        atual->ant = aux;               // O anterior de cada nodo passa a ser o seu proximo (recuperamos esse valor graças ao nodo aux)
        if (aux != NULL)                 // Adicionamos esse if para guardar a posicao do ultimo elemento da lista invertida e apontar lista->prim para ele
            atual = aux;                // Atual recupera a posicao de aux para que continuemos avançando na lista
    }
    lista->prim = atual;                // O primeiro item da lista passa a ser o atual (guardamos seu endereco graças ao if dentro do while)
}



