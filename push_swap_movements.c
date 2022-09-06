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

t_list *newnode (void)
{
	printf("			newmode\n");
	t_list *a;

	a = (t_list *)malloc(sizeof(t_list));
	if (!a)
		exit(write(1, "Error\n", 5) - 5);
	a->next = NULL;
	printf("			completo\n");
	return a;
}

void	print_list(t_data *data)
{
	t_list	*a;
	int i;

	i = 0;
	a = data->a;
	printf("------------------------------\nImprimiendo lista:\n");
	while (a)
	{
		printf("     a%d : -%d-\n", i, a->content);
		i++;
		a = a->next;
	}
	
}

void	r(t_data *data, int i)
{
	printf("r\n");
	print_list(data);
	t_list	*a;
	t_list	*b;

	if (i == 1)
		a = data->b;
	else
		a = data->a;
	b = a;
	if (a)
	{
		while (a->next)
			a = a->next;
		a->next = b;
		if (i == 1)
			data->b = b->next;
		else
			data->a = b->next;
		b->next = NULL;
	}
	printf("				inr %d\n", *data->first);
	printf("				inr %d\n", *data->last);
	sleep(2);
	
	write(1, "r", 1);
	if (i == 1)
		write(1, "b", 1);
	else
		write(1, "a", 1);
	printf("completo\n");
	print_list(data);
	limits(data, i);
}

void	p(t_data *data, int i)
{
	printf("p\n");
	t_list	*a;
	t_list	*b;

	a = data->a;
	b = data->b;
	if (i == 1)
	{
		a = data->b;
		b = data->a;
	}
	if (!a)
		a = newnode();
	if (!b)
		b = newnode();
	a->next = b;
	*b = *a;
	printf("completo\n");
}

int	isorg(t_data *data, int i)
{
	printf("	isorg\n");
	t_list	*a;
	t_list	*b;

	a = data->a;
	b = data->b;
	if (a)
	{
		while (a->next)
		{
			if (a->content > a->next->content && (i == 0 || i == 2))
				return (printf("	completo1\n") - printf("	completo2\n") + 1);
			a = a->next;
		}
	}
	if (b)
	{
		while (b->next)
		{
			if (b->content > b->next->content && (i == 1 || i == 2))
				return (printf("	completo3\n") - printf("	completo4\n") + 1);
			b = b->next;
		}
	}
	printf("	completo\n");
	return 0;
}

/*void	r(t_data *data, int i)
{
	
}
*/
