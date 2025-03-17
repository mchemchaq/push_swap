/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:21:56 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:42:44 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	s_a(t_stack **stack_a, int i)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	if (!(*stack_a))
		return ;
	a = *stack_a;
	b = a->next;
	c = a->next->next;
	b->next = b;
	b->prev = b;
	a->next = c;
	c->prev = a;
	ft_lstadd_front(stack_a, b);
	if (i == 1)
		write(1, "sa\n", 3);
}

void	s_b(t_stack **stack_a, int i)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	if (!(*stack_a))
		return ;
	a = *stack_a;
	b = a->next;
	c = a->next->next;
	b->next = b;
	b->prev = b;
	a->next = c;
	c->prev = a;
	ft_lstadd_front(stack_a, b);
	if (i == 1)
		write(1, "sb\n", 3);
}

void	s_s(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i == 1)
		write(1, "ss\n", 3);
	s_a(stack_a, 0);
	s_a(stack_b, 0);
}
