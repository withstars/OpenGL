// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h" //产生预编译头文件和使用预编译头文件
#include <stdio.h>  
#include <glut.h>  //导入opengl函数库
#include <stdlib.h>

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 50.0, 0.0, 50.0, -1.0, 1.0);
}

void display() {
	GLfloat vertices[3][3] = { { 0.0,0.0,0.0 },{ 25.0, 50.0, 0.0 },{ 50.0, 0.0, 0.0 } };
	GLfloat p[3] = { 7.5,5.0,0.0 };

	glBegin(GL_POINTS);
	for (int i = 0; i<5000; ++i) {
		int x = rand() % 3;

		p[0] = (p[0] + vertices[x][0]) / 2;
		p[1] = (p[1] + vertices[x][1]) / 2;

		glVertex3fv(p);
	}
	glEnd();
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);							 // 初始化GLUT库函数的常用形式  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // 这是默认显示模式，可忽略       
	glutInitWindowSize(500, 500);                   // 大小为500×500绘图窗口       
	glutInitWindowPosition(300, 100);                   // 定位绘图窗口     
	glutCreateWindow("谢尔宾斯基三角形");         // 创建绘图窗口，参数为绘图窗口的标题  
	init();
	glutDisplayFunc(display);                       // 注册显示回调函数       
	glutMainLoop();                                 // 进入事件循环       
	return 0;                                       // 该句不会执行，仅为了有个返回值   
}