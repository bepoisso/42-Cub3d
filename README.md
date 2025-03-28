<div align="center">
  <img height="200" src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/cub3d.png"  />
</div>

# Cub3D - 3D Game Engine

Cub3D is a project that introduces you to the basics of 3D rendering using the Raycasting technique, inspired by the classic Wolfenstein 3D game. The goal is to create a simple first-person perspective game engine.

## Status
<div align="center">
  <img height="200" src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/cub3d_success.png"  />
</div>

## Example
<div align="center">
  <img src="https://raw.githubusercontent.com/Benjamin-poisson/My_image_bank/refs/heads/main/cub3d_exp.png"  />
</div>

## Objectives

The goal of this project is to create a basic 3D engine using raycasting, allowing the user to navigate in a maze-like environment. You will work with graphical libraries, handle player movement, and implement texture rendering.

## Great Resources

<li><a href="https://lodev.org/cgtutor/raycasting.html">Lode’s Computer Graphics Tutorial - Raycasting</a></li>
<li><a href="https://harm-smits.github.io/42docs/libs/minilibx">MiniLibX Documentation</a></li>
<li><a href="http://users.atw.hu/wolf3d/">Try Wolfenstein 3D</a></li>

## Mandatory

<table>
  <tr>
    <th>Program name</th>
    <td>cub3D</td>
  </tr>
  <tr>
    <th>Turn in files</th>
    <td>All necessary files to compile the program</td>
  </tr>
  <tr>
    <th>Makefile</th>
    <td>Yes</td>
  </tr>
  <tr>
    <th>External functions</th>
    <td>open, close, read, write, malloc, free, perror, strerror, exit</td>
  </tr>
  <tr>
    <th>MinilibX</th>
    <td>Yes</td>
  </tr>
  <tr>
    <th>Description</th>
    <td>Develop a simple 3D game engine using raycasting in a maze-like environment.</td>
  </tr>
</table>

- The project must be written in C.
- The code must follow the Norm.
- No memory leaks are tolerated.
- Provide a Makefile with rules for `all`, `clean`, `fclean`, and `re`.
- Use MiniLibX for graphical rendering.
- Implement player movement and wall collisions.
- Render textures for walls and floor/ceiling.

## Functionality

- **Raycasting Algorithm:** Implement a simple raycasting algorithm to simulate 3D perspective.
- **Map Parsing:** Read a `.cub` configuration file to generate the game environment.
- **Player Movement:** Handle keyboard inputs to move the player within the maze.
- **Rendering:** Display walls with textures and basic lighting effects.
- **Collisions:** Ensure the player cannot walk through walls.

### Example Usage

```bash
$ ./cub3D maps/example.cub
```

---

## Bonuses

If the mandatory part is completed perfectly, consider the following bonus features:

- **Sprite Rendering:** Implement object rendering (e.g., enemies, collectibles).
- **Mini-map:** Display a 2D mini-map to show the player's position.
- **Door System:** Add openable doors in the maze.
- **Lighting Effects:** Implement simple shading or fog of war.

Bonus files should be named with the `_bonus` suffix.

---

## Key Concepts to Master

- **Raycasting:** Understanding the fundamentals of 3D rendering in a 2D plane.
- **File Parsing:** Reading and processing configuration files.
- **Graphics Programming:** Working with MiniLibX for rendering.
- **Memory Management:** Avoiding leaks and ensuring optimized performance.

---

## Example Output

```bash
$ ./cub3D maps/level1.cub
Rendering game window...
Player moves with WASD keys.
```

This output represents the correct behavior of the program, where a 3D maze environment is generated, and the player can navigate using keyboard inputs.
