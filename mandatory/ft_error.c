/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:46:50 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/23 14:39:37 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

void	ft_ok(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(0);
}

char	**erreur(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	lst_clear(t_stack **list)
{
	int		s;
	int		i;
	t_stack	*tmp;
	t_stack	*court;

	i = 0;
	tmp = *list;
	s = ft_lstsize((*list));
	while (i < s)
	{
		court = tmp;
		tmp = tmp->next;
		free (court);
		i++;
	}
	*list = NULL;
}
