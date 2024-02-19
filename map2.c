/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuka <kmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:10:07 by kmatsuka          #+#    #+#             */
/*   Updated: 2024/02/19 14:02:10 by kmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**add_strarray(char **strs, char *str)
{
	char	**new;
	int		count;
	int		i;

	count = count_words(strs);
	new = malloc(sizeof(char *) * (count + 1));
	if (!new)
		exit(1);
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

static void	delete_nl(char *str)
{
	int	ind;
	
	ind = 0;
	while (str[ind])
		ind++;
	if (ind > 0 && str[--ind] == '\n')
		str[ind] = '\0';
}

int	count_words(char **strs)
{
	int	count;

	count = 0;
	while (strs[count++])
		;
	return (count);
}

char	**input_map(int fd)
{
	char	**map;
	char	*str;

	map = malloc(sizeof(char *));
	if (!map)
		exit(1);
	map[0] = NULL;
	str = get_next_line(fd);
	while (str)
	{
		delete_nl(str);
		map = add_strarray(map, str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (map);
}