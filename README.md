# Conway's Game of Life
This is a pure C implementation of Conway's Game of Life. It uses the SDL/ SDL2 library to display the game in a window.

# How It Works
Conway's Game of Life is a cellular automataton simulation on a 2D grid, where each cell has two possible states: dead or alive. Each cell has neighbours in every direction including diagonally (eight neighbours total). The simulation follows these rules:
1) A live cell with less than two neighbours dies (isolation)
2) A live cell with two or three neighbours survives (survival)
3) A cell with more than three neighbours dies (overpopulation)
4) A dead cell with exactly three neighbours becomes alive (reproduction)

These rules are applied before every generation and are then displayed. Even with these simple rules complexity emerges, and based on starting positions different patterns can form. 

# Demo
The default start is a random simulation. However, passing 'g' as a command line argument will start with the glider pattern, 'gg' is the glider gun, and 'ss' is the spaceship. You can also use the left arrow key to slow down the simulation and the right arrow key to speed it up.

<p align="center">
  <img width="506" height="506" src="https://github.com/Hamoudi0427/Conway-s-Game-of-Life/blob/main/Img/random.gif">
</p>


<p align="center">
  <img width="506" height="504" src="https://github.com/Hamoudi0427/Conway-s-Game-of-Life/blob/main/Img/gildergun.gif">
</p>


<p align="center">
  <img width="506" height="508" src="https://github.com/Hamoudi0427/Conway-s-Game-of-Life/blob/main/Img/spaceship.gif">
</p>

# Download and Installation

1) Download files found in src (3 files in total)
2) Download and link SDL2 and add SDL2.dll to the project folder. A helpful tutorial can be found here: https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php
3) Compile the program and run (to run different patterns use the command line arguments found above)

# To - Do
1) Gosper's Algorithmn for efficiency 
2) Add more patterns
