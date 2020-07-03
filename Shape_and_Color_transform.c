// ccube.c
// OpenGL SuperBible, Chapter 6
// Demonstrates primative RGB Color Cube
// Program by Richard S. Wright Jr.

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>

static int i = 0;
static int seq = 0;
static GLfloat vadd = 5.0;
static GLfloat cadd = 0.2;

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat zRot = 0.0f;

static GLfloat c0[3] = { 1.0,1.0,1.0 };
static GLfloat c1[3] = { 1.0,1.0,0.0 };
static GLfloat c2[3] = { 1.0,0.0,0.0 };
static GLfloat c3[3] = { 1.0,0.0,1.0 };
static GLfloat c4[3] = { 0.0,1.0,1.0 };
static GLfloat c5[3] = { 0.0,1.0,0.0 };
static GLfloat c6[3] = { 0.0,0.0,0.0 };
static GLfloat c7[3] = { 0.0,0.0,1.0 };

static GLfloat v0[3] = { 50.0,50.0,50.0 };
static GLfloat v1[3] = { 50.0,-50.0,50.0 };
static GLfloat v2[3] = { -50.0,-50.0,50.0 };
static GLfloat v3[3] = { -50.0,50.0,50.0 };
static GLfloat v4[3] = { 50.0,50.0,-50.0 };
static GLfloat v5[3] = { 50.0,-50.0,-50.0 };
static GLfloat v6[3] = { -50.0,-50.0,-50.0 };
static GLfloat v7[3] = { -50.0,50.0,-50.0 };

static int inc0 = 0;
static int inc1 = 0;
static int inc2 = 0;
static int inc3 = 0;
static int inc4 = 0;
static int inc5 = 0;
static int inc6 = 0;
static int inc7 = 0;

// Called to draw scene
void RenderScene(void)
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glRotatef(zRot, 0.0f, 0.0f, 1.0f);

	// Front face
	glBegin(GL_POLYGON);
	// White
	glColor3f(c0[0], c0[1], c0[2]);
	glVertex3f(v0[0], v0[1], v0[2]);

	// Yellow
	glColor3f(c1[0], c1[1], c1[2]);
	glVertex3f(v1[0], v1[1], v1[2]);

	// Red
	glColor3f(c2[0], c2[1], c2[2]);
	glVertex3f(v2[0], v2[1], v2[2]);

	// Magenta
	glColor3f(c3[0], c3[1], c3[2]);
	glVertex3f(v3[0], v3[1], v3[2]);
	glEnd();


	// Back Face
	glBegin(GL_POLYGON);
	// Cyan
	glColor3f(c4[0], c4[1], c4[2]);
	glVertex3f(v4[0], v4[1], v4[2]);

	// Green
	glColor3f(c5[0], c5[1], c5[2]);
	glVertex3f(v5[0], v5[1], v5[2]);

	// Black
	glColor3f(c6[0], c6[1], c6[2]);
	glVertex3f(v6[0], v6[1], v6[2]);

	// Blue
	glColor3f(c7[0], c7[1], c7[2]);
	glVertex3f(v7[0], v7[1], v7[2]);
	glEnd();


	// Top Face
	glBegin(GL_POLYGON);
	// Cyan
	glColor3f(c4[0], c4[1], c4[2]);
	glVertex3f(v4[0], v4[1], v4[2]);

	// White
	glColor3f(c0[0], c0[1], c0[2]);
	glVertex3f(v0[0], v0[1], v0[2]);

	// Magenta
	glColor3f(c3[0], c3[1], c3[2]);
	glVertex3f(v3[0], v3[1], v3[2]);

	// Blue
	glColor3f(c7[0], c7[1], c7[2]);
	glVertex3f(v7[0], v7[1], v7[2]);
	glEnd();


	// Bottom Face
	glBegin(GL_POLYGON);
	// Green
	glColor3f(c5[0], c5[1], c5[2]);
	glVertex3f(v5[0], v5[1], v5[2]);

	// Yellow
	glColor3f(c1[0], c1[1], c1[2]);
	glVertex3f(v1[0], v1[1], v1[2]);

	// Red
	glColor3f(c2[0], c2[1], c2[2]);
	glVertex3f(v2[0], v2[1], v2[2]);

	// Black
	glColor3f(c6[0], c6[1], c6[2]);
	glVertex3f(v6[0], v6[1], v6[2]);
	glEnd();


	// Left face
	glBegin(GL_POLYGON);
	// White
	glColor3f(c0[0], c0[1], c0[2]);
	glVertex3f(v0[0], v0[1], v0[2]);

	// Cyan
	glColor3f(c4[0], c4[1], c4[2]);
	glVertex3f(v4[0], v4[1], v4[2]);

	// Green
	glColor3f(c5[0], c5[1], c5[2]);
	glVertex3f(v5[0], v5[1], v5[2]);

	// Yellow
	glColor3f(c1[0], c1[1], c1[2]);
	glVertex3f(v1[0], v1[1], v1[2]);
	glEnd();


	// Right face
	glBegin(GL_POLYGON);
	// Magenta
	glColor3f(c3[0], c3[1], c3[2]);
	glVertex3f(v3[0], v3[1], v3[2]);

	// Blue
	glColor3f(c7[0], c7[1], c7[2]);
	glVertex3f(v7[0], v7[1], v7[2]);

	// Black
	glColor3f(c6[0], c6[1], c6[2]);
	glVertex3f(v6[0], v6[1], v6[2]);

	// Red
	glColor3f(c2[0], c2[1], c2[2]);
	glVertex3f(v2[0], v2[1], v2[2]);
	glEnd();

	glPopMatrix();

	// Show the graphics
	glutSwapBuffers();
}

