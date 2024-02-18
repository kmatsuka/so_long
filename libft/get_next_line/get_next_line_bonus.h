/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:44:34 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/13 12:22:39 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*my_make_save(char *save, int fd);
void	my_split_save(char **save, char **line);

typedef struct s_list_g
{
	int				fd;
	char			*str;
	struct s_list_g	*next;
}	t_list_g;

#endif
