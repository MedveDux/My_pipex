# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 13:49:12 by cyelena           #+#    #+#              #
#    Updated: 2022/01/29 16:47:17 by cyelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_strlen.c ft_strlcpy.c \
		ft_strnstr.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_split.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_strncmp.c
HEAD = libft.h

OBJ = ${patsubst %.c,%.o,$(SRCS)}


CC = gcc
FLAGS = -Wall -Werror -Wextra
OPTFLAGS = -O2
RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} $?

%.o : %.c ${HEAD} Makefile
	${CC} ${FLAGS} ${OPTFLAGS} -c $< -o $@ 
		
clean:
	${RM} ${OBJ} 


fclean: clean 
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
