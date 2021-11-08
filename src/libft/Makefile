# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 11:34:36 by rafernan          #+#    #+#              #
#    Updated: 2021/11/08 11:45:41 by rafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME	=		libft.a

# Commands
RM		=		rm -f
PRNT	=		printf

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

$(OBJ_D)/%.o: $(SRC_D)%.c
	@ $(PRNT) "▰"
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_D) $(LIB_D)
	@ $(PRNT) "├—● libft\n│$(C_GRN)"
	@ $(MAKE) -s $(OBJS)
	@ $(AR) $(LIB_D)/$@ $(OBJS)
	@ $(PRNT) "$(C_DEF)\n"

$(OBJ_D):
	@ mkdir $(OBJ_D)

$(LIB_D):
	@ mkdir $(LIB_D)

clean:
	@ $(RM) $(OBJS)

fclean: clean
	@ $(RM) $(LIB_D)/$(NAME)

re: fclean all

.PHONY: all clean fclean re