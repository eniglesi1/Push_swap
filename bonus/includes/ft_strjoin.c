/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:23:07 by eniglesi          #+#    #+#             */
/*   Updated: 2023/03/16 11:05:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*a;

	i = ft_strlen(s2) + ft_strlen(s1) + 1;
	if (i == 0)
		return (NULL);
	a = malloc(sizeof(char) * i + 1);
	if (!a)
		return (NULL);
	ft_strlcpy(a, s1, i + 1);
	ft_strlcat(a, s2, i + 1);
	return (a);
}
