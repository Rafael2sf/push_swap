# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 12:50:23 by rafernan          #+#    #+#              #
#    Updated: 2021/11/09 15:31:00 by rafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME	=		push_swap

# Terminal commands
RM		=		rm -f
PRNT	=		printf

# Colors
C_GRN	=		\033[32m
C_DEF	=		\033[39m
C_RED	=		\033[31m

# Directories
SRC_D	=		./src
OBJ_D	=		./obj
LIB_D	=		./libs
BIN_D	=		./bin

# Commands
CC		=		gcc
AR		=		ar rcs
CFLAGS	=		-g -Wall -Werror -Wextra -fsanitize=address

# Files
SRCS	=		$(SRC_D)/main.c
OBJS	=		$(patsubst $(SRC_D)%.c,$(OBJ_D)/%.o,$(SRCS))
LIBS	=		$(LIB_D)/libps.a

# Rules
all: $(NAME)

$(OBJ_D)/%.o: $(SRC_D)%.c
	@ $(PRNT) "▰"
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(BIN_D)
	@ $(PRNT) "\n●\n│\n"
	@ $(MAKE) -s deps
	@ $(PRNT) "├—● main\n│$(C_GRN)"
	@ $(MAKE) -s $(OBJS)
	@ $(CC) $(CFLAGS) -o $(BIN_D)/$(NAME) -L. $(LIBS) $(SRCS)
	@ $(PRNT) "$(C_DEF)\n"
	@ $(PRNT) "● $(NAME)\n"

deps:
	@ $(MAKE) libps.a -C ./src/libps

$(BIN_D):
	mkdir $(BIN_D)

clean:
	@ $(RM) $(OBJ_D)/*.o $(LIB_D)/*.a 

fclean: clean
	@ $(RM) -rf $(OBJ_D) $(LIB_D) $(BIN_D)

re: fclean all

.PHONY: all deps clean fclean re