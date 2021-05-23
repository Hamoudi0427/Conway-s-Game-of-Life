# Conway's Game of Life
This is a pure C implementation of Conway's Game of Life. It uses the SDL/ SDL2 library to display the game in a window.

# How It Works
Conway's Game of Life is a cellular automataton simulation on a 2D grid, where each cell has two possible states: dead or alive. Each cell has neighbours in every direction including diagonally (eight neighbours total). The simulation follows these rules:
1) A live cell with less than two neighbours dies (isolation).
2) A live cell with two or three neighbours survives (survival).
3) A cell with more than three neighbours dies (overpopulation).
4) A dead cell with exactly three neighbours becomes alive (reproduction).

These rules are applied before every generation and are then displayed. Even with these simple rules complexity emerges, and based on starting positions different patterns can emerge. 

# Demo
Currently only some start patterns are supported. The default start is a random simulation. However, passing 'g' as a command line argument will start with the glider pattern, 'gg' is the glider gun, and 'ss' is the spaceship. You can also use the left arrow key to slow down the simulation and the right arrow key to speed it up.

<p align="center">
  <img width="506" height="506" src="https://github.com/Hamoudi0427/Conway-s-Game-of-Life/blob/main/Img/random.gif">
</p>


<p align="center">
  <img width="506" height="504" src="https://github.com/Hamoudi0427/Conway-s-Game-of-Life/blob/main/Img/gildergun.gif">
</p>


<p align="center">
  <img width="506" height="508" src="https://github.com/Hamoudi0427/Conway-s-Game-of-Life/blob/main/Img/spaceship.gif">
</p>
