/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:09:36 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/13 12:21:32 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define FD 1
# include "../libft/libft.h"
# include <stdarg.h>

int			ft_printf(const char *format, ...);
ssize_t		my_putchar_fd(char c, int fd);
ssize_t		my_putstr_fd(char *s, int fd);
ssize_t		my_putnbr_fd(int n, int fd, ssize_t size);
ssize_t		my_putnbr_u_fd(unsigned int n, int fd, ssize_t size);
ssize_t		my_format_p(void *p, int fd);
ssize_t		my_format_x(unsigned int n, int fd, int uppercase);

#endif
