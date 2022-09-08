/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniglesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:49:20 by eniglesi          #+#    #+#             */
/*   Updated: 2022/06/20 12:49:22 by eniglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	int				numeration;
	int				position;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int		i;
	int		min;
	int		max;
	int		*first;
	int		*last;
	t_list	*a;
	t_list	*b;
}	t_data;

t_list	*newnode(void);
int		isorg(t_data *data, int i);
void	limits(t_data *data, int i);
void	p(t_data *data, int i);
void	r(t_data *data, int i);
void	rr(t_data *data, int i);
void	print_list(t_data *data);

#endif
