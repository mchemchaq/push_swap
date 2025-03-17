/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finel_linked.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:01:14 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:39:30 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	return (lst->prev);
}

t_stack	*ft_lstnew(int c)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (list == NULL)
		return (NULL);
	list->index = 0;
	list->t_p = -1;
	list->cost = 0;
	list->position = 0;
	list->t_cost = 0;
	list->total = 0;
	list->c = c;
	list->next = list;
	list->prev = list;
	return (list);
}

void	ft_lstadd_back(t_stack **lst, t_stack *newlst)
{
	t_stack	*last;
	t_stack	*first;

	if (*lst == NULL)
		*lst = newlst;
	else
	{
		first = *lst;
		last = ft_lstlast(*lst);
		last->next = newlst;
		newlst->next = first;
		first->prev = newlst;
		newlst->prev = last;
	}
}

void	ft_lstadd_front(t_stack **lst, t_stack *newlst)
{
	if (*lst == NULL)
		*lst = newlst;
	else
	{
		ft_lstadd_back(lst, newlst);
		*lst = newlst;
	}
}

int	ft_lstsize(t_stack *lst)
{
	t_stack	*i;
	int		s;
	t_stack	*last;

	last = ft_lstlast(lst);
	s = 1;
	i = lst;
	if (lst == NULL)
		return (0);
	while (i != last)
	{
		s += 1;
		i = i->next;
	}
	return (s);
}
