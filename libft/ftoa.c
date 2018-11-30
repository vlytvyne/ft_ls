/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:51:10 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/17 13:12:40 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	float_abs(long double num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

static void			cat_free(char *str, char *itoa_ret)
{
	ft_strcat(str, itoa_ret);
	free(itoa_ret);
}

static void			fill_zeros(char *str, char *itoa_ret, int precision)
{
	int itoa_len;

	itoa_len = ft_strlen(itoa_ret);
	while (itoa_len++ < precision)
		ft_strcat(str, "0");
}

char				*ftoa(long double num, unsigned int precision)
{
	long long int	ip;
	long double		fp;
	char			*str;
	char			*itoa_ret;

	str = ft_strnew(30);
	if (num < 0)
	{
		ft_strcat(str, "-");
		num = float_abs(num);
	}
	ip = (long long int)num;
	fp = num - ip;
	itoa_ret = ft_itoa(ip);
	cat_free(str, itoa_ret);
	if (precision != 0)
	{
		ft_strcat(str, ".");
		fp = fp * power(10, precision);
		itoa_ret = fp - (int)fp >= 0.5 ? ft_itoa(fp + 1) : ft_itoa(fp);
		fill_zeros(str, itoa_ret, precision);
		cat_free(str, itoa_ret);
	}
	return (str);
}
