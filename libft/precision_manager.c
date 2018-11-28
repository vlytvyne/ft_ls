/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:46:34 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/17 17:46:36 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	prec_for_minus(t_form form, char **src)
{
	int		size;
	char	*new_str;
	char	*beginning;

	size = form.precision - ft_strlen(*src);
	if (size <= 0)
		return ;
	beginning = ft_strnew(size);
	while (--size >= 0)
		beginning[size] = '0';
	new_str = ft_strjoin(beginning, *src);
	free(*src);
	free(beginning);
	*src = new_str;
}

static void	prec_without_minus(t_form form, char **src)
{
	int		size;
	char	*new_str;
	char	*beginning;

	size = form.precision - ft_strlen(*src) + 2;
	if (size <= 0)
		return ;
	beginning = ft_strnew(size);
	beginning[0] = '-';
	while (--size >= 1)
		beginning[size] = '0';
	new_str = ft_strjoin(beginning, (*src + 1));
	free(*src);
	free(beginning);
	*src = new_str;
}

void		precision_manager(t_form form, char **src)
{
	char	*to_free;

	if (form.type == 's' && form.precision_set
		&& form.precision < ft_strlen(*src))
	{
		to_free = *src;
		*src = ft_strsub(*src, 0, form.precision);
		free(to_free);
	}
	else if (ft_strchr("diouxX", form.type))
	{
		if (**src != '-')
			prec_for_minus(form, src);
		else
			prec_without_minus(form, src);
	}
}
