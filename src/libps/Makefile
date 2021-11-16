# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 16:11:32 by rafernan          #+#    #+#              #
#    Updated: 2021/11/16 13:51:15 by rafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME	=		libps.a

# Terminal commands
RM		=		rm -f
PRNT	=		printf
MD		=		mkdir

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
LIBS	=		$(LIB_D)/libft.a

# Rules
all: $(NAME)

$(OBJ_D)/%.o: $(SRC_D)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): deps $(OBJ_D) $(LIB_D)
	$(MAKE) $(OBJS)
	cp $(LIBS) $(LIB_D)/$(NAME)
	$(AR) $(LIB_D)/$@ $(OBJS)

deps:
	$(MAKE) -C ../libft

$(OBJ_D):
	$(MD) $(OBJ_D)

$(LIB_D):
	$(MD) $(LIB_D)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIB_D)/$(NAME)

re: fclean all

.PHONY: all deps clean fclean re