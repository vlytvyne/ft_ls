/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette_hello.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:01:16 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/26 21:01:17 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	norm_psize(char *mode_line, t_stat fstat)
{
	if (ft_strchr(mode_line, 'b') || ft_strchr(mode_line, 'c'))
		ft_printf("%4d,%4d", major(fstat.st_rdev), minor(fstat.st_rdev));
	else
		ft_printf("%9d", fstat.st_size);
}

void	norm_free_strs(char **mode_line, char **time_str, char **link_line)
{
	ft_strdel(mode_line);
	ft_strdel(time_str);
	ft_strdel(link_line);
}

t_list	*norm_get_head(t_dent *dent, const char *dir_name)
{
	char	*file_name;
	t_list	*head;

	file_name = ultimate_join(3, dir_name, "/", dent->d_name);
	head = ft_lstnew(file_name, ft_strlen(file_name) + 1);
	free(file_name);
	return (head);
}

void	norm_init(int *i, int *k, char **options)
{
	*options = ft_strnew(ft_strlen(OPTIONS));
	*i = 0;
	*k = 0;
}

char	*norm_not_minus(char *options, int *arg_start, int i)
{
	*arg_start = i;
	return (options);
}
