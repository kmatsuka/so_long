#include "so_long.h"

void	my_message_error(int n)
{
	ft_printf("Error\n");
	if (n == 1)
		ft_printf("Wrong number of arguments\n");
	else if (n == 2)
		ft_printf("Invalid filename\n");
	else if (n == 3)
		ft_printf("Invalid filepath\n");
	else if (n == 4)
		ft_printf("Input is empty\n");
	else if (n == 5)
		ft_printf("Map isn't rectangle\n");
	else if (n == 6)
		ft_printf("Map's elements is wrong\n");
	else if (n == 7)
		ft_printf("Map isn't closed\n");
	
	exit(1);
}

void	my_system_error(void)
{
	ft_printf("System error\n");
	exit(1);
}