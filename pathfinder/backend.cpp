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
	std::stack<int> stck;
	stck.push(start_x);
	stck.push(start_y);
	int x, y;
	while (stck.size() != 0)
	{
		y = stck.top();
		stck.pop();
		x = stck.top();
		stck.pop();
		if (map[y][x] == 3)
		{
			return true;
		}
		if ((x < map_width - 1) && (map[y][x + 1] == 0 || map[y][x + 1] == 3))
		{
			stck.push(x + 1);
			stck.push(y);
			if (map[y][x + 1] == 0)
				map[y][x + 1] = 4;
		}
		if ((y < map_height - 1) && (map[y + 1][x] == 0 || map[y + 1][x] == 3))
		{
			stck.push(x);
			stck.push(y + 1);
			if (map[y + 1][x] == 0)
				map[y + 1][x] = 4;
		}
		if ((y > 0) && (map[y - 1][x] == 0 || map[y - 1][x] == 3))
		{
			stck.push(x);
			stck.push(y - 1);
			if (map[y - 1][x] == 0)
				map[y - 1][x] = 4;
		}
		if ((x > 0) && (map[y][x - 1] == 0 || map[y][x - 1] == 3))
		{
			stck.push(x - 1);
			stck.push(y);
			if (map[y][x - 1] == 0)
				map[y][x - 1] = 4;
		}
	}
	return false;
}
bool backend::bfs()
{
	std::map<point, point> backwards_map;
	std::queue<point> que2;
	que2.push({start_x, start_y});
	point buf;
	int x, y;
	while (que2.size() != 0)
	{
		buf = que2.front();
		y = buf.y;
		x = buf.x;
		que2.pop();
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
		if ((x < map_width - 1) && (map[y][x + 1] == 0 || map[y][x + 1] == 3))
		{
			backwards_map[{y, x + 1}] = {y, x};
			que2.push({y, x + 1});
			if (map[y][x + 1] == 0)
				map[y][x + 1] = 4;
		}
		if ((y < map_height - 1) && (map[y + 1][x] == 0 || map[y + 1][x] == 3))
		{
			backwards_map[{y + 1, x}] = {y, x};
			que2.push({y + 1, x});
			if (map[y + 1][x] == 0)
				map[y + 1][x] = 4;
		}
		if ((y > 0) && (map[y - 1][x] == 0 || map[y - 1][x] == 3))
		{
			backwards_map[{y - 1, x}] = {y, x};
			que2.push({y - 1, x});
			if (map[y - 1][x] == 0)
				map[y - 1][x] = 4;
		}
		if ((x > 0) && (map[y][x - 1] == 0 || map[y][x - 1] == 3))
		{
			backwards_map[{y, x - 1}] = {y, x};
			que2.push({y, x - 1});
			if (map[y][x - 1] == 0)
				map[y][x - 1] = 4;
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

