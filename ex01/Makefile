SRCS	= ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

INCS	= ./includes/ft.h

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	 ${CC} ${FLAGS} -I includes -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	 ar rcs ${NAME} ${OBJS}

all:	 ${NAME}

clean:	
	 rm ${OBJS}

fclean:	 clean
	 rm ${NAME}
