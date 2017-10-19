// tetrahedrold.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>  
#include <glut.h>  
#include <stdlib.h>
#include <windows.h>        
#include <math.h>    

#define pi 3.1415927f;  
float a = 0.5f;
float u = sqrtf(2.0) / 3;
float v = float(1 / 3);
float t = sqrtf(6.0) / 3;

static const GLfloat vertex_list[][3] = {
	0.0f   , 0.0f  ,  a   ,
	-2 * a*u , 0,0   , -a*v ,
	a*u    , a*t   , -a*v ,
	a*u    , -a*t  , -a*v ,
};

static const GLint index_list[][3] = {
	0, 1, 2,
	0, 1, 2,
	0, 1, 3,
	1, 2, 3,
};

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(45, 1, 1, 1);
	glFrontFace(GL_CCW);

	for (int i = 0; i < 4; ++i)      // 有四个面，循环六次  
	{
		glBegin(GL_LINE_LOOP);
		for (int j = 0; j < 3; ++j)     // 每个面有四个顶点，循环四次  
			glVertex3fv(vertex_list[index_list[i][j]]);
		glEnd();
	}

	glFlush();
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("opengl1");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

