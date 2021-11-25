# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 11:34:36 by rafernan          #+#    #+#              #
#    Updated: 2021/11/25 11:37:56 by rafernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############# STATIC LIBRARY ############

NAME	=		libft.a

################### TERMINAL ############

RMV		=		rm -f
MKD		=		mkdir
PRT		=		printf
MKE		=		make
CPY		=		cp

################### COLORS ##############

--GRN	=		\033[32m
--RED	=		\033[31m
--WHT	=		\033[39m

################### DIRS ################

_SRC	=		.
_OBJ	=		../../obj
_LIB	=		../../libs
_BIN	=		../../bin

################### COMPILER ############

CC		=		gcc
AR		=		ar rcs
CF		=		-Wall -Werror -Wextra

################### FILES ###############

SRCS	=		$(shell find . -maxdepth 1 -name "*.c")
OBJS	=		$(patsubst $(_SRC)/%.c,$(_OBJ)/%.o,$(SRCS))

################### RULES ###############

all: $(NAME)

$(_OBJ)/%.o: $(_SRC)/%.c
	$(CC) $(CF) -c $< -o $@

$(NAME): $(_LIB) $(_LIB)/$(NAME)
$(_LIB)/$(NAME): $(_OBJ) $(OBJS)
	$(AR) $@ $(OBJS)

################### STRUCTURE ###########

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