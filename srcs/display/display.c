/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:44:31 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 18:58:44 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_points(t_mlx *mlx)
{
	int			i;
	int			j;
	t_3d_point	p;

	if (mlx->map->z_range == -10)
		*(mlx->map) = init_map(*(mlx->map));
	i = -1;
	while (++i < mlx->map->line_count)
	{
		j = -1;
		while (++j < mlx->map->line_size)
		{
			p = init_3d_point(j, i, mlx->map->map[i][j]);
			if (j > 0)
				trace_line(project(p, mlx->map), project(init_3d_point(j - 1,
							i, mlx->map->map[i][j - 1]), mlx->map), mlx);
			if (i > 0)
				trace_line(project(p, mlx->map), project(init_3d_point(j,
							i - 1, mlx->map->map[i - 1][j]), mlx->map), mlx);
		}
	}
}

void	display_background(t_mlx *mlx, int color)
{
	int		x;
	int		y;
	void	*img_ptr;
	int		*data;
	int		useless;

	img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	data = (int *)mlx_get_data_addr(img_ptr, &useless, &useless, &useless);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			data[y * WIDTH + x] = color;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window_ptr, img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img_ptr);
}

void	display_menu_2(t_mlx *mlx, int text_color)
{
	if (mlx->map->camera.proj == ISO)
		mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 330, text_color,
			"Current projection: Isometric");
	if (mlx->map->camera.proj == PARALLEL)
		mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 330, text_color,
			"Current projection: Parallel");
}

void	display_menu_string(t_mlx *mlx, int text_color)
{
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 50, text_color,
		"Arrows UP / DOWN | Rotate X axis");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 70, text_color,
		"Arrows RIGHT / LEFT | Rotate Z axis");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 90, text_color,
		"CTRL right / OPT right | Rotate Y axis");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 130, text_color,
		"Wheel UP / DOWN | Zoom in/out");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 170, text_color,
		"Keypad + / - | Change Z scale");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 210, text_color,
		"W / A / S / D | Move projection");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 250, text_color,
		"C | Toggle color mod");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 265, text_color,
		"(All projection movements disable");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 280, text_color,
		" colors to reduce lag)");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 310, text_color,
		"P | Toggle projection (Iso, Parallel)");
	display_menu_2(mlx, text_color);
}

void	display_menu(t_mlx *mlx, int background_color, int text_color)
{
	int		x;
	int		y;
	void	*img_ptr;
	int		*data;
	int		useless;

	img_ptr = mlx_new_image(mlx->mlx_ptr, MENU_WIDTH, HEIGHT);
	data = (int *)mlx_get_data_addr(img_ptr, &useless, &useless, &useless);
	x = -1;
	while (++x < MENU_WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			data[y * MENU_WIDTH + x] = background_color;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window_ptr, img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img_ptr);
	display_menu_string(mlx, text_color);
}
