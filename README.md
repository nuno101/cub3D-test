# cub3D
My first RayCaster with MLX42

( ͡° ͜ʖ ͡°) 

Requirements summary:

1. Smooth window management
  - minimise window
  - change to another window and back
  - ESC or clicking on red cross on the window’s frame closes the window and quits the program cleanly

2. Use different wall textures for each wall
  - North, South, East, West

3. Support different floor and ceiling colors

4. Window image
  - left and right arrows allow to look left and right
  - W, A, S, and D keys allow to move the point of view

4. Map file requirements
  - blank lines allowed between elements
  - blank spaces allowed within each element definition, except for the map
  - map element must be last in map file

4.1. Non map elements requirements:
  - \<type identifier\> \<any number of spaces\> \<definition\>
  - For textures:
    - \<(NO|SO|WE|EA)\> \<any number of spaces\> \<texture filepath\>
  - For colors:
    - <(F|C)> \<any number of spaces\> \<R,G,B\>
      - each R,G,B parameter must be in range [0,255]

4.2 Map element requirements:
  - only 6 possible characters:
  - 0 for an empty space
  - 1 for a wall
  - N,S,E or W for the player’s start position and spawning orientation
  - map must be closed/surrounded by walls
  - map must be parsed as it looks in the file

# Notes:

- Only push when make is working without errors

# TODOs:

1. Leaks at some exitpoints found

2. Edgecases:
- search and fix edgecases!
