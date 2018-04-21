/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:52:07 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/09 16:52:08 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	info(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 10, 0xE6B0AA,
		"Arrows = MOVE");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 30, 0xD7BDE2,
		"+ - = ZOOM");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 50, 0xA9CCE3,
		"Rotate X = A or D");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 70, 0xA9DFBF,
		"Rotate Y = W or S");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 90, 0xF9E79F,
		"Rotate Z = Q or E");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 110, 0xC0392B,
		"Red picture = R");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 130, 0x27AE60,
		"Green picture = G");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 150, 0x2471A3,
		"Blue picture = B");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 170, 0x9B59B6,
		"Purple picture = P");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 190, 0xF1C40F,
		"Yellow picture =  Y");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 210, 0xFF0000,
		"Exit = Esc");
}
