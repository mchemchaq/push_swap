# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 14:40:48 by mchemcha          #+#    #+#              #
#    Updated: 2024/03/23 14:43:19 by mchemcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = mandatory/finel_linked.c \
		mandatory/libft.c \
		mandatory/libft_1.c \
		mandatory/push_swap.c \
		mandatory/parsing_1.c \
		mandatory/parsing_2.c \
		mandatory/ft_error.c \
		mandatory/rotate.c \
		mandatory/index_list.c \
		mandatory/Longest_algo.c \
		mandatory/best_move.c \
		mandatory/sort_3_4_5.c \
		mandatory/sort_algo.c \
		mandatory/utils.c \
		mandatory/linked_list2.c \
		mandatory/p_a_p_b.c \
		mandatory/swap.c \
		mandatory/rev_rotate.c

SRCSB = bonus/get_next_line.c \
		mandatory/utils.c \
		mandatory/parsing_1.c \
		mandatory/parsing_2.c \
		mandatory/ft_error.c \
		mandatory/rotate.c \
		mandatory/libft.c \
		mandatory/libft_1.c \
		mandatory/finel_linked.c \
		bonus/checker.c \
		mandatory/p_a_p_b.c \
		mandatory/swap.c \
		mandatory/rev_rotate.c \
		bonus/t_list.c \
		bonus/utile_checker.c
	
NAME = push_swap
NAMEBONUS = checker 
OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${SRCSB:.c=.o}
CC = cc
FLAGS = -Wall -Werror -Wextra 
RM = rm -rf

all: ${NAME}

bonus :${NAMEBONUS}

${NAME}: ${OBJS}
	${CC} $(FLAGS) ${OBJS} -o $(NAME)

${NAMEBONUS}: ${OBJSBONUS}
	${CC} $(FLAGS) ${OBJSBONUS} -o $(NAMEBONUS)

%.o: %.c push_swap.h 
	$(CC) $(FLAGS) -c $< -o $@	

clean:
	$(RM) $(OBJS) $(OBJSBONUS) 

fclean: clean
	$(RM) $(NAME) $(NAMEBONUS)

re: fclean all

.PHONY: clean