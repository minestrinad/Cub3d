/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:05:02 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/29 16:09:05 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	press_key_w(t_game *game)
{
	if (game->map[(int)(game->player.x + game->player.dir_x * \
		game->mov_speed)][(int)(game->player.y)] == '0')
		game->player.x += game->player.dir_x * game->mov_speed;
	if (game->map[(int)(game->player.x)] \
		[(int)((game->player.y + game->player.dir_y * game->mov_speed))] == '0')
		game->player.y += game->player.dir_y * game->mov_speed;
	return (0);
}

int	press_key_a(t_game *game)
{
	if (game->map[(int)(game->player.x - game->player.dir_y * \
		game->mov_speed)][(int)(game->player.y)] == '0')
		game->player.x -= game->player.dir_y * game->mov_speed;
	if (game->map[(int)(game->player.x)] \
		[(int)((game->player.y + game->player.dir_x * game->mov_speed))] == '0')
		game->player.y += game->player.dir_x * game->mov_speed;
	return (0);
}

int	press_key_s(t_game *game)
{
	if (game->map[(int)(game->player.x - game->player.dir_x * \
		game->mov_speed)][(int)(game->player.y)] == '0')
		game->player.x -= game->player.dir_x * game->mov_speed;
	if (game->map[(int)(game->player.x)] \
		[(int)((game->player.y - game->player.dir_y * game->mov_speed))] == '0')
		game->player.y -= game->player.dir_y * game->mov_speed;
	return (0);
}

int	press_key_d(t_game *game)
{
	if (game->map[(int)(game->player.x + game->player.dir_y * \
		game->mov_speed)][(int)(game->player.y)] == '0')
		game->player.x += game->player.dir_y * game->mov_speed;
	if (game->map[(int)(game->player.x)] \
		[(int)((game->player.y - game->player.dir_x * game->mov_speed))] == '0')
		game->player.y -= game->player.dir_x * game->mov_speed;
	return (0);
}
