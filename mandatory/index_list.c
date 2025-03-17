/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:10:35 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:41:39 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_list(t_stack *list)
{
	int		i;
	t_stack	*first;
	t_stack	*tmp;
	int		s;
	int		size;

	size = ft_lstsize(list);
	first = list;
	tmp = list;
	i = 0;
	while (size--)
	{
		s = ft_lstsize(list);
		i = 0;
		while (s--)
		{
			if (first->c < tmp->c)
				i++;
			first = first->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
}

void	positionlist(t_stack *list)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(list);
	while (size--)
	{
		list->position = i;
		i++;
		list = list->next;
	}
}

t_stack	*min_list(t_stack *list)
{
	t_stack	*min_node;
	int		size;
	int		min;

	min = INT_MAX;
	size = ft_lstsize(list);
	positionlist(list);
	while (size)
	{
		if (list->index < min)
		{
			min = list->index;
			min_node = list;
		}
		list = list->next;
		size--;
	}
	return (min_node);
}

t_stack	*min_total_cost_list(t_stack *list)
{
	t_stack	*min_node;
	int		size;
	int		min;

	min = INT_MAX;
	size = ft_lstsize(list);
	positionlist(list);
	while (size)
	{
		if (list->total < min)
		{
			min = list->total;
			min_node = list;
		}
		list = list->next;
		size--;
	}
	return (min_node);
}

int	index_list(t_stack *list, int mark)
{
	int		i;
	t_stack	*cont;
	t_stack	*last;
	t_stack	*compar;

	compar = list;
	last = ft_lstlast(list);
	cont = list;
	i = 0;
	while (compar)
	{
		compar->lis = 0;
		if (compar->c >= cont->c)
		{
			cont = compar;
			if (mark)
				cont->lis = 1;
			i++;
		}
		if (compar == last)
			break ;
		compar = compar->next;
	}
	return (i);
}
