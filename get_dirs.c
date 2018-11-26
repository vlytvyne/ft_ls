/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:52:44 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/25 16:52:45 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int	is_dir_due(t_list *entry, char *options)
{
	char	*dirname;

	dirname = ft_strrchr((char*)entry->content, '/') + 1;
	if (ft_strchr(options, 'a'))
	{
		if (ft_strequ(dirname, ".") || ft_strequ(dirname, ".."))
			return (0);
		else
			return (1);
	}
	else
	{
		if (*dirname != '.')
			return (1);
		else
			return (0);
	}
	return (0);
}

t_list		*get_directories(t_list *entries, char *options)
{
	t_list	*dirs;
	t_stat	fstat;
	int		mode;

	dirs = NULL;
	while (entries)
	{
		lstat((char*)entries->content, &fstat);
		mode = fstat.st_mode & S_IFMT;
		if ((mode == S_IFDIR) &&
			is_dir_due(entries, options))
		{
			if (dirs == NULL)
				dirs = ft_lstnew(entries->content,
					ft_strlen((char*)entries->content) + 1);
			else
				lst_add_end(dirs, ft_lstnew(entries->content,
					ft_strlen((char*)entries->content) + 1));
		}
		entries = entries->next;
	}
	return (dirs);
}
