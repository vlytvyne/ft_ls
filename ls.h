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
# include "printf.h"
# include "libft.h"

# define OPTIONS "lRart1"

typedef struct		s_options
{
	unsigned int	l:1;
	unsigned int	big_r:1;
	unsigned int	a:1;
	unsigned int	r:1;
	unsigned int	t:1;
}					t_opts;

typedef struct dirent t_dent;
typedef struct stat t_stat;

#endif
