/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:42:36 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 18:30:42 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	press_up(t_mlx *mlx)
{
	mlx->map->camera.alpha += 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_down(t_mlx *mlx)
{
	mlx->map->camera.alpha -= 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_left(t_mlx *mlx)
{
	mlx->map->camera.gamma += 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_right(t_mlx *mlx)
{
	mlx->map->camera.gamma -= 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}
