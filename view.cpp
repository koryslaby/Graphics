#include <GL/glut.h>
#include <iostream>

using namespace std;

void display_shape(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 0.0, 0.5);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.0, 0.0, 0.5);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	printf("%s\n", "does this work" );
	cout << "what about this" << endl;
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(400,300);
	glutInitWindowPosition(100, 100);
	glutInit(&argc, argv);
	glutCreateWindow("Hellow world");
	glutSetCursor(GLUT_CURSOR_DESTROY);
	glutDisplayFunc(display_shape);
	glutMainLoop();
	return 0;
}