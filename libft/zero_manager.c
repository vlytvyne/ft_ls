/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:49:30 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/17 17:49:31 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	dif_zero_manager(t_form form, char **src, char *new_str, int srclen)
{
	unsigned int i;

	i = 0;
	if (form.plus || form.space || **src == '-')
	{
		if (**src == '-')
			new_str[i++] = '-';
		else if (form.plus)
			new_str[i++] = '+';
		else if (form.space)
			new_str[i++] = ' ';
		while (i < form.width - srclen + 1)
			new_str[i++] = '0';
		ft_strcpy(&new_str[i], (*src + 1));
	}
	else
	{
		while (i < form.width - srclen)
			new_str[i++] = '0';
		ft_strcpy(&new_str[i], *src);
	}
	free(*src);
	*src = new_str;
}

static void	hex_zero_manager(t_form form, char **src, char *new_str, int srclen)
{
	unsigned int i;

	i = 0;
	if (form.hash)
	{
		new_str[i++] = '0';
		new_str[i++] = form.type == 'x' ? 'x' : 'X';
		while (i < form.width - srclen + 2)
			new_str[i++] = '0';
		ft_strcpy(&new_str[i], (*src + 2));
	}
	else
	{
		while (i < form.width - srclen)
			new_str[i++] = '0';
		ft_strcpy(&new_str[i], *src);
	}
	free(*src);
	*src = new_str;
}

void		zero_manager(t_form form, char **src, char *new_str, int srclen)
{
	unsigned int i;

	i = 0;
	if (ft_strchr("dif", form.type))
		dif_zero_manager(form, src, new_str, srclen);
	else if ((form.type == 'x' || form.type == 'X'))
		hex_zero_manager(form, src, new_str, srclen);
	else if (form.type == 'u' || form.type == 'o' || form.type == 'c')
	{
		while (i < form.width - srclen)
		{
			new_str[i] = '0';
			i++;
		}
		ft_strcpy(&new_str[i], *src);
		free(*src);
		*src = new_str;
	}
}
