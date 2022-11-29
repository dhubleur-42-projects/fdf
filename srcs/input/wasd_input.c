/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:44:16 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 15:06:51 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	press_w(t_mlx *mlx)
{
	mlx->map->camera.y_offset -= 25;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_a(t_mlx *mlx)
{
	mlx->map->camera.x_offset -= 25;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_s(t_mlx *mlx)
{
	mlx->map->camera.y_offset += 25;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_d(t_mlx *mlx)
{
	mlx->map->camera.x_offset += 25;
	mlx->map->colors = FALSE;
	display(mlx);
}
