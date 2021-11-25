# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 12:50:23 by rafernan          #+#    #+#              #
#    Updated: 2021/11/25 12:18:30 by rafernan         ###   ########.fr        #
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
_BIN	=		bin

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

$(NAME): deps $(_BIN) $(_BIN)/$(NAME)
$(_BIN)/$(NAME): $(_OBJ) $(OBJS)
	$(CC) $(CF) $(LIBS) $(OBJS) -o $@ -L $(_LIB)

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

$(_BIN):
	$(MKD) $(_BIN)

################### CLEAN ###############

clean:
	$(RMV) -r $(_OBJ)

fclean: clean
	$(RMV) -r $(_BIN) $(_LIB)

re: fclean all

.PHONY: all clean fclean re