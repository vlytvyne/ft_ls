# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 15:35:57 by vlytvyne          #+#    #+#              #
#    Updated: 2018/11/26 21:23:14 by vlytvyne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c formers.c custom_input_handler.c \
printer.c utils.c get_dirs.c norminette_hello.c norminette_hello2.c \
sorter.c print_set1.c print_set2.c

LIBS = libft.a libftprintf.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)


$(NAME):
	gcc $(FLAGS) $(SRC) $(LIBS) -o $(NAME)

clean:
	@echo "Clean rule do nothing"

fclean: clean
	rm -f $(NAME)

re: fclean all
