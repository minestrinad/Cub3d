/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:32:51 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/15 15:09:40 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
{
	char	*i;
	int		y1;

	y1 = y * data->img->line_len;
	i = data->img->data + (y1 + x * (data->img->bits_pixel / 8));
	*(unsigned int *)i = color;
}

int	image(t_game *data)
{
	data->img->mlx_img = mlx_new_image(data->window->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img->data = mlx_get_data_addr(data->img->mlx_img,
			&data->img->bits_pixel,
			&data->img->line_len,
			&data->img->endian);
	draw(data);
	mlx_put_image_to_window(data->window->mlx, data->window->win,
		data->img->mlx_img, 0, 0);
	// key_map(data);
	return (0);
}
