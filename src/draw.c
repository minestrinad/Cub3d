/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:12 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/25 11:58:52 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_draw_floor_ceiling(t_game *game, int floor_ceiling, int y)
{
	int	x;
	int	k;

	if (floor_ceiling == 0)
		k = WIN_HEIGHT;
	else
		k = WIN_HEIGHT / 2;
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

static void	draw_vertical_line(t_game *game, t_ray *ray, int x)
{
	int	color;
	int	y;

	y = ray->draw_start;
	ray->text_x = ray->wall_x * ray->texture.width;
	if (ray->side == N_S && ray->ray_dir_x > 0)
		ray->text_x = ray->texture.width - ray->text_x - 1;
	if (ray->side == E_W && ray->ray_dir_y < 0)
		ray->text_x = ray->texture.width - ray->text_x - 1;
	ray->step = 1.0 * ray->texture.height / ray->line_height;
	ray->text_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) \
		* ray->step;
	while (y <= ray->draw_end)
	{
		ray->text_y = (int)ray->text_pos & (ray->texture.height - 1);
		ray->text_pos += ray->step;
		color = get_pixel_color(ray->texture, ray->text_x, ray->text_y);
		my_mlx_pixel_put(game, x, y, color);
		y++;
	}
}

void	draw(t_game *game)
{
	t_ray	ray;
	int		x;

	ft_draw_floor_ceiling(game, 0, WIN_HEIGHT / 2);
	ft_draw_floor_ceiling(game, 1, 0);
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_vars(game, x, &ray);
		init_step_and_side_dist(game, &ray);
		ft_dda(game, &ray);
		calc_line_draw(game, &ray);
		choose_texture(game, &ray);
		draw_vertical_line(game, &ray, x);
		x++;
	}
}
