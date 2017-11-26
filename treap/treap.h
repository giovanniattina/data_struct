#ifndef TREAP_H
#define TREAP_H

#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
  int valor;
  int prioridade;
}item;


typedef struct nodo nodo;

struct nodo{

  nodo *esquerda, *direita;
  item i;
};

typedef struct {
  nodo *raiz;
}arvore;

nodo *cria(int i);
nodo* insere(nodo *raiz, int chave);
nodo *deleta(nodo *raiz, int chave);
nodo *busca(nodo *raiz, int chave);
nodo *rotacao_esquerda(nodo *x);
nodo *rotacao_direita(nodo *x);
void libera(nodo *x);
void libera_arvore (nodo *raiz);

#endif
