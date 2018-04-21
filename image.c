/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 20:16:44 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/07 20:16:46 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	getting_pic(t_map *map)
{
	t_var	tmp;

	tmp.x = 0;
	tmp.y = 0;
	while (tmp.x < map->rows)
	{
		while (tmp.y < map->colums)
		{
			if (tmp.x + 1 < map->rows)
				drawing_line(map, &map->dot[tmp.x][tmp.y],
					&map->dot[tmp.x + 1][tmp.y]);
			if (tmp.y + 1 < map->colums)
				drawing_line(map, &map->dot[tmp.x][tmp.y],
					&map->dot[tmp.x][tmp.y + 1]);
			tmp.y++;
		}
		tmp.y = 0;
		tmp.x++;
	}
	info(map);
}

void	drawing_line(t_map *map, t_pixel *p0, t_pixel *p1)
{
	double x;
	double y;

	x = p0->x;
	y = p0->y;
	if (fabs(p1->y - p0->y) > fabs(p1->x - p0->x))
	{
		while (p0->y > p1->y ? y >= p1->y : y <= p1->y)
		{
			x = ((y - p0->y) / (p1->y - p0->y) * (p1->x - p0->x) + p0->x);
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, p0->color);
			p1->y > p0->y ? y++ : y--;
		}
	}
	else
	{
		while (p0->x > p1->x ? x >= p1->x : x <= p1->x)
		{
			y = ((x - p0->x) / (p1->x - p0->x) * (p1->y - p0->y) + p0->y);
			mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, p0->color);
			p1->x > p0->x ? x++ : x--;
		}
	}
}
