/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_format_px.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:33:47 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/10/03 15:37:03 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*my_radix_conversion(unsigned long n, int base, int uppercase);
static size_t	my_measure_size(char **s, unsigned long n, int base);

ssize_t	my_format_p(void *p, int fd)
{
	unsigned long	adr;
	ssize_t			size;
	char			*s;

	size = 0;
	if (p == NULL)
		size = write(fd, "0x0", 3);
	else
	{
		adr = (unsigned long)p;
		size += write(fd, "0x", 2);
		s = my_radix_conversion(adr, 16, 0);
		size += my_putstr_fd(s, fd);
		free(s);
	}
	return (size);
}

ssize_t	my_format_x(unsigned int n, int fd, int uppercase)
{
	ssize_t	size;
	char	*s;

	s = my_radix_conversion((unsigned long)n, 16, uppercase);
	size = my_putstr_fd(s, fd);
	free(s);
	return (size);
}

static char	*my_radix_conversion(unsigned long n, int base, int uppercase)
{
	char	*s;
	char	c;
	size_t	size;
	size_t	ind;

	size = my_measure_size(&s, n, base);
	if (size == 0)
		return (NULL);
	c = 'a' + ('A' - 'a') * uppercase;
	if (n % base > 9)
		s[size - 1] = c + (n % base - 10);
	else
		s[size - 1] = '0' + n % base;
	n /= base;
	ind = 2;
	while (n)
	{
		if (n % base > 9)
			s[size - ind] = c + (n % base - 10);
		else
			s[size - ind] = '0' + n % base;
		n /= base;
		ind++;
	}
	return (s);
}

static size_t	my_measure_size(char **s, unsigned long n, int base)
{
	size_t	size;

	size = 1;
	while (n / base)
	{
		n /= base;
		size++;
	}
	*s = (char *)calloc(size + 1, sizeof(char));
	if (*s == NULL)
		return (0);
	return (size);
}
