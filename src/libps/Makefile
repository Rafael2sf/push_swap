# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 16:11:32 by rafernan          #+#    #+#              #
#    Updated: 2021/11/24 18:26:26 by rafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME	=		libps.a

# Terminal commands
RM		=		rm -f
PRNT	=		printf
MD		=		mkdir
M		=		make
CP		=		cp
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
CFLAGS	=		-g -Wall -Werror -Wextra -fsanitize=address

# Files
SRCS	=		$(shell find . -maxdepth 1 -name "*.c")
OBJS	=		$(patsubst $(SRC_D)%.c,$(OBJ_D)/%.o,$(SRCS))
LIBS	=		../libft/libft.a

# Rules
all: deps $(NAME)

$(OBJ_D)/%.o: $(SRC_D)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_D) $(LIB_D) $(OBJS)
	$(M) libft.a -C ../libft
	$(AR) libft.a $(OBJS)
	mv libft.a $(NAME)

$(OBJ_D):
	$(MD) $(OBJ_D)

$(LIB_D):
	$(MD) $(LIB_D)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all deps clean fclean re