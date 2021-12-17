# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 11:24:39 by tarchimb          #+#    #+#              #
#    Updated: 2021/12/17 14:25:07 by tarchimb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	pipex.c						\
				ft_parsing.c				\

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	./Includes/pipex.h			\
				./Includes/libft.h			\

CC			= gcc \

CFLAGS		= -Wall -Wextra -Werror

NAME		=	pipexlib.a

LIBS		= 	./libft/libft.a			\
				./pipexlib.a			\
				
EXEC		=	pipex

all:		libft ${EXEC}

%.o:		%.c ${INCLUDES}
			${CC} ${CFLAGS} -I ./Includes -c $< -o $@

${EXEC}:	pipex.c ${LIBS}
			${CC} ${CFLAGS} ${LIBS} pipex.c -o ${EXEC}

libft:		${INCLUDES}
			make -C libft


$(NAME):	${OBJS} ${INCLUDES}
			ar rcs ${NAME} ${OBJS}

clean:
			@${RM} ${OBJS} ${OBJSBONUS}
			make clean -C ./libft


fclean:		clean
			make fclean -C ./libft
			@${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean libft
