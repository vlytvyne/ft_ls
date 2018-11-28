/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:59:31 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/19 12:39:44 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*btoa(long long int num, unsigned int bytes)
{
	long long int	binary;
	int				till;
	int				i;
	char			*str;

	if (bytes > 8)
		bytes = 8;
	i = 0;
	binary = 1;
	till = bytes * 8;
	str = ft_strnew(till);
	while (i < till)
	{
		if (binary & num)
			str[till - i - 1] = '1';
		else
			str[till - i - 1] = '0';
		binary = binary << 1;
		i++;
	}
	return (str);
}
