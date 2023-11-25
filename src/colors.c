/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:07:38 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/25 11:51:49 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_rgb(int *color, int t)
{
	return (t << 24 | color[0] << 16 | color[1] << 8 | color[2]);
}

void	choose_texture(t_game *game, t_ray *ray)
{
	if (game->map[ray->map_x][ray->map_y] == '1' && ray->wall_dir == NO)
		ray->texture = game->view.north;
	else if (game->map[ray->map_x][ray->map_y] == '1' && \
		ray->wall_dir == SO)
		ray->texture = game->view.south;
	else if (game->map[ray->map_x][ray->map_y] == '1' && \
		ray->wall_dir == WE)
		ray->texture = game->view.east;
	else if (game->map[ray->map_x][ray->map_y] == '1' && \
		ray->wall_dir == EA)
		ray->texture = game->view.weast;
}

int	get_pixel_color(t_texture texture, int x, int y)
{
	char	*pixel_add;
	int		new_color;

	if (x < 0 || x >= texture.width || y < 0 || y >= texture.height)
		return (0);
	pixel_add = texture.pixels + (y * texture.line_len + x * \
		(texture.bits_pixel / 8));
	new_color = *(unsigned int *)pixel_add;
	return (new_color);
}
