// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h" 
#include <stdio.h>  
#include <glut.h>  


void display() {
	glClear(GL_COLOR_BUFFER_BIT);       
	glRotatef(130.0, 0.0, 0.0, 1.0);//没有这句时，程序运 行结果是第一张图。    
	glBegin(GL_TRIANGLES);       // 绘制三角形   
	glVertex3f( 0.0f, 0.5f, 0.0f);     // 上顶点   
	glVertex3f(-0.5f,-0.5f, 0.0f);     // 左下   
	glVertex3f( 0.5f,-0.5f, 0.0f);     // 右下  
	glEnd();          
	glFlush();   
}  
int main(int argc, char** argv)   
{        // 初始化GLUT库函数的常用形式       
	glutInit(&argc, argv);        
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // 这是默认显示模式，可忽略       
	glutInitWindowSize(500, 500);                   // 大小为500×500绘图窗口       
	glutInitWindowPosition(0, 0);                   // 把绘图窗口的左上角放在屏幕左上角        
	glutCreateWindow("Sierpinski Gasket");          // 创建绘图窗口，参数为绘图窗口的标题        
	glutDisplayFunc(display);                       // 注册显示回调函数       
	glutMainLoop();                                 // 进入事件循环       
	return 0;                                       // 该句不会执行，仅为了有个返回值   
}