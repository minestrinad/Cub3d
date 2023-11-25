/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:28:01 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/25 11:53:33 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_keys(int key)
{
	if (key == SX || key == DX)
		return (1);
	if (key == W || key == A || key == S || key == D)
		return (1);
	return (0);
}

static int	press_key_arr_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(-game->rot_speed) - \
		game->player.dir_y * sin(-game->rot_speed);
	game->player.dir_y = old_dir_x * sin(-game->rot_speed) + \
		game->player.dir_y * cos(-game->rot_speed);
	game->player.plane_x = game->player.plane_x * cos(-game->rot_speed) - \
		game->player.plane_y * sin(-game->rot_speed);
	game->player.plane_y = old_plane_x * sin(-game->rot_speed) + \
		game->player.plane_y * cos(-game->rot_speed);
	return (0);
}

static int	press_key_arr_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(game->rot_speed) - \
		game->player.dir_y * sin(game->rot_speed);
	game->player.dir_y = old_dir_x * sin(game->rot_speed) + \
		game->player.dir_y * cos(game->rot_speed);
	game->player.plane_x = game->player.plane_x * cos(game->rot_speed) - \
		game->player.plane_y * sin(game->rot_speed);
	game->player.plane_y = old_plane_x * sin(game->rot_speed) + \
		game->player.plane_y * cos(game->rot_speed);
	return (0);
}

static void	keys(int key, t_game *game)
{
	if (!game->mouse_x)
		game->rot_speed = 0.07;
	if (key == DX)
		press_key_arr_right(game);
	else if (key == SX)
		press_key_arr_left(game);
	else if (key == W)
		press_key_w(game);
	else if (key == A)
		press_key_a(game);
	else if (key == S)
		press_key_s(game);
	else if (key == D)
		press_key_d(game);
}

int	deal_keys(int key, t_game *game)
{
	if (check_keys(key))
	{
		mlx_destroy_image((*game).mlx_ptr, (*game).test.img);
		keys(key, game);
		image(game);
	}
	if (key == ESC)
		ft_close(game);
	return (0);
}
