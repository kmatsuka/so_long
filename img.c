#include "so_long.h"

void	set_img(t_mlx *mlx, t_img *img)
{
	img[0].ptr = mlx_xpm_file_to_image(mlx->ptr, "./textures/player.xpm", &img[0].width, &img[0].height);
	img[1].ptr = mlx_xpm_file_to_image(mlx->ptr, "./textures/exit.xpm", &img[1].width, &img[1].height);
	img[2].ptr = mlx_xpm_file_to_image(mlx->ptr, "./textures/exit_fin.xpm", &img[2].width, &img[2].height);
	img[3].ptr = mlx_xpm_file_to_image(mlx->ptr, "./textures/collection.xpm", &img[3].width, &img[3].height);
	img[4].ptr = mlx_xpm_file_to_image(mlx->ptr, "./textures/empty.xpm", &img[4].width, &img[4].height);
	img[5].ptr = mlx_xpm_file_to_image(mlx->ptr, "./textures/wall.xpm", &img[5].width, &img[5].height);
}

void	render_map(t_mlx *mlx, t_map *map, t_img *img)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (++i < map->width)
	{
		j = -1;
		while (++j < map->height)
		{
			c = (map->data)[j][i];
			if (c == 'P')
				mlx_put_image_to_window(mlx->ptr, mlx->win, img[0].ptr, i * 64, j * 64);
			else if (c == 'E')
				mlx_put_image_to_window(mlx->ptr, mlx->win, img[1].ptr, i * 64, j * 64);
			else if (c == 'C')
				mlx_put_image_to_window(mlx->ptr, mlx->win, img[3].ptr, i * 64, j * 64);
			else if (c == '0')
				mlx_put_image_to_window(mlx->ptr, mlx->win, img[4].ptr, i * 64, j * 64);
			else if (c == '1')
				mlx_put_image_to_window(mlx->ptr, mlx->win, img[5].ptr, i * 64, j * 64);
		}
	}
}