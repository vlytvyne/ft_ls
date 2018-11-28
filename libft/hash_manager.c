/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:51:06 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/27 13:26:25 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	check_ending(char *src)
{
	if (*src == '\0')
		return (0);
	while (*src)
		src++;
	src--;
	if (*src == '0')
		return (0);
	return (1);
}

void		hash_manager(t_form form, char **src)
{
	char *new_str;

	new_str = NULL;
	if (form.hash)
	{
		if (form.type == 'o' && **src != '0')
			new_str = ft_strjoin("0", *src);
		else if (form.type == 'x' && check_ending(*src))
			new_str = ft_strjoin("0x", *src);
		else if (form.type == 'X' && check_ending(*src))
			new_str = ft_strjoin("0X", *src);
		else if (form.type == 'f' && form.precision_set && form.precision == 0)
			new_str = ft_strjoin(*src, ".");
		else if (form.type == 's')
			capitalize(*src);
		else if (form.type == 'w')
			new_str = ft_strsub(*src, 11, 8);
		if (new_str != NULL)
		{
			free(*src);
			*src = new_str;
		}
	}
}
