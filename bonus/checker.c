/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:30:13 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 22:19:16 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	**tab;
	char	*s;
	t_stack	*list;
	t_stack	*stack_b;

	stack_b = NULL;
	list = NULL;
	if (ac < 2)
		exit(0);
	i = 0;
	while (av[++i])
	{
		check_empty(av[i]);
		check_space(av[i]);
	}
	s = ft_strjoin1(ac, av);
	tab = ft_split(s, ' ');
	free(s);
	parcing(&list, tab);
	erreur(tab);
	list = if_instraction(&list, &stack_b);
	lst_clear(&list);
}

t_list	*instr(char *read, t_list **inst)
{
	if (compar(read, "ra\n"))
		add_back(inst, new_list("ra"));
	else if (compar(read, "rra\n"))
		add_back(inst, new_list("rra"));
	else if (compar(read, "rrb\n"))
		add_back(inst, new_list("rrb"));
	else if (compar(read, "rrr\n"))
		add_back(inst, new_list("rrr"));
	else if (compar(read, "rb\n"))
		add_back(inst, new_list("rb"));
	else if (compar(read, "rr\n"))
		add_back(inst, new_list("rr"));
	else if (compar(read, "sa\n"))
		add_back(inst, new_list("sa"));
	else if (compar(read, "sb\n"))
		add_back(inst, new_list("sb"));
	else if (compar(read, "ss\n"))
		add_back(inst, new_list("ss"));
	else if (compar(read, "pb\n"))
		add_back(inst, new_list("pb"));
	else if (compar(read, "pa\n"))
		add_back(inst, new_list("pa"));
	else
		ft_error("Error");
	return (*inst);
}

t_stack	*if_instraction(t_stack **list, t_stack **stack_b)
{
	char	*read;
	t_list	*instra;

	instra = NULL;
	read = get_next_line(0);
	while (read)
	{
		instr(read, &instra);
		free(read);
		read = get_next_line(0);
	}
	do_instra(list, stack_b, &instra);
	lst_clear_inst(&instra);
	if ((*stack_b))
		ft_error("KO");
	check_list_sort(*list);
	return (*list);
}

void	compra_instra(char *content, t_stack **list, t_stack **stack_b)
{
	if (compar(content, "ra"))
		r_a(list, 0);
	else if (compar(content, "rb"))
		r_b(stack_b, 0);
	else if (compar(content, "rr"))
		r_r(list, stack_b, 0);
	else if (compar(content, "rra"))
		r_r_a(list, 0);
	else if (compar(content, "rrb"))
		r_r_b(stack_b, 0);
	else if (compar(content, "rrr"))
		r_r_r(list, stack_b, 0);
	else if (compar(content, "sa"))
		s_a(list, 0);
	else if (compar(content, "sb"))
		s_b(stack_b, 0);
	else if (compar(content, "ss"))
		s_s(list, stack_b, 0);
	else if (compar(content, "pb"))
		p_b(list, stack_b, 0);
	else if (compar(content, "pa"))
		p_a(list, stack_b, 0);
}

void	do_instra(t_stack **list, t_stack **stack_b, t_list **inst)
{
	while ((*inst) != NULL)
	{
		compra_instra((*inst)->content, list, stack_b);
		(*inst) = (*inst)->next;
	}
}
