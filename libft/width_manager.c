/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:48:38 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/17 17:48:42 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	left_align_manager(char *new_str, char **src, int srclen, int width)
{
	ft_strcpy(new_str, *src);
	while (srclen < width)
		new_str[srclen++] = ' ';
	free(*src);
	*src = new_str;
}

static void	right_align_manager(char *new_str, char **src,
	int srclen, int width)
{
	int		i;
	int		cpy_from;

	cpy_from = width - srclen;
	ft_strcpy(new_str + cpy_from, *src);
	i = 0;
	while (i < cpy_from)
		new_str[i++] = ' ';
	free(*src);
	*src = new_str;
}

void		width_manager(t_form form, char **src)
{
	int		srclen;
	int		width;
	char	*new_str;

	width = form.width;
	srclen = ft_strlen(*src);
	if (width <= srclen)
		return ;
	new_str = ft_strnew(width);
	if (form.minus)
		left_align_manager(new_str, src, srclen, width);
	else
	{
		if (ft_strchr("diouxXfc", form.type) && form.zero
			&& (!form.precision_set || form.type == 'f'))
			zero_manager(form, src, new_str, srclen);
		else
			right_align_manager(new_str, src, srclen, width);
	}
}
