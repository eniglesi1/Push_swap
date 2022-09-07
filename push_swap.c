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
	printf("		numparam\n");
	if (argc == 1)
		exit(write(1, "Error, número de parametros incorrecto\n", 40) - 40);
	printf("		completo\n");
}

void	nochars(char **argv)
{
	printf("			nochars\n");
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
	printf("			completo\n");
}

t_list	*allints(char **argv)
{
	printf("		allints\n");
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
	printf("		completo\n");
	return	c;
}

void	dupnum(t_list *a)
{
	printf("dupnum\n");
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
				exit(write(1, "Error\n", 5) - 5);
			a = a->next;
		}
		b = b->next;
		a = b;
	}
	printf("completo\n");
}

t_list	*parseo(int argc, char **argv)
{
	printf("	parseo\n");
	t_list	*a;

	numparam(argc);
	a = allints(argv);
	dupnum(a);
	printf("	completo\n");
	return a;
}

void	limits(t_data *data, int i)
{
	printf("	limits\n");
	t_list	*a;

	if (i == 0)
		a = data->a;
	if (i == 1)
		a = data->b;
	if (a)
	{
		data->first = &a->content;
		printf("	first - %d\n", *data->first);
		data->min = a->content;
		printf("	min - %d\n", data->min);
		data->max = a->content;
		printf("	max - %d\n", data->max);
		while (a)
		{
			if (a->content > data->max)
				data->max = a->content;
			printf("	min - %d\n", data->min);
			if (a->content < data->min)
				data->min = a->content;
			printf("	max - %d\n", data->max);
			data->last = &a->content;
			printf("	last - %d\n", *data->last);
			a = a->next;
		}
		printf("	completo \n		min -%d-\n		max -%d-\n		first -%d-\n		last -%d-\n", data->min, data->max, *data->first, *data->last);
	}
}


void	org(t_data *data, int i)
{
	printf("org %d\n", i);
	limits(data, i);
	if (isorg(data,i))
		r(data, i + 1); //when i = 1 rb when i = 2 ra
	while (isorg(data, i))//when i = 0 a when i = 1 b
	{
		printf("				While %d\n", *data->last);
		if (*data->first == data->min)
			r(data, i); //when i = 0 ra when i = 1 rb
		while (*data->first > *data->last && *data->first != data->min)
			r(data, i);//when i = 0 ra when i = 1 rb
		printf("				While2 %d\n", *data->last);
		while (*data->first < *data->last && *data->first != data->min)
			p(data, i);//when i = 0 pb(p to b) when i = 1 pa (p to a)
		printf("				completo\n");
	}
	printf("completo\n");
}

void	org_ab(t_data *data)
{
	printf("org_ab\n");
	while (isorg(data, 2))
	{
		org(data, 0);
		org(data, 1);
	}
	limits(data, 0);
	while(data->b || isorg(data, 0))
	{
		if (data->b)
		{
			if (data->b->content > *data->last && data->b->content < data->a->content)
				p(data, 1);
			else
				r(data, 0);
		}
		else
			while (isorg(data, 0))
				r(data,0);
	}
	printf("completo\n");
}

int	main(int argc, char **argv)
{
	printf("main\n");
	t_data	data;

	data.a = parseo(argc, argv);
	data.i = 1;
	org_ab(&data);
	printf("completo\n");
	return (0);
}
