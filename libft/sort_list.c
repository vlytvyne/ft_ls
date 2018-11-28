/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:33:48 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/22 20:33:55 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sort_list(t_list *root, int (*cmp)(t_list*, t_list*))
{
	t_list	*lst;
	void	*tmp;
	int		swaped;

	if (root == NULL || cmp == NULL)
		return ;
	swaped = 1;
	while (swaped)
	{
		swaped = 0;
		lst = root;
		while (lst->next)
		{
			if (cmp(lst, lst->next) > 0)
			{
				tmp = lst->next->content;
				lst->next->content = lst->content;
				lst->content = tmp;
				swaped = 1;
			}
			lst = lst->next;
		}
	}
}
