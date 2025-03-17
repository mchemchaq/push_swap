/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:21:43 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:45:04 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*new_list(char *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list -> content = content;
	list -> next = NULL;
	return (list);
}

t_list	*last(t_list *lst)
{
	t_list	*p;

	p = lst ;
	while (p != NULL && p -> next != NULL)
	{
		p = p -> next;
	}
	return (p);
}

void	add_back(t_list **lst, t_list *newlst)
{
	t_list	*p;

	if (lst == NULL || newlst == NULL)
		return ;
	if (*lst == NULL)
		*lst = newlst;
	else
	{
		p = last(*lst);
		p -> next = newlst;
	}
}

int	size_instra(t_list *lst)
{
	t_list	*i;
	int		s;

	s = 0;
	i = lst;
	if (lst == NULL)
		return (0);
	while (i != NULL)
	{
		s += 1;
		i = i -> next;
	}
	return (s);
}
