/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:48:14 by eniglesi          #+#    #+#             */
/*   Updated: 2023/03/16 11:05:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;

	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	a = 0;
	while (a < (size - 1) && src[a] != '\0')
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (ft_strlen(src));
}
