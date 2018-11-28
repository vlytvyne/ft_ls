/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:42:53 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/19 17:53:22 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <time.h>
# include "libft.h"

# define CONVERSIONS "cspdiouxXfbtwq"
# define FLAGS "hlL#0-+ "

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define B_RED "\x1b[31;1m"
# define B_GREEN "\x1b[32;1m"
# define B_YELLOW "\x1b[33;1m"
# define B_BLUE "\x1b[34;1m"
# define B_MAGENTA "\x1b[35;1m"
# define B_CYAN "\x1b[36;1m"
# define B_WHITE "\x1b[37;1m"
# define EOC "\x1b[0m"

typedef struct		s_form
{
	unsigned int	hash:1;
	unsigned int	zero:1;
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	space:1;
	unsigned int	l:1;
	unsigned int	ll:1;
	unsigned int	h:1;
	unsigned int	hh:1;
	unsigned int	upper_l:1;
	unsigned int	precision_set:1;
	unsigned int	width;
	unsigned int	precision;
	char			type;
}					t_form;

int					ft_printf(const char *format, ...);
t_form				parse(const char **format);
char				*get_num_str(t_form form, va_list args);
void				precision_manager(t_form form, char **src);
void				width_manager(t_form form, char **src);
void				hash_manager(t_form form, char **src);
void				plus_space_manager(t_form form, char **src);
void				zero_manager(t_form form, char **src,
					char *new_str, int srclen);
int					set_color(va_list args);
char				*get_char_str(va_list args);
char				*get_pointer_str(va_list args);
char				*get_timestamp(void);
char				*get_str(va_list args);
int					print_list(t_form form, va_list args);

#endif
