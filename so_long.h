/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:58:58 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/18 14:30:36 by kmatsuka         ###   ########.fr       */
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

char	**my_handle_map(int argc, char *argv[]);

int		my_check_argument(int argc, char *argv[]);
void	my_system_error(void);
void	my_message_error(int n);


#endif