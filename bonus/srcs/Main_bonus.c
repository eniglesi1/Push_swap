/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:26:08 by codespace         #+#    #+#             */
/*   Updated: 2023/03/16 12:24:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_swap_bonus.h"

int	numeration(t_list *list, t_list *list2)
{
	if (list2 && list->num > list2->num)
		return (numeration(list, list2->next) + 1);
	if (list2)
		return (numeration(list, list2->next) + 0);
	return (0);
}

t_list	*renum(t_list *list, t_list *list2)
{
	t_list	*a;

	if (list)
	{
		a = new_node(numeration(list, list2) + 1);
		a->next = renum(list->next, list2);
		return (a);
	}
	return (NULL);
}

t_list	*get_list(char **aux)
{
	t_list	*a;

	if (aux[0])
	{
		a = new_node(ft_atoi(aux[0]));
		a->next = get_list(&(aux[1]));
		return (a);
	}
	return (NULL);
}

void	clean(t_data *data, char **aux, char *str, t_list *temp)
{
	int		i;

	i = -1;
	clean_list(data->a);
	clean_list(data->b);
	clean_list(temp);
	while (aux[++i])
		free(aux[i]);
	free(aux[i]);
	free(aux);
	free(str);
	free(data);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**aux;
	t_data	*data;
	t_list	*temp;

	if (argc > 1)
	{
		data = (t_data *)malloc(sizeof(t_data) + 1);
		data->b = NULL;
		str = args_to_str(argv);
		aux = ft_split(str, ' ');
		parseo(str, aux);
		temp = get_list(aux);
		data->a = renum(temp, temp);
		check(data, argv);
		clean(data, aux, str, temp);
	}
}
