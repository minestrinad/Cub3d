/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:12 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/16 16:08:42 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	ft_rgb(int *color, int t)
{
	return (t << 24 | color[0] << 16 | color[1] << 8 | color[2]);
}

static void	ft_draw_floor_ceiling(t_game *game, t_texture *img, int floor_ceiling, int y)
{
	int	x;
	int k;

	if (floor_ceiling == 0)
		k = WIN_HEIGHT / 2;
	else
		k = WIN_HEIGHT;
	while (y < k)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (floor_ceiling == 0)
				my_mlx_pixel_put(game, x, y, ft_rgb(game->view.floor, 0));
			else
				my_mlx_pixel_put(game, x, y, ft_rgb(game->view.cealing, 0));
			x++;
		}
		y++;
	}
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
		ray->delta_dis_x = (ray->map_x + 1.0 - game->player.x) * \
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
		ray->delta_dis_y = (ray->map_y + 1.0 - game->player.y) * \
			ray->delta_dis_y;
	}
}

void	draw(t_game *game)
{
	t_ray	*ray;
	int		x;

	ft_draw_floor_ceiling(game, &(*game).test, 0, 0);
	ft_draw_floor_ceiling(game, &(*game).test, 1, WIN_HEIGHT / 2);
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_vars(game, x, &ray);
		init_step_and_side_dist(game, &ray);
		ft_dda(game, &ray);
		calc_line_draw(game, &ray);
		choose_texture(game, &ray);
		x++;
	}
}
