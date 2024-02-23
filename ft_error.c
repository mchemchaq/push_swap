#include "push_swap.h"
#include <unistd.h>
void    ft_error(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
    exit (1);
}