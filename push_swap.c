/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:04:02 by mchemcha          #+#    #+#             */
/*   Updated: 2024/02/23 18:45:20 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>


int	main(int ac, char *av[])
{
	int		i;
	int 	j;
	t_stack	*list;
	char	**tab;
	char	*s;
	
	if (ac < 2)
		exit (1);
	i = 0;
	while(av[++i])
	{
		check_empty(av[i]);
		check_space(av[i]);
	}
	s = av[1];
	i = 1;
	while(av[++i])
	{
		s = ft_strjoin(s, " ");
		s = ft_strjoin(s, av[i]);
	}
	tab = ft_split(s, ' ');
	parcing(tab);
	j = -1;
	while (tab[++j])
		*tab[j] = atoi(tab[j]);
	list = to_list(tab);
	// printf_lst_next(list);
	// printf("prev----->\n");
	s_a(&list);
	// r_a(&list);
	// r_r_a(&list);
	
	// printf_lst_next(list);
	// printf("<------>\n");
	// printf_lst_prev(list);
}
