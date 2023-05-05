#pragma once
class backend
{
	private:
		int **map;
		unsigned int map_height, map_width;
		int start_x, start_y, end_x, end_y;
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
};

