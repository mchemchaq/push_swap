/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_a_p_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:19:57 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:42:18 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	p_b(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*a;
	t_stack	*last;
	t_stack	*b;
	t_stack	*first;

	if (!*stack_a)
		return ;
	if (ft_lstsize(*stack_a) == 1)
	{
		first = *stack_a;
		ft_lstadd_front(stack_b, first);
		*stack_a = NULL;
		return ;
	}
	a = *stack_a;
	last = ft_lstlast(*stack_a);
	b = a->next;
	a->next = a;
	a->prev = a;
	b->prev = last;
	last->next = b;
	ft_lstadd_front(stack_b, a);
	*stack_a = b;
	if (i == 1)
		write(1, "pb\n", 3);
}

void	p_a(t_stack **stack_a, t_stack **stack_b, int i)
{
	t_stack	*a;
	t_stack	*last;
	t_stack	*b;
	t_stack	*first;

	if (!*stack_b)
		return ;
	if (i == 1)
		write(1, "pa\n", 3);
	if (ft_lstsize(*stack_b) == 1)
	{
		first = *stack_b;
		ft_lstadd_front(stack_a, first);
		*stack_b = NULL;
		return ;
	}
	a = *stack_b;
	last = ft_lstlast(*stack_b);
	b = a->next;
	a->next = a;
	a->prev = a;
	b->prev = last;
	last->next = b;
	ft_lstadd_front(stack_a, a);
	*stack_b = b;
}
