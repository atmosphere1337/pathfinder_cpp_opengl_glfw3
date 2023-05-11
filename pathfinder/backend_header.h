#pragma once
#include <map>
#include <vector>
struct point {	int y;	int x; };
bool operator<(const point& p1, const point& p2);

class backend
{
	private:
		int **map;
		unsigned int map_height, map_width;
		int start_x, start_y, end_x, end_y;
		std::vector<point> path;
		void map_memory_free(void);
		void map_memory_alloc(int height, int width);
	public:
		backend(void);
		void map_random_generate(int height, int width);
		bool dfs();
		bool bfs();
		void dijkstra(void);
		void astar(void);
		void map_print(void);
		int** map_get(int& input_height, int& input_width);
		void show_path();
		void clear_map_paths();
};

