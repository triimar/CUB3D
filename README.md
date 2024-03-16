CUB3D - adventures in raycasting
Overview
CUB3D is a project strongly inspired by Wolfenstein 3D game. Raycasting is used to create a walled space where the "palyer" can move around.

This CUB3D uses MLX42 graphics library version 2.2.1. It has been created in cooperation with Christina Repou

Bonus
Bonus version of the program implements a minimap in the left upper corner of the window and includes doors that can be opened and closed. Movement is smoother because wall collisions are avoided and viewpoint can be changed with the use of the mouse.

Actions
left and right arrow keys allow the player to look left and right
W, A, S, and D keys move the player forward, left, right and backward within the maze.
Pressing ESC or clicking the X ont he window closes the window and quits the program.

Added to the bonus:

SPACE bar opens and closes the doors.
MOUSE movement within the window allows to rotate the point of view.

Running the Program(s)
./cub3d <.cub_file_for_input>
./cub3d_bonus <.cub_file_for_input>: Validates the sorting actions and returns success or failure.