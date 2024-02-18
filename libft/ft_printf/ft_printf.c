/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:47:23 by kmatsuka          #+#    #+#             */
/*   Updated: 2023/10/03 16:10:42 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	my_handle_format(const char format, va_list *ap, int *format_error);
static int	error_handle(int tmp, int format_error);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		tmp;
	int		format_error;

	len = 0;
	format_error = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tmp = my_handle_format(*format, &ap, &format_error);
			if (error_handle(tmp, format_error))
				return (-1);
			len += tmp;
		}
		else
			len += my_putchar_fd(*format, FD);
		format++;
	}
	va_end(ap);
	return (len);
}

static int	my_handle_format(const char format, va_list *ap, int *format_error)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = (int)my_putchar_fd(va_arg(*ap, int), FD);
	else if (format == 's')
		len = (int)my_putstr_fd(va_arg(*ap, char *), FD);
	else if (format == 'p')
		len = (int)my_format_p(va_arg(*ap, void *), FD);
	else if (format == 'd' || format == 'i')
		len = (int)my_putnbr_fd(va_arg(*ap, int), FD, 1);
	else if (format == 'u')
		len = (int)my_putnbr_u_fd(va_arg(*ap, unsigned int), FD, 1);
	else if (format == 'x')
		len = (int)my_format_x(va_arg(*ap, unsigned int), FD, 0);
	else if (format == 'X')
		len = (int)my_format_x(va_arg(*ap, unsigned int), FD, 1);
	else if (format == '%')
		len = (int)my_putchar_fd('%', FD);
	else
		*format_error = 1;
	return (len);
}

static int	error_handle(int tmp, int format_error)
{
	if (format_error)
	{
		write(1, "----format error----\n", 21);
		return (1);
	}
	if (tmp < 0)
	{
		write(1, "----error----\n", 14);
		return (-1);
	}
	return (0);
}
