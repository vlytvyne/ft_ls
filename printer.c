/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:41:18 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/25 16:41:19 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "prints.h"

static void	print_avec_a(t_list *lst, char *options)
{
	if (ft_strchr(options, 'o'))
		ft_lstiter(lst, print_ao);
	else if ((ft_strchr(options, 'm')))
		print_ma(lst);
	else if (ft_strchr(options, 'l'))
		ft_lstiter(lst, print_long_with_a);
	else if (ft_strchr(options, 'n'))
		ft_lstiter(lst, print_na);
	else
		ft_lstiter(lst, print_short_with_a);
}

static void	print_sans_a(t_list *lst, char *options)
{
	if (ft_strchr(options, 'o'))
		ft_lstiter(lst, print_o);
	else if ((ft_strchr(options, 'm')))
		print_m(lst);
	else if (ft_strchr(options, 'l'))
		ft_lstiter(lst, print_long);
	else if (ft_strchr(options, 'n'))
		ft_lstiter(lst, print_n);
	else
		ft_lstiter(lst, print_short);
}

void		printer(t_list *lst, char *options)
{
	if (ft_strchr(options, 'a'))
		print_avec_a(lst, options);
	else
		print_sans_a(lst, options);
}
