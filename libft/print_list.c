/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:15:03 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/27 13:15:04 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static void	print_list_str(t_list *list)
{
	ft_putstr((char*)list->content);
	ft_putchar('\n');
}

static void	print_list_int(t_list *list)
{
	ft_putnbr(*(int*)list->content);
	ft_putchar('\n');
}

int			print_list(t_form form, va_list args)
{
	t_list *list;

	list = va_arg(args, t_list*);
	if (form.hash == 1)
		ft_lstiter(list, print_list_int);
	else
		ft_lstiter(list, print_list_str);
	return (0);
}
