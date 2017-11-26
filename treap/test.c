#include "treap.h"



int main(){
    srand(time(NULL));
      arvore *a = (arvore*)malloc(sizeof(arvore));
      a->raiz = insere(a->raiz, 50);
      a->raiz = insere(a->raiz, 30);
      a->raiz = insere(a->raiz, 20);
      a->raiz = insere(a->raiz, 40);
      a->raiz = insere(a->raiz, 70);
      a->raiz = insere(a->raiz, 60);
      a->raiz = insere(a->raiz, 80);

      a->raiz = deleta(a->raiz, 20);

      a->raiz = deleta(a->raiz, 30);

      a->raiz = deleta(a->raiz, 50);

      busca(a->raiz, 50);


  libera_arvore(a->raiz);
  free(a);
  return 0;
}
