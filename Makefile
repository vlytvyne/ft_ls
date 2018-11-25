# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 15:35:57 by vlytvyne          #+#    #+#              #
#    Updated: 2018/11/22 15:37:13 by vlytvyne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c formers.c custom_input_handler.c \
printer.c utils.c get_dirs.c

all:
	gcc $(SRC) lib libftprintf.a -o $(NAME)
