/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:31 by codespace         #+#    #+#             */
/*   Updated: 2023/03/15 14:09:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

int	char_in_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32
			&& str[i] != '-' && str[i] != '+'
			&& (str[i] <= 47 || str[i] >= 58))
			return (1);
		if ((str[i] == '+' || str[i] == '-')
			&& (i > 0 && str[i - 1] != ' '))
			return (1);
		i++;
	}
	return (0);
}

int	int_max(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		if (ft_atol(a[i]) > 2147483647 || ft_atol(a[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	isdup(char **a)
{
	int	i;
	int	j;

	i = 0;
	while (a[i])
	{
		j = i;
		while (a[++j])
			if (ft_atol(a[j]) == ft_atol(a[i]))
				return (1);
		i++;
	}
	return (0);
}

void	parseo(char *str, char **a)
{
	if (char_in_str(str) || int_max(a) || isdup(a))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}
