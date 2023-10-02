<!DOCTYPE html>
<html>
<body>
  <h1>Cub3D Project :</a></h1>
  <p>Welcome to the Cub3D project !</p>
  <p>This project is the discovery of <a href="https://fr.wikipedia.org/wiki/Raycasting">Raycasting</a> and a deeper dive into the <a href="https://github.com/42Paris/minilibx-linux">MLX42</a>.</p>
  
  <h2>Project Description</h2>
  <p>You must create a “realistic” 3D graphical representation of the inside of a maze from a first-person perspective. 
      You have to create this representation using the Ray-Casting principles:</p>
  <ol>
    <li>
      <strong>Map Exemple:</strong>
    <table>
      <tr><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td></tr>
      <tr><td>1</td><td>0</td><td>0</td><td>0</td><td>0</td><td>1</td></tr>
      <tr><td>1</td><td>0</td><td>1</td><td>0</td><td>0</td><td>1</td></tr>
      <tr><td>1</td><td>0</td><td>1</td><td>0</td><td><strong>P<strong></td><td>1</td></tr>
      <tr><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td><td>1</td></tr>
    </table>
    </li>
    <li>
      <strong>Raycasting:</strong>
    </li>
      <img src="https://play-lh.googleusercontent.com/HXhTE6XEpW-rjidz_efz8prDveFF57tl3dfhaeBhBWdVMtJARZQKJELt52Sdr20nuw" alt="RayCasting on map" width="215">
  </ol>
  <h2>Project Requirements</h2>
  <ul>
    <li>The management of your window must remain smooth.</li>
    <li>Display different wall textures (NSEW).</li>
    <li>Take a ".cub" map file as an argument (be sure to check if it is in fact a file and not a dir).</li>
    <li>Pressing ESC or clicking the red cross must close the window and quit the program cleanly.</li>
    <li>The map must be closed/surrounded by walls.</li>
    <li>The map need one and ONLY one player (P=NSEW).</li>
    <li>Before the map itself, the configuration file will give the path for every textures and the color of the floor and ceiling.</li>
  </ul>

  <h2>Getting Started</h2>
  <ol>
    <li>Parse the map according to the rules given (most errors comes from the parsing).</li>
    <li>Start the raycasting represented on a minimap (free bonus btw).</li>
    <li>Finish by displaying everything needed.</li>
    <li>For the bonuses:
      <ul>- Wall colisions are important but make sure not to crash when colisions aren't on.</ul>
      <ul>- Animated sprite takes more time but might be fun.</ul>
      <ul>- As I said earlier, the minimap helps you understand the raycasting and doesnt take much time so try to do it.</ul>
      <ul>- It is easy to rotate the POV with the mouse, but the MLX causes leaks when trying to lock the mouse on the window or making it disappear so don't lose too much time on this one.</ul>
    </li>
  </ol>

  <h2>Resources</h2>
  <ul>
    <li><a href="https://lodev.org/cgtutor/raycasting.html">Lodev's Tutorial</a></li>
    <li><a href="https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html">MLX Documentation</a></li>

</body>
</html>
