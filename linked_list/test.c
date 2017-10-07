#include "linked_list.h"



int main(){

	t_list t;
	create_list(&t);

	add_sort(&t, 1);
	add_sort(&t, 2);
	add_sort(&t, 10);
	delete_item(&t, search(&t, 1));
	add_sort(&t, 5);
	add_sort(&t, 1);
	show_itens(&t);



	return 0;
}