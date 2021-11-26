# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 16:11:32 by rafernan          #+#    #+#              #
#    Updated: 2021/11/26 10:43:45 by rafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############# STATIC LIBRARY ############

NAME	=		libps.a

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

_SRC	=		.
_OBJ	=		../../obj
_LIB	=		../../libs
_BIN	=		../../bin

############### COMPILER ################

CC		=		gcc
AR		=		ar rcs
CF		=		-Wall -Werror -Wextra

################ FILES ##################

SRCS	=		\
				$(_SRC)/ps_atoi.c \
				$(_SRC)/ps_get_next.c \
				$(_SRC)/ps_issorted.c \
				$(_SRC)/ps_lst_utils.c \
				$(_SRC)/ps_opers.c \
				$(_SRC)/ps_opers2.c \
				$(_SRC)/ps_osort.c \
				$(_SRC)/ps_sort.c \
				$(_SRC)/ps_sort_utils.c \
				$(_SRC)/ps_utils.c \
				$(_SRC)/push_swap.c

OBJS	=		$(patsubst $(_SRC)/%.c,$(_OBJ)/%.o,$(SRCS))

################ RULES ##################

all: $(NAME)

$(_OBJ)/%.o: $(_SRC)/%.c
	$(CC) $(CF) -c $< -o $@

$(NAME): $(_LIB) $(_LIB)/$(NAME)
$(_LIB)/$(NAME): $(_OBJ) $(OBJS)
	$(AR) $@ $(OBJS)

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
	$(RMV) $(OBJS)

fclean: clean
	$(RMV) $(_LIB)/$(NAME)

re: fclean all

.PHONY: all clean fclean re