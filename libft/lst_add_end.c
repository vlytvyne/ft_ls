/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 19:21:16 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/13 13:23:30 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_add_end(t_list *head, t_list *new)
{
	if (head == NULL || new == NULL)
		return ;
	while (head->next)
		head = head->next;
	head->next = new;
}