// This function does any needed initialization on the rendering
// context. 
void SetupRC()
{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	//	glEnable(GL_DITHER);
	glShadeModel(GL_SMOOTH);
}

void SpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
		xRot -= 5.0f;

	if (key == GLUT_KEY_DOWN)
		xRot += 5.0f;

	if (key == GLUT_KEY_LEFT)
		yRot -= 5.0f;

	if (key == GLUT_KEY_RIGHT)
		yRot += 5.0f;

	if (key > 356.0f)
		xRot = 0.0f;

	if (key < -1.0f)
		xRot = 355.0f;

	if (key > 356.0f)
		yRot = 0.0f;

	if (key < -1.0f)
		yRot = 355.0f;

	// Refresh the Window
	glutPostRedisplay();
}

void TimerFunction(int value)
{
	// v0
	if (seq == 0) {
		for (int i = 0; i < 3; i++) {
			if (inc0 == 0) {
				if (v0[i] < 0.0) {
					v0[i] -= vadd;
				}
				if ((v0[i] > 40.0) && (v0[i] < 60.0)) {
					v0[i] -= vadd;
				}
				else {
					inc0 = 1;
				}
			}
			else {
				if (v0[i] < 0.0) {
					v0[i] += vadd;
				}
				if ((v0[i] > 40.0) && (v0[i] < 60.0)) {
					v0[i] += vadd;
				}
				else {
					inc0 = 0;
				}
			}
		}
		seq = 1;
		for (i = 0; i < 3; i++) {
			if (c0[i] >= 1.0) {
				c0[i] = 0.0;
			}
			else {
				c0[i] += cadd;
			}
		}
	}

	//v1
	if (seq == 1) {
		for (int i = 0; i < 3; i++) {
			if (inc1 == 0) {
				if (v1[i] < 0.0) {
					v1[i] -= vadd;
				}
				if ((v1[i] > 40.0) && (v1[i] < 60.0)) {
					v1[i] -= vadd;
				}
				else {
					inc1 = 1;
				}
			}
			else {
				if (v1[i] < 0.0) {
					v1[i] += vadd;
				}
				if ((v1[i] > 40.0) && (v1[i] < 60.0)) {
					v1[i] += vadd;
				}
				else {
					inc1 = 0;
				}
			}
		}
		seq = 2;
		for (i = 0; i < 3; i++) {
			if (c1[i] >= 1.0) {
				c1[i] = 0.0;
			}
			else {
				c1[i] += cadd;
			}
		}
	}

	//v2
	if (seq == 2) {
		for (int i = 0; i < 3; i++) {
			if (inc2 == 0) {
				if (v2[i] < 0.0) {
					v2[i] -= vadd;
				}
				if ((v2[i] > 40.0) && (v2[i] < 60.0)) {
					v2[i] -= vadd;
				}
				else {
					inc2 = 1;
				}
			}
			else {
				if (v2[i] < 0.0) {
					v2[i] += vadd;
				}
				if ((v2[i] > 40.0) && (v2[i] < 60.0)) {
					v2[i] += vadd;
				}
				else {
					inc2 = 0;
				}
			}
		}
		seq = 3;
		for (i = 0; i < 3; i++) {
			if (c2[i] >= 1.0) {
				c2[i] = 0.0;
			}
			else {
				c2[i] += cadd;
			}
		}
	}

	//v3
	if (seq == 3) {
		for (int i = 0; i < 3; i++) {
			if (inc3 == 0) {
				if (v3[i] < 0.0) {
					v3[i] -= vadd;
				}
				if ((v3[i] > 40.0) && (v3[i] < 60.0)) {
					v3[i] -= vadd;
				}
				else {
					inc3 = 1;
				}
			}
			else {
				if (v3[i] < 0.0) {
					v3[i] += vadd;
				}
				if ((v3[i] > 40.0) && (v3[i] < 60.0)) {
					v3[i] += vadd;
				}
				else {
					inc3 = 0;
				}
			}
		}
		seq = 4;
		for (i = 0; i < 3; i++) {
			if (c3[i] >= 1.0) {
				c3[i] = 0.0;
			}
			else {
				c3[i] += cadd;
			}
		}
	}

	//v4
	if (seq == 4) {
		for (int i = 0; i < 3; i++) {
			if (inc4 == 0) {
				if (v4[i] < 0.0) {
					v4[i] -= vadd;
				}
				if ((v4[i] > 40.0) && (v4[i] < 60.0)) {
					v4[i] -= vadd;
				}
				else {
					inc4 = 1;
				}
			}
			else {
				if (v4[i] < 0.0) {
					v4[i] += vadd;
				}
				if ((v4[i] > 40.0) && (v4[i] < 60.0)) {
					v4[i] += vadd;
				}
				else {
					inc4 = 0;
				}
			}
		}
		seq = 5;
		for (i = 0; i < 3; i++) {
			if (c4[i] >= 1.0) {
				c4[i] = 0.0;
			}
			else {
				c4[i] += cadd;
			}
		}
	}

	//v5
	if (seq == 5) {
		for (int i = 0; i < 3; i++) {
			if (inc5 == 0) {
				if (v5[i] < 0.0) {
					v5[i] -= vadd;
				}
				if ((v5[i] > 40.0) && (v5[i] < 60.0)) {
					v5[i] -= vadd;
				}
				else {
					inc5 = 1;
				}
			}
			else {
				if (v5[i] < 0.0) {
					v5[i] += vadd;
				}
				if ((v5[i] > 40.0) && (v5[i] < 60.0)) {
					v5[i] += vadd;
				}
				else {
					inc5 = 0;
				}
			}
		}
		seq = 6;
		for (i = 0; i < 3; i++) {
			if (c5[i] >= 1.0) {
				c5[i] = 0.0;
			}
			else {
				c5[i] += cadd;
			}
		}
	}

	//v6
	if (seq == 6) {
		for (int i = 0; i < 3; i++) {
			if (inc6 == 0) {
				if (v6[i] < 0.0) {
					v6[i] -= vadd;
				}
				if ((v6[i] > 40.0) && (v6[i] < 60.0)) {
					v6[i] -= vadd;
				}
				else {
					inc6 = 1;
				}
			}
			else {
				if (v6[i] < 0.0) {
					v6[i] += vadd;
				}
				if ((v6[i] > 40.0) && (v6[i] < 60.0)) {
					v6[i] += vadd;
				}
				else {
					inc6 = 0;
				}
			}
		}
		seq = 7;
		for (i = 0; i < 3; i++) {
			if (c6[i] >= 1.0) {
				c6[i] = 0.0;
			}
			else {
				c6[i] += cadd;
			}
		}
	}

	//v7
	if (seq == 7) {
		for (int i = 0; i < 3; i++) {
			if (inc7 == 0) {
				if (v7[i] < 0.0) {
					v7[i] -= vadd;
				}
				if ((v7[i] > 40.0) && (v7[i] < 60.0)) {
					v7[i] -= vadd;
				}
				else {
					inc7 = 1;
				}
			}
			else {
				if (v7[i] < 0.0) {
					v7[i] += vadd;
				}
				if ((v7[i] > 40.0) && (v7[i] < 60.0)) {
					v7[i] += vadd;
				}
				else {
					inc7 = 0;
				}
			}
		}
		seq = 0;
		for (i = 0; i < 3; i++) {
			if (c7[i] >= 1.0) {
				c7[i] = 0.0;
			}
			else {
				c7[i] += cadd;
			}
		}
	}
	if (xRot < 355.0) {
		xRot += 5.0;
	}
	else {
		xRot = 0.0;
	}
	if (yRot < 355.0) {
		yRot += 5.0;
	}
	else {
		yRot = 0.0;
	}
	if (zRot < 355.0) {
		zRot += 5.0;
	}
	else {
		zRot = 0.0;
	}

	// Redraw the scene with new coordinates
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}

void ChangeSize(int w, int h)
{
	GLfloat nRange = 150.0f;

	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("RGB Cube");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(330, TimerFunction, 1);
	SetupRC();
	glutMainLoop();

	return 0;
}