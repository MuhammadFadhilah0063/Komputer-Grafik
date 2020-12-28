//Memanggil Library
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>

//Deklarasi Variable
float z_pos=-10.0f;
float rot=0.0f;

//Membuat Method resize
void resize(int width, int height)
{
       glViewport(0, 0, width, height);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       gluPerspective(45.0, (float)width/(float)height, 1.0, 300.0);
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       }

//Membuat Method timeout
void myTimeOut(int id)
{
// called if timer event
// ...advance the state of animation incrementally...
       rot+=10;
       glutPostRedisplay(); // request redisplay
       glutTimerFunc(100, myTimeOut, 0); // request next timer event
}

//Membuat Method keyboard
void myKeyboard(unsigned char key,int x, int y)
{
       if((key=='<')||(key==',')) z_pos-=0.1f;
       if((key=='>')||(key=='.')) z_pos+=0.1f;
}

//Membuat Method display
void mydisplay(void)
{
//glClear(GL_COLOR_BUFFER_BIT );
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glLoadIdentity();
       glTranslatef(0.0,0.0f,z_pos);
       glRotatef(rot, 0, 1, 0);
       glBegin(GL_QUADS);
// Front Face, red
       glColor3f(1.0,0.0,0.0);
       glVertex3f(-1.5f, -1.0f, 1.0f);
       glColor3f(1.0,1.0,0.0);
       glVertex3f( 1.0f, -1.0f, 1.0f);
       glColor3f(1.0,0.0,1.0);
       glVertex3f( 1.5f, 1.0f, 1.0f);
       glColor3f(1.0,0.5,0.0);
       glVertex3f(-1.0f, 1.0f, 1.0f);
       glEnd();
       glFlush();
       glutSwapBuffers();
}

//Membuat Method inisialisasi
void init()
{
       glEnable(GL_DEPTH_TEST);
       glClearColor( 0.0, 0.0, 0.0, 1.0 ); // A Background Clear Color
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       gluPerspective(45, (GLdouble)500.0/(GLdouble)500.0, 0, 100);
       glMatrixMode(GL_MODELVIEW);
       return;
}

//Program Utama
int main(int argc, char** argv)
{
       glutInit(&argc,argv);
       //glutInitDisplayMode( GLUT_DOUBLE /*| GLUT_DEPTH*/ );
       glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
       glutInitWindowSize(500,500);
       glutInitWindowPosition(0,0);
       glutCreateWindow("Jajar Genjang Warna Animasi");
       // callbacks
       glutDisplayFunc(mydisplay);
       glutKeyboardFunc(myKeyboard);
       glutTimerFunc(100, myTimeOut, 0);
       glutReshapeFunc(resize);
       init();
       glutMainLoop();
       return 0;
}

