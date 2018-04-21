/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:00:45 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/09 17:00:46 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel		rotating_y(t_pixel *pixel, t_pixel *centre, int ang)
{
	t_pixel	tmp;
	double	angle;

	pixel->x = pixel->x - centre->x;
	pixel->y = pixel->y - centre->y;
	angle = ang * PI / 180;
	tmp.x = pixel->x;
	tmp.y = pixel->y * cos(angle) + pixel->z * sin(angle);
	tmp.z = (-(pixel->y) * sin(angle)) + pixel->z * cos(angle);
	tmp.color = pixel->color;
	tmp.x = tmp.x + centre->x;
	tmp.y = tmp.y + centre->y;
	return (tmp);
}

t_pixel		rotating_x(t_pixel *pixel, t_pixel *centre, int ang)
{
	t_pixel	tmp;
	double	angle;

	pixel->x = pixel->x - centre->x;
	pixel->y = pixel->y - centre->y;
	angle = ang * PI / 180;
	tmp.x = pixel->x * cos(angle) + pixel->z * sin(angle);
	tmp.y = pixel->y;
	tmp.z = -(pixel->x) * sin(angle) + pixel->z * cos(angle);
	tmp.color = pixel->color;
	tmp.x = tmp.x + centre->x;
	tmp.y = tmp.y + centre->y;
	return (tmp);
}

t_pixel		rotating_z(t_pixel *pixel, t_pixel *centre, int ang)
{
	t_pixel	tmp;
	double	angle;

	pixel->x = pixel->x - centre->x;
	pixel->y = pixel->y - centre->y;
	angle = ang * PI / 180;
	tmp.x = pixel->x * cos(angle) - pixel->y * sin(angle);
	tmp.y = pixel->x * sin(angle) + pixel->y * cos(angle);
	tmp.z = pixel->z;
	tmp.color = pixel->color;
	tmp.x = tmp.x + centre->x;
	tmp.y = tmp.y + centre->y;
	return (tmp);
}

void		rotating(t_map *map, int kcode)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->colums)
		{
			if (kcode == K_A)
				map->dot[i][j] = rotating_x(&map->dot[i][j], map->centre, -10);
			else if (kcode == K_D)
				map->dot[i][j] = rotating_x(&map->dot[i][j], map->centre, 10);
			else if (kcode == K_W)
				map->dot[i][j] = rotating_y(&map->dot[i][j], map->centre, -10);
			else if (kcode == K_S)
				map->dot[i][j] = rotating_y(&map->dot[i][j], map->centre, 10);
			else if (kcode == K_Q)
				map->dot[i][j] = rotating_z(&map->dot[i][j], map->centre, 10);
			else if (kcode == K_E)
				map->dot[i][j] = rotating_z(&map->dot[i][j], map->centre, -10);
			j++;
		}
		i++;
	}
}
