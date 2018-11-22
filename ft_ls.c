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

void	print_no_options(t_list *lst)
{
	t_stat	fstat;
	char	*file_name;
	int		mode;

	file_name = ft_strrchr((char*)lst->content, '/') + 1;
	stat((char*)lst->content, &fstat);
	mode = fstat.st_mode;
	if (*file_name != '.')
		ft_printf("%s -- %.7o\n", file_name, fstat.st_mode);
}

void	error(const char *msg)
{
	if (errno == EACCES)
		ft_printf("ft_ls: %s: Permission denied\n", ft_strchr(msg, '/') ? ft_strrchr(msg, '/') + 1 : msg);
	else if (errno == ENOENT)
		ft_printf("ft_ls: %s: No such file or directory\n", msg);
	else
	{
		ft_printf("%s", msg);
		exit(errno);
	}
}

t_list	*extract_dir_entries(const char *dir_name)
{
	DIR		*dir;
	t_dent	*dent;
	t_list	*head;
	t_list	*new;
	char	*file_name;

	if (!(dir = opendir(dir_name)))
	{
		error(dir_name);
		return (NULL);
	}
	if ((dent = readdir(dir)))
	{
		file_name = ultimate_join(3, dir_name, "/", dent->d_name);
		head = ft_lstnew(file_name, ft_strlen(file_name) + 1);
		free(file_name);
	}
	while ((dent = readdir(dir)))
	{
		file_name = ultimate_join(3, dir_name, "/", dent->d_name);
		new = ft_lstnew(file_name, ft_strlen(file_name) + 1);
		free(file_name);
		lst_add_end(head, new);
	}
	if (closedir(dir))
		error("Error closing directory.");
	return (head);
}

char	*parse_options(char **args, int *arg_start)
{
	char	*options;
	int		i;
	int		j;
	int		k;

	options = ft_strnew(ft_strlen(OPTIONS));
	i = 1;
	k = 0;
	while (args[i])
	{
		j = 1;
		if (args[i][0] != '-')
		{
			*arg_start = i;
			return (options);
		}
		while (args[i][j])
		{
			if (ft_strchr(OPTIONS, args[i][j]))
			{
				if (!ft_strchr(options, args[i][j]))
					options[k++] = args[i][j];
			}
			else
				error(ultimate_join(5, "ft_ls: illegal option -- ", ft_strsub(args[i], j, 1), "\nusage: ls [-", OPTIONS, "] [file ...]\n"));
			j++;
		}
		i++;
	}
	*arg_start = -1;
	return (options);
}

int		main(int argc, char **args)
{
	t_list	*list;
	char	*options;
	int		arg_start;

	options = parse_options(args, &arg_start);
	if (arg_start == -1)
	{
		list = extract_dir_entries(".");
		ft_lstiter(list, print_no_options);
	}
	else
		while (argc > arg_start)
		{
			list = extract_dir_entries(args[arg_start]);
			ft_lstiter(list, print_no_options);
			arg_start++;
		}
	//system("leaks a.out");
}