#include "push_swap.h"



t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	// lst = lst ->prev;
	// pru("#####");
	return (lst ->prev);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (list == NULL)
		return (NULL);
	list -> content = content;
	list -> next = list;
    list -> prev = list;                                                                                                                                                                                                              
	return (list);
}
void	ft_lstadd_back(t_stack **lst, t_stack *newlst)
{
	t_stack	*last;
	t_stack	*first;

	if (*lst == NULL)
		*lst = newlst;
	else
	{
		first = *lst;
		last = ft_lstlast(*lst);
		last -> next = newlst;
		newlst -> next = first;
		first->prev=newlst;
		newlst->prev=last;
	}
}
void	ft_lstadd_front(t_stack **lst, t_stack *newlst)
{
	// t_stack	*last;
	// t_stack	*first;
	if (*lst == NULL)
		*lst = newlst;
	else
	{
		ft_lstadd_back(lst, newlst);
		
		*lst = newlst;
	}
}
t_stack *to_list(char **tab)
{
    int i;
    t_stack *list;

	list = NULL;
	i = 0;
    while (tab[i])
    {
		t_stack *p = ft_lstnew((int)*tab[i]);
		if (list == NULL)
			list=p;
		else
			ft_lstadd_back(&list, p);
		i++;
	}
	//printf_lst_next(list);
	return(list);
}
int	ft_lstsize(t_stack *lst)
{
	t_stack	*i;
	int		s;
	t_stack *last = ft_lstlast(lst);
	s = 1;
	i = lst;
	if (lst == NULL)
		return (0);
	while (i != last && i -> next != NULL)
	{
		s += 1;
		i = i -> next;
	}

	return (s);
}