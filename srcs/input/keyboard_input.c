/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:54:00 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 18:03:34 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	press_escape(t_mlx *mlx)
{
	quit(mlx);
}

int	handle_key2(int key, void *ptr)
{
	if (key == W)
		press_w((t_mlx *) ptr);
	if (key == A)
		press_a((t_mlx *) ptr);
	if (key == S)
		press_s((t_mlx *) ptr);
	if (key == D)
		press_d((t_mlx *) ptr);
	if (key == C)
		press_c((t_mlx *) ptr);
	if (key == P)
		press_p((t_mlx *) ptr);
	return (0);
}

int	handle_key(int key, void *ptr)
{
	if (key == ESC)
		press_escape((t_mlx *) ptr);
	if (key == UP)
		press_up((t_mlx *) ptr);
	if (key == LEFT)
		press_left((t_mlx *) ptr);
	if (key == DOWN)
		press_down((t_mlx *) ptr);
	if (key == RIGHT)
		press_right((t_mlx *) ptr);
	if (key == OPTION)
		press_option((t_mlx *) ptr);
	if (key == CTRL_RIGHT)
		press_ctrl((t_mlx *) ptr);
	if (key == PLUS)
		press_plus((t_mlx *) ptr);
	if (key == MINUS)
		press_minus((t_mlx *) ptr);
	return (handle_key2(key, ptr));
}
