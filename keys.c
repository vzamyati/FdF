/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:51:43 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/17 15:28:38 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_scale(int kcode, t_map *map)
{
	static size_t count;

	if (kcode == K_PLUS)
	{
		scaling(map, 1.5);
		count++;
	}
	else if (kcode == K_MINUS && count > 0)
	{
		scaling(map, 0.5);
		count--;
	}
}

void	key_moving(int kcode, t_map *map)
{
	if (kcode == K_LEFT)
		moving_x(map, -20);
	if (kcode == K_RIGHT)
		moving_x(map, 20);
	if (kcode == K_DOWN)
		moving_y(map, 20);
	if (kcode == K_UP)
		moving_y(map, -20);
}

int		key_hook(int kcode, t_map *map)
{
	centring(map);
	if (kcode == K_ESC)
	{
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		exit(1);
	}
	if (kcode >= K_LEFT && kcode <= K_UP)
		key_moving(kcode, map);
	else if (kcode == K_PLUS || kcode == K_MINUS)
		key_scale(kcode, map);
	else if (kcode == K_RED)
		key_redcolor(map);
	else if (kcode == K_GREEN)
		key_greencolor(map);
	else if (kcode == K_BLUE)
		key_bluecolor(map);
	else if (kcode == K_PURPLE)
		key_purplecolor(map);
	else if (kcode == K_YELLOW)
		key_yellowcolor(map);
	rotating(map, kcode);
	free(map->centre);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	getting_pic(map);
	return (0);
}
