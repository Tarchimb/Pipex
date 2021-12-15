# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 11:24:39 by tarchimb          #+#    #+#              #
#    Updated: 2021/12/02 11:59:11 by tarchimb         ###   ########.fr        #
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

RM			=	rm -f

LIBS		= 	./Libs/libft.a			\
				./Libs/pipexlib.a			\

all:		${NAME}

%.o:		%.c ${INCLUDES}
			${CC} ${CFLAGS} -I ./Includes -c $< -o $@

gc:
			${CC} ${CFLAGS} ${LIBS} pipex.c -o pipex
			./pipex infile "sleep 2" "lr" "cat -e" "wc -l" outfile


$(NAME):	${OBJS} ${INCLUDES}
			make -C ./Libft
			ar rcs ${NAME} ${OBJS}
			mv ${NAME} ./Libs

clean:
			@${RM} ${OBJS} ${OBJSBONUS}
			make clean -C ./Libft


fclean:		clean
			make fclean -C ./Libft
			@${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
