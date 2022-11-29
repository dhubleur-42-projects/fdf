/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:45:26 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/09 09:22:33 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	press_ctrl(t_mlx *mlx)
{
	mlx->map->camera.beta += 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_option(t_mlx *mlx)
{
	mlx->map->camera.beta -= 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_plus(t_mlx *mlx)
{
	if (mlx->map->camera.z_scale > 1)
		mlx->map->camera.z_scale -= 1;
	if (mlx->map->camera.z_scale < 0)
		mlx->map->camera.z_scale -= 1;
	if (mlx->map->camera.z_scale == -20)
		mlx->map->camera.z_scale = 20;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_minus(t_mlx *mlx)
{
	if (mlx->map->camera.z_scale < 20 && mlx->map->camera.z_scale > 0)
		mlx->map->camera.z_scale += 1;
	if (mlx->map->camera.z_scale < -1 && mlx->map->camera.z_scale < 0)
		mlx->map->camera.z_scale += 1;
	if (mlx->map->camera.z_scale == 20)
		mlx->map->camera.z_scale = -20;
	mlx->map->colors = FALSE;
	display(mlx);
}
