/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:22:18 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/24 13:02:07 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	deal_mouse(int x, int y, t_game *game)
{
	int	old_x;

	(void)y;
	game->rot_speed = 0.01;
	old_x = game->mouse_x;
	game->mouse_x = x;
	if (game->mouse_x > WIN_WIDTH / 7)
		game->rot_speed = 0.03;
	if (game->mouse_x > WIN_WIDTH / 7 * 6)
		game->rot_speed = 0.03;
	if (old_x < game->mouse_x)
		deal_keys(DX, game);
	if (old_x > game->mouse_x)
		deal_keys(SX, game);
	return (0);
}
