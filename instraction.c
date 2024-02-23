/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:28:16 by mchemcha          #+#    #+#             */
/*   Updated: 2024/02/23 18:46:09 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_a(t_stack **stack_a)
{
	t_stack *a ;
	t_stack *b;
	t_stack *c;
	
	a = *stack_a;
	b = a->next;
	c = a->next->next;
	b->next = b;
	b->prev = b;
	a->next=c;
	c->prev = a;
	ft_lstadd_front(stack_a, b);
}
void s_s(t_stack **stack_a, t_stack **stack_b)
{
	s_a(stack_a);
	s_a(stack_b);	
}

void r_a(t_stack **stack_a)
{
	
	t_stack *b;
	t_stack *first;
	
	first = *stack_a;
	b = first->next;
	*stack_a = b;
	
}
void r_r(t_stack **stack_a, t_stack **stack_b)
{
	r_a(stack_a);
	r_a(stack_b);
}
void r_r_a(t_stack **stack_a)
{
	*stack_a = ft_lstlast(*stack_a);
}
void r_r_r(t_stack **stack_a, t_stack **stack_b)
{
	r_r_a(stack_a);
	r_r_a(stack_a);
}
void p_b(t_stack **stack_a,t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *a;
	t_stack *last;
	t_stack *b;
	
	a = *stack_a;
	last = ft_lstlast(*stack_a);
	b = a->next;
	a->next =a;
	a->prev=a;
	b->prev =last;
	last->next=b;
	*stack_a=b;
	ft_lstadd_front(stack_b,a);
}
void p_a(t_stack **stack_a,t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *a;
	t_stack *last;
	t_stack *b;
	
	a = *stack_b;
	last = ft_lstlast(*stack_b);
	b = a->next;
	a->next =a;
	a->prev=a;
	b->prev =last;
	last->next=b;
	*stack_b=b;
	ft_lstadd_front(stack_a,a);
}
