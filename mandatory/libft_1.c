/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:34:18 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 16:47:02 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	cont_word(char const *str, char c)
{
	int	i;
	int	cont;
	int	pp;

	i = 0;
	cont = 0;
	while (str[i])
	{
		pp = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			i++;
			pp = 1;
		}
		if (pp)
			cont += 1;
	}
	return (cont);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	j = 0;
	if (!s)
		return (NULL);
	tab = (char **)ft_calloc((cont_word(s, c) + 1) * sizeof(char *), 1);
	while (tab == NULL)
		return (NULL);
	while (++k < cont_word(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		tab[k] = ft_substr(s, j, i - j);
		if (!tab[k])
			return (erreur(tab));
	}
	return (tab);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t	i;

	if (size != 0 && count >= SIZE_MAX / size)
		return (NULL);
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}

static size_t	ft_str_len(int ac, char **av)
{
	int		i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (++i < ac)
	{
		while (av[i][k])
		{
			k++;
			j++;
		}
		k = 0;
		j++;
	}
	return (j);
}

char	*ft_strjoin1(int ac, char **av)
{
	char	*str;
	int		i;
	int		y;
	int		j;

	str = (char *)malloc(ft_str_len(ac, av));
	if (!str)
		return (NULL);
	i = 0;
	y = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			str[y] = av[i][j];
			j++;
			y++;
		}
		str[y] = ' ';
		y++;
	}
	str[--y] = 0;
	return (str);
}
