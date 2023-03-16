/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:49:20 by eniglesi          #+#    #+#             */
/*   Updated: 2023/03/16 11:21:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdio.h>

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

int			ft_atoi(const char *nptr);

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

long int	ft_atol(char *str);

char		*args_to_str(char **argv);
char		*itobin(unsigned int num, char *aux, int neg);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);

void		clean_list(t_list *list);
void		parseo(char *str, char **a);
void		check(t_data *data, char **argv);
void		ft_bzero(void *s, size_t n);

void		rotate(t_list **list, char *str);
void		reverse_rotate(t_list **list, char *str);
void		swap(t_list **list, char *str);
void		push(t_list **src, t_list **dst, char *str);

t_list		*new_node(int num);

#endif
