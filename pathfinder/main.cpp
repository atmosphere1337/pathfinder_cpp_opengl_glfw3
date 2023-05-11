#include "backend_header.h"
#include "frontend_header.h"
#include "include/GLFW/glfw3.h"
#include "include/GLFW/glfw3native.h"
#include <iostream>
backend bck;
frontend frnt;
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		bck.show_path();
	}
	if (key == GLFW_KEY_2 && action == GLFW_PRESS)
	{
		bck.clear_map_paths();
	}
}
int main()
{
	if (!glfwInit())
		return -1;
	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello world", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	if (bck.bfs())
		std::cout << "Done" << std::endl;
	else
		std::cout << "Nothing" << std::endl;
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