#include "backend_header.h"
#include "include/GLFW/glfw3.h"
#include "include/GLFW/glfw3native.h"
#include <iostream>
int main()
{
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
		glBegin(GL_TRIANGLES);
			glColor3f(170/255.0, 0.0, 0.0);
			glVertex2f(0.0,0.0);
			glVertex2f(0.75, 0.75);
			glVertex2f(0.75, 0.0);
		glEnd();

		//glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
	




	backend bck;
	//bck.map_init();
	bck.map_print();


	
}