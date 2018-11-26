# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 15:35:57 by vlytvyne          #+#    #+#              #
#    Updated: 2018/11/26 21:14:43 by vlytvyne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c formers.c custom_input_handler.c \
printer.c utils.c get_dirs.c norminette_hello.c norminette_hello2.c

LIBS = libft.a libftprintf.a

all: $(NAME)


$(NAME):
	gcc $(SRC) $(LIBS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
