/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:29:33 by everonel          #+#    #+#             */
/*   Updated: 2023/11/26 22:06:27 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static t_game	ft_parse_input_file(t_game game, char *file)
{
	char	**file_content;
	int		last_readed;

	last_readed = 0;
	file_content = ft_read_file(file);
	if (!file_content)
		ft_error(&game, "invalid file\n");
	if (parse_infos(&game, file_content, &last_readed))
	{
		ft_free_matrix(file_content);
		ft_error(&game, "invalid file header\n");
	}
	if (!parse_map(&game, file_content + last_readed + 1))
	{
		ft_free_matrix(file_content);
		ft_error(&game, "invalid map\n");
	}
	ft_free_matrix(file_content);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	init_game(&game);
	game.mlx_ptr = mlx_init();
	if (argc == 2)
		game = ft_parse_input_file(game, argv[1]);
	else
		ft_error (&game, "Usage: ./cub3d maps/<map_name.cub>\n");
	ft_init_player(&game);
	handle_window(&game);
	ft_freegame(game);
	return (0);
}
