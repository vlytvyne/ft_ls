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

void	print_short(t_list *lst)
{
	t_stat	fstat;
	char	*file_name;
	int		mode;

	file_name = ft_strchr((char*)lst->content, '/') ? ft_strrchr((char*)lst->content, '/') + 1 : (char*)lst->content;
	stat((char*)lst->content, &fstat);
	mode = fstat.st_mode;
	if (*file_name != '.')
		ft_printf("%s\n", file_name);
		//ft_printf("%s -- %.7o\n", file_name, fstat.st_mode);
}

void	print_short_with_a(t_list *lst)
{
	t_stat	fstat;
	char	*file_name;
	int		mode;

	file_name = ft_strchr((char*)lst->content, '/') ? ft_strrchr((char*)lst->content, '/') + 1 : (char*)lst->content;
	stat((char*)lst->content, &fstat);
	mode = fstat.st_mode;
	ft_printf("%s\n", file_name);
		//ft_printf("%s -- %.7o\n", file_name, fstat.st_mode);
}

void	printer(t_list *lst, char *options)
{
	if (ft_strchr(options, 'a'))
		ft_lstiter(lst, print_short_with_a);
	else
		ft_lstiter(lst, print_short);
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

t_list	*extract_dir_entries(const char *dir_name, int is_custom)
{
	DIR		*dir;
	t_dent	*dent;
	t_list	*head;
	char	*file_name;

	head = NULL;
	if (!(dir = opendir(dir_name)))
	{
		if (!is_custom)
			error(dir_name);
		return (NULL);
	}
	while ((dent = readdir(dir)))
	{
		file_name = ultimate_join(3, dir_name, "/", dent->d_name);
		if (head == NULL)
			head = ft_lstnew(file_name, ft_strlen(file_name) + 1);
		else
			lst_add_end(head, ft_lstnew(file_name, ft_strlen(file_name) + 1));
		free(file_name);
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

int		is_dir_due(t_list *entry, char *options)
{
	char	*dirname;

	dirname = ft_strchr((char*)entry->content, '/') ? ft_strrchr((char*)entry->content, '/') + 1 : (char*)entry->content;
	if (ft_strchr(options, 'a'))
	{
		if (ft_strequ(dirname, ".") || ft_strequ(dirname, ".."))
			return (0);
		else
			return (1);
	}
	else
		return (*dirname != '.');
	return (0);
}

t_list	*get_directories(t_list *entries, char *options)
{
	t_list	*dirs;
	t_stat	fstat;

	dirs = NULL;
	while (entries)
	{
		lstat((char*)entries->content, &fstat);
		if (fstat.st_mode & S_IFDIR && is_dir_due(entries, options))
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

t_list	*get_directories_custom(t_list *entries)
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

int		cmp_time(t_list *first, t_list *second)
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

void	sorter(t_list **list, char *options)
{
	t_stat	fstat;

	if (ft_strchr(options, 't'))
		sort_list(*list, cmp_time);
	else
		sort_list_ascii(*list);
	if (ft_strchr(options, 'r'))
		reverse_list(list);
}

void	print_dir_entries(char *dirname, char *options, int is_custom)
{
	t_list		*entries;
	t_list		*dirs;
	static int	first_call = 1;

	if (!first_call)
		ft_printf("\n%s:\n", dirname);
	first_call = 0;
	if ((entries = extract_dir_entries(dirname, is_custom)))
	{
		sorter(&entries, options);
		printer(entries, options);
	}
	if (ft_strchr(options, 'R'))
	{
		dirs = get_directories(entries, options);
		while (dirs)
		{
			print_dir_entries((char*)dirs->content, options, is_custom);
			dirs = dirs->next;
		}
	}
}

int		print_files(t_list *entries, char *options)
{
	t_list	*files;
	t_stat	fstat;
	int		ret;

	ret = 0;
	files = NULL;
	while (entries)
	{
		if (stat((char*)entries->content, &fstat) == -1)
		{
			error((char*)entries->content);
			ret = 1;
		}
		else
			if (!(fstat.st_mode & S_IFDIR))
			{
				if (files == NULL)
					files = ft_lstnew(entries->content, ft_strlen((char*)entries->content) + 1);
				else
					lst_add_end(files, ft_lstnew(entries->content, ft_strlen((char*)entries->content) + 1));
			}
		entries = entries->next;
	}
	sorter(&files, options);
	ft_lstiter(files, print_short_with_a);
	if (files != NULL)
		ret = 1;
	return (ret);
}

void	print_custom_input(t_list *entries, char *options)
{
	t_list *dirs;
	int files_were_printed;

	files_were_printed = print_files(entries, options);

	dirs = get_directories_custom(entries);
	sorter(&dirs, options);
	if (files_were_printed)
		ft_printf("\n%s:\n", (char*)dirs->content);
	else if (dirs && dirs->next)
		ft_printf("%s:\n", (char*)dirs->content);
	while (dirs)
	{
		print_dir_entries((char*)dirs->content, options, 1);
		dirs = dirs->next;
	}
}

int		main(int argc, char **args)
{
	char	*options;
	int		arg_start;
	t_list	*entries;

	options = parse_options(args, &arg_start);
	entries = NULL;
	if (arg_start == -1)
	{
		print_dir_entries(".", options, 0);
	}
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
		print_custom_input(entries, options);
	}
	//system("leaks ft_ls");
}