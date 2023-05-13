#include <iostream>
#include "backend_header.h"
#include <queue>
#include <stack>

const int maze_example1[10][13] = {
  {0,1,1,1,1,1,1,1,1,1,1,1,1},
  {0,0,1,0,1,0,1,0,0,0,0,0,1},
  {1,0,1,0,0,0,1,0,1,1,1,0,1},
  {1,0,0,0,1,1,1,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,1,1,1,0,1},
  {1,0,1,0,1,1,1,0,1,0,0,0,1},
  {1,0,1,0,1,0,0,0,1,1,1,0,1},
  {1,0,1,0,1,1,1,0,1,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,1,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,0,0},
};
const int maze_example1_height = 10;
const int maze_example1_width = 13;
point backend::ways_shift[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

backend::backend(void)
{
	map_memory_alloc(maze_example1_height, maze_example1_width);
	for (int i = 0; i < map_height; i++)
		for (int j = 0; j < map_width; j++)
			map[i][j] = maze_example1[i][j];
	start_x = 0;
	start_y = 0;
	end_x = map_width - 1;
	end_y = map_height - 1;
	map[start_y][start_x] = 2;
	map[end_y][end_x] = 3;
}
bool backend::dfs()
{
	path.clear();
	std::map<point, point> backwards_map;
	std::stack<point> stck;
	stck.push({start_y, start_x});
	point buf;
	int x, y;
	while (stck.size() != 0)
	{
		buf = stck.top();
		y = buf.y;
		x = buf.x;
		stck.pop();
		if (map[y][x] == 3)
		{
			while (buf.y != start_y || buf.x != start_x)
			{
				buf = backwards_map[buf];
				path.push_back(buf);
			}
			if (path.size() > 1)
				path.pop_back();
			clear_map_paths();
			show_path();
			return true;
		}
		for (int i = 0; i < 4; i++)
		{
			if (bounds_check(i, y, x) && (map[y + ways_shift[i].y][x + ways_shift[i].x] == 0 || map[y + ways_shift[i].y][x + ways_shift[i].x] == 3))
			{
				backwards_map[{y + ways_shift[i].y, x + ways_shift[i].x}] = {y, x};
				stck.push({y + ways_shift[i].y, x + ways_shift[i].x});
				if (map[y + ways_shift[i].y][x + ways_shift[i].x] == 0)
					map[y + ways_shift[i].y][x + ways_shift[i].x] = 4;
			}
		}

	}
	return false;
}
bool backend::bfs()
{
	path.clear();
	std::map<point, point> backwards_map;
	std::queue<point> que;
	que.push({start_y, start_x});
	point buf;
	int x, y;
	while (que.size() != 0)
	{
		buf = que.front();
		y = buf.y;
		x = buf.x;
		que.pop();
		if (map[y][x] == 3)
		{
			while (buf.y != start_y || buf.x != start_x)
			{
				buf = backwards_map[buf];
				path.push_back(buf);
			}
			if (path.size() > 1)
				path.pop_back();
			clear_map_paths();
			show_path();
			return true;
		}
		for (int i = 0; i < 4; i++)
		{
			if (bounds_check(i, y, x) && (map[y + ways_shift[i].y][x + ways_shift[i].x] == 0 || map[y + ways_shift[i].y][x + ways_shift[i].x] == 3))
			{
				backwards_map[{y + ways_shift[i].y, x + ways_shift[i].x}] = {y, x};
				que.push({y + ways_shift[i].y, x + ways_shift[i].x});
				if (map[y + ways_shift[i].y][x + ways_shift[i].x] == 0)
					map[y + ways_shift[i].y][x + ways_shift[i].x] = 4;
			}
		}
	}
	clear_map_paths();
	return false;
}
int** backend::map_get(int& height, int& width)
{
	height = map_height;
	width = map_width;
	return map;
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
void backend::clear_map_paths()
{
	for (int i = 0; i < map_height; i++)
		for (int j = 0; j < map_width; j++)
		{
			if (map[i][j] == 4 || map[i][j] == 5)
				map[i][j] = 0;
		}
}
void backend::show_path()
{
	for (int i = 0; i < path.size(); i++)
		map[path[i].y][path[i].x] = 5;
}
bool backend::bounds_check(int border_way, int y, int x)
{
	switch (border_way)
	{
		case 0:
			return x < map_width - 1;
		case 1:
			return y < map_height - 1;
		case 2:
			return y > 0;
		case 3:
			return x > 0;
		default:
			 break;
	}
	return false;
}
void backend::set_start(int y, int x)
{
	if (map[y][x] != 1 && y >= 0 && y < map_height && x >= 0 && x < map_width)
	{
		map[start_y][start_x] = 0;
		start_x = x;
		start_y = y;
		map[y][x] = 2;
	}
}
bool operator<(const point & p1, const point & p2)
{
	if (p1.y < p2.y)
		return true;
	else if (p1.y == p2.y)
	{
		return p1.x < p2.x;
	}
	else
		return false;
}

