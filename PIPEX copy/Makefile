SRCS 	= srcs/pipex.c   \
    srcs/utils.c   \

B_SRC	= srcs/pipex_bonus.c   \
    srcs/utils_bonus.c

OBJS	= $(SRCS:.c=.o) 

B_OBJS	= $(B_SRCS:.c=.o) 

HEADS	=	includes/pipex.h

B_HEADS	=	includes/pipex_bonus.h

LIBNAME	=	libft/libft.a

LIB		=	libft

NAME	= pipex

GCC		= gcc -g -Wall -Wextra -Werror -MMD

RM		= rm -f


#%.o:	%.c $(HEADS) $(B_HEADS) Makefile
%.o:	%.c Makefile
	$(GCC) -c $< -o $@

#$(NAME):	$(HEADS) $(OBJS) $(LIBNAME)
$(NAME):	$(OBJS) $(LIBNAME)
	$(GCC) $(OBJS) $(LIBNAME) -o $(NAME)

all:	$(NAME)

$(LIBNAME):	lib

lib:	
	@$(MAKE) -C $(LIB)

#bonus:	$(B_HEADS) $(B_OBJS) $(LIBNAME)
#	$(GCC) $(B_OBJS) $(LIBNAME) -o $(NAME)

#bonus:	includes/pipex_bonus.h srcs/pipex_bonus.o srcs/utils_bonus.o libft/libft.a
#bonus:	$(B_HEADS) $(B_OBJS) $(LIBNAME)
bonus:	$(B_OBJS) $(LIBNAME)
	$(GCC) srcs/pipex_bonus.o srcs/utils_bonus.o $(LIBNAME) -o $(NAME)
#	gcc -g -Wall -Wextra -Werror -MMD srcs/pipex_bonus.o srcs/utils_bonus.o libft/libft.a -o pipex

clean:
	@$(MAKE) -C $(LIB) clean
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)

fclean:	clean
	@$(MAKE) -C $(LIB) fclean
	$(RM) $(wildcard srcs/*.d)
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all bonus clean fclean re lib
include ${wildcard srcs/*.d}