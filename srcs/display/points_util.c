/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:21:17 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/09 09:21:43 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_pixel(t_mlx *mlx, t_point cur, t_point point1, t_point point2)
{
	if (mlx->map->colors)
		mlx_pixel_put(mlx->mlx_ptr, mlx->window_ptr, cur.x,
			cur.y, get_gradient_color(point1, point2, cur, mlx->map));
	else
		mlx_pixel_put(mlx->mlx_ptr, mlx->window_ptr, cur.x,
			cur.y, encode_rgb(100, 200, 100));
}

t_point	set_sign(t_point point1, t_point point2)
{
	t_point	sign;

	if (point2.x < point1.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (point2.y < point1.y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

void	trace_line(t_point point1, t_point point2, t_mlx *mlx)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = abs(point1.x - point2.x);
	delta.y = abs(point1.y - point2.y);
	sign = set_sign(point1, point2);
	error[0] = delta.x - delta.y;
	cur = point2;
	while (cur.x != point1.x || cur.y != point1.y)
	{
		color_pixel(mlx, cur, point1, point2);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

t_3d_point	init_3d_point(int x, int y, int z)
{
	t_3d_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
