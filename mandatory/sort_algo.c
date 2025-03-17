/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:41:15 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:44:36 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	best_move(t_stack **list, t_stack **stack_b)
{
	int		s_b;
	int		j;
	t_stack	*best_move;

	j = 0;
	if (check_sort(*list))
		exit (0);
	if (ft_lstsize(*list) == 2 || ft_lstsize(*list) == 3
		|| ft_lstsize(*list) == 4 || ft_lstsize(*list) == 5)
		sort_2_3_4_5(list, stack_b);
	else
	{
		push_to_b(list, stack_b);
		s_b = ft_lstsize(*stack_b);
		while (j < s_b)
		{
			post_list(list, stack_b);
			best_move = min_total_cost_list(*stack_b);
			instr_best(&best_move, list, stack_b);
			p_a(list, stack_b, 1);
			j++;
		}
		get_finel(list);
	}
}

void	post_list(t_stack **list, t_stack **stack_b)
{
	positionlist(*list);
	positionlist(*stack_b);
	target_position(*list, *stack_b);
	cost(*list);
	cost(*stack_b);
	target_cost(*list, *stack_b);
	total_cost(*stack_b);
}

void	instr_best(t_stack **best_move, t_stack **list, t_stack **stack_b)
{
	instr_best2(best_move, list, stack_b);
	while ((*best_move)->cost > 0)
	{
		r_b(stack_b, 1);
		(*best_move)->cost--;
	}
	while ((*best_move)->cost < 0)
	{
		r_r_b(stack_b, 1);
		(*best_move)->cost++;
	}
	while ((*best_move)->t_cost > 0)
	{
		r_a(list, 1);
		(*best_move)->t_cost--;
	}
	while ((*best_move)->t_cost < 0)
	{
		r_r_a(list, 1);
		(*best_move)->t_cost++;
	}
}

void	instr_best2(t_stack **best_move, t_stack **list, t_stack **stack_b)
{
	while ((*best_move)->cost > 0 && (*best_move)->t_cost > 0)
	{
		r_r(list, stack_b, 1);
		(*best_move)->cost--;
		(*best_move)->t_cost--;
	}
	while ((*best_move)->cost < 0 && (*best_move)->t_cost < 0)
	{
		r_r_r(list, stack_b, 1);
		(*best_move)->cost++;
		(*best_move)->t_cost++;
	}
}

void	get_finel(t_stack **list)
{
	t_stack	*min;

	min = min_list(*list);
	sort_list(*list);
	cost(*list);
	while (min->cost > 0)
	{
		r_a(list, 1);
		min->cost--;
	}
	while (min->cost < 0)
	{
		r_r_a(list, 1);
		min->cost++;
	}
}
