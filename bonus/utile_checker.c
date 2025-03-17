/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:29:44 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:45:13 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	compar(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			return (0);
			break ;
		}
		if ((s1[i] == '\0' && s2[i] != '\0')
			|| (s1[i] != '\0' && s2[i] == '\0'))
		{
			return (0);
			break ;
		}
	}
	return (1);
}

void	check_list_sort(t_stack *list)
{
	int		i;
	t_stack	*last;
	t_stack	*compar;
	t_stack	*first;

	first = list;
	compar = list->next;
	last = ft_lstlast(list);
	i = 0;
	while (compar)
	{
		if (first == last)
			break ;
		if (first->c < compar->c)
		{
			first = first->next;
			compar = compar->next;
		}
		else
			ft_error("KO");
	}
	ft_ok("OK");
}

void	lst_clear_inst(t_list **list)
{
	int		s;
	int		i;
	t_list	*tmp;
	t_list	*court;

	i = 0;
	tmp = *list;
	s = size_instra((*list));
	while (i < s)
	{
		court = tmp;
		tmp = tmp->next;
		free (court);
		i++;
	}
	*list = NULL;
}
