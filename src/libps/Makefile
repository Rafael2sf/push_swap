# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 16:11:32 by rafernan          #+#    #+#              #
#    Updated: 2021/11/25 10:44:58 by rafernan         ###   ########.fr        #
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

SRCS	=		$(shell find . -maxdepth 1 -name "*.c")
OBJS	=		$(patsubst $(_SRC)/%.c,$(_OBJ)/%.o,$(SRCS))
DEPS	=		libft.a

################ RULES ##################

all: $(NAME)

$(_OBJ)/%.o: $(_SRC)/%.c
	$(CC) $(CF) -c $< -o $@

$(NAME): deps $(_LIB) $(_LIB)/$(NAME)
$(_LIB)/$(NAME): $(_OBJ) $(OBJS)
	$(CPY) $(_LIB)/libft.a $@
	$(AR) $@ $(OBJS)

################ DEPS ###################

deps: $(DEPS)

libft.a:
	$(MKE) libft.a -C ../libft

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

dclean:
	$(MKE) fclean -C ../libft	

fclean: clean dclean
	$(RMV) $(_LIB)/$(NAME)

re: fclean all

.PHONY: all clean fclean re