/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:32:40 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/12 15:52:01 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*my_make_save(char *save, int fd)
{
	char	*buf;
	char	*tmp;
	ssize_t	len_read;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	len_read = 0;
	while (!len_read)
	{
		len_read = read(fd, buf, BUFFER_SIZE);
		if (len_read <= 0)
			break ;
		buf[len_read] = '\0';
		tmp = save;
		save = ft_strjoin(save, buf);
		free(tmp);
		while ((!save && len_read > -1)
			|| (len_read > 0 && buf[len_read - 1] != '\n'))
			len_read--;
	}
	free(buf);
	if (len_read == -1)
		return (NULL);
	return (save);
}

void	my_split_save(char **save, char **line)
{
	size_t	len_save;
	size_t	len_line;
	char	*tmp;

	len_save = 0;
	while (*save && (*save)[len_save])
		len_save++;
	len_line = 0;
	while (len_line < len_save)
	{
		if ((*save)[len_line++] == '\n')
			break ;
	}
	tmp = *save;
	*line = ft_substr(*save, 0, len_line);
	if (*line)
		*save = ft_substr(*save, len_line, len_save - len_line);
	free(tmp);
}
