/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Longest_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:50:13 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:45:31 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	longest_increasing_subsequence(t_stack *list, int mark)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		i;
	int		j;

	tmp2 = list;
	tmp = list;
	i = 0;
	while (tmp)
	{
		j = index_list(tmp, 0);
		if (j > i)
		{
			i = j;
			tmp2 = tmp;
		}
		tmp = tmp->next;
		if (tmp == list)
			break ;
	}
	if (mark == 1)
		index_list(tmp2, 1);
	return (i);
}

void	push_to_b(t_stack **list, t_stack **stack_b)
{
	int	lis;
	int	pivot;

	lis = longest_increasing_subsequence(*list, 1);
	sort_list(*list);
	pivot = ft_lstsize(*list) / 2;
	while (ft_lstsize(*list) > lis)
	{
		if ((*list)->lis == 0)
		{
			p_b(list, stack_b, 1);
			if ((*stack_b)->index > pivot)
				r_b(stack_b, 1);
		}
		else
			r_a(list, 1);
	}
}

int	check_sort(t_stack *list)
{
	int		i;
	t_stack	*last;
	t_stack	*compar;
	t_stack	*first;

	compar = list->next;
	first = list;
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
			return (0);
	}
	return (1);
}
