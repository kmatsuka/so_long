/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:58:58 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/19 17:31:41 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_mms_20200219/mlx.h"
# include "libft/libft/libft.h"
# include "libft/ft_printf/printf.h"
# include "libft/get_next_line/get_next_line_bonus.h"

# include <fcntl.h>

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_map
{
	char	**data;
	int		width;
	int		height;
	int		player;
	int		goal;
	int		collection;
	int		wall;
	int		empty;
	int		inv_char;
	int		pos_i;
	int		pos_j;
}	t_map;

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
}	t_img;


//map1
void	handle_map(int argc, char *argv[], t_map *map);

//map2
int		count_words(char **strs);
char	**input_map(int fd);

//error1
void	message_error(int n);
void	check_elems(t_map *map);
void	checkif_close(t_map *map);

//img
void	set_img(t_mlx *mlx, t_img *img);
void	render_map(t_mlx *mlx, t_map *map, t_img *img);

//keyhook
int	key_press(int keycode, void *map);

#endif