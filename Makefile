NAME	= libftprintf.a

HEADER	= ft_printf.h

SRC		= ft_printf.c printf_char.c printf_p.c printf_str.c ft_strlen.c printf_d.c printf_x.c printf_u.c

OBJ		= ${patsubst %.c,%.o,${SRC}}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		${NAME}

${NAME}:	${OBJ} ${HEADER}
			ar rcs ${NAME} $?

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} -c $< -o $@	

clean:	
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re