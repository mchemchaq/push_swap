/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:04:02 by mchemcha          #+#    #+#             */
/*   Updated: 2024/02/26 21:47:39 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int ac, char *av[])
{
	int		i;
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
	list = to_list(tab);
	Longest_Increasing_Subsequence(list);
}
