#include "so_long.h"

static void	my_check_char(char c, t_count_elems *count)
{
	if (c == '0' || c == '1')
		;
	else if (c == 'P')
		(count->p)++;
	else if (c == 'E')
		(count->e)++;
	else if (c == 'C')
		(count->c)++;
	else
		(count->invalid)++;;
}

static void	my_check_elems(t_map *data)
{
	t_count_elems	count;
	int				i;
	int				j;

	count.p = 0;
	count.e = 0;
	count.c = 0;
	count.invalid = 0;
	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
			my_check_char((data->map)[i][j], &count);
	}
	if (count.p != 1 || count.e != 1 || count.c < 1 || count.invalid > 0)
		my_message_error(6);
}

static void	my_checkif_close(t_map *data)
{
	int	i;

	i = -1;
	while (++i < data->width)
	{
		if ((data->map)[0][i] != '1' || (data->map)[data->height - 1][i] != '1')
			my_message_error(7);
	}
	i = 0;
	while (++i < data->height - 1)
	{
		if ((data->map)[i][0] != '1' || (data->map)[i][data->width - 1] != '1')
			my_message_error(7);
	}
}


void	my_error_map(t_map *data)
{
	my_check_elems(data);
	my_checkif_close(data);
}