/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:41:18 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/25 16:41:19 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static void	print_long(t_list *lst)
{
	t_stat	fstat;
	char	*file_name;
	char	*mode_line;
	char	*time_str;
	char	*link_line;

	link_line = ft_strnew(1000);
	file_name = get_file_name(lst);
	lstat((char*)lst->content, &fstat);
	mode_line = form_mode_line(lst, fstat.st_mode);
	time_str = form_time_line(fstat);
	if (fstat.st_mode & S_IFLNK)
		readlink((char*)lst->content, link_line, 1000);
	if (*file_name != '.')
	{
		ft_printf("%-11s ", mode_line);
		ft_printf("%3d ", fstat.st_nlink);
		ft_printf("%8s ", getpwuid(fstat.st_uid)->pw_name);
		ft_printf("%-15s ", getgrgid(fstat.st_gid)->gr_name);
		if (ft_strchr(mode_line, 'b') || ft_strchr(mode_line, 'c'))
			ft_printf("%4d,%4d", major(fstat.st_rdev), minor(fstat.st_rdev));
		else
			ft_printf("%9d", fstat.st_size);
		ft_printf(" %s %s", time_str, file_name);
		if (*link_line != '\0')
			ft_printf(" -> %s", link_line);
		ft_printf("\n");
	}
	ft_strdel(&mode_line);
	ft_strdel(&time_str);
	ft_strdel(&link_line);
}

static void	print_long_with_a(t_list *lst)
{
	t_stat	fstat;
	char	*file_name;
	char	*mode_line;
	char	*time_str;
	char	*link_line;

	link_line = ft_strnew(1000);
	file_name = get_file_name(lst);
	lstat((char*)lst->content, &fstat);
	mode_line = form_mode_line(lst, fstat.st_mode);
	time_str = form_time_line(fstat);
	if (fstat.st_mode & S_IFLNK)
		readlink((char*)lst->content, link_line, 1000);
		ft_printf("%-11s ", mode_line);
		ft_printf("%3d ", fstat.st_nlink);
		ft_printf("%8s ", getpwuid(fstat.st_uid)->pw_name);
		ft_printf("%-15s ", getgrgid(fstat.st_gid)->gr_name);
		if (ft_strchr(mode_line, 'b') || ft_strchr(mode_line, 'c'))
			ft_printf("%4d,%4d", major(fstat.st_rdev), minor(fstat.st_rdev));
		else
			ft_printf("%9d", fstat.st_size);
		ft_printf(" %s %s", time_str, file_name);
		if (*link_line != '\0')
			ft_printf(" -> %s", link_line);
		ft_printf("\n");
		ft_strdel(&mode_line);
		ft_strdel(&time_str);
		ft_strdel(&link_line);
}

static void	print_short(t_list *lst)
{
	t_stat	fstat;
	char	*file_name;
	int		mode;

	file_name = get_file_name(lst);
	stat((char*)lst->content, &fstat);
	mode = fstat.st_mode;
	if (*file_name != '.')
		ft_printf("%s\n", file_name);
}

static void	print_short_with_a(t_list *lst)
{
	t_stat	fstat;
	char	*file_name;
	int		mode;

	file_name = get_file_name(lst);
	stat((char*)lst->content, &fstat);
	mode = fstat.st_mode;
	ft_printf("%s\n", file_name);
}

void		printer(t_list *lst, char *options)
{
	if (ft_strchr(options, 'a') && ft_strchr(options, 'l'))
		ft_lstiter(lst, print_long_with_a);
	else if (ft_strchr(options, 'a'))
		ft_lstiter(lst, print_short_with_a);
	else if (ft_strchr(options, 'l'))
		ft_lstiter(lst, print_long);
	else
		ft_lstiter(lst, print_short);
}
