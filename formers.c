/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:46:34 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/25 16:46:35 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*form_mode_line(t_list *lst, int mode)
{
	char	*str_mode;
	int		mode_mask;

	str_mode = ft_strnew(11);
	mode_mask = mode & S_IFMT;
	if (mode_mask == S_IFDIR)
		str_mode[0] = 'd';
	else if (mode_mask == S_IFLNK)
		str_mode[0] = 'l';
	else if (mode_mask == S_IFCHR)
		str_mode[0] = 'c';
	else if (mode_mask == S_IFBLK)
		str_mode[0] = 'b';
	else if (mode_mask == S_IFIFO)
		str_mode[0] = 'p';
	else if (mode_mask == S_IFSOCK)
		str_mode[0] = 's';
	else
		str_mode[0] = '-';
	str_mode[1] = mode & 0400 ? 'r' : '-';
	str_mode[2] = mode & 0200 ? 'w' : '-';
	str_mode[3] = mode & 0100 ? 'x' : '-';
	str_mode[4] = mode & 0040 ? 'r' : '-';
	str_mode[5] = mode & 0020 ? 'w' : '-';
	str_mode[6] = mode & 0010 ? 'x' : '-';
	str_mode[7] = mode & 0004 ? 'r' : '-';
	str_mode[8] = mode & 0002 ? 'w' : '-';
	str_mode[9] = mode & 0001 ? 'x' : '-';
	// if (listxattr((char*)lst->content, NULL, 0, XATTR_NOFOLLOW))
	// 	str_mode[10] = '@';
	return (str_mode);
}

char	*form_time_line(t_stat fstat)
{
	char	*time_str;
	time_t	time_last_mod;

	time_last_mod = (fstat.st_mtimespec).tv_sec;
	time_str = ctime(&time_last_mod);
	if (time_last_mod + HALF_YEAR < time(NULL))
		return (ft_strjoin(ft_strsub(time_str, 4, 7), ft_strsub(time_str, 19, 5)));
	else
		return (ft_strsub(time_str, 4, 12));
}
