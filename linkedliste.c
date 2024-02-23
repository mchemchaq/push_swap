#include <stdio.h>

typedef struct s_list
{
    int content;
    struct s_list *next;
    struct s_list *prev;
}t_list;

void add_back(t_list *lst, t_list new_node)
{
    t_list *last;

    last = lst;
    while(last -> next != lst)
        last = last -> next;
    
}