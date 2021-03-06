#include "stdafx.h"
#include<GL/glut.h>
#include "stdlib.h"
#include "stdio.h"

GLfloat xi = 0.0;
GLfloat yi = 0.0;
void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void ArrowKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		xi += 0.5;
		break;
	case GLUT_KEY_LEFT:
		xi -= 0.5;
		break;
	case GLUT_KEY_UP:
		yi += 0.5;
		break;
	case GLUT_KEY_DOWN:
		yi -= 0.5;
		break;
	}
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(yi, 1, 0, 0);
	glRotatef(xi, 0, 1, 0);
	glutWireTorus(0.5, 1, 28, 28);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, 0.1, 20.0);
	glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(ArrowKey);
	glutMainLoop();
	return 0;
}