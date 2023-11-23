/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:04:34 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/23 19:06:20 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_close(t_game *game)
{
	ft_freegame(*game);
	printf ("ft_close\n");
	mlx_destroy_image((*game).mlx_ptr, (*game).test.img);
	// mlx_destroy_window((*game).mlx_ptr, (*game).win_ptr);
	mlx_destroy_display((*game).mlx_ptr);
	free((*game).mlx_ptr);
	//fare free di tutto
	exit(0);
	return (0);
}
