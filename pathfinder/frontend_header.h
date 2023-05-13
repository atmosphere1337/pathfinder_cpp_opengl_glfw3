#pragma once
#include <vector>
#include <iostream>
#include "include/GLFW/glfw3.h"
#include "include/GLFW/glfw3native.h"
#include "backend_header.h"
class frontend
{
	private:
		float shift_x, shift_y;
		float origin_x, origin_y;
		int size_x, size_y;
		int window_width, window_height;
	public:
		frontend(int width, int height);
		void system_mount(int y, int x);
		void print_grid(void);
		void print_cell(int y, int x, int color);
		void print_field(int ** input_map, int input_height, int input_width);
		bool translate_pixels_to_cells(float in_y, float in_x, int & out_y, int & out_x);//
};
