#include "linked_list.h"


void create_list(t_list *l){
	t_item *L = malloc(sizeof(t_item));

	l->qnt = 0;
	l->L = L;
	l->L->prev = l->L;
	l->L->next = l->L->prev;
}

void add_item(t_list *l, int item){

	t_item *t = malloc(sizeof(t_item));
	t->data.d = item;

	t->next = l->L->next;
	printf("oi\n");
	l->L->next->prev = t;
	l->L->next = t;
	t->prev =  l->L;
	l->qnt++;

}
void delete_item(t_list *l, t_item *item){
	l->qnt--;
	item->prev->next = item->next;
	item->next->prev = item->prev;
}

t_item *search(t_list *l, int k){
	t_item *t = l->L->next;
	while(t != l->L && t->data.d != k) t = t->next;

	return t;

}

void show_itens(t_list *l){
	t_item *t = l->L->next;
	while(t != l->L){
		printf("%d\n", t->data.d);
		t = t->next;
	}
}

void add_sort(t_list *l, int item){
	t_item *t = malloc(sizeof(t_item));

	t->data.d = item;

	t_item *aux = l->L->next;

	while(aux != l->L && aux->data.d >= item) aux = aux->next;

	aux->prev->next = t;
	t->prev = aux->prev;
	t->next = aux;
	aux->prev = t;
}
