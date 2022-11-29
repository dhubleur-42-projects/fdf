/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:25:12 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/09 09:22:32 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void	project_iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_point	project(t_3d_point point, t_map *map)
{
	t_point	projected_point;

	projected_point.real_point = point;
	point.x *= map->camera.zoom;
	point.y *= map->camera.zoom;
	point.z *= map->camera.zoom / map->camera.z_scale;
	point.x -= (map->line_size * map->camera.zoom) / 2;
	point.y -= (map->line_count * map->camera.zoom) / 2;
	rotate_x(&point.y, &point.z, map->camera.alpha);
	rotate_y(&point.x, &point.z, map->camera.beta);
	rotate_z(&point.x, &point.y, map->camera.gamma);
	if (map->camera.proj == ISO)
		project_iso(&point.x, &point.y, point.z);
	point.x += (WIDTH - MENU_WIDTH) / 2 + map->camera.x_offset;
	point.y += (HEIGHT + map->line_count * map->camera.zoom)
		/ 2 + map->camera.y_offset;
	projected_point.x = point.x;
	projected_point.y = point.y;
	return (projected_point);
}
