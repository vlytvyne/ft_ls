/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:42:20 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/15 19:14:49 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_digits_base(unsigned long long int num, int base)
{
	int size;

	size = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		size++;
		num /= base;
	}
	return (size);
}

char			*uitoa_base(unsigned long long int num, int base)
{
	char	*str;
	int		size;
	char	*base_str;

	base_str = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	size = count_digits_base(num, base);
	str = (char*)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	while (size > 0)
	{
		size--;
		str[size] = base_str[num % base];
		num /= base;
	}
	return (str);
}
