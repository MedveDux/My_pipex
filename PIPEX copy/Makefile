# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyelena <cyelena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 16:57:07 by cyelena           #+#    #+#              #
#    Updated: 2022/01/28 17:59:46 by cyelena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = pipex

SRCS_Mandatory = ./srcs/pipex.c ./srcs/utils.c

SRCS_Bonus = ./srcs/pipex_bonus.c ./srcs/utils_bonus.c

OBJ = $(patsubst %.c,%.o,$(SRCS_Mandatory))

OBJ_Bonus = $(patsubst %.c,%.o,$(SRCS_Bonus))

HEAD =  ./includes/pipex.h ./libft/libft.h

HEAD_BONUS = ./includes/pipex_bonus.h ./libft/libft.h

FLAGS = -Wall -Werror -Wextra

OPTFLAGS = -O2

RM = @rm -f

all:	$(Name)
	@printf "\n\t\033[92m \xE2\x9C\x94 \xF0\x9F\x98\x8A complied!"

$(Name):	libft/libft.a $(OBJ) $(HEAD)
	@cc -o $(Name) $(OBJ) libft/libft.a
#$(Name):	libft/libft.a $(OBJ) 
#	@gcc -o $(Name) $(OBJ) libft/libft.a

#%.o	: %.c $(HEAD) $(HEAD_BONUS) Makefile	
#	@cc $(FLAGS) $(OPTFLAGS) -c $< -o $@ 

bonus: libft/libft.a $(OBJ_Bonus) $(HEAD_BONUS)
	@cc -o $(Name) $(OBJ_Bonus)  libft/libft.a

libft/libft.a: xz
	@make -C libft

clean:
	$(RM) $(OBJ) $(OBJ_Bonus)
	@make -C libft clean
	@rm -f ./libft/libft.a

fclean: clean 
	$(RM) $(Name)	

re: fclean all

.PHONY: all clean fclean re xz bonus