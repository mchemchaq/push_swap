/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:10:35 by mchemcha          #+#    #+#             */
/*   Updated: 2024/02/26 21:50:51 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int index_list(t_stack *list)
{
    int i;
    t_stack *cont = list;
    t_stack *compar = list -> next;
    i = 1;

    while (compar != list)
    {
        if(compar -> content >= cont -> content)
        {
            cont = compar;
            i++;
        }
        compar = compar -> next;
    }
    return(i);
}
t_stack Longest_Increasing_Subsequence(t_stack *list)
{
    t_stack *tmp = list;
    
    
    while(tmp)
    {
        int i = index_list(tmp);
        printf("%d----->%d\n", tmp -> content, i);
        tmp = tmp->next;
        if(tmp == list)
            break;
    }
    return(*tmp);
}