/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:44:44 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:40:39 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*to_list(int *tab, int len)
{
	int		i;
	t_stack	*list;
	t_stack	*p;

	list = NULL;
	i = 0;
	while (i < len)
	{
		p = ft_lstnew(tab[i]);
		if (list == NULL)
			list = p;
		else
			ft_lstadd_back(&list, p);
		i++;
	}
	return (list);
}
