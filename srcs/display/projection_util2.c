/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_util2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:40:05 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/09 09:22:19 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	min(int i1, int i2)
{
	if (i1 < i2)
		return (i1);
	return (i2);
}

t_map	setup_camera(t_map map)
{
	map.camera.zoom = min(WIDTH / map.line_size / 2,
			HEIGHT / map.line_count / 2);
	map.camera.alpha = 0;
	map.camera.beta = 0;
	map.camera.gamma = 0;
	map.camera.z_scale = 7;
	map.camera.x_offset = MENU_WIDTH;
	map.camera.y_offset = -250;
	map.camera.proj = ISO;
	return (map);
}

t_map	init_map(t_map map)
{
	int	i;
	int	j;

	map.z_max = map.map[0][0];
	map.z_min = map.map[0][0];
	i = -1;
	while (++i < map.line_count)
	{
		j = -1;
		while (++j < map.line_size)
		{
			if (map.map[i][j] > map.z_max)
				map.z_max = map.map[i][j];
			if (map.map[i][j] < map.z_min)
				map.z_min = map.map[i][j];
		}
	}
	map.z_range = map.z_max - map.z_min;
	return (setup_camera(map));
}
