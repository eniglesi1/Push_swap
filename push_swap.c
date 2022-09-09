/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniglesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:15:34 by eniglesi          #+#    #+#             */
/*   Updated: 2022/05/13 12:15:36 by eniglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	numparam(int argc)
{
	if (argc == 1)
		exit(write(1, "Error, número de parametros incorrecto\n", 40) - 40);
}

void	nochars(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != 32 && argv[i][j] != 9 && argv[i][j] != 10
				&& argv[i][j] != 11 && argv[i][j] != 12 && argv[i][j] != 13
				&& argv[i][j] != '-' && argv[i][j] != '+'
				&& (argv[i][j] < 47 || argv[i][j] > 58))
			{
				exit(write(1, "Error. char\n", 11) - 11);
			}
				j++;
		}
				i++;
	}
}

t_list	*allints(char **argv)
{
	int		i;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	nochars(argv);
	b = newnode();
	b->content = atoi(argv[1]);
	b->next = NULL;
	i = 2;
	c = b;
	while (argv[i])
	{
		a = newnode();
		a->content = atoi(argv[i]);
		b->next = a;
		b = b->next;
		i++;
	}
	return (c);
}

void	dupnum(t_list *a)
{
	int		i;
	t_list	*b;

	b = a;
	while (b)
	{
		a = a->next;
		i = b->content;
		while (a)
		{
			if (a->content == i)
				exit(write(1, "Error, número duplicado\n", 25) - 25);
			a = a->next;
		}
		b = b->next;
		a = b;
	}
}

t_list	*parseo(int argc, char **argv)
{
	t_list	*a;

	numparam(argc);
	a = allints(argv);
	dupnum(a);
	return (a);
}

void	limits(t_data *data, int i)
{
	t_list	**a;

	if (i == 0 || i == 2)
		a = &data->a;
	if (i == 1)
		a = &data->b;
	printf("Antes\n");
	if (a)
	{
		data->first = *a;
		data->min = **a;
		data->max = **a;
		while (*a)
		{
			if ((*a)->content > data->max.content)
				data->max = **a;
			if ((*a)->content < data->min.content)
				data->min = **a;
			data->last = *a;
			(*a) = (*a)->next;
		}
		*a = data->first;
	}
	printf("Después\n");
	printf(" ---  LIMITS  --- \n -%d- -%d- \n -%d- -%d- \n -%d- -%d- \n -%d- -%d- \n", data->first->content, data->first->numeration, data->min.content, data->min.numeration, data->max.content, data->max.numeration, data->last->content, data->last->numeration);
}
/*
void	org(t_data *data, int i)
{
	limits(data, i);
	if (isorg(data, i + 1))
		r(data, i + 1); //when i = 1 rb when i = 2 ra
	while (isorg(data, i)) //when i = 0 a when i = 1 b
	{
		if (*data->first == data->min)
			r(data, i); //when i = 0 ra when i = 1 rb
		while (*data->first > *data->last && *data->first != data->min)
			r(data, i);//when i = 0 ra when i = 1 rb
		while (*data->first < *data->last && *data->first != data->min)
			p(data, i);//when i = 0 pb(p to b) when i = 1 pa (p to a)
	}
}

void	org_ab(t_data *data)
{
	while (isorg(data, 2))
	{
		org(data, 0);
		org(data, 1);
	}
	limits(data, 0);
	while (data->b || isorg(data, 0))
	{
		if (data->b)
		{
			if (data->b->content > *data->last
				&& data->b->content < data->a->content)
				p(data, 1);
			else
				r(data, 0);
		}
		else
			while (isorg(data, 0))
				r(data, 0);
	}
}
*/

int		isnumered(t_data *data)
{
	t_list	*a;

	a = data->a;
	while(a)
	{
		if (a->numeration == 0)
			return (1);
		a = a->next;
	}
	return (0);
}

void	numered(t_data *data)
{
	t_list	*c;
	t_list	*min;
	int		i;

	i = 1;
	while (isnumered(data))
	{
		min = data->a;
		c = data->a;
		while (c)
		{
			if (min->content > c->content && c->numeration == 0)
				min = c;
			else if (c->numeration == 0 && min->numeration != 0)
				min = c;
			c = c->next;
		}
		min->numeration = i;
		print_list(data);
		limits(data, 0);
		r(data, 0);
		sleep(5);
		i++;
	}
	data->i = i;
}

void	impar(t_data *data)
{
	limits(data, 0);
	
}

void	renumered(t_data *data)
{
	if (data->i % 2 == 1)
		impar(data);
}

void	org_ab(t_data *data)
{
	numered(data);
	print_list(data);
	renumered(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.a = parseo(argc, argv);
	org_ab(&data);
	return (0);
}
