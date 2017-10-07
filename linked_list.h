#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int d;
}t_data;

typedef struct t_item t_item;

struct t_item{

	t_data data;
	t_item *next;
	t_item *prev;

};

typedef struct {
	int qnt;
	t_item *L;
}t_list;


void create_list(t_list *l);
void add_item(t_list *l, int item);
void delete_item(t_list *l, t_item *item);
t_item *search(t_list *l, int k);
void show_itens(t_list *l);
void add_sort(t_list *l, int item);


#endif