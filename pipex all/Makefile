SRCS 	= srcs/pipex.c   \
    srcs/utils.c   \

B_SRCS	=	srcs/pipex_bonus.o srcs/utils_bonus.o

OBJS	=	$(SRCS:.c=.o) 

B_OBJS	=	$(B_SRCS:.c=.o) 

HEADS	=	includes/pipex.h

B_HEADS	=	includes/pipex_bonus.h

LIBNAME	=	libft/libft.a

LIB		=	libft

NAME	= pipex

GCC		= cc -g -Wall -Wextra -Werror -MMD

RM		= rm -f

TEMP_FILE = .temp_file

%.o:	%.c Makefile 
	$(GCC) -c $< -o $@

$(NAME):	$(OBJS) $(LIBNAME) $(HEADS)
	$(GCC) $(OBJS) $(LIBNAME) -o $(NAME)

all:	$(NAME)

$(LIBNAME):	libft/*.h $(wildcard libft/*.c)
	make -C libft

bonus : ${TEMP_FILE}

${TEMP_FILE}: $(B_OBJS) $(LIBNAME) $(B_HEADS) 
	$(GCC) $(B_OBJS) $(LIBNAME) -o $(NAME)
	touch ${TEMP_FILE}

clean:
	$(MAKE) -C $(LIB) clean
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
	${RM} ${TEMP_FILE}
	$(RM) $(wildcard srcs/*.d)

fclean:	clean
	$(MAKE) -C $(LIB) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all bonus clean fclean re lib 
include ${wildcard srcs/*.d}