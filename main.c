/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:15:51 by vzamyati          #+#    #+#             */
/*   Updated: 2018/03/17 17:15:52 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		**reading_map(char *av)
{
	char	**ret_map;
	char	*res;
	int		fd;
	size_t	i;
	size_t	str_count;

	i = 0;
	str_count = counting_strs(av);
	if ((fd = open(av, O_RDONLY)) == -1 || read(fd, &res, 0) == -1)
	{
		perror("Error");
		exit(1);
	}
	ret_map = (char **)malloc(sizeof(char*) * (str_count + 1));
	while (get_next_line(fd, &res) > 0)
	{
		ret_map[i] = ft_strdup(res);
		i++;
		free(res);
	}
	ret_map[i] = NULL;
	close(fd);
	validating_map(ret_map);
	return (ret_map);
}

void		next_step(char **av)
{
	char	**ret_map;
	size_t	colums;
	size_t	rows;
	t_map	*map;

	ret_map = reading_map(av[1]);
	colums = counting_colums(ret_map[0]);
	rows = counting_rows(ret_map);
	map = creating_map(ret_map, rows, colums);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "fdf by vz");
	centring(map);
	moving_centre(map);
	free(map->centre);
	getting_pic(map);
	mlx_hook(map->win_ptr, 2, 5, key_hook, map);
	mlx_loop(map->mlx_ptr);
}

int			main(int ac, char **av)
{
	if (ac == 2)
		next_step(av);
	else
	{
		ft_putstr("Usage: ./fdf map.fdf\n");
		exit(1);
	}
	return (0);
}
