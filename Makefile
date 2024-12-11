# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 12:11:14 by mmiguelo          #+#    #+#              #
#    Updated: 2024/12/11 10:34:47 by mmiguelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#==============================================================================#
#                                    NAMES                                     #
#==============================================================================#

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = -rm -f
LIBFT = my_libft/libft.a

#==============================================================================#
#                                    FILES                                     #
#==============================================================================#

SRCS	= main.c
SRCS	+= utils/parsing_utils.c
SRCS	+= utils/parsing.c
SRCS	+= utils/stacks.c
SRCS	+= utils/stack_utils.c
SRCS	+= commands/sort.c
SRCS	+= commands/swap.c
SRCS	+= commands/push.c
#SRCS	+= commands/rotate.c
#SRCS	+= commands/reverse_rotate.c

OBJS = $(SRCS:%.c=%.o)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./my_libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C ./my_libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./my_libft
	@$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re


