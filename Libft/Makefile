# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchimb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 14:57:46 by tarchimb          #+#    #+#              #
#    Updated: 2021/11/08 11:08:13 by tarchimb         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #
SRCS		=	./ft_atoi.c ./ft_calloc.c ./ft_isalpha.c ./ft_isdigit.c \
      			./ft_memcmp.c ./ft_memmove.c ./ft_putchar_fd.c\
				./ft_split.c ./ft_strdup.c ./ft_strjoin.c ./ft_strlcpy.c \
				./ft_strmapi.c ./ft_strnstr.c ./ft_strtrim.c ./ft_tolower.c \
				./ft_bzero.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c \
				./ft_memchr.c ./ft_memcpy.c ./ft_memset.c ./ft_putendl_fd.c \
				./ft_putstr_fd.c ./ft_strchr.c ./ft_striteri.c \
				./ft_strlen.c ./ft_strncmp.c ./ft_strrchr.c ./ft_substr.c \
				./ft_toupper.c ./ft_itoa.c ./ft_putnbr_fd.c ./ft_strlcat.c\
				./ft_lstadd_back.c ./ft_lstadd_front.c \
				./ft_lstlast.c ./ft_lstsize.c ./ft_lstnew.c ./ft_lstclear.c \
				./ft_lstiter.c ./ft_lstdelone.c  ./ft_lstmap.c \

OBJS		=	${SRCS:.c=.o}


INCLUDES	=	../Includes/libft.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

NAME		=	libft.a

RM			=	rm -f

all:		${NAME}

.c.o:		${INCLUDES}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${INCLUDES}
			ar rcs ${NAME} ${OBJS}
			mv ${NAME} ../Libs/

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re bonus
