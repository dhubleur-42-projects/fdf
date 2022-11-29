/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:17:20 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 19:23:12 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_putendl_fd("Please specify one map", 1);
		return (1);
	}
	map = parse_map(argv[1]);
	if (!map)
		return (1);
	init_window("Fdf", map);
	return (0);
}

void	quit(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->map->line_count)
	{
		free((mlx->map->map)[i]);
	}
	free(mlx->map->map);
	free(mlx->map);
	mlx_loop_end(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	exit(0);
}

t_mlx	*quit_before_start(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->map->line_count)
	{
		free((mlx->map->map)[i]);
	}
	free(mlx->map->map);
	free(mlx->map);
	free(mlx);
	if (mlx->mlx_ptr && mlx->window_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->window_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	return (NULL);
}
