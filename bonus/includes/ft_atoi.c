/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:50:37 by eniglesi          #+#    #+#             */
/*   Updated: 2023/03/16 11:05:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap_bonus.h"

int	ft_atoi(const char *nptr)
{
	int	a;
	int	b;
	int	neg;

	neg = 0;
	a = 0;
	b = 0;
	while (nptr[b] == 32 || nptr[b] == 9 || nptr[b] == 10 || nptr[b] == 11
		|| nptr[b] == 12 || nptr[b] == 13)
		b++;
	if (nptr[b] == '-')
		neg++;
	else if (nptr[b] == '+')
		b++;
	b = b + neg;
	while (nptr[b] != '\0' && nptr[b] > 47 && nptr[b] < 58)
	{
		a = a * 10 + (nptr[b] - 48);
		b++;
	}
	if (neg % 2 == 1)
		a = a * -1;
	return (a);
}
