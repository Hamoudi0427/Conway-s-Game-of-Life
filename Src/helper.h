//function prototypes and constants
#define MAP_SIZE 100
typedef int Map[MAP_SIZE][MAP_SIZE];
void init_map(Map map_array, int start_position);
void update_map(Map map_array, int* generation_p, int* pop);
void copy_map(Map map_array, Map tmp_array);
void count_pop(Map map_array, int* pop);