#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "linked_list.h"

typedef struct nodoLEnc2 {
	char info;               // Info é apenas um outro nome para a struct Livro
	struct nodoLEnc2* ant;
	struct nodoLEnc2* prox;
} NodoLEnc2;

typedef struct ListaEnc2Plus {
	struct nodoLEnc2* prim;
	int tamanho;             // Variável que guarda o tamanho da lista
} ListaEnc2Plus;

// Funcao que cria uma lista
ListaEnc2Plus* criaLista();

// Funcao que destroi uma lista
void destroiLista(ListaEnc2Plus* lista);

// Funcao que imprime todos os nodos de uma lista
void imprimeLista(ListaEnc2Plus* lista);

// Funcao que insere um nodo no inicio de uma lista
int insereInicioLista(ListaEnc2Plus* lista, char info);

// Funcao que resgata um nodo com uma informacao de uma lista
NodoLEnc2* buscaInfoLista(ListaEnc2Plus* lista, int matricula);

// Funcao que remove um nodo com uma informacao de uma lista
int removeInfoLista(ListaEnc2Plus* lista, int matricula);

// Funcao que calcula o tamanho da lista
int tamanhoLista(ListaEnc2Plus* lista);

// Funcao que adiciona um livro em uma posicao especifica da lista
int insereEmPosicaoLista(ListaEnc2Plus* lista, char info, int posicao);

// Funcao que imprime uma lista comecando pelo final
void imprimeInversoLista(ListaEnc2Plus* lista);

// Funcao que inverte uma lista duplamente encadeada
void inverteLista(ListaEnc2Plus* lista);

#endif
