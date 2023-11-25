/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:17:23 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/25 12:01:02 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_step_and_side_dist(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dis_x = (game->player.x - ray->map_x) * ray->delta_dis_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dis_x = (ray->map_x + 1.0 - game->player.x) * \
			ray->delta_dis_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dis_y = (game->player.y - ray->map_y) * ray->delta_dis_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dis_y = (ray->map_y + 1.0 - game->player.y) * \
			ray->delta_dis_y;
	}
}

void	calc_line_draw(t_game *game, t_ray *ray)
{
	if (ray->side == N_S)
		ray->p_wall_dis = (ray->side_dis_x - ray->delta_dis_x);
	else
		ray->p_wall_dis = (ray->side_dis_y - ray->delta_dis_y);
	ray->line_height = (int)(WIN_HEIGHT / ray->p_wall_dis);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->side == N_S)
		ray->wall_x = game->player.y + ray->p_wall_dis * ray->ray_dir_y;
	else
		ray->wall_x = game->player.x + ray->p_wall_dis * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

static void	set_wall_hit(t_ray *ray)
{
	if (ray->side == N_S && ray->step_x == -1)
		ray->wall_dir = SO;
	else if (ray->side == N_S && ray->step_x == 1)
		ray->wall_dir = NO;
	else if (ray->side == E_W && ray->step_y == -1)
		ray->wall_dir = WE;
	else if (ray->side == E_W && ray->step_y == 1)
		ray->wall_dir = EA;
}

void	ft_dda(t_game *game, t_ray *ray)
{
	while (ray->if_hit == 0)
	{
		if (ray->side_dis_x < ray->side_dis_y)
		{
			ray->side_dis_x += ray->delta_dis_x;
			ray->map_x += ray->step_x;
			ray->side = N_S;
		}
		else
		{
			ray->side_dis_y += ray->delta_dis_y;
			ray->map_y += ray->step_y;
			ray->side = E_W;
		}
		if (game->map[ray->map_x][ray->map_y] == '1')
			ray->if_hit = 1;
		set_wall_hit(ray);
	}
}
