#include "so_long.h"

static int	check_argument(int argc, char *argv[])
{
	size_t	len;
	int		fd;

	if (argc != 2)
		message_error(1);
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(&argv[1][len - 4], ".ber", 5))
		message_error(2);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		message_error(3);
	return (fd);
}

static void	measure_mapsize(t_map *map)
{
	int	width;
	int	i;

	map->height = count_words(map->data) - 1;
	width = ft_strlen((map->data)[0]);
	i = 0;
	while (++i < map->height)
	{
		if ((int)ft_strlen((map->data)[i]) != width)
			message_error(5);
	}
	map->width = width;
}

void	handle_map(int argc, char *argv[], t_map *map)
{
	int		fd;

	fd = check_argument(argc, argv);
	map->data = input_map(fd);
	if (!(map->data)[0])
		message_error(4);
	measure_mapsize(map);
	check_elems(map);
	checkif_close(map);
	
	close(fd);
}