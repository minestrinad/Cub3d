/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:55:23 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/29 16:08:28 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_game(t_game *game)
{
	(*game).mlx_ptr = NULL;
	(*game).win_ptr = NULL;
	(*game).mouse_x = 0;
	(*game).mouse_y = 0;
	(*game).mov_speed = 0.07;
	(*game).view.north.img = NULL;
	(*game).view.north.addr = NULL;
	(*game).view.south.img = NULL;
	(*game).view.south.addr = NULL;
	(*game).view.east.img = NULL;
	(*game).view.east.addr = NULL;
	(*game).view.weast.img = NULL;
	(*game).view.weast.addr = NULL;
	(*game).view.cealing = NULL;
	(*game).view.floor = NULL;
	(*game).map = NULL;
	(*game).m_x = 5;
	(*game).m_y = 5;
	(*game).player.start_dir = 0;
	(*game).player.x = 0;
	(*game).player.y = 0;
}

static t_player	player_data(double dir_x, double dir_y, \
	double plane_x, double plane_y)
{
	t_player	player;

	player.dir_x = dir_x;
	player.dir_y = dir_y;
	player.plane_x = plane_x;
	player.plane_y = plane_y;
	return (player);
}

void	ft_init_player(t_game *game)
{
	double	x;
	double	y;

	x = game->player.x;
	y = game->player.y;
	if (game->player.start_dir == 'N')
		game->player = player_data(-1, 0, 0, 0.66);
	else if (game->player.start_dir == 'W')
		game->player = player_data(0, -1, -0.66, 0);
	else if (game->player.start_dir == 'S')
		game->player = player_data(1, 0, 0, -0.66);
	else if (game->player.start_dir == 'E')
		game->player = player_data(0, 1, 0.66, 0);
	game->player.x = x + 0.01;
	game->player.y = y + 0.01;
}

void	init_vars(t_game *game, int x, t_ray *ray)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->map_x = (int)game->player.x;
	ray->map_y = (int)game->player.y;
	if (ray->ray_dir_x == 0)
		ray->delta_dis_x = 1e30;
	else
		ray->delta_dis_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dis_y = 1e30;
	else
		ray->delta_dis_y = fabs(1 / ray->ray_dir_y);
	ray->if_hit = 0;
}
