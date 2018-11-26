/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:41:43 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/21 17:50:53 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <unistd.h>
# include "printf.h"
# include "libft.h"

# define OPTIONS "lRart1"
# define HALF_YEAR 2592000

typedef struct dirent t_dent;
typedef struct stat t_stat;

void		sorter(t_list **list, char *options);
void		error(const char *msg);
char		*get_file_name(t_list *lst);
void		printer(t_list *lst, char *options);
char		*form_mode_line(t_list *lst, int mode);
char		*form_time_line(t_stat fstat);
void		print_custom_input(t_list *entries, char *options);
t_list		*get_directories(t_list *entries, char *options);
void		print_dir_entries(char *dirname, char *options);
void		del(void *content, size_t size);

#endif
