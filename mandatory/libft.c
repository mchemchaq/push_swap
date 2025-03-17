/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:02:55 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:42:08 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ab(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	size_t		i;
	long long	sign;
	long long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result - 1 > INT_MAX))
			ft_error("Error");
		result = (result * 10) + str[i] - 48;
		i++;
	}
	return (result *= sign);
}

int	ft_strlen(const char *str)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		s = s + 1;
		i++;
	}
	return (s);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(ft_strlen(s1) + 1);
	if (!str)
		return (free(str), str = NULL, NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
