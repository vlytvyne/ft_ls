/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette_hello2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:02:31 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/26 21:02:33 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void			norm_recur_print(t_list *entries, char *options)
{
	t_list		*to_free;
	t_list		*dirs;

	dirs = get_directories(entries, options);
	to_free = dirs;
	while (dirs)
	{
		print_dir_entries((char*)dirs->content, options);
		dirs = dirs->next;
	}
	ft_lstdel(&to_free, del);
}
