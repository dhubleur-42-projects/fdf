/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:21:13 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/09 09:22:14 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum e_proj {
	ISO,
	PARALLEL
}	t_proj;
typedef struct s_camera
{
	int		zoom;
	double	alpha;
	double	beta;
	double	gamma;
	float	z_scale;
	int		x_offset;
	int		y_offset;
	t_proj	proj;
}	t_camera;

typedef struct s_map
{
	int			**map;
	int			line_size;
	int			line_count;
	int			z_min;
	int			z_max;
	int			z_range;
	t_camera	camera;
	t_bool		colors;
}	t_map;

typedef struct s_3d_point
{
	int	x;
	int	y;
	int	z;
}	t_3d_point;
typedef struct s_point
{
	int			x;
	int			y;
	t_3d_point	real_point;
}	t_point;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window_ptr;
	t_map	*map;
}	t_mlx;

#endif