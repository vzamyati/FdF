/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 19:27:40 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/07 19:27:42 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	centring(t_map *map)
{
	map->centre = (t_pixel *)malloc(sizeof(t_pixel));
	map->centre->x = (map->dot[map->rows - 1][map->colums - 1].x +
		map->dot[0][0].x) / 2;
	map->centre->y = (map->dot[map->rows - 1][map->colums - 1].y +
		map->dot[0][0].y) / 2;
}

void	moving_centre(t_map *map)
{
	t_var	tmp;

	tmp.y = (HEIGHT) / 2 - map->centre->y;
	tmp.x = (WIDTH) / 2 - map->centre->x;
	moving_y(map, tmp.y);
	moving_x(map, tmp.x);
}

void	moving_y(t_map *map, int down)
{
	t_var	tmp;

	tmp.x = 0;
	while (tmp.x < map->rows)
	{
		tmp.y = 0;
		while (tmp.y < map->colums)
		{
			map->dot[tmp.x][tmp.y].y = map->dot[tmp.x][tmp.y].y + down;
			tmp.y++;
		}
		tmp.x++;
	}
}

void	moving_x(t_map *map, int right)
{
	t_var	tmp;

	tmp.x = 0;
	while (tmp.x < map->rows)
	{
		tmp.y = 0;
		while (tmp.y < map->colums)
		{
			map->dot[tmp.x][tmp.y].x = map->dot[tmp.x][tmp.y].x + right;
			tmp.y++;
		}
		tmp.x++;
	}
}

void	scaling(t_map *map, double scale)
{
	t_var	tmp;

	tmp.x = 0;
	while (tmp.x < map->rows)
	{
		tmp.y = 0;
		while (tmp.y < map->colums)
		{
			map->dot[tmp.x][tmp.y].x = (map->dot[tmp.x][tmp.y].x -
				map->centre->x) * scale + map->centre->x;
			map->dot[tmp.x][tmp.y].y = (map->dot[tmp.x][tmp.y].y -
				map->centre->y) * scale + map->centre->y;
			map->dot[tmp.x][tmp.y].z = map->dot[tmp.x][tmp.y].z * scale;
			tmp.y++;
		}
		tmp.x++;
	}
}
