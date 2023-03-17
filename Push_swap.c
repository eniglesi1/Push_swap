/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:39 by codespace         #+#    #+#             */
/*   Updated: 2023/03/17 13:58:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	isorded(t_list *list, int i)
{
	if (list && list->next)
	{
		if (list->num > list->next->num
			|| (i == 1 && list->num < list->next->num))
			return (0);
		return (isorded(list->next, i) * 1);
	}
	return (1);
}

int	list_len(t_list *list)
{
	if (list)
		return (list_len(list->next) + 1);
	return (0);
}

int	ispositioned(t_data *data)
{
	int	aux;

	reverse_rotate(&(data->a), "");
	aux = data->a->num;
	rotate(&(data->a), "");
	return ((data->b->num < data->a->num && aux < data->b->num)
		|| (data->b->num == 1 && (data->a->num == 2 || aux == 5))
		|| (data->b->num == 5 && (data->a->num == 1 || aux == 4))
		|| (data->b->num == 2 && (data->a->num == 3 && aux == 5))
		|| (data->b->num == 4 && (data->a->num == 1 && aux == 3)));
}

void	three_five(t_data *data)
{
	while (!isorded(data->a, 0))
		if (data->a->num < data->a->next->num
			&& data->a->num > data->a->next->next->num)
			reverse_rotate(&(data->a), "rra\n");
	else if (data->a->num > data->a->next->num
		&& data->a->num > data->a->next->next->num)
		rotate(&(data->a), "ra\n");
	else
		swap(&(data->a), "sa\n");
	while (data->b)
		if (ispositioned(data))
			push(&(data->b), &(data->a), "pa\n");
	else
		if ((data->a->num == ((data->b->num + 3) % 5) + 1))
			rotate(&(data->a), "ra\n");
	else
		reverse_rotate(&(data->a), "rra\n");
	while (!isorded(data->a, 0))
		if (data->a->num > 3)
			rotate(&(data->a), "ra\n");
	else
		reverse_rotate(&(data->a), "rra\n");
}

void	push_swap(t_data *data)
{
	int	i;
	int	listlen;

	i = 32;
	if (list_len(data->a) <= 5 && !isorded(data->a, 0))
		while (list_len(data->a) > 3)
			push(&(data->a), &(data->b), "pb\n");
	if (list_len(data->a) == 3)
		three_five(data);
	while (--i >= 0 && !isorded(data->a, 0))
	{
		listlen = list_len(data->a);
		while (listlen-- > 0)
			if (data->a->bin[i] == '0')
				push(&(data->a), &(data->b), "pb\n");
		else
			rotate(&(data->a), "ra\n");
		while (data->b)
			push(&(data->b), &(data->a), "pa\n");
	}
}
