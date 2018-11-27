/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:25:14 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/27 14:25:16 by vlytvyne         ###   ########.fr       */
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

static int	cmp_size(t_list *first, t_list *second)
{
	t_stat	fstat_first;
	t_stat	fstat_second;
	off_t	first_size;
	off_t	second_size;

	lstat((char*)first->content, &fstat_first);
	lstat((char*)second->content, &fstat_second);
	first_size = fstat_first.st_size;
	second_size = fstat_second.st_size;
	return (second_size - first_size);
}

void		sorter(t_list **list, char *options)
{
	if (ft_strchr(options, 'S'))
		sort_list(*list, cmp_size);
	else if (ft_strchr(options, 't'))
		sort_list(*list, cmp_time);
	else
		sort_list_ascii(*list);
	if (ft_strchr(options, 'r'))
		reverse_list(list);
}
