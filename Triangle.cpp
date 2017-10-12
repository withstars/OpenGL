// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h" //产生预编译头文件和使用预编译头文件
#include <stdio.h>  
#include <glut.h>  //导入opengl函数库


void display() {
	glClear(GL_COLOR_BUFFER_BIT);        
	glBegin(GL_TRIANGLES);				// 开始绘制三角形   
	glVertex3f( 0.0f, 0.5f, 0.0f);     // 上顶点   
	glVertex3f(-0.5f,-0.5f, 0.0f);     // 左下   
	glVertex3f( 0.5f,-0.5f, 0.0f);     // 右下  
	glEnd();                           //结束绘制
	glFlush();						//强制刷新缓冲，保证绘图命令将被执行
}  
int main(int argc, char** argv)   
{            
	glutInit(&argc, argv);							 // 初始化GLUT库函数的常用形式  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // 这是默认显示模式，可忽略       
	glutInitWindowSize(500, 500);                   // 大小为500×500绘图窗口       
	glutInitWindowPosition(0, 0);                   // 把绘图窗口的左上角放在屏幕左上角        
	glutCreateWindow("OpenGL绘制的三角形");                     // 创建绘图窗口，参数为绘图窗口的标题        
	glutDisplayFunc(display);                       // 注册显示回调函数       
	glutMainLoop();                                 // 进入事件循环       
	return 0;                                       // 该句不会执行，仅为了有个返回值   
}