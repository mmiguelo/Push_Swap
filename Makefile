# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 12:11:14 by mmiguelo          #+#    #+#              #
#    Updated: 2024/12/12 14:22:06 by mmiguelo         ###   ########.fr        #
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
SRCS	+= commands/rotate.c
SRCS	+= commands/reverse_rotate.c

OBJS = $(SRCS:%.c=%.o)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

$(VERBOSE).SILENT:

all: $(NAME)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C ./my_libft

$(NAME): $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NAME) compiled sucessfully"

clean:
	@echo "Cleaning object files..."
	@$(MAKE) clean -C ./my_libft
	@$(RM) $(OBJS)

fclean: clean
	@echo "Cleaning $(NAME) and libft..."
	@$(MAKE) fclean -C ./my_libft
	@$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re
