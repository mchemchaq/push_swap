/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:28:16 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:43:37 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_a(t_stack **stack_a, int i)
{
	t_stack	*a;
	t_stack	*first;

	if (!(*stack_a))
		return ;
	first = *stack_a;
	a = first->next;
	*stack_a = a;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	r_b(t_stack **stack_b, int i)
{
	t_stack	*b;
	t_stack	*first;

	if (!(*stack_b))
		return ;
	first = *stack_b;
	b = first->next;
	*stack_b = b;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	r_r(t_stack **stack_a, t_stack **stack_b, int i)
{
	r_a(stack_a, 0);
	r_b(stack_b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
