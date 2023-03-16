/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:57 by codespace         #+#    #+#             */
/*   Updated: 2023/03/16 10:59:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap_bonus.h"

void	clean_list(t_list *list)
{
	t_list	*listaux;

	while (list)
	{
		listaux = list->next;
		free(list);
		list = listaux;
	}
}

char	*itobin(unsigned int num, char *aux, int neg)
{
	int	index;

	index = 32;
	while (--index > 0)
	{
		aux[index] = (num % 2) + '0';
		num /= 2;
	}
	aux[index] = '0';
	if (neg == 0)
		aux[index] = '1';
	return (aux);
}

t_list	*new_node(int num)
{
	t_list	*a;

	a = (t_list *)malloc(sizeof(t_list) + 1);
	a->num = num;
	itobin(num, &(a->bin[0]), num < 0);
	a->bin[32] = '\0';
	a->next = NULL;
	return (a);
}

char	*args_to_str(char **argv)
{
	char	*str;
	char	*aux;
	int		i;

	i = 0;
	aux = malloc(sizeof(char) * 1);
	aux[0] = '\0';
	while (argv[++i + 1])
	{
		str = ft_strjoin(aux, argv[i]);
		free(aux);
		aux = str;
		str = ft_strjoin(str, " ");
		free(aux);
		aux = str;
	}
	return (str);
}

long int	ft_atol(char *str)
{
	long int	a;
	long int	b;
	long int	neg;

	neg = 0;
	a = 0;
	b = 0;
	while (str[b] == 32 || str[b] == 9 || str[b] == 10 || str[b] == 11
		|| str[b] == 12 || str[b] == 13)
		b++;
	if (str[b] == '-')
		neg++;
	else if (str[b] == '+')
		b++;
	b = b + neg;
	while (str[b] != '\0' && str[b] > 47 && str[b] < 58)
	{
		a = a * 10 + (str[b] - 48);
		b++;
	}
	if (neg % 2 == 1)
		a = a * -1;
	return (a);
}
