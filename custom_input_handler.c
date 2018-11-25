/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_input_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:48:02 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/25 16:48:04 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static t_list	*check_invalid_input(t_list *entries)
{
	t_stat	fstat;
	t_list	*valid_entries;

	valid_entries = NULL;
	while (entries)
	{
		if (lstat((char*)entries->content, &fstat) == -1)
		{
			if (errno == ENOENT)
				error((char*)entries->content);
		}	
		else
		{
			if (valid_entries == NULL)
				valid_entries = ft_lstnew((char*)entries->content, ft_strlen((char*)entries->content) + 1);
			else
				lst_add_end(valid_entries, ft_lstnew((char*)entries->content, ft_strlen((char*)entries->content) + 1));
		}
		entries = entries->next;
	}
	return (valid_entries);
}

static t_list	*get_directories_custom(t_list *entries)
{
	t_list	*dirs;
	t_stat	fstat;

	dirs = NULL;
	while (entries)
	{
		stat((char*)entries->content, &fstat);
		if (fstat.st_mode & S_IFDIR)
		{
			if (dirs == NULL)
				dirs = ft_lstnew(entries->content, ft_strlen((char*)entries->content) + 1);
			else
				lst_add_end(dirs, ft_lstnew(entries->content, ft_strlen((char*)entries->content) + 1));
		}
		entries = entries->next;
	}
	return (dirs);
}

static t_list	*get_files(t_list *lst)
{
	t_stat	fstat;
	t_stat	fstat1;
	t_list	*files;

	files = NULL;
	while (lst)
	{
		if (lstat((char*)lst->content, &fstat) != -1)
		{
			stat((char*)lst->content, &fstat1);
			if (!(fstat.st_mode & S_IFDIR) && !(fstat1.st_mode & S_IFDIR))
			{
				if (files == NULL)
					files = ft_lstnew((char*)lst->content, ft_strlen((char*)lst->content) + 1);
				else
					lst_add_end(files, ft_lstnew((char*)lst->content, ft_strlen((char*)lst->content) + 1));
			}
		}
		lst = lst->next;
	}
	return (files);
}

void			print_custom_input(t_list *entries, char *options)
{
	t_list	*valid_entries;
	t_list	*dirs;
	t_list	*files;

	valid_entries = check_invalid_input(entries);
	files = get_files(valid_entries);
	printer(files, options);
	dirs = get_directories_custom(valid_entries);
	if (entries->next)
		ft_printf("\n%s:\n", (char*)dirs->content);
	while (dirs)
	{
		print_dir_entries((char*)dirs->content, options);
		dirs = dirs->next;
	}
}
