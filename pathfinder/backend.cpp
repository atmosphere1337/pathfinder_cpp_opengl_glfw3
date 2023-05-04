#include <iostream>
#include "backend_header.h"

const int maze_example1[10][13] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,1,0,1,0,1,0,0,0,0,0,1},
  {1,0,1,0,0,0,1,0,1,1,1,0,1},
  {1,0,0,0,1,1,1,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,1,1,1,0,1},
  {1,0,1,0,1,1,1,0,1,0,0,0,1},
  {1,0,1,0,1,0,0,0,1,1,1,0,1},
  {1,0,1,0,1,1,1,0,1,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1},
};
const int maze_example1_height = 10;
const int maze_example1_width = 13;

backend::backend(void)
{
	map_memory_alloc(maze_example1_height, maze_example1_width);
	for (int i = 0; i < map_height; i++)
		for (int j = 0; j < map_width; j++)
			map[i][j] = maze_example1[i][j];
}
void backend::map_random_generate(int height, int width)
{
	

}
void backend::dijkstra(void)
{

}
void backend::astar(void)
{

}








void backend::map_memory_free(void)
{
	for (int i = 0; i < map_height; i++)
		delete[] map[i];
	delete[] map;
	map = nullptr;
	map_width = 0;
	map_height = 0;
}
void backend::map_memory_alloc(int height, int width)
{
	map_width = width;
	map_height = height;
	map = new int*[height];
	for (int i = 0; i < height; i++)
		map[i] = new int[width];
}
void backend::map_print(void)
{
	for (int i = 0; i < map_height; i++, std::cout << std::endl)
		for (int j = 0; j < map_width; j++)
			std::cout << map[i][j] << " ";
}