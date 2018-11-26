/*                                                                            */
/* ************************************************************************** */
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

static t_list	*extract_dir_entries(const char *dir_name)
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

static void		print_total(t_list *entries, char *options)
{
	int		total;
	t_stat	fstat;
	int		count_hiden;

	total = 0;
	count_hiden = ft_strchr(options, 'a') ? 1 : 0;
	while (entries)
	{
		if (*get_file_name(entries) != '.' ||
			count_hiden)
			if (lstat((char*)entries->content, &fstat) != -1)
				total += fstat.st_blocks;
		entries = entries->next;
	}
	ft_printf("total %d\n", total);
}

void		print_dir_entries(char *dirname, char *options)
{
	t_list		*entries;
	t_list		*dirs;
	static int	first_call = 1;

	if (!first_call)
		ft_printf("\n%s:\n", dirname);
	first_call = 0;
	if ((entries = extract_dir_entries(dirname)))
	{
		if (ft_strchr(options, 'l'))
			print_total(entries, options);
		sorter(&entries, options);
		printer(entries, options);
	}
	if (ft_strchr(options, 'R'))
	{
		dirs = get_directories(entries, options);
		while (dirs)
		{
			print_dir_entries((char*)dirs->content, options);
			dirs = dirs->next;
		}
	}
}

static char		*parse_options(char **args, int *arg_start)
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

int				main(int argc, char **args)
{
	char	*options;
	int		arg_start;
	t_list	*entries;

	options = parse_options(args, &arg_start);
	if (arg_start == -1)
		print_dir_entries(".", options);
	else
	{
		while (argc > arg_start)
		{
			if (entries == NULL)
				entries = ft_lstnew(args[arg_start], ft_strlen(args[arg_start]) + 1);
			else
				lst_add_end(entries, ft_lstnew(args[arg_start], ft_strlen(args[arg_start]) + 1));
			arg_start++;
		}
		sorter(&entries, options);
		print_custom_input(entries, options);
	}
	//system("leaks ft_ls");
}