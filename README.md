# Conway's Game of Life
This is a pure c implementation of Conway's Game of Life. It uses the SDL/ SDL2 library to display the game in a window.

# How It Works
Conway's Game of Life is a cellular automataton simulation on a 2D grid, where each cell has two possible states: dead or alive. Each cell has neighbours in every direction including diagonally (eight neighbours total). The simulation follows these rules:
1) A live cell with less than two neighbours dies (isolation).
2) A live cell with two or three neighbours survives (survival).
3) A cell with more than three neighbours dies (overpopulation).
4) A dead cell with exactly three neighbours becomes alive (reproduction).

These rules are applied before every generation and are then displayed. Even with these simple rules complexity emerges, and based on starting positions different patterns can emerge. 

# Demo
Currently only some start patterns are supported. The default start is a random simulation. However, passing 'g' as a command line argument will start with the glider pattern, 'gg' is the glider gun, and 'ss' is the spaceship.

<iframe src="https://giphy.com/embed/btHvxRGcKPJep8LTri" width="480" height="478" frameBorder="0" class="giphy-embed" allowFullScreen></iframe><p><a href="https://giphy.com/gifs/btHvxRGcKPJep8LTri">via GIPHY</a></p>


