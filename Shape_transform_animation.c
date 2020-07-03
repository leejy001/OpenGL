// Shapes.c
// OpenGL SuperBible, Chapter 3
// Demonstrates GLUT menuing and some GLUT prebuilt shapes
// Program by Richard S. Wright Jr.

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>


// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;


// Light values and coordinates
GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat  specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

static int iShape = 0;
static float sphere_add = 0.1;
static float cube_add = 0.1;
static float cone_add = 0.1;
static float torus_add = 0.1;
static float hedron_add = 0.1;
static float octa_add = 0.1;
static float tetra_add = 0.1;
static float lcosa_add = 0.1;
static float teapot_add = 0.1;

static int sphere_cnt = 0;
static float cube_cnt = 0;
static float cone_cnt = 0;
static float torus_cnt = 0;
static float hedron_cnt = 0;
static float octa_cnt = 0;
static float tetra_cnt = 0;
static float lcosa_cnt = 0;
static float teapot_cnt = 0;

///////////////////////////////////////////////////////////////////////////////
// Reset flags as appropriate in response to menu selections
void ProcessMenu(int value)
{
	iShape = value;

	glutPostRedisplay();
}


// Called to draw scene
void RenderScene(void)
{
	// Clear the window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// Save matrix state and do the rotation
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	if (iShape == 0)
	{
		glPushMatrix();
		glutWireSphere(1.0f + sphere_add, 25, 25);
		glPopMatrix();
	}
	if (iShape == 1)
	{
		glPushMatrix();
		glutWireCube(1.0f + cube_add);
		glPopMatrix();
	}
	if (iShape == 2)
	{
		glPushMatrix();
		glutWireCone(0.30f + cone_add, 1.1f + cone_add, 20, 20);
		glPopMatrix();
	}
	if (iShape == 3)
	{
		glPushMatrix();
		glutWireTorus(0.3f + torus_add, 1.0f + torus_add, 10, 25);
		glPopMatrix();
	}
	if (iShape == 4)
	{
		glPushMatrix();
		glScalef(1.0 + hedron_add, 1.0 + hedron_add, 1.0 + hedron_add);
		glutWireDodecahedron();
		glPopMatrix();
	}
	if (iShape == 5)
	{
		glPushMatrix();
		glScalef(1.0 + octa_add, 1.0 + octa_add, 1.0 + octa_add);
		glutWireOctahedron();
		glPopMatrix();
	}
	if (iShape == 6)
	{
		glPushMatrix();
		glScalef(1.0 + tetra_add, 1.0 + tetra_add, 1.0 + tetra_add);
		glutWireTetrahedron();
		glPopMatrix();
	}
	if (iShape == 7)
	{
		glPushMatrix();
		glScalef(1.0 + lcosa_add, 1.0 + lcosa_add, 1.0 + lcosa_add);
		glutWireIcosahedron();
		glPopMatrix();
	}
	if (iShape == 8)
	{
		glPushMatrix();
		glScalef(1.0 + teapot_add, 1.0 + teapot_add, 1.0 + teapot_add);
		glutWireTeapot(1.0f);
		glPopMatrix();
	}
	if (iShape == 9)
	{
		glPushMatrix();
		glutSolidSphere(1.0f + sphere_add, 25, 25);
		glPopMatrix();
	}
	if (iShape == 10)
	{
		glPushMatrix();
		glutSolidCube(1.0f + cube_add);
		glPopMatrix();
	}
	if (iShape == 11)
	{
		glPushMatrix();
		glutSolidCone(0.30f + cone_add, 1.1f + cone_add, 20, 20);
		glPopMatrix();
	}
	if (iShape == 12)
	{
		glPushMatrix();
		glutSolidTorus(0.3f + torus_add, 1.0f + torus_add, 10, 25);
		glPopMatrix();
	}
	if (iShape == 13)
	{
		glPushMatrix();
		glScalef(1.0 + hedron_add, 1.0 + hedron_add, 1.0 + hedron_add);
		glutSolidDodecahedron();
		glPopMatrix();
	}
	if (iShape == 14)
	{
		glPushMatrix();
		glScalef(1.0 + octa_add, 1.0 + octa_add, 1.0 + octa_add);
		glutSolidOctahedron();
		glPopMatrix();
	}
	if (iShape == 15)
	{
		glPushMatrix();
		glScalef(1.0 + tetra_add, 1.0 + tetra_add, 1.0 + tetra_add);
		glutSolidTetrahedron();
		glPopMatrix();
	}
	if (iShape == 16)
	{
		glPushMatrix();
		glScalef(1.0 + lcosa_add, 1.0 + lcosa_add, 1.0 + lcosa_add);
		glutSolidIcosahedron();
		glPopMatrix();
	}
	if (iShape == 17)
	{
		glPushMatrix();
		glScalef(1.0 + teapot_add, 1.0 + teapot_add, 1.0 + teapot_add);
		glutSolidTeapot(1.0f);
		glPopMatrix();
	}

	// Restore transformations
	glPopMatrix();

	// Flush drawing commands
	glutSwapBuffers();
}

