/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_space_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:50:33 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/17 17:50:35 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	plus_space_manager(t_form form, char **src)
{
	char *new_str;

	if (ft_strchr("dif", form.type) &&
		(form.space || form.plus) && **src != '-')
	{
		if (form.plus)
			new_str = ft_strjoin("+", *src);
		else
			new_str = ft_strjoin(" ", *src);
		free(*src);
		*src = new_str;
	}
}
