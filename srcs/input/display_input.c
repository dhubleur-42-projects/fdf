/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:38:58 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 18:28:37 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	press_c(t_mlx *mlx)
{
	if (mlx->map->colors)
		mlx->map->colors = FALSE;
	else
		mlx->map->colors = TRUE;
	display(mlx);
}

void	press_p(t_mlx *mlx)
{
	if (mlx->map->camera.proj == ISO)
		mlx->map->camera.proj = PARALLEL;
	else
		mlx->map->camera.proj = ISO;
	mlx->map->camera.alpha = 0;
	mlx->map->camera.beta = 0;
	mlx->map->camera.gamma = 0;
	display(mlx);
}
