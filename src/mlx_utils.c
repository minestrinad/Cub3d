/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:32:51 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/25 11:17:42 by ncortigi         ###   ########.fr       */
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

void	handle_window(t_game *game)
{
	(*game).win_ptr = mlx_new_window((*game).mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
		"Cub3d");
	image(game);
	mlx_hook((*game).win_ptr, 17, 0L, ft_close, game);
	mlx_hook((*game).win_ptr, 2, 1L << 0, deal_keys, game);
	mlx_hook((*game).win_ptr, 6, 1L << 6, deal_mouse, game);
	mlx_loop((*game).mlx_ptr);
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
