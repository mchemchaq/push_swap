/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:45:52 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:39:40 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	target_position(t_stack *stack_a, t_stack *stack_b)
{
	int	closest_biggest;
	int	s_a;
	int	j;

	s_a = ft_lstsize(stack_a);
	positionlist(stack_a);
	positionlist(stack_b);
	if (stack_b == NULL)
		return ;
	while (stack_b->t_p == -1)
	{
		j = -1;
		closest_biggest = INT_MAX;
		while (++j < s_a)
		{
			if (stack_b->index < stack_a->index
				&& stack_a->index < closest_biggest)
			{
				closest_biggest = stack_a->index;
				stack_b->t_p = stack_a->position;
			}
			stack_a = stack_a->next;
		}
		stack_b = stack_b->next;
	}
}

void	cost(t_stack *stack_a)
{
	int	size;
	int	pm;
	int	i;

	size = ft_lstsize(stack_a);
	pm = ft_lstsize(stack_a) / 2;
	i = 0;
	positionlist(stack_a);
	while (i < size)
	{
		if (stack_a->position <= pm)
		{
			stack_a->cost = stack_a->position;
		}
		else if (stack_a->position > pm)
		{
			stack_a->cost = (size - stack_a->position) * (-1);
		}
		stack_a = stack_a->next;
		i++;
	}
}

void	target_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	closest_biggest;
	int	s_a;
	int	s_b;
	int	i;

	s_b = ft_lstsize(stack_b);
	s_a = ft_lstsize(stack_a);
	while (s_b--)
	{
		i = 0;
		closest_biggest = INT_MAX;
		while (i < s_a)
		{
			if (stack_b->index < stack_a->index
				&& stack_a->index < closest_biggest)
			{
				closest_biggest = stack_a->index;
				stack_b->t_cost = stack_a->cost;
			}
			stack_a = stack_a->next;
			i++;
		}
		stack_b = stack_b->next;
	}
}

void	total_cost(t_stack *stack_a)
{
	int	s;
	int	i;

	s = ft_lstsize(stack_a);
	i = -1;
	while (++i < s)
	{
		if (stack_a->cost >= 0 && stack_a->t_cost >= 0)
		{
			if (stack_a->cost > stack_a->t_cost)
				stack_a->total = stack_a->cost;
			else
				stack_a->total = stack_a->t_cost;
		}
		else if (stack_a->cost < 0 && stack_a->t_cost < 0)
		{
			if (ab(stack_a->cost) > ab(stack_a->t_cost))
				stack_a->total = ab(stack_a->cost);
			else
				stack_a->total = ab(stack_a->t_cost);
		}
		else
			stack_a->total = ab((stack_a->cost)) + ab((stack_a->t_cost));
		stack_a = stack_a->next;
	}
}
