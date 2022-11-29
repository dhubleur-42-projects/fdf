/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:51:48 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 19:21:55 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*init_window(char *name, t_map *map)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx_ptr = NULL;
	mlx->window_ptr = NULL;
	mlx->map = map;
	mlx->map->z_range = -10;
	mlx->map->colors = FALSE;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (quit_before_start(mlx));
	mlx->window_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, name);
	if (!mlx->window_ptr)
		return (quit_before_start(mlx));
	mlx_key_hook(mlx->window_ptr, handle_key, mlx);
	mlx_mouse_hook(mlx->window_ptr, handle_mouse, mlx);
	display(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (mlx);
}

void	display(t_mlx *mlx)
{
	display_background(mlx, encode_rgb(0, 0, 0));
	display_points(mlx);
	display_menu(mlx, encode_rgb(0, 0, 0), encode_rgb(255, 255, 255));
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}
