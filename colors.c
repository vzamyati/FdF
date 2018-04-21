/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:29:18 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/11 19:29:19 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_redcolor(t_map *map)
{
	t_var	tmp;

	tmp.x = 0;
	while (tmp.x < map->rows)
	{
		tmp.y = 0;
		while (tmp.y < map->colums)
		{
			map->dot[tmp.x][tmp.y].color = 0xC0392B;
			tmp.y++;
		}
		tmp.x++;
	}
}

void	key_greencolor(t_map *map)
{
	t_var	tmp;

	tmp.x = 0;
	while (tmp.x < map->rows)
	{
		tmp.y = 0;
		while (tmp.y < map->colums)
		{
			map->dot[tmp.x][tmp.y].color = 0x27AE60;
			tmp.y++;
		}
		tmp.x++;
	}
}

void	key_bluecolor(t_map *map)
{
	t_var	tmp;

	tmp.x = 0;
	while (tmp.x < map->rows)
	{
		tmp.y = 0;
		while (tmp.y < map->colums)
		{
			map->dot[tmp.x][tmp.y].color = 0x2980B9;
			tmp.y++;
		}
		tmp.x++;
	}
}

void	key_purplecolor(t_map *map)
{
	t_var	tmp;

	tmp.x = 0;
	while (tmp.x < map->rows)
	{
		tmp.y = 0;
		while (tmp.y < map->colums)
		{
			map->dot[tmp.x][tmp.y].color = 0x9B59B6;
			tmp.y++;
		}
		tmp.x++;
	}
}

void	key_yellowcolor(t_map *map)
{
	t_var	tmp;

	tmp.x = 0;
	while (tmp.x < map->rows)
	{
		tmp.y = 0;
		while (tmp.y < map->colums)
		{
			map->dot[tmp.x][tmp.y].color = 0xF1C40F;
			tmp.y++;
		}
		tmp.x++;
	}
}
