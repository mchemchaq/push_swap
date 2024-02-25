/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 09:02:55 by mchemcha          #+#    #+#             */
/*   Updated: 2024/02/24 14:01:08 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n
		&& ((unsigned char)s1[i] != '\0' || (unsigned char)s2[i] != '\0'))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
long long	ft_atoi(char *str)
{
	size_t				i;
	long long				sign;
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
		result = (result * 10 + str[i] - 48);
		i++;
	}
	return (result *= sign);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;
	size_t	s;

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
	str = (char *)malloc (ft_strlen(s1) + 1);
	if (!str)
	{
		return (NULL);
	}
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	i = 0;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
static char	**erreur(char **tab)
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

char	**ft_split(char const *s, char c)
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
	tab = (char **)calloc((cont_word(s, c) + 1) * sizeof(char *), 1);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[j + s1_len] = s2[j];
		j++;
	}
	return (str);
}