/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:47:43 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 14:50:10 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_gradient(int c1, int c2, float d1, float d2)
{
	float		range;
	float		part;

	range = c1 - c2;
	part = d2 / (d1 + d2);
	return (c2 + (part * range));
}

int	get_gradient_color(t_point point1, t_point point2, t_point cur, t_map *map)
{
	float	distance1;
	float	distance2;

	distance1 = sqrt(pow(abs(point1.x - cur.x), 2)
			+ pow(abs(point1.y - cur.y), 2));
	distance2 = sqrt(pow(abs(point2.x - cur.x), 2)
			+ pow(abs(point2.y - cur.y), 2));
	return (encode_rgb(get_gradient(get_red(point1.real_point, map->z_min,
					map->z_max), get_red(point2.real_point, map->z_min,
					map->z_max), distance1, distance2),
			get_gradient(get_green(point1.real_point, map->z_min, map->z_max),
				get_green(point2.real_point, map->z_min, map->z_max), distance1,
				distance2), get_gradient(get_blue(point1.real_point,
					map->z_min, map->z_max), get_blue(point2.real_point,
					map->z_min, map->z_max), distance1, distance2)));
}
