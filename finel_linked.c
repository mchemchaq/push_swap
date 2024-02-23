#include "push_swap.h"

void    printf_lst_next(t_stack *list)
{
    t_stack *p;
    
    if (list == NULL)
        return;
    p = list;
    do{
        printf("%d\n", p->content);
        p = p->next;
    } while (p != list);
}
void    printf_lst_prev(t_stack *list)
{
    t_stack *head;
    
    head = list->prev;
    while(head)
    {
        printf("%d\n",head->content);
        head = head->prev;
        if(head == list->prev)
            break; 
    }
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack *last;
	last = lst ->prev;
	return (last);
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
		newlst->next = first;
		first->prev=newlst;
		newlst->prev=last;
	}
}
void	ft_lstadd_front(t_stack **lst, t_stack *newlst)
{
	t_stack *first;
	t_stack *last;

	first = *lst;
	last = ft_lstlast(*lst);
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		newlst -> next = NULL;
	newlst->next = first;
	first->prev = newlst;
	newlst->prev = last;
	last->next = newlst;
	*lst = newlst;
}
t_stack *to_list(char **tab)
{
    int i;
    t_stack *list;

	list = NULL;
    i = 0;
    while ((int *)tab[i])
    {
		t_stack *p=ft_lstnew(*tab[i]);
		if (list == NULL)
			list = p;
		else
			ft_lstadd_back(&list, p);
		i++;
    }
    return(list);
}