#include "so_long.h"

int	key_press(int keycode, void *map)
{
	(void)map;
	ft_printf("key is %d\n", keycode);
	return (0);
}