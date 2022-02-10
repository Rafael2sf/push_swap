# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 21:55:53 by rafernan          #+#    #+#              #
#    Updated: 2022/01/20 21:55:53 by rafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################ PROGRAM ################

NAME	=		push_swap

################ TERMINAL ###############

RMV		=		rm -f
MKD		=		mkdir
PRT		=		printf
MKE		=		make
CPY		=		cp

################# COLORS ################

--GRN	=		\033[32m
--RED	=		\033[31m
--WHT	=		\033[39m

################# DIRS ##################

_SRC	=		src
_OBJ	=		obj
_LIB	=		libs

############### COMPILER ################

CC		=		gcc
AR		=		ar rcs
CF		=		-Wall -Werror -Wextra

################ FILES ##################

MAIN	=		$(_SRC)/main.c
OBJS	=		$(_OBJ)/main.o
DEPS	=		libft.a libps.a 
LIBS	=		-lps -lft

################ RULES ##################

all: deps $(NAME)

$(_OBJ)/%.o: $(_SRC)/%.c
	$(CC) $(CF) -c $< -o $@

$(NAME): deps $(_OBJ) $(OBJS)
	$(CC) $(CF) $(_OBJ)/*.o -o $(NAME)

################ DEPS ###################

deps: $(DEPS)

libps.a:
	$(MKE) libps.a -C src/libps

libft.a:
	$(MKE) libft.a -C src/libft

############## STRUCTURE ################

$(_OBJ):
	$(MKD) $(_OBJ)

$(_LIB):
	$(MKD) $(_LIB)

$(_SRC):
	$(MKD) $(_SRC)

################### CLEAN ###############

clean:
	$(RMV) -r $(_OBJ) $(_LIB)

fclean: clean
	$(RMV) -r $(NAME)

re: fclean all

.PHONY: all clean fclean re