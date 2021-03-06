/*
* OGL01Shape3D.cpp: 3D Shapes
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

#define PI 3.14159265359
#define abuabu1 164,168,167
#define abuabu2 180,180,180
#define abuabu3 110,115,115
#define hitam 0,0,0
#define ROTATE_ANGLE 1

using namespace std;


/* Global variables */
char title[] = "3D Shapes";
GLfloat angle = 0.0f;
GLfloat viewangle = 0, tippangle = 0;
GLfloat  xAngle = 0.0, yAngle = 0.0, zAngle = 0.0;
int refreshMills = 15;
double twicePi = PI * 2;
int triangleAmount = 40;
GLfloat scale = 0.002f;
int sign = 1;
int count = 0;
GLuint texture;

GLuint LoadTexture( const char * filename ){

	GLuint texture;

	int width, height;

	unsigned char * data;

	FILE * file;

	file = fopen( filename, "rb" );

	if ( file == NULL ){ cout << "file error" ;return 0;}
	width = 720;
	height = 1280;
	data = (unsigned char *)malloc( width * height * 3 );
	//int size = fseek(file,);
	fread( data, width * height * 3, 1, file );
	fclose( file );

	for(int i = 0; i < width * height ; ++i)
	{
		int index = i*3;
		unsigned char B,R;
		B = data[index];
		R = data[index+2];

		data[index] = R;
		data[index+2] = B;

	}


	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );
	// glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
	// glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );
	//
	//
	// glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
	// glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_CLAMP_TO_BORDER );
	// glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_CLAMP_TO_BORDER );

	//baru
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_CLAMP_TO_BORDER );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_CLAMP_TO_BORDER );
    glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, 8, 8, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);

	gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
	free( data );

	// unsigned char texDat[64];
    // for (int i = 0; i < 64; ++i)
    //     texDat[i] = ((i + (i / 8)) % 2) * 128 + 127;
	//
	// //upload to GPU texture
    // GLuint tex;
    // glGenTextures(1, &tex);
    // glBindTexture(GL_TEXTURE_2D, tex);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, 8, 8, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, texDat);
    // glBindTexture(GL_TEXTURE_2D, 0);

	return texture;
}

void Special_Keys(int key, int x, int y)
{
	switch (key) {

		case GLUT_KEY_LEFT:  viewangle -= ROTATE_ANGLE;  break;
		case GLUT_KEY_RIGHT:  viewangle += ROTATE_ANGLE;  break;
		case GLUT_KEY_UP:  tippangle -= ROTATE_ANGLE;  break;
		case GLUT_KEY_DOWN:  tippangle += ROTATE_ANGLE;  break;
	}

	glutPostRedisplay();
}


/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
	texture= LoadTexture( "lineage.bmp" );
	std::cout << texture << std::endl;
}

/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */

