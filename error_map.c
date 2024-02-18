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
	
}

void	my_system_error(void)
{
	ft_printf("System error\n");
	exit(1);
}

int	my_check_argument(int argc, char *argv[])
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
