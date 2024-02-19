#include "so_long.h"

static void	check_char(t_map *map, int i, int j)
{
	char	c;

	c = (map->data)[i][j];
	if (c == '0')
		(map->empty)++;
	else if (c == '1')
		(map->wall)++;
	else if (c == 'P')
	{
		(map->player)++;
		map->pos_i = i;
		map->pos_j = j;
	}
	else if (c == 'E')
		(map->goal)++;
	else if (c == 'C')
		(map->collection)++;
	else
		(map->inv_char)++;;
}

void	message_error(int n)
{
	ft_printf("Error\n");
	if (n == 1)
		ft_printf("Wrong num of args\n");
	else if (n == 2)
		ft_printf("Wrong filename\n");
	else if (n == 3)
		ft_printf("Wrong filepath\n");
	else if (n == 4)
		ft_printf("Empty input\n");
	else if (n == 5)
		ft_printf("Not rectangle\n");
	else if (n == 6)
		ft_printf("Wrong elements\n");
	else if (n == 7)
		ft_printf("Not closed\n");
	else if (n == 8)
		ft_printf("Can't clear\n");
	exit(1);
}

void	check_elems(t_map *map)
{
	int				i;
	int				j;

	map->player = 0;
	map->goal = 0;
	map->collection = 0;
	map->inv_char = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			check_char(map, i, j);
	}
	if (map->player != 1 || map->goal != 1 || map->collection < 1 || map->inv_char > 0)
		message_error(6);
}

void	checkif_close(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
	{
		if ((map->data)[0][i] != '1' || (map->data)[map->height - 1][i] != '1')
			message_error(7);
	}
	i = 0;
	while (++i < map->height - 1)
	{
		if ((map->data)[i][0] != '1' || (map->data)[i][map->width - 1] != '1')
			message_error(7);
	}
}