/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capitalize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 10:18:19 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/10/24 10:21:50 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	capitalize(char *str)
{
	int	i;

	i = 1;
	if (str == NULL)
		return ;
	str[0] = ft_toupper(str[0]);
	while (str[i])
	{
		if (is_whitespace(str[i - 1]))
			str[i] = ft_toupper(str[i]);
		else
			str[i] = ft_tolower(str[i]);
		i++;
	}
}
