# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 12:50:23 by rafernan          #+#    #+#              #
#    Updated: 2021/11/23 17:21:45 by rafernan         ###   ########.fr        #
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
SRC_D	=		src
OBJ_D	=		obj
LIB_D	=		libs
BIN_D	=		bin

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
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(BIN_D)
	$(MAKE) deps
	$(MAKE) $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_D)/$(NAME) $(OBJS) $(LIBS)

deps:
	$(MAKE) -C ./src/libps

$(BIN_D):
	mkdir $(BIN_D)

clean:
	$(RM) $(OBJ_D)/*.o $(LIB_D)/*.a $(BIN_D)/$(NAME)

fclean: clean
	$(RM) -r $(OBJ_D) $(LIB_D) $(BIN_D) 

re: fclean all

.PHONY: all deps clean fclean re