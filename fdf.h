/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 17:20:44 by vzamyati          #+#    #+#             */
/*   Updated: 2018/03/17 17:20:46 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define PI 		3.14159265359
# define HEIGHT		1200
# define WIDTH 		1200
# define K_LEFT		123
# define K_RIGHT	124
# define K_DOWN		125
# define K_UP		126
# define K_ESC		53
# define K_PLUS		69
# define K_MINUS	78
# define K_W 		13
# define K_S 		1
# define K_A		0
# define K_D 		2
# define K_Q 		12
# define K_E 		14
# define K_RED 		15
# define K_GREEN 	5
# define K_BLUE 	11
# define K_PURPLE 	35
# define K_YELLOW 	16

typedef struct		s_var
{
	size_t			x;
	size_t			y;
}					t_var;

typedef struct		s_pixel
{
	double			x;
	double			y;
	double			z;
	long int		color;
}					t_pixel;

typedef	struct		s_map
{
	size_t			rows;
	size_t			colums;
	t_pixel			**dot;
	t_pixel			*centre;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image;
}					t_map;

char				**reading_map(char *av);
size_t				counting_strs(char *av);
size_t				counting_rows(char **av);
size_t				counting_colums(char *str);
int					validating_mapsize(char **ret_map);
int					key_hook(int	keycode, t_map *map);
void				key_redcolor(t_map *map);
void				key_greencolor(t_map *map);
void				key_bluecolor(t_map *map);
void				key_purplecolor(t_map *map);
void				key_yellowcolor(t_map *map);
void				next_step(char **av);
void				key_moving(int	kcode, t_map *map);
void				key_scale(int kcode, t_map *map);
void				drawing_line(t_map *map, t_pixel *p0, t_pixel *p1);
void				getting_pic(t_map *map);
void				centring(t_map *map);
void				scaling(t_map *map, double scale);
void				moving_centre(t_map *map);
void				moving_y(t_map *map, int down);
void				moving_x(t_map *map, int right);
void				validating_map(char **ret_map);
void				making_pixel(t_pixel *pixel, char *str, int row, int colum);
void				info(t_map *map);
void				free_pixel(char **str);
void				rotating(t_map *map, int kcode);
t_pixel				rotating_x(t_pixel *pixel, t_pixel *centre, int ang);
t_pixel				rotating_y(t_pixel *pixel, t_pixel *centre, int ang);
t_pixel				rotating_z(t_pixel *pixel, t_pixel *centre, int ang);
t_map				*creating_map(char	**ret_map, size_t rows, size_t colums);
t_map				*list_map(size_t rows, size_t colums);
t_map				*creating_map(char	**ret_map, size_t rows, size_t colums);

#endif
