/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:59:07 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/18 17:15:38 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	//void	*mlx;
	//void	*mlx_win;
	t_map	*data;

	data = malloc(sizeof(t_map));
	if (!data)
		my_system_error();
	my_handle_map(argc, argv, data);
	
	int	i = -1;
	while ((data->map)[++i])
		ft_printf("%s\n", (data->map)[i]);


	// //initialize mlx
	// mlx = mlx_init();
	// if (!mlx)
	// 	exit(1);

	// //mlx_new_window(mlxpointer, width, height, title)
	// mlx_win = mlx_new_window(mlx, 1600, 900, "game");
	// if (!mlx_win)
	// 	exit(1);


	// mlx_loop(mlx);
	
	
	return (0);
}
