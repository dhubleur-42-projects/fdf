/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:14:21 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 15:06:41 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	up(t_mlx *mlx)
{
	mlx->map->camera.zoom += 1;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	down(t_mlx *mlx)
{
	if (mlx->map->camera.zoom > 0)
		mlx->map->camera.zoom -= 1;
	mlx->map->colors = FALSE;
	display(mlx);
}

int	handle_mouse(int button, int x, int y, void *ptr)
{
	(void) x;
	(void) y;
	if (button == WHEEL_UP)
		up((t_mlx *) ptr);
	if (button == WHEEL_DOWN)
		down((t_mlx *) ptr);
	return (0);
}
