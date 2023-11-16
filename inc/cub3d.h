/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:22:11 by everonel          #+#    #+#             */
/*   Updated: 2023/11/16 14:11:24 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


# define WIN_WIDTH 800
# define WIN_HEIGHT 500

# define ESC 65307
# define DX 65363
# define SX 65361
# define W 119
# define A 97
# define S 115
# define D 100

# define EMPTY          '0'
# define WALL           '1'
# define PLAYER         "NSEW"

# define NORTH_PATH     "NO ./"
# define SOUTH_PATH     "SO ./"
# define WEST_PATH      "WE ./"
# define EAST_PATH      "EA ./"
# define CEALING        "C"
# define FLOOR          "F"

# define DEFAULT_MAP    "default.cub"




// typedef struct	s_window
// {
// 	void	*mlx;
// 	void	*win;
// }				t_window;

typedef struct  s_map
{
	char	**map;
	int		map_width;
	int		map_height;
}				t_map;

typedef struct	s_texture
{
	void	*img;
	void	*addr;
	int		width;
	int		height;
	int		bits_pixel;
	int		line_len;
	int		endian;
}				t_texture;


typedef struct	s_view
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	weast;
	int			*cealing;
	int			*floor;
}				t_view;

typedef struct	s_player			//prendere pos da map
{
	char		start_dir;
	double		x;
	double		y;
}				t_player;

// typedef struct s_img
// {
// 	void	*mlx_img;
// 	char	*data;
// }		t_img;

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_view		view;
	t_texture	test;
	t_player	player;
}				t_game;

// Parsing

int	parse_infos(t_game *, char **, int *);
void	parse_map(t_game *, char **);

// Utils
void	ft_error(t_game, char *);
void	ft_freegame(t_game game);

// Window
int		deal_keys(int key, t_game *game);
int		ft_close(t_game *game);

// mlx_utils
void	my_mlx_pixel_put(t_game *data, int x, int y, int color);
int		image(t_game *data);

void	draw(t_game *game);

#endif