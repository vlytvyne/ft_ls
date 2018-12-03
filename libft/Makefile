# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/23 20:46:18 by vlytvyne          #+#    #+#              #
#    Updated: 2018/12/03 12:16:33 by vlytvyne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCDIR = includes/

SRC = btoa.c capitalize.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c\
ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c\
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_printf.c\
ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c\
ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
ft_tolower.c ft_toupper.c ftoa.c get_abs.c get_next_line.c get_num_str.c hash_manager.c\
is_whitespace.c itoa_base.c lst_add_end.c parser.c plus_space_manager.c power.c\
precision_manager.c print_list.c reverse_list.c sort_list.c sort_list_ascii.c strrev.c\
uitoa_base.c ultimate_join.c utils.c width_manager.c zero_manager.c 

OBJDIR = objects

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: ./%.c $(INCDIR)/*.h | $(OBJDIR)
	gcc $(FLAGS) -o $@ -c $< -I $(INCDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -Rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
