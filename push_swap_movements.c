/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniglesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:03:10 by eniglesi          #+#    #+#             */
/*   Updated: 2022/09/06 12:03:13 by eniglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_list	*newnode(void)
{
	t_list	*a;

	a = (t_list *)malloc(sizeof(t_list));
	if (!a)
		exit(write(1, "Error\n", 5) - 5);
	a->next = NULL;
	return (a);
}

void	print_list(t_data *data)
{
	t_list	*a;
	int		i;

	i = 0;
	a = data->a;
	printf("------------------------------\nImprimiendo lista: a\n");
	while (a && i < 20)
	{
		printf("     a%d : -%d-\n", i, a->content);
		i++;
		a = a->next;
	}
	a = data->b;
	printf("------------------------------\nImprimiendo lista: b\n");
	while (a && i < 20)
	{
		printf("     a%d : -%d-\n", i, a->content);
		i++;
		a = a->next;
	}
}

void	r(t_data *data, int i)
{
	t_list	**a;
	t_list	*b;

	a = &data->a;
	if (i == 1)
		a = &data->b;
	b = *a;
	if (*a)
	{
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = b;
		*a = (*a)->next->next;
		b->next = NULL;
	}
	if (i == 1)
		write(1, "rb\n", 4);
	else
		write(1, "ra\n", 4);
//	print_list(data);
	limits(data, i % 2);
}

void	p(t_data *data, int i)
{
	t_list	**a;
	t_list	**b;
	t_list	*c;

	a = &data->a;
	b = &data->b;
	c = data->a->next;
	if (i == 1)
	{
		a = &data->b;
		b = &data->a;
		c = data->b->next;
	}
	(*a)->next = *b;
	*b = *a;
	*a = c;
	if (i == 1)
		write(1, "pa\n", 4);
	else
		write(1, "pb\n", 4);
//	print_list(data);
	limits(data, i);
}

int	isorg(t_data *data, int i)
{
	t_list	*a;
	t_list	*b;

	a = data->a;
	b = data->b;
	if (a)
	{
		while (a->next)
		{
			if (a->content > a->next->content && (i == 0 || i == 2))
				return (1);
			a = a->next;
		}
	}
	if (b)
	{
		while (b->next)
		{
			if (b->content > b->next->content && (i == 1 || i == 2))
				return (1);
			b = b->next;
		}
	}
	return (0);
}

void	rr(t_data *data, int i)
{
	t_list	**a;
	t_list	*b;

	a = &data->a;
	if (i == 1)
		a = &data->b;
	b = *a;
	if (*a)
	{
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = b;
		*a = (*a)->next->next;
		b->next = NULL;
	}
	if (i == 1)
		write(1, "rb\n", 4);
	else
		write(1, "ra\n", 4);
//	print_list(data);
	limits(data, i % 2);
}
