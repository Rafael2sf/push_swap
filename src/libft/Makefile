# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 11:34:36 by rafernan          #+#    #+#              #
#    Updated: 2021/11/24 18:27:01 by rafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME	=		libft.a

# Commands
RM		=		rm -f
MD		=		mkdir
PRNT	=		printf
M		=		make

# Colors
C_GRN	=		\033[32m
C_DEF	=		\033[39m
C_RED	=		\033[31m

# Directories
SRC_D	=		./
OBJ_D	=		../../obj
LIB_D	=		../../libs

# Compiling commands
CC		=		gcc
AR		=		ar rcs
CFLAGS	=		-g -Wall -Werror -Wextra

# Files
SRCS	=		$(shell find . -maxdepth 1 -name "*.c")
OBJS	=		$(patsubst $(SRC_D)%.c,$(OBJ_D)/%.o,$(SRCS))

# Rules
all: $(NAME)

$(OBJ_D)/%.o: $(SRC_D)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libft.a $(OBJ_D) $(LIB_D) $(OBJS)
	$(AR) $@ $(OBJS)
	cp $(NAME) ../libps/$(NAME)

$(OBJ_D):
	$(MD) $(OBJ_D)

$(LIB_D):
	$(MD) $(LIB_D)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re