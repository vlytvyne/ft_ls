/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:31:01 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/22 14:31:13 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

char	*ultimate_join(int howmuch, ...)
{
	va_list args;
	int		i;
	char	*result;
	char	*arg_str;
	char	*to_free;

	i = 0;
	result = ft_strnew(0);
	va_start(args, howmuch);
	while (i < howmuch)
	{
		arg_str = va_arg(args, char *);
		to_free = result;
		result = ft_strjoin(result, arg_str);
		free(to_free);
		i++;
	}
	va_end(args);
	return (result);
}
