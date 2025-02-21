# so_long

## Description
**so_long** is a 2D game built using the **MiniLibX** library. The game involves navigating a player through a map to collect all collectibles and reach the exit while avoiding obstacles. The game is inspired by classic maze-based games and serves as an introduction to graphical programming in **C**.

## Features
- The game reads a map file (**.ber**) and renders a 2D world.
- The player can move **up, down, left, and right**.
- The goal is to collect all collectibles (**C**) and then reach the exit (**E**).
- The number of movements is displayed in the terminal.
- The game window is created using **MiniLibX**, and textures are displayed from **XPM** files.

## Controls
- **W** or **↑**: Move up
- **S** or **↓**: Move down
- **A** or **←**: Move left
- **D** or **→**: Move right
- **ESC**: Quit the game

## Mandatory Part
- The game correctly parses and validates the map.
- The map must be surrounded by walls and contain at least one **C**, one **E**, and one player start position (**P**).
- The player can move only through valid paths.
- The game closes properly when the player reaches the exit after collecting all items.

## Bonus Features
In the bonus part, additional features enhance the gameplay:
- **Enemy Movement:** Enemies (**M**) patrol left and right, making the game more challenging.
- **Game Over Mechanic:** If the player touches an enemy, the game ends.
- **Animated Sprites:** The player and enemies have animations for more dynamic visuals.
- **On-Screen Move Counter:** Instead of displaying moves in the terminal, they are rendered directly on the game screen.
- **Improved Graphics:** Enhanced rendering and smoother gameplay with additional visual elements.

## Compilation
To build the project, run:
```sh
make
```
For the bonus version:
```sh
make Bonus
```
To clean object files:
```sh
make clean
```
To remove binaries and object files:
```sh
make fclean
```
To recompile everything:
```sh
make re
```

## How to Play
Run the game with:
```sh
./so_long maps/map.ber
```
For the bonus version:
```sh
./so_long_Bonus maps/map.ber
```

## Dependencies
- **MiniLibX**: Ensure you have it installed.
- **X11** and **Xext** libraries are required for graphics rendering.

## Author
**Yhajji** - 42 Network

