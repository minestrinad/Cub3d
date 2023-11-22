/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:32:51 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/22 16:49:47 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
{
	char	*i;
	int		y1;

	y1 = y * (*data).test.line_len;
	i = (*data).test.addr + (y1 + x * ((*data).test.bits_pixel / 8));
	*(unsigned int *)i = color;
}

void	draw_square_player(t_game *data, int x, int y, int color)
{
	int	i;
	int	k;

	k = 0;
	while (k < 3)
	{
		i = 0;
		while (i < 3)
		{
			my_mlx_pixel_put(data, x + k, y + i, color);
			i++;
		}
		k++;
	}	
}

void	draw_square(t_game *data, int x, int y, int color)
{
	int	i;
	int	k;

	k = 0;
	while (k < 5)
	{
		i = 0;
		while (i < 5)
		{
			my_mlx_pixel_put(data, x + k, y + i, color);
			i++;
		}
		k++;
	}
}

void	draw_minimap(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_square(data, x * 5, y * 5, 0XFFFFFF);
			else if (data->map[y][x] == '0')
				draw_square(data, x * 5, y * 5, 0x000000);
			x++;
		}
		y++;
	}
	draw_square_player(data, data->player.y * 5, data->player.x * 5, 0xb000f5);
}

int	image(t_game *data)
{
	(*data).test.img = mlx_new_image((*data).mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	(*data).test.addr = mlx_get_data_addr((*data).test.img,
			&(*data).test.bits_pixel,
			&(*data).test.line_len,
			&(*data).test.endian);
	draw(data);
	draw_minimap(data);
	mlx_put_image_to_window((*data).mlx_ptr, (*data).win_ptr,
		(*data).test.img, 0, 0);
	return (0);
}
