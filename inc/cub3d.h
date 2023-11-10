/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:22:11 by everonel          #+#    #+#             */
/*   Updated: 2023/11/10 04:37:15 by everonel         ###   ########.fr       */
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

# define EMPTY "0"
# define WALL "1"
# define PLAYER "N" "S" "E" "W"

# define MAP "default.cub"
# define BUFFER_SIZE 42

typedef struct  s_window
{
    void    *mlx;
    void    *win;
}               t_window;

typedef struct  s_map
{
    char    **map;
    int     map_width;
    int     map_height;
}               t_map;

typedef struct  s_player
{
    int     x;
    int     y;
    char    dir;
}               t_player;

/*
• Display different wall textures (the choice is yours) that vary depending on which
side the wall is facing (North, South, East, West).
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
• Your program must be able to set the floor and ceiling colors to two different ones.
• The program displays the image in a window and respects the following rules:
◦ The left and right arrow keys of the keyboard must allow you to look left and
    right in the maze.
◦ The W, A, S, and D keys must allow you to move the point of view through
    the maze.
◦ Pressing ESC must close the window and quit the program cleanly.
◦ Clicking on the red cross on the window’s frame must close the window and
    quit the program cleanly.
◦ The use of images of the minilibX is strongly recommended.
• Your program must take as a first argument a scene description file with the .cub
extension.
◦ The map must be composed of only 6 possible characters: 0 for an empty space,
    1 for a wall, and N,S,E or W for the player’s start position and spawning
    orientation.
This is a simple valid map:
111111
100101
101001
1100N1
111111
◦ The map must be closed/surrounded by walls, if not the program must return
    an error.
◦ Except for the map content, each type of element can be separated by one or
    more empty line(s).
◦ Except for the map content which always has to be the last, each type of
    element can be set in any order in the file.
◦ Except for the map, each type of information from an element can be separated
    by one or more space(s).
◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
    map and are up to you to handle. You must be able to parse any kind of map,
    as long as it respects the rules of the map.
7
cub3D My first RayCaster with miniLibX
◦ Each element (except the map) firsts information is the type identifier (com-
posed by one or two character(s)), followed by all specific informations for each
object in a strict order such as :
∗       North texture:
STDERR: NO ./path_to_the_north_texture
    · identifier: NO
    · path to the north texure
∗ South texture:
STDERR: SO ./path_to_the_south_texture
    · identifier: SO
    · path to the south texure
∗       West texture:
STDERR: WE ./path_to_the_west_texture
    · identifier: WE
    · path to the west texure
∗        East texture:
STDERR: EA ./path_to_the_east_texture
    · identifier: EA
    · path to the east texure
∗       Floor color:
STDERR: F 220,100,0
    · identifier: F
    · R,G,B colors in range [0,255]: 0, 255, 255
*       Ceiling color:
STDERR: C 225,30,0
    ·identifier: C
    · R,G,B colors in range [0,255]: 0, 255, 255

◦ Example of the mandatory part with a minimalist .cub scene:
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
◦ If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice.*/
#endif