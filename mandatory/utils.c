/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:52:13 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/22 15:41:26 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
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
	str = malloc(s1_len + s2_len + 1);
	i = -1;
	j = 0;
	if (!str)
		return (free(str), NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[j + s1_len] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(s1), s1 = NULL, str);
}

size_t	ft_strlen2(const char *str)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		s = s + 1;
		i++;
	}
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if ((int)start > ft_strlen(s))
		return (ft_strdup(""));
	if ((int)len > ft_strlen(s + start))
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
