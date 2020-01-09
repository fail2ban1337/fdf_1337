# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/08 22:27:40 by abelomar          #+#    #+#              #
#    Updated: 2019/05/08 22:28:36 by abelomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

all : $(NAME)

$(NAME) :
			@make -C libft
			@gcc -Wall -Wextra -Werror -I /usr/local/include/ ./src/designfdf.c ./src/draw_fdf.c ./src/fdf.c ./src/freefunc.c ./src/get_next_line.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(NAME)

clean :
			@make clean -C libft

fclean :
			@make fclean -C libft
			@rm -f $(NAME)

re : fclean all
