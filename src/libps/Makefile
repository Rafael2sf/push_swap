# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 16:11:32 by rafernan          #+#    #+#              #
#    Updated: 2021/11/07 00:31:19 by rafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME	=		libps.a

# Terminal commands
RM		=		rm -f

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
LIBS	=		$(LIB_D)/libft.a

# Rules
all: $(NAME)

$(OBJ_D)/%.o: $(SRC_D)%.c
	@ echo -n "▰"
	@ $(CC) $(CFLAGS) -o $@ -c $<

$(NAME): deps
	@ echo -n "├—● libps\n│$(C_GRN)"
	@ $(MAKE) -s $(OBJS)
	@ $(AR) $(LIB_D)/$@ $(OBJS)
	@ echo -n "$(C_DEF)\n"

deps:
	@$(MAKE) libft.a -C ../libft

clean:
	@ $(RM) $(OBJS)

fclean: clean
	@ $(RM) $(LIB_D)/$(NAME)

re: fclean all

.PHONY: all clean fclean re