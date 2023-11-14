/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:17:22 by emma              #+#    #+#             */
/*   Updated: 2023/11/13 15:36:30 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "libft.h"

// #include <stdio.h>
// #include <stdlib.h>

// #define ROWS 10
// #define COLS 10

// #include <stdio.h>

// #define ROWS 10
// #define COLS 10

// int isPlayerSurrounded(char **map, int row, int col) {
//     if (map[row][col] != 'P') {
//         return 0; // If the player is not at the given position, return false
//     }

//     // Check all four sides around the player
//     if (row > 0 && map[row - 1][col] != '1') {
//         return 0; // Check top
//     }
//     if (row < ROWS - 1 && map[row + 1][col] != '1') {
//         return 0; // Check bottom
//     }
//     if (col > 0 && map[row][col - 1] != '1') {
//         return 0; // Check left
//     }
//     if (col < COLS - 1 && map[row][col + 1] != '1') {
//         return 0; // Check right
//     }

//     return 1; // If all sides around the player are walls, return true
// }

// int main() {
//     char *validMap[ROWS] = {
//         "1111111111",
//         "1000011001",
//         "1010011001",
//         "1000011001",
//         "1111111111",
//         "1000000001",
//         "1000000001",
//         "10000P0001",
//         "1000000001",
//         "1111111111"
//     };

//     char *invalidMap[ROWS] = {
//         "1111111111",
//         "1000011001",
//         "1010011001",
//         "1000011001",
//         "1111111111",
//         "100000000",
//         "1000000001",
//         "10000P0001",
//         "1000000001",
//         "1111111111"
//     };

//     int resultValid = isPlayerSurrounded(validMap, 7, 5);
//     int resultInvalid = isPlayerSurrounded(invalidMap, 7, 5);

//     if (resultValid) {
//         printf("La mappa valida è corretta.\n");
//     } else {
//         printf("La mappa valida non è corretta.\n");
//     }

//     if (resultInvalid) {
//         printf("La mappa non valida è considerata corretta, ma è errata.\n");
//     } else {
//         printf("La mappa non valida è correttamente considerata errata.\n");
//     }

//     return 0;
// }
