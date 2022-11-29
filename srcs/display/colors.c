/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:28:10 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 15:04:54 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(t_3d_point point, int z_min, int z_max)
{
	int	step;
	int	current_z;
	int	red;
	int	green;
	int	blue;

	step = z_max - z_min;
	current_z = point.z - z_min;
	if (current_z <= step / 2)
	{
		blue = 0;
		red = 255 - ((510 * current_z) / step);
		green = 255 - red;
	}
	else
	{
		red = 0;
		blue = (255 * current_z) / step;
		green = 255 - blue;
	}
	return (encode_rgb(red, green, blue));
}

int	get_red(t_3d_point point, int z_min, int z_max)
{
	int	step;
	int	current_z;

	step = z_max - z_min;
	current_z = point.z - z_min;
	if (current_z <= step / 2)
		return (255 - ((510 * current_z) / step));
	else
		return (0);
}

int	get_blue(t_3d_point point, int z_min, int z_max)
{
	int	step;
	int	current_z;

	step = z_max - z_min;
	current_z = point.z - z_min;
	if (current_z <= step / 2)
		return (0);
	else
		return ((255 * current_z) / step);
}

int	get_green(t_3d_point point, int z_min, int z_max)
{
	int	step;
	int	current_z;

	step = z_max - z_min;
	current_z = point.z - z_min;
	if (current_z <= step / 2)
		return (255 - (255 - ((510 * current_z) / step)));
	else
		return (255 - ((255 * current_z) / step));
}
