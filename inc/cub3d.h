/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:22:11 by everonel          #+#    #+#             */
/*   Updated: 2023/11/22 15:26:37 by ncortigi         ###   ########.fr       */
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
# define N_S 0
# define E_W 1
# define NO 0
# define SO 1
# define EA 2
# define WE 3
# define W 119
# define A 97
# define S 115
# define D 100

# define EMPTY          '0'
# define WALL           '1'
# define PLAYER         "NSEW"

# define NORTH_PATH     "NO "
# define SOUTH_PATH     "SO "
# define WEST_PATH      "WE "
# define EAST_PATH      "EA "
# define CEALING        "C"
# define FLOOR          "F"

# define DEFAULT_MAP    "default.cub"

typedef struct	s_texture
{
	void	*img;
	void	*addr;
	char	*pixels;
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

typedef struct	s_player
{
	char		start_dir;
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct	s_ray
{
	int			if_hit;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	int			wall_dir;
	int			draw_start;
	int			draw_end;
	int			line_height;
	int			text_x;
	int			text_y;
	double		camera_x;
	double		plane_x;
	double		plane_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dis_x;
	double		delta_dis_y;
	double		side_dis_x;
	double		side_dis_y;
	double		p_wall_dis;
	double		wall_x;
	double		step;
	double		text_pos;
	t_texture	texture;
}				t_ray;

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			map_width;
	int			map_height;
	int			frame;
	double		mov_speed;
	double		rot_speed;
	t_view		view;
	t_texture	test;
	t_player	player;
}				t_game;

// Parsing
int		parse_infos(t_game *, char **, int *);
int		parse_map(t_game *, char **);

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

// colors
int		ft_rgb(int *color, int t);
int		get_pixel_color(t_texture texture, int x, int y);
int		ft_make_shade(int color);

// dda
void    ft_dda(t_game *game, t_ray *ray);
void	calc_line_draw(t_game *game, t_ray *ray);
void	init_step_and_side_dist(t_game *game, t_ray *ray);
void	choose_texture(t_game *game, t_ray *ray);

// keys
int	press_key_w(t_game *game);
int	press_key_a(t_game *game);
int	press_key_s(t_game *game);
int	press_key_d(t_game *game);

#endif