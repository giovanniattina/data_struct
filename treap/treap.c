#include "treap.h"



nodo *cria(int i){
  nodo *n = (nodo*)malloc(sizeof(nodo));

  n->i.valor = i;
  n->i.prioridade = rand()%100;
  n->direita = NULL; n->esquerda = NULL;

  return n;

}
nodo* insere(nodo *raiz, int chave){
  //se o ROOT for NULL cria nodo
  if(!raiz) return cria(chave);

  if(chave < raiz->i.valor){// chave menor que a raiz
    raiz->esquerda = insere(raiz->esquerda, chave);

    //se a prioridade da heap foi violada
    if(raiz->esquerda->i.prioridade > raiz->i.prioridade) raiz = rotacao_direita(raiz);

  }else{//chave maior que a  raiz
    raiz->direita = insere(raiz->direita, chave);

    //se a prioridade da heap foi violada
    if(raiz->direita->i.prioridade > raiz->i.prioridade) raiz = rotacao_esquerda(raiz);

  }

  return raiz;
}

nodo *deleta(nodo *raiz, int chave){
  //se a raiz for nula
  if(raiz == NULL) return raiz;

  //se a chave não esta na raiz
  //chave do lado esquerdo
  if(chave < raiz->i.valor) raiz->esquerda = deleta(raiz->esquerda, chave);
  //chave do lado direita
  else if(chave > raiz->i.valor) raiz->direita = deleta(raiz->direita, chave);

  //se a chave esta na raiz
  //
  //ve se lado esquerda nao e' nulo
  else if(raiz->esquerda == NULL){
    nodo *temp = raiz->esquerda;
    libera(raiz);
    raiz = temp;
  }

  //ve se lado direito nao e' NULL
  else if(raiz->direita == NULL){
    nodo *temp = raiz->direita;
    libera(raiz);
    raiz = temp;
  }

  // se direita e esquerda nao sa~o nulos

  //se a prioridade da direita for maior que a da esquerda
  else if(raiz->esquerda->i.prioridade < raiz->direita->i.prioridade){
    raiz = rotacao_esquerda(raiz);
    raiz->esquerda = deleta(raiz->esquerda, chave);
  }
  //se a prioridade da esquerda for maior
  else{
    raiz = rotacao_direita(raiz);
    raiz->direita = deleta(raiz->direita, chave);
  }

  return raiz;
}

nodo *rotacao_esquerda(nodo *x){
  nodo *y = x->direita, *aux = y->esquerda;

  y->esquerda = x;
  x->direita = aux;

  return y;
}

nodo *rotacao_direita(nodo *x){
  nodo *y = x->esquerda, *aux = y->direita;

  y->direita = x;
  x->esquerda = aux;

  return y;
}

void libera(nodo *x){
  free(x);
}

nodo *busca(nodo *raiz, int chave){
  //se for nulo ou acho a chave
  if(raiz == NULL || raiz->i.valor == chave){
    return raiz;
  }
  //se nao, valor da raiz e maior que a chave vai para direita
  if(raiz->i.valor > chave) return busca(raiz->direita, chave);
  return busca(raiz->esquerda, chave);

}


void libera_arvore (nodo *raiz){
  if(raiz != NULL ){
    //se nao, valor da raiz e maior que a chave vai para direita
    libera_arvore(raiz->esquerda);
    libera_arvore(raiz->direita);
    printf("oi\n");
    free(raiz);
    return;
  }

}
