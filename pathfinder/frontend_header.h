#pragma once
class frontend
{
	private:
		float shift_x, shift_y;
		float origin_x, origin_y;
		int size_x, size_y;
	public:
		frontend(void);
		void system_mount(int y, int x);
		void print_grid(void);
		void print_cell(int y, int x, int color);
		void print_field(void);
};
