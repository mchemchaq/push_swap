/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_linked.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:09:13 by mchemcha          #+#    #+#             */
/*   Updated: 2024/02/17 10:47:19 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


noeud *to_list(char **tab)
{
    int i;
    noeud *list;

	list = NULL;
    i = 0;
    while (tab[i])
    {
		noeud *p = (noeud *)malloc(sizeof(noeud));
		p->content = *tab[i];
		p->next = NULL; 
		if (list == NULL) 
		{
			list = p;
		}else 
		{
			noeud *c = list;
			while (c->next != NULL) 
                c = c->next;
            c->next = p;
        }
		i++;
    }
    return(list);
}