/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:53:45 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/23 11:44:24 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long	ft_atoi_2(char *str)
{
	size_t		i;
	long long	sign;
	long long	result;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;
	}
	return (result *= sign);
}

int	check_min_max(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_atoi_2(tab[i]) > INT_MAX || ft_atoi_2(tab[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_int(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		if (tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	parcing(t_stack **list, char **tab)
{
	int	i;

	i = 0;
	if (!check_int(tab))
		ft_error("Error");
	if (!check_min_max(tab) || !check_dubl(tab))
		ft_error("Error");
	while (tab[i])
	{
		ft_lstadd_back(list, ft_lstnew(ft_atoi(tab[i])));
		i++;
	}
}
