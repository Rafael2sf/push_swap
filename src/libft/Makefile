# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafernan <rafernan@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 11:34:36 by rafernan          #+#    #+#              #
#    Updated: 2021/11/25 12:36:00 by rafernan         ###   ########.fr        #
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

SRCS	=		\
				$(_SRC)/ft_atoi.c \
				$(_SRC)/ft_bzero.c \
				$(_SRC)/ft_calloc.c \
				$(_SRC)/ft_is.c \
				$(_SRC)/ft_isalnum.c \
				$(_SRC)/ft_isalpha.c \
				$(_SRC)/ft_isascii.c \
				$(_SRC)/ft_isdigit.c \
				$(_SRC)/ft_isprint.c \
				$(_SRC)/ft_itoa.c \
				$(_SRC)/ft_lstadd_back.c \
				$(_SRC)/ft_lstadd_front.c \
				$(_SRC)/ft_lstclear.c \
				$(_SRC)/ft_lstdelone.c \
				$(_SRC)/ft_lstiter.c \
				$(_SRC)/ft_lstlast.c \
				$(_SRC)/ft_lstmap.c \
				$(_SRC)/ft_lstnew.c \
				$(_SRC)/ft_lstsize.c \
				$(_SRC)/ft_memchr.c \
				$(_SRC)/ft_memcmp.c \
				$(_SRC)/ft_memcpy.c \
				$(_SRC)/ft_memmove.c \
				$(_SRC)/ft_memset.c \
				$(_SRC)/ft_printf.c \
				$(_SRC)/ft_putaddr.c \
				$(_SRC)/ft_putchar.c \
				$(_SRC)/ft_putendl.c \
				$(_SRC)/ft_putnbr.c \
				$(_SRC)/ft_putnbr_b.c \
				$(_SRC)/ft_putstr.c \
				$(_SRC)/ft_putunbr_b.c \
				$(_SRC)/ft_split.c \
				$(_SRC)/ft_strchr.c \
				$(_SRC)/ft_strdup.c \
				$(_SRC)/ft_striteri.c \
				$(_SRC)/ft_strjoin.c \
				$(_SRC)/ft_strlcat.c \
				$(_SRC)/ft_strlcpy.c \
				$(_SRC)/ft_strlen.c \
				$(_SRC)/ft_strmapi.c \
				$(_SRC)/ft_strncmp.c \
				$(_SRC)/ft_strnstr.c \
				$(_SRC)/ft_strrchr.c \
				$(_SRC)/ft_strtrim.c \
				$(_SRC)/ft_substr.c \
				$(_SRC)/ft_tolower.c \
				$(_SRC)/ft_toupper.c \
				$(_SRC)/get_next_line.c

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