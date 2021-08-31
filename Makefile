# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 12:03:41 by gasselin          #+#    #+#              #
#    Updated: 2021/08/31 11:10:55 by gasselin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CHECKER		= checker

RM			= rm -rf
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -g

SRCS		= push_swap.c \
				ft_utils.c \
				ft_utils2.c \
				ft_utils3.c \
				build_pile.c \
				init_stacks.c \
				ft_sort_big.c \
				ft_sort_medium.c \
				ft_sort_small.c \
				operations.c \
				operations2.c \
				print_inst.c \
				print_swap.c

SRCS_BONUS	= checker.c \
				operations_bonus.c \
				build_pile_bonus.c \
				ft_utils_bonus.c

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

all : ${OBJS} ${OBJS_BONUS}
			$(MAKE) bonus -C ./libft
			$(CC) $(FLAGS) $(OBJS) -o $(NAME) libft/libft.a
			$(CC) $(FLAGS) $(OBJS_BONUS) -o $(CHECKER) libft/libft.a

bonus : all

clean :
			$(MAKE) clean -C ./libft
			${RM} ${OBJS} ${OBJS_BONUS}

fclean : clean
			$(MAKE) fclean -C ./libft
			${RM} ${NAME} ${CHECKER}

re : fclean all