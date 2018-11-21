/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:27:20 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/21 17:27:23 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_list(t_list *lst)
{
	t_stat fstat;

	stat((char*)lst->content, &fstat);
	ft_printf("%s -- %.7o\n", (char*)lst->content, fstat.st_mode);
}

t_list	*extract_dir_entries(const char *dir_name)
{
	DIR		*dir;
	t_dent	*dent;
	t_list	*head;
	t_list	*new;

	dir = opendir(dir_name);
	if ((dent = readdir(dir)))
		head = ft_lstnew(dent->d_name, ft_strlen(dent->d_name) + 1);
	while ((dent = readdir(dir)))
	{
		new = ft_lstnew(dent->d_name, ft_strlen(dent->d_name) + 1);
		lst_add_end(head, new);
	}
	closedir(dir);
	return (head);
}

int		main(void)
{
	t_list *list;
	list = extract_dir_entries(".");
	ft_lstiter(list, print_list);
}