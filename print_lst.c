/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:29 by mchemcha          #+#    #+#             */
/*   Updated: 2024/02/20 21:19:36 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    printf_lst_next(t_stack *list)
{
    t_stack *p;
    
    if (list == NULL)
        return;
    p = list;
    do {
        printf("%d\n", p->content);
        p = p->next;
    } while (p != list);
}


void    printf_lst_prev(t_stack *list)
{
    t_stack *head;
    
    head = list;
    while(list)
    {
        printf("%d\n",list->content);
        list = list->prev;
        if(head == list)
            break; 
    }
}
