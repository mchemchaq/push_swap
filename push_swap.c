/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:04:02 by mchemcha          #+#    #+#             */
/*   Updated: 2024/02/25 17:29:36 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include <sys/_types/_null.h>
#include <unistd.h>


int	main(int ac, char *av[])
{
	int		i;
	t_stack	*list;
	t_stack	*stack_b;
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

	
	stack_b = NULL;
	p_b(&list, &stack_b);
	p_b(&list, &stack_b);
	p_b(&list, &stack_b);
	p_b(&list, &stack_b);
	p_b(&list, &stack_b);
	p_b(&list, &stack_b);


	p_a(&list, &stack_b);
	p_a(&list, &stack_b);
	puts("---->");

	printf_lst_next(list);
	// p_a(&list, &stack_b);

	// p_a(&list, &stack_b);

	// p_a(&list, &stack_b);
	// p_b(&list, &stack_b);
	
	puts("---->");
	printf_lst_next(stack_b);
	// printf_lst_next(stack_b);


	puts("--->");
	
}
