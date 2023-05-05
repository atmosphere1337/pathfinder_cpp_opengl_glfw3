#include "backend_header.h"
#include "frontend_header.h"
#include "include/GLFW/glfw3.h"
#include "include/GLFW/glfw3native.h"
#include <iostream>
int main()
{
	frontend frnt;
	if (!glfwInit())
		return -1;
	GLFWwindow* window;
	window = glfwCreateWindow(640, 480, "Hello world", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		frnt.print();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
	
	backend bck;
	bck.map_print();


	
}