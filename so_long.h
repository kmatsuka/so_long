/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:58:58 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/18 16:25:57 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx_mms_20200219/mlx.h"
#include "libft/libft/libft.h"
#include "libft/ft_printf/printf.h"
#include "libft/get_next_line/get_next_line_bonus.h"

#include <fcntl.h>

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_count_elems
{
	int	p;
	int	e;
	int	c;
	int	invalid;
}	t_count_elems;

//handle_map
void	my_handle_map(int argc, char *argv[], t_map *data);

//input_map
int		my_count_words(char **strs);
char	**my_input_map(int fd);

//message_error
void	my_message_error(int n);
void	my_system_error(void);

//error_map
void	my_error_map(t_map *data);

#endif