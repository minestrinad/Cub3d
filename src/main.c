/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:19:27 by everonel          #+#    #+#             */
/*   Updated: 2023/11/10 04:46:03 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void static    ft_window_manager(void *mlx, void *win)
// {
//     mlx_pixel_put(mlx, win, 400, 250, 0x00FFFFFF);
// }

// void static    ft_game_loop(void *mlx, void *win)
// {
//     mlx_loop(mlx);
//     (void) win;
// }

static char **ft_lst_to_matrix(t_list *map)
{
    char    **map_matrix;
    int     i;

    i = 0;
    map_matrix = (char **)malloc(sizeof(char *) * ft_lstsize(map));
    while (map)
    {
        map_matrix[i] = (char *)malloc(sizeof(char) * ft_strlen(map->data));
        map_matrix[i] = ft_strdup(map->data);
        map = map->next;
        i++;
    }
    // free (map);
    return (map_matrix);
}

static void ft_check_charachters(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        while (map[i][j])
        {
            if (ft_strchr(EMPTY, map[i][j]) || ft_strchr(WALL, map[i][j]) || ft_strchr(PLAYER, map[i][j]) || map[i][j] == '\n' || map[i][j] == '\0')
                j++;
            else
                ft_putstr_fd("Invalid charachter in map", 2);
            printf ("Map is valid\n");
            printf ("char : %c\n", map[i][j]);
        }
        j = 0;
        i++;
    }
}


int     get_next_line(int fd, char **line)
{
    int i = 0;
    int rd = 0;
    char character;

    char *buffer = malloc(100); // check before the current BUFFER_SIZE and then malloc
    while ((rd = read(fd, &character, 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    buffer[i] = '\0';
    if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
        return (free(buffer), 0);
    *line = buffer;
    return (1);
}

static char **ft_read_file(char *map_file)
{
    int     fd;
    char    *line;
    t_list  *map;
    t_list  *tmp;
    char    **map_matrix;

    map = NULL;
    fd = open(map_file, O_RDONLY);
    if (fd == -1)
        ft_putstr_fd("Error\nFile not found", 2);
    while (get_next_line(fd, &line))
    {
        tmp = ft_lstnew(ft_strdup(line));
        ft_lstadd_back(&map, tmp);
    }
    close(fd);
    map_matrix = ft_lst_to_matrix(map);    
    return (map_matrix);
}

static char    **ft_mapparser(char *map_file)
{
    char **map;

    map = ft_read_file(map_file);
    ft_check_charachters(map);
    // ft_check_enclosure(map);
    return (map);
}

int main(int argc, char **argv)
{
    void    *mlx;
    void    *win;
    t_map   *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (argc == 2)
            map->map = ft_mapparser(argv[1]);
    else
        map->map = ft_mapparser(MAP);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 500, "Hello World");
    mlx_loop(mlx);
    // ft_window_manager(mlx, win);
    // ft_game_loop(mlx, win);
    (void) win;
    printf("Hello World\n");
    return (0);
}