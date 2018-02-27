#include <stdlib.h>
#include "GL/glut.h"
#include <iostream>
#pragma comment(lib, "glut32.lib")
#define WINDOW_TITLE "Project"
using namespace std;

const float ANGLE = 45.f;
const float FOV = 70.f;
const float NCP = 0.001f;
const float FCP = 40.f;
int m_iWidth = 800;		//width of the viewport
int m_iHeight = 600;	//height of the viewport

///
/// Function designed to be use in the glutKeyboardFunc
/// @param key represents the key pressed in the keyboard
/// 
void keyboardDown(unsigned char key, int x, int y) 
{
 
  switch(key) {
  case 'Q':
  case 'q':
  case  27:   // ESC
	  exit(0);
  }
}

/// Function invoked on idle time of program
void idle(void)
{
	glutPostRedisplay();
}

/// All the drawing code here
void draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.6,0.6,0.6,1);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
 
  //begin - rendering a simple triangle (testing)
	glBegin(GL_TRIANGLES);
		glColor3f(1,0,0);
		glVertex3f(-0.5,0,-1);
		glColor3f(0.5,0.5,0);
		glVertex3f(0.5,0,-1);
		glColor3f(0,0.5,0.5);
		glVertex3f(0,0.5,-1);
	glEnd();
  //begin - rendering a simple triangle
	glutSwapBuffers();
}

/// Is invoked when window is resized, modifying the projection matrix and viewport
void reshape(int width, int height) 
{
  glViewport (0, 0, (GLsizei) width, (GLsizei) height);
 
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  float ratio = (height == 0)?1:(GLfloat) width/(GLfloat) height;
  gluPerspective(FOV, ratio, NCP, FCP);
 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

/// Insert all your initialization objects and OpenGL status
bool initialize()
{
	glEnable(GL_DEPTH_TEST);
	return true;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(m_iWidth, m_iHeight);
	glutCreateWindow(WINDOW_TITLE);
	if(!initialize()) return 1;
	glutDisplayFunc(draw);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardDown);
	glutMainLoop();
	return 0;
}