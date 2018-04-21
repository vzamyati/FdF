/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:59:41 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/06 17:59:42 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_pixel(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void		making_pixel(t_pixel *pixel, char *str, int colum, int row)
{
	pixel->x = row * 25;
	pixel->y = colum * 25;
	pixel->z = ft_atoi(str);
	if (!(ft_strchr(str, ',')))
		pixel->color = 0xC1BFB9;
	else
		pixel->color = ft_atol_base(ft_strchr(str, ',') + 1, 16);
}

t_map		*list_map(size_t rows, size_t colums)
{
	t_map	*map;
	size_t	i;

	i = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->rows = rows;
	map->colums = colums;
	map->dot = (t_pixel **)malloc(sizeof(t_pixel *) * (rows + 1));
	while (i < rows)
	{
		map->dot[i] = (t_pixel *)malloc(sizeof(t_pixel) * colums);
		i++;
	}
	map->dot[i] = NULL;
	return (map);
}

t_map		*creating_map(char **ret_map, size_t rows, size_t colums)
{
	t_map	*map;
	char	**pixel;
	t_var	tmp;

	tmp.x = 0;
	map = list_map(rows, colums);
	while (tmp.x < rows)
	{
		tmp.y = 0;
		pixel = ft_strsplit(ret_map[tmp.x], ' ');
		while (tmp.y < colums)
		{
			making_pixel(&map->dot[tmp.x][tmp.y], pixel[tmp.y], tmp.x, tmp.y);
			tmp.y++;
		}
		free_pixel(pixel);
		tmp.x++;
	}
	free_pixel(ret_map);
	return (map);
}
