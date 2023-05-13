#include "frontend_header.h"

frontend::frontend(int width, int height)
{
	window_height = height;
	window_width = width;
	system_mount(10, 10);
}
void frontend::system_mount(int y, int x)
{
	origin_x = -0.8;
	origin_y = -0.8;
	float end_x = -origin_x;
	float end_y = -origin_y;
	shift_x = (end_x - origin_x) / (float)x;
	shift_y = (end_y - origin_y) / (float)y;
	size_x = x;
	size_y = y;
}
void frontend::print_grid(void)
{
	for (int i = 0; i <= size_x; i++)
		for (int j = 0; j <= size_y; j++)
		{
			glBegin(GL_LINES);
				glColor3f(1.0, 1.0, 1.0);
				glVertex2f(origin_x + i * shift_x, origin_y);
				glVertex2f(origin_x + i * shift_x, -origin_y);
				glVertex2f(origin_x, origin_y + j * shift_y);
				glVertex2f(-origin_x, origin_y + j * shift_y);
			glEnd();
		}
}
void frontend::print_cell(int y, int x, int color)
{
	float start_x = origin_x + shift_x * x;
	float start_y = origin_y + (size_y - y - 1) * shift_y;
	glBegin(GL_QUADS);
		if (color == 0)
			glColor3f(1.0, 1.0, 1.0);
		else if (color == 1)
			glColor3f(0.3, 0.3, 0.3);
		else if (color == 5)
			glColor3f(0.0, 0.0, 1.0);
		else 
			glColor3f(1.0, 0.0, 0.0);
		glVertex2f(start_x, start_y);
		glVertex2f(start_x, start_y + shift_y);
		glVertex2f(start_x + shift_x, start_y + shift_y);
		glVertex2f(start_x + shift_x, start_y);
	glEnd();
}
void frontend::print_field(int **input_map, int input_height, int input_width)
{
	print_grid();
	for (int i = 0; i < input_height; i++)
		for (int j = 0; j < input_width; j++)
			print_cell(i, j, input_map[i][j]);
}
bool frontend::translate_pixels_to_cells(float in_y, float in_x, int& out_y, int& out_x) 
{
	float gl_ycoord = 2 * in_y / (float)window_height - (1 + origin_y);
	float gl_xcoord = 2 * in_x / (float)window_width - (1 + origin_x);
	out_x = gl_xcoord / shift_x;
	out_y = gl_ycoord / shift_y;
	return true;
}