void gambarbalokHP(){
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
	// Top face (y = 7.5f)
	// Define vertices in counter-clockwise (CCW) order with normal pointing out
	glColor3ub(abuabu1);
	glVertex3f(-3.8f, 7.5f, 0.435f);
	glVertex3f(3.8f, 7.5f, 0.435f); glColor3ub(abuabu3);
	glVertex3f(3.8f, 7.5f, -0.435f);
	glVertex3f(-3.8f, 7.5f, -0.435f);

	// Bottom face (y = -1.0f)
	glColor3ub(abuabu1);
	glVertex3f(-3.8f, -7.5f, 0.435f);
	glVertex3f(3.8f, -7.5f, 0.435f);
// <<<<<<< HEAD
// 	glVertex3f(3.8f, -7.5f, -0.435f);
// 	glVertex3f(-3.8f, -7.5f, -0.435f);
// 	glEnd();  // End of drawing color-cube
//
	// glEnable(GL_TEXTURE_2D);
	// glBindTexture (GL_TEXTURE_2D, texture);
	// glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
	// // Front face  (z = 1.0f)
	// glColor3f(abuabu1);     // white
	// glTexCoord2i(0, 1); glVertex3f(-3.8f, 7.5f, 0.435f);
	// glTexCoord2i(0, 0); glVertex3f(-3.8f, -7.5f, 0.435f);
	// glTexCoord2i(1, 0); glVertex3f(3.8f, -7.5f, 0.435f);
	// glTexCoord2i(1, 1); glVertex3f(3.8f, 7.5f, 0.435f);
	// glEnd();  // End of drawing color-cube
	// glDisable(GL_TEXTURE_2D);
//
// 	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
// =======
	glColor3ub(abuabu3);
	glVertex3f(3.8f, -7.5f, -0.435f);
	glVertex3f(-3.8f, -7.5f, -0.435f);
	glEnd();


	glEnable(GL_TEXTURE_2D);
	glBindTexture (GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);

	// Front face  (z = 1.0f)

	glBindTexture (GL_TEXTURE_2D, texture);
	glColor3f(abuabu1);     // white
	glTexCoord2i(0, 1);glVertex3f(-3.8f, 7.5f, 0.435f);
	glTexCoord2i(0, 0);glVertex3f(-3.8f, -7.5f, 0.435f);
	glTexCoord2i(1, 0);glVertex3f(3.8f, -7.5f, 0.435f);
	glTexCoord2i(1, 1);glVertex3f(3.8f, 7.5f, 0.435f);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glBegin(GL_QUADS);
	// Back face (z = -1.0f)
	glColor3ub(abuabu1);
	glVertex3f(-3.8f, 7.5f, -0.435f);
	glVertex3f(-3.8f, -7.5f, -0.435f);
	glColor3ub(abuabu3);
	glVertex3f(3.8f, -7.5f, -0.435f);
	glVertex3f(3.8f, 7.5f, -0.435f);

	// Left face (x = -1.0f)
	glColor3ub(abuabu1);
	glVertex3f(-3.8f, 7.5f, 0.435f);
	glVertex3f(-3.8f, 7.5f, -0.435f); glColor3ub(abuabu3);
	glVertex3f(-3.8f, -7.5f, -0.435f);
	glVertex3f(-3.8f, -7.5f, 0.435f);

	// Right face (x = 1.0f)
	glColor3ub(abuabu1);
	glVertex3f(3.8f, 7.5f, 0.435f);
	glVertex3f(3.8f, 7.5f, -0.435f); glColor3ub(abuabu3);
	glVertex3f(3.8f, -7.5f, -0.435f);
	glVertex3f(3.8f, -7.5f, 0.435f);
	glEnd();  // End of drawing color-cube
}

void gambarkomponenbawah(){
	glBegin(GL_QUADS);
	glColor3ub(34, 36, 35);
	glVertex3f(-2.56f, -7.5f, 0.21f);
	glVertex3f(-1.85f, -7.5f, 0.21f);
	glVertex3f(-1.75f, -7.5f, -0.21f);
	glVertex3f(-2.66f, -7.5f, -0.21f);
	glEnd();

	float x = -3.4;
	float y = -7.5;
	float z = 0;
	float radius = 0.05;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(hitam);
	glVertex3f(x, y, 0); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y,
			z + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

}

