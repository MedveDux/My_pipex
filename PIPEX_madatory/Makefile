# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 16:57:07 by cyelena           #+#    #+#              #
#    Updated: 2022/01/24 17:27:44 by cyelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = pipex
SRCS_Mandatory = pipex.c utils.c
OBJ = ${patsubst %.c,%.o,$(SRCS_Mandatory)}
HEAD = pipex.h
CC = gcc
FLAGS = -Wall -Werror -Wextra
OPTFLAGS = -O2
RM = rm -f

all:	$(Name)
	printf "\n\t\033[92m \xE2\x9C\x94 \xF0\x9F\x98\x8A complied! \n\t\033[92m\n\n "

$(Name):	libft/libft.a $(OBJ)
	gcc -o $(Name) $(OBJ) libft/libft.a
%.o : %.c $(HEAD) Makefile	
	cc $(FLAGS) $(OPTFLAGS) -c $< -o $@ 
libft/libft.a:
	make -C libft
clean:
	$(RM) $(OBJ) 
	make -C libft clean


fclean: clean 
	$(RM) $(NAME)
	$(RM) libft/libft.a

re: fclean all

.PHONY: all clean fclean re 	