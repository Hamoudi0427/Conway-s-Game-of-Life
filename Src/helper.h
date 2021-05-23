//function prototypes and constants
#define MAP_SIZE 100
void init_map(int map_array[100][100], int start_position);
void update_map(int map_array[100][100], int* generation_p, int* pop);
void copy_map(int map_array[100][100], int tmp_array[100][100]);
void count_pop(int map_array[100][100], int* pop);