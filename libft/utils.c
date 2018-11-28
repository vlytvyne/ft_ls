/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:43:24 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/27 13:24:53 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		set_color(va_list args)
{
	char	*ansi_code;

	ansi_code = va_arg(args, char*);
	if (ft_strequ(ansi_code, RED) ||
		ft_strequ(ansi_code, GREEN) ||
		ft_strequ(ansi_code, YELLOW) ||
		ft_strequ(ansi_code, BLUE) ||
		ft_strequ(ansi_code, MAGENTA) ||
		ft_strequ(ansi_code, CYAN) ||
		ft_strequ(ansi_code, WHITE) ||
		ft_strequ(ansi_code, B_RED) ||
		ft_strequ(ansi_code, B_GREEN) ||
		ft_strequ(ansi_code, B_YELLOW) ||
		ft_strequ(ansi_code, B_BLUE) ||
		ft_strequ(ansi_code, B_MAGENTA) ||
		ft_strequ(ansi_code, B_CYAN) ||
		ft_strequ(ansi_code, B_WHITE) ||
		ft_strequ(ansi_code, EOC))
		ft_putstr(ansi_code);
	return (0);
}

char	*get_char_str(va_list args)
{
	char	*result;

	result = ft_strnew(1);
	*result = va_arg(args, int);
	return (result);
}

char	*get_pointer_str(va_list args)
{
	int		i;
	char	*tmp;
	char	*result;

	i = 0;
	tmp = itoa_base(va_arg(args, long long unsigned int), 16);
	while (tmp[i])
	{
		tmp[i] = ft_tolower(tmp[i]);
		i++;
	}
	result = ft_strjoin("0x", tmp);
	free(tmp);
	return (result);
}

char	*get_timestamp(void)
{
	time_t t;

	t = time(NULL);
	return (ft_strdup(ctime(&t)));
}

char	*get_str(va_list args)
{
	char	*result;

	result = ft_strdup(va_arg(args, char*));
	if (result == NULL)
		result = ft_strdup("(null)");
	return (result);
}
