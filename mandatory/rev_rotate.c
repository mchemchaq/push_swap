/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:25:00 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:42:52 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_r_a(t_stack **stack_a, int i)
{
	if (!(*stack_a))
		return ;
	*stack_a = ft_lstlast(*stack_a);
	if (i == 1)
		write(1, "rra\n", 4);
}

void	r_r_b(t_stack **stack_a, int i)
{
	if (!(*stack_a))
		return ;
	*stack_a = ft_lstlast(*stack_a);
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	r_r_r(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i == 1)
		write(1, "rrr\n", 4);
	r_r_a(stack_a, 0);
	r_r_b(stack_b, 0);
}
