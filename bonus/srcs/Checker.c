/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:59:52 by codespace         #+#    #+#             */
/*   Updated: 2023/03/16 12:51:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap_bonus.h"

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

void	s(t_data *data, char *str)
{
	if (str[1] == 'a' && str[2] == '\0')
		swap(&(data->a), "");
	else if (str[1] == 'b' && str[2] == '\0')
		swap(&(data->b), "");
	else if (str[1] == 's' && str[2] == '\0')
	{
		swap(&(data->a), "");
		swap(&(data->b), "");
	}
	else
		exit(write(1, &"Error\n", 6) - 6);
}

void	r(t_data *data, char *str)
{
	if (str[1] == 'a' && str[2] == '\0')
		rotate(&(data->a), "");
	else if (str[1] == 'b' && str[2] == '\0')
		rotate(&(data->b), "");
	else if (str[1] == 'r' && str[2] == '\0')
	{
		rotate(&(data->a), "");
		rotate(&(data->b), "");
	}
	else if (str[1] == 'r' && str[2] == 'a' && str[3] == '\0')
		reverse_rotate(&(data->a), "");
	else if (str[1] == 'r' && str[2] == 'b' && str[3] == '\0')
		reverse_rotate(&(data->b), "");
	else if (str[1] == 'r' && str[2] == 'r' && str[3] == '\0')
	{
		reverse_rotate(&(data->a), "");
		reverse_rotate(&(data->b), "");
	}
	else
		exit(write(1, &"Error\n", 6) - 6);
}

void	movements(t_data *data, char *str)
{
	if (str[0] == 'r')
		r(data, str);
	else if (str[0] == 's')
		s(data, str);
	else if (str[0] == 'p')
	{
		if (str[1] == 'a' && str[2] == '\0')
			push(&(data->b), &(data->a), "");
		else if (str[1] == 'b' && str[2] == '\0')
			push(&(data->a), &(data->b), "");
		else
			exit(write(1, &"Error\n", 6) - 6);
	}
	else
		exit(write(1, &"Error\n", 6) - 6);
}

void	check(t_data *data, char **argv)
{
	int		i;
	char	**aux;

	i = 0;
	while (argv[++i + 1])
		;
	aux = ft_split(argv[i], ' ');
	i = -1;
	while (aux[++i])
	{
		movements(data, aux[i]);
	}
	if (isorded(data->a, 0) && data->b == NULL)
		write(1, &"OK\n", 3);
	else
		write(1, &"KO\n", 3);
	i = -1;
	while (aux[++i])
		free(aux[i]);
	free(aux);
}
