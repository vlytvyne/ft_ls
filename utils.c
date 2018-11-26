/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:37:27 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/25 16:37:28 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int	cmp_time(t_list *first, t_list *second)
{
	t_stat	fstat_first;
	t_stat	fstat_second;
	time_t	first_time;
	time_t	second_time;

	lstat((char*)first->content, &fstat_first);
	lstat((char*)second->content, &fstat_second);
	first_time = (fstat_first.st_mtimespec).tv_sec;
	second_time = (fstat_second.st_mtimespec).tv_sec;
	return (second_time - first_time);
}

void		sorter(t_list **list, char *options)
{
	t_stat	fstat;

	if (ft_strchr(options, 't'))
		sort_list(*list, cmp_time);
	else
		sort_list_ascii(*list);
	if (ft_strchr(options, 'r'))
		reverse_list(list);
}

void		error(const char *msg)
{
	if (errno == EACCES)
		ft_printf("ft_ls: %s: Permission denied\n",
			ft_strchr(msg, '/') ? ft_strrchr(msg, '/') + 1 : msg);
	else if (errno == ENOENT)
		ft_printf("ft_ls: %s: No such file or directory\n", msg);
	else
	{
		ft_printf("%s", msg);
		exit(errno);
	}
}

char		*get_file_name(t_list *lst)
{
	return (ft_strchr((char*)lst->content, '/') ?
		ft_strrchr((char*)lst->content, '/') + 1 : (char*)lst->content);
}

void		del(void *content, size_t size)
{
	(void)size;
	free(content);
}
