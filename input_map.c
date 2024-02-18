/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:10:07 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/18 14:50:11 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	my_count_words(char **strs)
{
	int	count;

	count = 0;
	while (strs[count++])
		;
	return (count);
}

static char	**my_add_strarray(char **strs, char *str)
{
	char	**new;
	int		count;
	int		i;

	count = my_count_words(strs);
	new = malloc(sizeof(char *) * (count + 1));
	if (!new)
		my_system_error();
	i = -1;
	while (++i < count - 1)
	{
		new[i] = ft_strdup(strs[i]);
		free(strs[i]);
	}
	new[i] = ft_strdup(str);
	new[count] = NULL;
	free(strs);
	return (new);
}

static void	my_delete_nl(char *str)
{
	int	ind;
	
	ind = 0;
	while (str[ind])
		ind++;
	if (ind > 0 && str[--ind] == '\n')
		str[ind] = '\0';
}

static char	**my_input_map(int fd)
{
	char	**map;
	char	*str;

	map = malloc(sizeof(char *) * 1);
	if (!map)
		my_system_error();
	map[0] = NULL;
	str = get_next_line(fd);
	while (str)
	{
		my_delete_nl(str);
		map = my_add_strarray(map, str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (map);
}

char	**my_handle_map(int argc, char *argv[])
{
	char	**map;
	int		fd;

	fd = my_check_argument(argc, argv);
	map = my_input_map(fd);
	
	close(fd);
	return (map);
}