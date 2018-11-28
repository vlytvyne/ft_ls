/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_ascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:09:18 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/22 19:09:37 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp_ascci(t_list *first, t_list *second)
{
	return (ft_strcmp((char*)first->content, (char*)second->content));
}

void		sort_list_ascii(t_list *root)
{
	sort_list(root, cmp_ascci);
}
