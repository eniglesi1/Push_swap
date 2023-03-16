/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:49:20 by eniglesi          #+#    #+#             */
/*   Updated: 2023/03/15 14:38:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./printf/ft_printf.h"

typedef struct s_list
{
	int				num;
	char			bin[33];
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_list			*a;
	t_list			*b;
}	t_data;

long int	ft_atol(char *str);

char		*args_to_str(char **argv);
char		*itobin(unsigned int num, char *aux, int neg);

void		clean_list(t_list *list);
void		parseo(char *str, char **a);
void		check(t_data *data, char **argv);

void		rotate(t_list **list, char *str);
void		reverse_rotate(t_list **list, char *str);
void		swap(t_list **list, char *str);
void		push(t_list **src, t_list **dst, char *str);

t_list		*new_node(int num);

#endif
