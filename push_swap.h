/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:27:09 by mchemcha          #+#    #+#             */
/*   Updated: 2024/02/23 18:45:51 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_stack
{
    int content;
    struct s_stack *next;
    struct s_stack *prev;
}t_stack;



char	    *ft_strdup(const char *s1);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
char	    *ft_strjoin(char const *s1, char const *s2);
char	    **ft_split(char const *s, char c);
size_t	    ft_strlen(const char *str);
void	    *ft_calloc(size_t count, size_t size);
int	        ft_strncmp(const char *s1, const char *s2, size_t n);
t_stack       *to_list(char **tab);
int         check_min_max(char **tab);
int         check_dubl(char **tab);
int         check_int(char **tab);
long long   ft_atoi(char *str);
int         parcing(char **tab);
int	        ft_isdigit(int c);
int         check_space(char *s);
int         check_empty(char *s);
void        ft_error(char *str);
t_stack	    *ft_lstlast(t_stack *lst);
void	    ft_lstadd_front(t_stack **lst, t_stack *newlst);
void	    ft_lstadd_back(t_stack **lst, t_stack *newlst);
t_stack	    *ft_lstnew(int content);
void        s_a(t_stack **stack_a);
void        r_a(t_stack **stack_a);
void        s_s(t_stack **stack_a, t_stack **stack_b);
void        r_r(t_stack **stack_a, t_stack **stack_b);
void        r_r_a(t_stack **stack_a);
void        r_r_r(t_stack **stack_a, t_stack **stack_b);
void        p_a(t_stack **stack_a,t_stack **stack_b);

void        printf_lst_prev(t_stack *list);
void        printf_lst_next(t_stack *list);

#endif