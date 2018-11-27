/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_set2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:29:46 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/27 18:29:47 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_ma(t_list *lst)
{
	int		first;
	t_stat	fstat;
	char	*file_name;

	first = 1;
	while (lst)
	{
		file_name = get_file_name(lst);
		stat((char*)lst->content, &fstat);
		if (first)
		{
			ft_printf("%s", file_name);
			first = 0;
		}
		else
			ft_printf(", %s", file_name);
		lst = lst->next;
	}
	ft_printf("\n", file_name);
}

void	print_long(t_list *lst)
{
	t_stat	fstat;
	char	*file_name;
	char	*mode_line;
	char	*time_str;
	char	*link_line;

	link_line = ft_strnew(1000);
	file_name = get_file_name(lst);
	lstat((char*)lst->content, &fstat);
	mode_line = form_mode_line(fstat.st_mode);
	time_str = form_time_line(fstat);
	if (fstat.st_mode & S_IFLNK)
		readlink((char*)lst->content, link_line, 1000);
	if (*file_name != '.')
	{
		ft_printf("%-11s %3d ", mode_line, fstat.st_nlink);
		ft_printf("%8s ", getpwuid(fstat.st_uid)->pw_name);
		ft_printf("%-15s ", getgrgid(fstat.st_gid)->gr_name);
		norm_psize(mode_line, fstat);
		ft_printf(" %s %s", time_str, file_name);
		if (*link_line != '\0')
			ft_printf(" -> %s", link_line);
		ft_printf("\n");
	}
	norm_free_strs(&mode_line, &time_str, &link_line);
}

void	print_long_with_a(t_list *lst)
{
	t_stat	fstat;
	char	*file_name;
	char	*mode_line;
	char	*time_str;
	char	*link_line;

	link_line = ft_strnew(1000);
	file_name = get_file_name(lst);
	lstat((char*)lst->content, &fstat);
	mode_line = form_mode_line(fstat.st_mode);
	time_str = form_time_line(fstat);
	if (fstat.st_mode & S_IFLNK)
		readlink((char*)lst->content, link_line, 1000);
	ft_printf("%-11s ", mode_line);
	ft_printf("%3d ", fstat.st_nlink);
	ft_printf("%8s ", getpwuid(fstat.st_uid)->pw_name);
	ft_printf("%-15s ", getgrgid(fstat.st_gid)->gr_name);
	norm_psize(mode_line, fstat);
	ft_printf(" %s %s", time_str, file_name);
	if (*link_line != '\0')
		ft_printf(" -> %s", link_line);
	ft_printf("\n");
	norm_free_strs(&mode_line, &time_str, &link_line);
}

void	print_short(t_list *lst)
{
	t_stat	fstat;
	char	*file_name;

	file_name = get_file_name(lst);
	stat((char*)lst->content, &fstat);
	if (*file_name != '.')
		ft_printf("%s\n", file_name);
}

void	print_short_with_a(t_list *lst)
{
	t_stat	fstat;
	char	*file_name;

	file_name = get_file_name(lst);
	stat((char*)lst->content, &fstat);
	ft_printf("%s\n", file_name);
}
