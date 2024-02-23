/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:39:37 by mchemcha          #+#    #+#             */
/*   Updated: 2024/02/21 17:16:40 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int check_empty(char *s)
{
    if(s[0] == '\0')
        ft_error("Error");
    return(1);
}
int check_int(char **tab)
{
    int i = 0;
    int j ;
    while(tab[i])
    {
        j = 0;
        if(tab[i][j] == '-' || tab[i][j] == '+')
            j++;
        while (tab[i][j])
        {
            if(ft_isdigit(tab[i][j]))
                j++;
            else
                return(0);
        }
        i++;       
    }
    return (1);
}
int check_space(char *s)
{
    int i = 0;

    if(s[i] == '-' || s[i] == '+')
        i++;
    
    if(s[0] == ' ')
    {
        while(s[i] == ' ')
            i++;
        if(s[i] == '\0')
            ft_error("Error");
    }
    while(s[i])
    {
        if(ft_isdigit(s[i]) || s[i] == '-' || s[i] == '+')
            i++;
        else if(s[i] != ' ')
            ft_error("Error");
        else
            return(1);
    }
    return (1);
}
int check_min_max(char **tab)
{
    int i = 0;
    while(tab[i])
    {
        if(ft_atoi(tab[i]) > INT_MAX || ft_atoi(tab[i]) < INT_MIN)
            return(0);
        i++;
    }
    return (1);
}
int check_dubl(char **tab)
{
    int i = 0;
    int j ;
    
    while(tab[i])
    {
        j = i + 1;
        while(tab[j])
        {
            if(ft_strncmp(tab[i], tab[j], 10)== 0)
                return(0);
            else 
                j++;
        }
        i++;
    }
    return (1);
}
int parcing(char **tab)
{
    t_stack *list;
    if (!check_dubl(tab) || !check_min_max(tab) || !check_int(tab))
        ft_error("Error");
    else
    {
        list = to_list(tab);
    }
    return(1);
}
