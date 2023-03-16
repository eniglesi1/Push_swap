/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:18 by codespace         #+#    #+#             */
/*   Updated: 2023/03/15 12:26:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	rotate(t_list **list, char *str)
{
	t_list	*aux;

	if ((*list)->next)
	{
		aux = *list;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = *list;
		*list = (*list)->next;
		aux = aux->next;
		aux->next = NULL;
		write(1, str, ft_strlen(str));
	}
}

void	reverse_rotate(t_list **list, char *str)
{
	t_list	*aux;

	if ((*list)->next)
	{
		aux = *list;
		while ((*list)->next != NULL)
			(*list) = (*list)->next;
		(*list)->next = aux;
		while (aux->next != *list)
			aux = aux->next;
		aux->next = NULL;
		write(1, str, ft_strlen(str));
	}
}

void	swap(t_list **list, char *str)
{
	t_list	*aux;

	if ((*list)->next)
	{
		aux = *list;
		(*list) = (*list)->next;
		aux->next = (*list)->next;
		(*list)->next = aux;
		write(1, str, ft_strlen(str));
	}
}

void	push(t_list **src, t_list **dst, char *str)
{
	t_list	*aux;

	if (*src)
	{
		aux = *src;
		(*src) = (*src)->next;
		aux->next = *dst;
		*dst = aux;
		write(1, str, ft_strlen(str));
	}
}