void gambarkomponenkanan(){

	glBegin(GL_LINES);
	glColor3ub(hitam);
		glVertex3f(3.8, 6.4, 0.435);
		glVertex3f(3.8, 6.4, -0.435);
		glVertex3f(3.8, -6.4, 0.435);
		glVertex3f(3.8, -6.4, -0.435);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(abuabu2);
	glVertex3f(3.8f, 1.7f, 0.21f);
	glVertex3f(3.8f, 1.7f, -0.21f);
	glVertex3f(3.8f, 0.7f, -0.21f);
	glVertex3f(3.8f, 0.7f, 0.21f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(abuabu2);
	glVertex3f(3.8f, 5.1f, 0.21f);
	glVertex3f(3.8f, 5.1f, -0.21f);
	glVertex3f(3.8f, 2.3f, -0.21f);
	glVertex3f(3.8f, 2.3f, 0.21f);
	glEnd();

}

void gambarkomponenkiri(){

	glBegin(GL_LINES);
	glColor3ub(hitam);
		glVertex3f(-3.8, 6.4, 0.435);
		glVertex3f(-3.8, 6.4, -0.435);
		glVertex3f(-3.8, -6.4, 0.435);
		glVertex3f(-3.8, -6.4, -0.435);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(abuabu2);
	glVertex3f(-3.8f, 5.4f, 0.21f);
	glVertex3f(-3.8f, 5.4f, -0.21f);
	glVertex3f(-3.8f, 2.9f, -0.21f);
	glVertex3f(-3.8f, 2.9f, 0.21f);
	glEnd();

	float x = -3.8;
	float y = 3.2;
	float z = 0;
	float radius = 0.05;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(hitam);
	glVertex3f(x, y, 0); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x, y + (radius * cos(i *  twicePi / triangleAmount)),
			z + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

}

void gambarkomponenatas(){



	float x = -1.5;
	float y = 7.5;
	float z = 0;
	float radius = 0.3;



	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(hitam);
	glVertex3f(x, y, 0); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y,
			z + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	x = 1.4;
	radius = 0.2;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(hitam);
	glVertex3f(x, y, 0); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y,
			z + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	x = -2.5;
	radius = 0.05;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(hitam);
	glVertex3f(x, y, 0); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y,
			z + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

}

void gambarkomponenbelakang(){


	glBegin(GL_LINES);
		glColor3ub(hitam);
		glVertex3f(3.8, 6.4, -0.435);
		glVertex3f(-3.8, 6.4, -0.435);
		glVertex3f(3.8, -6.4, -0.435);
		glVertex3f(-3.8, -6.4, -0.435);
	glEnd();



	float x = 0;
	float y = 5.4;
	float z = -0.435;
	float radius = 0.7;



	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(hitam);
	glVertex3f(x, y, z); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)),
			z
			);
	}
	glEnd();


	x = 0;
	y = 5.4;
	z = -0.435;
	radius = 0.25;



	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(51,51,51);
	glVertex3f(x, y, z); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)),
			z
			);
	}
	glEnd();

	x = 0;
	y = 5.4;
	z = -0.435;
	radius = 0.1;



	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(hitam);
	glVertex3f(x, y, z); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)),
			z
			);
	}
	glEnd();

	x = 0;
	y = 4.3;
	z = -0.435;
	radius = 0.3;



	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(hitam);
	glVertex3f(x, y, z); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)),
			z
			);
	}
	glEnd();

	x = 0;
	y = 3.1;
	z = -0.435;
	radius = 0.7;



	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(hitam);
	glVertex3f(x, y, z); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)),
			z
			);
	}
	glEnd();

	x = 0;
	y = 3.1;
	z = -0.435;
	radius = 0.65;



	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(abuabu1);
	glVertex3f(x, y, z); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex3f(
			x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)),
			z
			);
	}
	glEnd();


	y = -5.7;
	z = -0.435;
	radius = 0.05;

	while (y > -6.3){
		x = -1.9;
		while (x <= 1.9){
			glBegin(GL_TRIANGLE_FAN);
			glColor3ub(hitam);
			glVertex3f(x, y, z); // center of circle
			for (int i = 0; i <= triangleAmount; i++) {
				glVertex3f(
					x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)),
					z
					);
			}
			glEnd();
			x = x + 0.2;
		}
		y = y - 0.2;
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

	// Render a color-cube consisting of 6 quads with different colors
	glLoadIdentity();                 // Reset the model-view matrix
	glTranslatef(0.0f, 0.0f, -30.0f);  // Move right and into the screen
	glRotatef(tippangle, 1, 0, 0);  // Up and down arrow keys 'tip' view.
	glRotatef(viewangle, 0, 1, 0);  // Right/left arrow keys 'turn' view.


	gambarbalokHP();
	gambarkomponenbawah();
	gambarkomponenkanan();
	gambarkomponenatas();
	gambarkomponenkiri();
	gambarkomponenbelakang();
	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
	angle += 0.2f;
	if (count < 80){
		count++;
		scale += (0.02f)*sign;
	}
	angle += 0.2f;
}

void timer(int value) {
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutSpecialFunc(Special_Keys);
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	initGL();                       // Our own OpenGL initialization
	glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}
