/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:19:05 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/02 20:19:06 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		counting_strs(char *av)
{
	int		fd;
	char	*res;
	size_t	str_count;

	str_count = 0;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &res) > 0)
	{
		str_count++;
		ft_strdel(&res);
	}
	close(fd);
	return (str_count);
}

size_t		counting_rows(char **ret_map)
{
	size_t	rows;

	rows = 0;
	while (ret_map[rows])
		rows++;
	return (rows);
}

size_t		counting_colums(char *str)
{
	char	**ret_str;
	size_t	colums;

	colums = 0;
	ret_str = ft_strsplit(str, ' ');
	while (ret_str[colums])
		colums++;
	free_pixel(ret_str);
	return (colums);
}
