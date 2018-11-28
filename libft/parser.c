/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:41:32 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/17 17:41:35 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	check_ll(const char **format, t_form *form)
{
	if ((*(*format + 1) == 'l'))
	{
		form->ll = 1;
		(*format)++;
	}
	else
		form->l = 1;
}

static void	check_hh(const char **format, t_form *form)
{
	if ((*(*format + 1) == 'h'))
	{
		form->hh = 1;
		(*format)++;
	}
	else
		form->h = 1;
}

static void	set_flag(const char **format, t_form *form)
{
	if (**format == '#')
		form->hash = 1;
	else if (**format == '0' && !form->precision_set)
		form->zero = 1;
	else if (**format == '-')
		form->minus = 1;
	else if (**format == '+')
		form->plus = 1;
	else if (**format == ' ')
		form->space = 1;
	else if (**format == 'L')
		form->upper_l = 1;
	else if (**format == 'l')
		check_ll(format, form);
	else if (**format == 'h')
		check_hh(format, form);
}

static void	set_digit(const char **format, t_form *form)
{
	if (!form->precision_set)
		form->width = ft_atoi(*format);
	else
		form->precision = ft_atoi(*format);
}

t_form		parse(const char **format)
{
	t_form	form;

	form = (t_form){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	while (**format)
	{
		if (ft_isalpha(**format) && **format != 'h' && **format != 'l'
			&& **format != 'L')
		{
			form.type = **format;
			return (form);
		}
		else if (ft_strchr(FLAGS, **format))
			set_flag(format, &form);
		else if (ft_isdigit(**format))
		{
			set_digit(format, &form);
			while (ft_isdigit(**format))
				(*format)++;
			(*format)--;
		}
		else if (**format == '.')
			form.precision_set = 1;
		(*format)++;
	}
	return (form);
}
