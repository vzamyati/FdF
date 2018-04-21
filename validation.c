/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:13:26 by vzamyati          #+#    #+#             */
/*   Updated: 2018/04/02 20:13:28 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			validating_mapsize(char **ret_map)
{
	size_t vars[3];

	vars[0] = 0;
	vars[1] = counting_colums(ret_map[0]);
	while (ret_map[vars[0]])
	{
		vars[2] = counting_colums(ret_map[vars[0]]);
		if (vars[1] > vars[2] || vars[1] < vars[2])
			return (1);
		vars[0] += 1;
	}
	return (0);
}

void		validating_map(char **ret_map)
{
	if (validating_mapsize(ret_map))
	{
		write(1, "Error: invalid map\n", 19);
		exit(1);
	}
}
