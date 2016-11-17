# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfichepo <pfichepo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:00:35 by pfichepo          #+#    #+#              #
#    Updated: 2016/11/17 11:10:28 by pfichepo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CC = clang
CFLAGS = -Wall  -Wextra -Ofast

SRCS = 	init.c \
		funcs.c \
		hook.c \
		extfunc.c \
		funcextmain.c \
		vectors.c \
		shapes.c
		
OBJS = $(SRCS:.c=.o)

all : $(NAME)

mlx:
	make -C minilibx_macos

$(NAME): $(OBJS)
	make -C minilibx_macos
	$(CC) -o $(NAME) $(OBJS) -framework OpenGL -framework AppKit -L minilibx_macos -lmlx

clean:
	make -C minilibx_macos/ clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: mlx clean fclean all re $(NAME)