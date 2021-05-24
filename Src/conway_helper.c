#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "helper.h"
#include <SDL.h>


//intializes map based on start position input
void init_map(Map map_array, int start_position)
{
    if (start_position == 0)
    {
        //randomize starting population
        srand(time(NULL));
        int pop = rand() % (MAP_SIZE * MAP_SIZE);

        //randomize starting positions
        for (int i = 0; i < pop; i++)
        {
            int x = rand() % (MAP_SIZE - 1);
            int y = rand() % (MAP_SIZE - 1);

            map_array[x][y] = 1;
        }
    }
    else if (start_position == 1)
    {
        //glider 
        map_array[6][15] = 1;
        map_array[6][16] = 1;
        map_array[6][17] = 1;
        map_array[5][17] = 1;
        map_array[4][16] = 1;

    }
    else if (start_position == 2)
    {
        //glider gun
        map_array[18][1] = 1;
        map_array[18][2] = 1;
        map_array[19][1] = 1;
        map_array[19][2] = 1;
        map_array[18][11] = 1;
        map_array[19][11] = 1;
        map_array[20][11] = 1;
        map_array[17][12] = 1;
        map_array[21][12] = 1;
        map_array[16][13] = 1;
        map_array[16][14] = 1;
        map_array[22][13] = 1;
        map_array[22][14] = 1;
        map_array[19][15] = 1;
        map_array[17][16] = 1;
        map_array[21][16] = 1;
        map_array[18][17] = 1;
        map_array[19][17] = 1;
        map_array[20][17] = 1;
        map_array[19][18] = 1;
        map_array[16][21] = 1;
        map_array[17][21] = 1;
        map_array[18][21] = 1;
        map_array[16][22] = 1;
        map_array[17][22] = 1;
        map_array[18][22] = 1;
        map_array[15][23] = 1;
        map_array[19][23] = 1;
        map_array[14][25] = 1;
        map_array[15][25] = 1;
        map_array[19][25] = 1;
        map_array[20][25] = 1;
        map_array[16][35] = 1;
        map_array[17][35] = 1;
        map_array[16][36] = 1;
        map_array[17][36] = 1;
    }
    else if (start_position == 3)
    {
        //space ship
        map_array[62][33] = 1;
        map_array[62][34] = 1;
        map_array[62][35] = 1;
        map_array[62][37] = 1;
        map_array[63][37] = 1;
        map_array[64][37] = 1;
        map_array[61][38] = 1;
        map_array[61][39] = 1;
        map_array[61][40] = 1;
        map_array[63][41] = 1;
        map_array[66][40] = 1;
        map_array[67][40] = 1;
        map_array[71][40] = 1;
        map_array[68][41] = 1;
        map_array[70][41] = 1;
        map_array[72][41] = 1;
        map_array[67][42] = 1;
        map_array[68][42] = 1;
        map_array[64][43] = 1;
        map_array[65][43] = 1;
        map_array[68][43] = 1;
        map_array[69][43] = 1;
        map_array[63][44] = 1;
        map_array[65][44] = 1;
        map_array[66][44] = 1;
        map_array[68][44] = 1;
        map_array[62][45] = 1;
        map_array[68][45] = 1;
        map_array[62][46] = 1;
        map_array[68][46] = 1;
        map_array[63][47] = 1;
        map_array[65][47] = 1;
        map_array[66][47] = 1;
        map_array[68][47] = 1;
        map_array[64][48] = 1;
        map_array[65][48] = 1;
        map_array[68][48] = 1;
        map_array[69][48] = 1;
        map_array[67][49] = 1;
        map_array[68][49] = 1;
        map_array[63][50] = 1;
        map_array[68][50] = 1;
        map_array[70][50] = 1;
        map_array[72][50] = 1;
        map_array[61][51] = 1;
        map_array[66][51] = 1;
        map_array[67][51] = 1;
        map_array[71][51] = 1;
        map_array[61][52] = 1;
        map_array[61][53] = 1;
        map_array[62][54] = 1;
        map_array[63][54] = 1;
        map_array[64][54] = 1;
        map_array[62][56] = 1;
        map_array[62][57] = 1;
        map_array[62][58] = 1;
    }

}


//updates map to next generation 
void update_map(Map map_array, int* generation_p, int* pop)
{
    //creates new temp array
    Map tmp = {0};

    //updates map 
    for (int y = 0; y < MAP_SIZE; y++)
    {
        for (int x = 0; x < MAP_SIZE; x++)
        {
            int count_neighbour = 0;

            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    //continues if it is out of array bounds
                    if (y - 1 + a < 0 || y - 1 + a > MAP_SIZE - 1 || x - 1 + b < 0 || x - 1 + b > MAP_SIZE - 1)
                    {
                        continue;
                    }

                    //counts value of neighbour
                    count_neighbour += map_array[y - 1 + a][x - 1 + b];
                }
            }

            //update tmp based on if live or dead
            if (map_array[y][x] == 0)
            {
                if (count_neighbour == 3)
                {
                    tmp[y][x] = 1;
                }
            }
            else
            {
                if (count_neighbour == 3 || count_neighbour == 4)
                {
                    tmp[y][x] = 1;
                }
                else
                {
                    tmp[y][x] = 0;
                }
            }
        }
    }

    //copies tmp back to map
    copy_map(map_array, tmp);

    //updates generation
    *generation_p += 1;

    //updates population count
    count_pop(map_array, pop);

}

//transfer tmp map back to original
void copy_map(Map map_array, Map tmp_array)
{
    for (int y = 0; y < MAP_SIZE; y++)
    {
        for (int x = 0; x < MAP_SIZE; x++)
        {
            if (tmp_array[y][x] == 1)
            {
                map_array[y][x] = 1;
            }
            else
            {
                map_array[y][x] = 0;
            }
        }
    }
}

//counts population
void count_pop(Map map_array, int* pop)
{
    int current_pop = 0;

    for (int y = 0; y < MAP_SIZE; y++)
    {
        for (int x = 0; x < MAP_SIZE; x++)
        {
            current_pop += map_array[y][x];
        }
    }

    *pop = current_pop;
}

