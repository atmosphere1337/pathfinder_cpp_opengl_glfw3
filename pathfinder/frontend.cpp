#include "frontend_header.h"
#include "include/GLFW/glfw3.h"
#include "include/GLFW/glfw3native.h"

frontend::frontend(void)
{
	
}
void frontend::print(void)
{
	for (float i = -1; i < 1.0; i += 0.1)
	{
		glBegin(GL_LINES);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2f(i, -1.0);
			glVertex2f(i, 1.0);
			glVertex2f(1.0, i);
			glVertex2f(-1.0, i);
		glEnd();
	}
	glBegin(GL_QUADS);
		glColor3f(170/255.0, 0.77, 0.0);
		glVertex2f(-0.8,-0.8);
		glVertex2f(-0.8,-0.9);
		glVertex2f(-0.9,-0.9);
		glVertex2f(-0.9,-0.8);
	glEnd();
}




