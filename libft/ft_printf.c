/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:40:50 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/13 14:41:09 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	run_managers(t_form form, char **result)
{
	precision_manager(form, result);
	plus_space_manager(form, result);
	hash_manager(form, result);
	width_manager(form, result);
}

static int	dispatcher(t_form form, va_list args)
{
	char	*result;
	int		printed;

	if (!ft_strchr(CONVERSIONS, form.type))
		return (0);
	if (form.type == 'q')
		return (print_list(form, args));
	if (form.type == 't')
		return (set_color(args));
	else if (form.type == 'c')
		result = get_char_str(args);
	else if (form.type == 'w')
		result = get_timestamp();
	else if (form.type == 's')
		result = get_str(args);
	else if (form.type == 'p')
		result = get_pointer_str(args);
	else if (ft_strchr("diouxXfb", form.type))
		result = get_num_str(form, args);
	run_managers(form, &result);
	ft_putstr(result);
	printed = ft_strlen(result);
	free(result);
	return (printed);
}

static void	print_and_move(const char ch, int *printed)
{
	ft_putchar(ch);
	(*printed)++;
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	t_form	form;
	int		printed;

	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			print_and_move(*format, &printed);
		else
		{
			format++;
			if (*format == '%')
				print_and_move('%', &printed);
			else
			{
				form = parse(&format);
				printed += dispatcher(form, args);
			}
		}
		format++;
	}
	va_end(args);
	return (printed);
}
