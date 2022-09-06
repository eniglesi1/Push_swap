#include "./push_swap.h"

t_list newnode (void)
{
	t_list a;

	a = (t_list *)malloc(sizeof(t_list));
	if (!a)
		exit(write(1, "Error\n", 5) - 5);
	a->next = NULL;
	return a;
}

p

r

