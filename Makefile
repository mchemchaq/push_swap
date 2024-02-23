SRCS  =  finel_linked.c libft.c  push_swap.c parsing.c ft_error.c instraction.c

NAME = push_swap
OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = #-Wall -Werror -Wextra
RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@	

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean