# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 12:50:23 by rafernan          #+#    #+#              #
#    Updated: 2021/11/07 00:30:29 by rafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME	=		push_swap

# Terminal commands
RM		=		rm -f

# Colors
C_GRN	=		\033[32m
C_DEF	=		\033[39m
C_RED	=		\033[31m

# Directories
SRC_D	=		./src
OBJ_D	=		./obj
LIB_D	=		./libs
BIN_D	=		./bin

# Compiling commands
CC		=		gcc
AR		=		ar rcs
CFLAGS	=		-g -Wall -Werror -Wextra

# Files
SRCS	=		$(SRC_D)/main.c
OBJS	=		$(patsubst $(SRC_D)%.c,$(OBJ_D)/%.o,$(SRCS))

# Rules
all: $(NAME)

$(OBJ_D)/%.o: $(SRC_D)%.c
	@ echo -n "▰"
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	@ echo -n "\n●\n│\n"
	@ $(MAKE) -s deps
	@ echo -n "├—● main\n│$(C_GRN)"
	@ $(MAKE) -s $(OBJS)
	@ $(CC) $(CFLAGS) -o $(BIN_D)/$(NAME) $(OBJ_D)/*.o
	@ echo -n "$(C_DEF)\n"
	@ echo "● $(NAME)\n"

deps:
	@ $(MAKE) libps.a -C ./src/libps

clean:
	@ $(RM) $(OBJ_D)/*.o $(LIB_D)/*.a 

fclean: clean
	@ $(RM) $(BIN_D)/$(NAME)

re: fclean all

.PHONY: all deps clean fclean re