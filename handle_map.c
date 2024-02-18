#include "so_long.h"

static int	my_check_argument(int argc, char *argv[])
{
	size_t	len;
	int		fd;

	if (argc != 2)
		my_message_error(1);
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(&argv[1][len - 4], ".ber", 5))
		my_message_error(2);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		my_message_error(3);
	return (fd);
}

static void	my_measure_mapsize(t_map *data)
{
	int	width;
	int	i;

	data->height = my_count_words(data->map) - 1;
	width = ft_strlen((data->map)[0]);
	i = 0;
	while (++i < data->height)
	{
		if ((int)ft_strlen((data->map)[i]) != width)
			my_message_error(5);
	}
	data->width = width;
}

void	my_handle_map(int argc, char *argv[], t_map *data)
{
	int		fd;

	fd = my_check_argument(argc, argv);
	data->map = my_input_map(fd);
	if (!(data->map)[0])
		my_message_error(4);
	my_measure_mapsize(data);
	my_error_map(data);
	
	close(fd);
}