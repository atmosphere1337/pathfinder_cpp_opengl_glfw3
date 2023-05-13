#include "backend_header.h"
#include "frontend_header.h"
#include "include/GLFW/glfw3.h"
#include "include/GLFW/glfw3native.h"
#include <iostream>
const int window_width = 640, window_height = 480;
backend bck;
frontend frnt(window_width, window_height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		bck.clear_map_paths();
		bck.bfs();
		bck.show_path();
	}
	if (key == GLFW_KEY_2 && action == GLFW_PRESS)
	{
		bck.clear_map_paths();
		bck.dfs();
		bck.show_path();
	}
	if (key == GLFW_KEY_0 && action == GLFW_PRESS)
	{
		bck.clear_map_paths();
	}
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		double xpos, ypos;
		int outx = -228, outy = -228;
		glfwGetCursorPos(window, &xpos, &ypos);
		std::cout << xpos << " " << ypos << std::endl;
		if (!frnt.translate_pixels_to_cells(ypos, xpos, outy, outx))
			return;
		//frnt.print_cell(outy, outx, 2);
		bck.set_start(outy, outx);
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		std::cout << "Hit the fire" << std::endl;
}
int main()
{
	if (!glfwInit())
		return -1;
	GLFWwindow* window = glfwCreateWindow(window_width, window_height, "Hello world", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	int height = 0, width = 0;

	int** map_buf = bck.map_get(height, width);
	frnt.system_mount(height, width);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		map_buf = bck.map_get(height, width);
		frnt.print_field(map_buf, height, width);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
	


	
}