// This function does any needed initialization on the rendering
// context. 
void SetupRC()
{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Enable Depth Testing
	glEnable(GL_DEPTH_TEST);

	// Enable lighting
	glEnable(GL_LIGHTING);

	// Setup and enable light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glEnable(GL_LIGHT0);

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	// All materials hereafter have full specular reflectivity
	// with a high shine
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);


	// Set drawing color to blue
	glColor3ub(0, 0, 255);
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


void ChangeSize(int w, int h)
{
	GLfloat	 lightPos[] = { -50.f, 50.0f, 100.0f, 1.0f };
	GLfloat nRange = 4.0f;

	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);

	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}

void TimerFunction(int value)
{
	// Redraw the scene with new coordinates
	if (iShape == 0)
	{
		sphere_add += 0.1;
		sphere_cnt++;
		if (sphere_cnt == 9)
		{
			sphere_add = 0.1;
			sphere_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 1)
	{
		cube_add += 0.1;
		cube_cnt++;
		if (cube_cnt == 9)
		{
			cube_add = 0.1;
			cube_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 2)
	{
		cone_add += 0.1;
		cone_cnt++;
		if (cone_cnt == 9)
		{
			cone_add = 0.1;
			cone_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 3)
	{
		torus_add += 0.1;
		torus_cnt++;
		if (torus_cnt == 9)
		{
			torus_add = 0.1;
			torus_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 4)
	{
		hedron_add += 0.1;
		hedron_cnt++;
		if (hedron_cnt == 9)
		{
			hedron_add = 0.1;
			hedron_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 5)
	{
		octa_add += 0.1;
		octa_cnt++;
		if (octa_cnt == 9)
		{
			octa_add = 0.1;
			octa_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 6)
	{
		tetra_add += 0.1;
		tetra_cnt++;
		if (tetra_cnt == 9)
		{
			tetra_add = 0.1;
			tetra_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 7)
	{
		lcosa_add += 0.1;
		lcosa_cnt++;
		if (lcosa_cnt == 9)
		{
			lcosa_add = 0.1;
			lcosa_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 8)
	{
		teapot_add += 0.1;
		teapot_cnt++;
		if (teapot_cnt == 9)
		{
			teapot_add = 0.1;
			teapot_cnt = 0;
			iShape++;
		}
	}

	//Solid
	if (iShape == 9)
	{
		sphere_add += 0.1;
		sphere_cnt++;
		if (sphere_cnt == 9)
		{
			sphere_add = 0.1;
			sphere_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 10)
	{
		cube_add += 0.1;
		cube_cnt++;
		if (cube_cnt == 9)
		{
			cube_add = 0.1;
			cube_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 11)
	{
		cone_add += 0.1;
		cone_cnt++;
		if (cone_cnt == 9)
		{
			cone_add = 0.1;
			cone_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 12)
	{
		torus_add += 0.1;
		torus_cnt++;
		if (torus_cnt == 9)
		{
			torus_add = 0.1;
			torus_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 13)
	{
		hedron_add += 0.1;
		hedron_cnt++;
		if (hedron_cnt == 9)
		{
			hedron_add = 0.1;
			hedron_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 14)
	{
		octa_add += 0.1;
		octa_cnt++;
		if (octa_cnt == 9)
		{
			octa_add = 0.1;
			octa_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 15)
	{
		tetra_add += 0.1;
		tetra_cnt++;
		if (tetra_cnt == 9)
		{
			tetra_add = 0.1;
			tetra_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 16)
	{
		lcosa_add += 0.1;
		lcosa_cnt++;
		if (lcosa_cnt == 9)
		{
			lcosa_add = 0.1;
			lcosa_cnt = 0;
			iShape++;
		}
	}
	if (iShape == 17)
	{
		teapot_add += 0.1;
		teapot_cnt++;
		if (teapot_cnt == 9)
		{
			teapot_add = 0.1;
			teapot_cnt = 0;
			iShape = 0;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}

int main(int argc, char* argv[])
{
	int nSolidMenu;
	int nWireMenu;
	int nMainMenu;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes");

	// Create the Menu
	nWireMenu = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Sphere", 1);
	glutAddMenuEntry("Cube", 2);
	glutAddMenuEntry("Cone", 3);
	glutAddMenuEntry("Torus", 4);
	glutAddMenuEntry("Dodecahedron", 5);
	glutAddMenuEntry("Octahedron", 6);
	glutAddMenuEntry("Tetrahedron", 7);
	glutAddMenuEntry("Icosahedron", 8);
	glutAddMenuEntry("Teapot", 9);


	nSolidMenu = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Sphere", 11);
	glutAddMenuEntry("Cube", 12);
	glutAddMenuEntry("Cone", 13);
	glutAddMenuEntry("Torus", 14);
	glutAddMenuEntry("Dodecahedron", 15);
	glutAddMenuEntry("Octahedron", 16);
	glutAddMenuEntry("Tetrahedron", 17);
	glutAddMenuEntry("Icosahedron", 18);
	glutAddMenuEntry("Teapot", 19);

	nMainMenu = glutCreateMenu(ProcessMenu);
	glutAddSubMenu("Wire", nWireMenu);
	glutAddSubMenu("Solid", nSolidMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(330, TimerFunction, 1);
	SetupRC();
	glutMainLoop();

	return 0;
}