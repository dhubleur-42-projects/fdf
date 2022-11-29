# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 09:16:50 by dhubleur          #+#    #+#              #
#    Updated: 2021/12/09 10:31:35 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \
			$(addprefix srcs/, \
				$(addprefix parse/, \
					map_parse.c \
					line_parse.c) \
				$(addprefix display/, \
					display.c \
					points_util.c \
					projection_util.c \
					projection_util2.c \
					display_util.c \
					colors.c \
					gradient.c) \
				$(addprefix input/, \
					keyboard_input.c \
					arrows_input.c \
					camera_input.c \
					wasd_input.c \
					mouse_input.c \
					display_input.c))
OBJS	=	${SRCS:.c=.o}
INCL	=	-I./includes -I./libft -I./minilibx-linux

NAME	=	fdf
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
CFLAGS  +=  -g3

RM		=	rm -f

LIBFT	=	libft/libft.a
LIBMLX	=   minilibx-linux/libmlx_Linux.a
MLXUTILS=	-lm -lbsd -lX11 -lXext

.c.o:
				${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

all:		${NAME}
bonus:		${NAME}

$(NAME):	${OBJS} ${LIBFT} ${LIBMLX}
				${CC} -o ${NAME} ${OBJS} ${LIBFT} ${LIBMLX} ${MLXUTILS}

$(LIBFT):
				$(MAKE) -C libft all

$(LIBMLX):
				$(MAKE) -C minilibx-linux all

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
