#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conway_helper.h"
#include <SDL.h>
#include <string.h>


int main(int argc, char* argv[])
{
    //Intro
    printf("Welcome to Conway's Game of Life!\n");
    printf("There are two rules:\n");
    printf("1) A live cell remains alive if it has two or three neighbours. \n");
    printf("2) A dead cell becomes alive if it has exactly three neighbours. \n");
    printf("You can press the left arrow key to slow down the simulation or the right arrow key to speed up the simulation. \n");
    SDL_Delay(7000);
    printf("The simulation will now begin.\n");
    SDL_Delay(2000);
    
    //simulation options, with random generation being the default
    int start_pos = 0;
    if (argc == 2)
    {
        if (strcmp(argv[1], "g") == 0)
        {
            //glider
            start_pos = 1;
        }
        else if (strcmp(argv[1], "gg") == 0)
        {
            //glider gun
            start_pos = 2;
        }
        else if (strcmp(argv[1], "ss") == 0)
        {
            //space ship
            start_pos = 3;
        }
    }
    
    //SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window* screen = SDL_CreateWindow("Conway's Game of Life", 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        500, 500,
        0);
    if (!screen) {
        fprintf(stderr, "Could not create window\n"); 
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_SOFTWARE); //creates renderer (part that draws)
    if (!renderer) {
        fprintf(stderr, "Could not create renderer\n");
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255); //sets renderer colour
    SDL_RenderClear(renderer); //clears window
    SDL_RenderPresent(renderer); //renders image on screen (draws)

    //simulation initialization
    Map map_array = {0};
    int generation = 0;
    int* generation_p = &generation;
    int population = 0;
    int* population_p = &population;
    int run_sim = 0;
    int sim_speed = 300;

    //initializes map and population
    init_map(map_array, start_pos);
    count_pop(map_array, population_p);

    //running simulation
    while (run_sim == 0)
    {
        for (int y = 0; y < MAP_SIZE; y++)
        {
            for (int x = 0; x < MAP_SIZE; x++)
            {
                //create a rectangle 
                SDL_Rect cell;
                cell.x = (x * 5);
                cell.y = (5 * y);
                cell.w = 5;
                cell.h = 5;

                //check if cell is alive or dead
                if (map_array[y][x] == 0)
                {
                    SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);
                }
                else
                {
                    SDL_SetRenderDrawColor(renderer, 211, 146, 175, 255);
                }

                //fill rectangle
                SDL_RenderFillRect(renderer, &cell);
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(sim_speed);
        SDL_RenderClear(renderer);
        update_map(map_array, generation_p, population_p);

        //processes quitting and simulation speed 
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                run_sim = 1;
                printf("Amount of Simulated Generations: %d\n", generation);
                printf("Final population: %d\n", population);
                printf("Thank you for playing Conway's Game of Life! Perhaps try another simulation.\n");
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:
                    if (sim_speed < 500)
                    {
                        sim_speed += 100;
                    }
                    break;
                case SDLK_RIGHT: 
                    if (sim_speed > 100)
                    {
                        sim_speed -= 100;
                    }
                    break;
                default:
                    break;
                }
            }
            
        }
        
    }
    
    //closes SDL window and quits
    SDL_Delay(1000);
    SDL_DestroyWindow(screen);
    SDL_Quit();
    return 0;
}

