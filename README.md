# Cub3D - My First RayCaster with miniLibX

## Introduction

Cub3D is a project inspired by the iconic Wolfenstein 3D game, aiming to provide a 3D graphical representation of a maze from a first-person perspective using Ray-Casting principles. The project is written in C and leverages the miniLibX library for graphics.

## Objective

The primary goal of Cub3D is to enhance skills in C programming, algorithms, and graphic design. The project encourages the exploration of mathematical concepts for creating elegant and efficient algorithms. The mandatory part involves implementing a basic 3D maze with features like wall textures, floor and ceiling colors, and player movement controls. The bonus part introduces additional features like wall collisions, a minimap system, doors, animated sprites, and mouse-controlled point of view rotation.

## Getting Started

To compile the project, use the provided Makefile with the following commands:

- `make all`: Compile the project.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and the executable.
- `make re`: Re-compile the project.

To run the program, provide a scene description file in the .cub format as the first argument:

```bash
./cub3D map.cub
```

## Scene Description File

The scene description file (.cub) defines the maze and its characteristics. Below are the basic elements that can be included in the file:

- **Textures:**
  - North texture: `NO ./path_to_the_north_texture`
  - South texture: `SO ./path_to_the_south_texture`
  - West texture: `WE ./path_to_the_west_texture`
  - East texture: `EA ./path_to_the_east_texture`

- **Colors:**
  - Floor color: `F R,G,B`
  - Ceiling color: `C R,G,B`

- **Map:**
  - The map is represented with 0 for an empty space, 1 for a wall, and N, S, E, or W for the player's start position and orientation.

Example:
```plaintext
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
11110111111101011111011101001
11111111111111111111111111111
```

## Controls

- Arrow keys: Look left and right
- W, A, S, D keys: Move the point of view
- ESC key: Close the window and quit the program
- Clicking on the red cross on the window's frame: Close the window and quit the program

## Bonus Features

The bonus part includes additional features like wall collisions, a minimap system, doors, animated sprites, and mouse-controlled point of view rotation. These features are evaluated only if the mandatory part is perfect.
<!-----```
## Examples

- Original Wolfenstein 3D: ![Wolfenstein3D](link_to_image)
- Mandatory part example: ![Example1](link_to_image)
- Bonus part example with minimap, floor/ceiling textures, and animated sprite: ![Example2](link_to_image)
---->
## Conclusion

Cub3D is a challenging project that combines graphics, mathematics, and programming skills. By following the principles of Ray-Casting, it provides a hands-on experience in creating a 3D maze. Explore the possibilities, be creative with textures, and enjoy the journey of building your first RayCaster with miniLibX.
