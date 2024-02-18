/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_format_csdiu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:44:19 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/10/03 13:21:16 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*c*/
ssize_t	my_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/*s*/
ssize_t	my_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		s = "(null)";
	return (write(fd, s, ft_strlen(s)));
}

/*di, size = 1*/
ssize_t	my_putnbr_fd(int n, int fd, ssize_t size)
{
	char	c;

	if (n == INT_MIN)
		size = write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			size += write(fd, "-", 1);
		}
		if (n > 9)
			size = my_putnbr_fd(n / 10, fd, size + 1);
		c = '0' + n % 10;
		write(fd, &c, 1);
	}
	return (size);
}

/*u, size = 1*/
ssize_t	my_putnbr_u_fd(unsigned int n, int fd, ssize_t size)
{
	char	c;

	if (n > 9)
		size = my_putnbr_u_fd(n / 10, fd, size + 1);
	c = '0' + n % 10;
	write(fd, &c, 1);
	return (size);
}
