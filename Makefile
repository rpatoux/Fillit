# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 12:11:19 by jamerlin          #+#    #+#              #
#    Updated: 2016/12/12 17:01:05 by jamerlin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADER = -I ./includes

LIB = -I ./libft -L ./libft/ -lft

SRC = srcs/ft_check.c \
	srcs/ft_fillit.c \
	srcs/ft_check_two.c \
	srcs/ft_map.c \
	srcs/ft_push_up_left.c \
	srcs/ft_sqrt.c \
	srcs/ft_stock.c \
	srcs/ft_tetrim_on_map.c \
	srcs/ft_check_map.c \
	srcs/ft_push_up_left_two.c \
	srcs/main.c \

CC = gcc -I./includes

OPTION = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(OPTION) -o $(NAME) $(OBJ) $(LIB) $(HEADER)

all : $(NAME)

clean : 
	rm -f $(OBJ)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	make fclean -C libft/

re : fclean all
