# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmiguelo <mmiguelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 12:11:14 by mmiguelo          #+#    #+#              #
#    Updated: 2024/12/18 12:09:31 by mmiguelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#==============================================================================#
#                                    NAMES                                     #
#==============================================================================#

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I./includes
VPATH = utils commands
LIBFT = ./my_libft/libft.a
RM = rm -rf

COMMANDS = push reverse_rotate rotate sort swap
UTILS = parsing_utils parsing stack_utils stacks

NAME = push_swap

#==============================================================================#
#                                    FILES                                     #
#==============================================================================#

SRCS =	$(addsuffix .c, $(COMMANDS))
SRCS +=	$(addsuffix .c, $(UTILS))
SRCS +=	main.c
	   
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./my_libft

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(BONUS_INC)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./my_libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./my_libft
	$(RM) $(NAME) $(OBJ_DIR)

re: fclean all

.SILENT:
