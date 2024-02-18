Cub3D Project :
===============

Welcome to the Cub3D project !

This project is the discovery of [Raycasting](https://fr.wikipedia.org/wiki/Raycasting) and a deeper dive into the [MLX42](https://github.com/42Paris/minilibx-linux).

Project Description
-------------------

You must create a “realistic” 3D graphical representation of the inside of a maze from a first-person perspective. You have to create this representation using the Ray-Casting principles:
1.  **Map Exemple:**
    
    | 1   | 1   | 1   | 1   | 1   | 1   |
    | --- | --- | --- | --- | --- | --- |
    | 1   | 0   | 0   | 0   | 0   | 1   |
    | 1   | 0   | 1   | 0   | 0   | 1   |
    | 1   | 0   | 1   | 0   | **P** | 1   |
    | 1   | 1   | 1   | 1   | 1   | 1   |
 
2.  **Raycasting:**
<p><img src="https://play-lh.googleusercontent.com/HXhTE6XEpW-rjidz_efz8prDveFF57tl3dfhaeBhBWdVMtJARZQKJELt52Sdr20nuw" alt="RayCasting on map" width="215"></p>

Project Requirements
--------------------

* The management of your window must remain smooth.
* Display different wall textures (NSEW).
* Take a ".cub" map file as an argument (be sure to check if it is in fact a file and not a dir).
* Pressing ESC or clicking the red cross must close the window and quit the program cleanly.
* The map must be closed/surrounded by walls.
* The map need one and ONLY one player (P=NSEW).
* Before the map itself, the configuration file will give the path for every textures and the color of the floor and ceiling.

Getting Started
---------------

1.  Parse the map according to the rules given (most errors comes from the parsing).
2.  Start the raycasting represented on a minimap (free bonus btw).
3.  Finish by displaying everything needed.
4.  For the bonuses:
    - Wall colisions are important but make sure not to crash when colisions aren't on.
    - Animated sprite takes more time but might be fun.
    - As I said earlier, the minimap helps you understand the raycasting and doesnt take much time so try to do it.
    - It is easy to rotate the POV with the mouse, but the MLX causes leaks when trying to lock the mouse on the window or making it disappear so don't lose too much time on this one.

Resources
---------

* [Lodev's Tutorial](https://lodev.org/cgtutor/raycasting.html)
* [MLX Documentation](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
