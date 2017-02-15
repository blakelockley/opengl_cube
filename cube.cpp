#include <stdlib.h>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#define ESC 27
#define SPC 32

bool do_rotate = false;
int h_roation = 0, v_rotation = 0;

void render(void) {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_QUADS); // of the color cube

  // Top-face
  glColor3f(0.0f, 1.0f, 0.0f); // green
  glVertex3f(0.5f, 0.5f, -0.5f);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glVertex3f(0.5f, 0.5f, 0.5f);

  // Bottom-face
  glColor3f(1.0f, 0.5f, 0.0f); // orange
  glVertex3f(0.5f, -0.5f, 0.5f);
  glVertex3f(-0.5f, -0.5f, 0.5f);
  glVertex3f(-0.5f, -0.5f, -0.5f);
  glVertex3f(0.5f, -0.5f, -0.5f);

  // Front-face
  glColor3f(1.0f, 0.0f, 0.0f); // red
  glVertex3f(0.5f, 0.5f, 0.5f);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glVertex3f(-0.5f, -0.5f, 0.5f);
  glVertex3f(0.5f, -0.5f, 0.5f);

  // Back-face
  glColor3f(1.0f, 1.0f, 0.0f); // yellow
  glVertex3f(0.5f, -0.5f, -0.5f);
  glVertex3f(-0.5f, -0.5f, -0.5f);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glVertex3f(0.5f, 0.5f, -0.5f);

  // Left-face
  glColor3f(0.0f, 0.0f, 1.0f); // blue
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glVertex3f(-0.5f, -0.5f, -0.5f);
  glVertex3f(-0.5f, -0.5f, 0.5f);

  // Right-face
  glColor3f(1.0f, 0.0f, 1.0f); // magenta
  glVertex3f(0.5f, 0.5f, -0.5f);
  glVertex3f(0.5f, 0.5f, 0.5f);
  glVertex3f(0.5f, -0.5f, 0.5f);
  glVertex3f(0.5f, -0.5f, -0.5f);

  glEnd(); // of the color cube

  glutSwapBuffers();
}

void rotate(void) {
  if (do_rotate)
    glRotatef(1.0f, 1.0f, 1.0f, 0.0f);

  if (v_rotation != 0)
    glRotatef(v_rotation * 2, 1.0f, 0.0f, 0.0f);
  if (h_roation != 0)
    glRotatef(h_roation * 2, 0.0f, 1.0f, 0.0f);

  v_rotation = h_roation = 0;

  glutPostRedisplay();
}

void keyboardPressed(unsigned char key, int x, int y) {
  if (key == ESC)
    exit(0);

  if (key == SPC)
    do_rotate = !do_rotate;
}

void specialPressed(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_LEFT:
      h_roation = -1;
      break;
    case GLUT_KEY_RIGHT:
      h_roation = 1;
      break;
    case GLUT_KEY_DOWN:
      v_rotation = -1;
      break;
    case GLUT_KEY_UP:
      v_rotation = 1;
      break;
    default:
      break;
  }
}

int main(int argc, char **argv) {
  glutInit(&argc, argv); //NOTE: address-of operator on argc

  //create window
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(400, 400);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutCreateWindow("Cube");

  //callbacks
  glutDisplayFunc(render);
  //glutReshapeFunc(...);
  glutIdleFunc(rotate);
  glutKeyboardFunc(keyboardPressed);
  glutSpecialFunc(specialPressed);
  //glutMouseFunc(...);

  //gl settings
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  //glScalef(0.5f, 0.5f, 0.5f);

  glutMainLoop();

  return 1;
}
