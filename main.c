/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:59:07 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/19 17:25:14 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;
	t_map	*map;
	t_img	*img;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(1);
	handle_map(argc, argv, map);

	// int	i=-1;
	// while ((map->data)[++i])
	// 	ft_printf("%s\n", (map->data)[i]);

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		exit(1);
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		exit(1);
	mlx->win = mlx_new_window(mlx->ptr, 1600, 900, argv[0]);
	if (!mlx->win)
	 	exit(1);

	img = malloc(sizeof(t_img) * 6);
	if (!img)
		exit(1);
	set_img(mlx, img);
	render_map(mlx, map, img);

	mlx_hook(mlx->win, 2, 0, &key_press, map);
	

	mlx_loop(mlx->ptr);
	
	
	return (0);
}
