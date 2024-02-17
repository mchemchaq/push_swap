/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:27:09 by mchemcha          #+#    #+#             */
/*   Updated: 2024/02/17 10:47:10 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct noeud
{
    char content;
    struct noeud *next;
    struct noeud *prec;
}noeud;

 // fonction libt
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
//

// push_swap
int	main(int ac, char *av[]);
noeud *to_list(char **tab);

#endif