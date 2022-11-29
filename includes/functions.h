/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:34:35 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 18:43:01 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

//Parse functions
t_map		*parse_map(char *file);
int			**process_line(char *line, int **table, int *line_size);
t_mlx		*quit_before_start(t_mlx *mlx);

//Display functions
t_mlx		*init_window(char *name, t_map *map);
int			encode_rgb(int red, int green, int blue);
void		display(t_mlx *mlx);
void		trace_line(t_point point1, t_point point2, t_mlx *mlx);
void		display_background(t_mlx *mlx, int color);
void		display_points(t_mlx *mlx);
void		display_menu(t_mlx *mlx, int background_color, int text_color);
int			get_color(t_3d_point point, int z_min, int z_max);
int			get_gradient_color(t_point point1, t_point point2, t_point cur,
				t_map *map);
int			get_green(t_3d_point point, int z_min, int z_max);
int			get_blue(t_3d_point point, int z_min, int z_max);
int			get_red(t_3d_point point, int z_min, int z_max);

//Calcul function
t_3d_point	init_3d_point(int x, int y, int z);
t_point		project(t_3d_point point, t_map *map);
t_map		init_map(t_map map);

//Input functions
int			handle_key(int key, void *ptr);
int			handle_mouse(int button, int x, int y, void *ptr);
void		press_up(t_mlx *mlx);
void		press_down(t_mlx *mlx);
void		press_left(t_mlx *mlx);
void		press_right(t_mlx *mlx);
void		press_w(t_mlx *mlx);
void		press_a(t_mlx *mlx);
void		press_s(t_mlx *mlx);
void		press_d(t_mlx *mlx);
void		press_escape(t_mlx *mlx);
void		press_ctrl(t_mlx *mlx);
void		press_option(t_mlx *mlx);
void		press_plus(t_mlx *mlx);
void		press_minus(t_mlx *mlx);
void		press_c(t_mlx *mlx);
void		press_p(t_mlx *mlx);

//System functions
void		quit(t_mlx *mlx);

#endif