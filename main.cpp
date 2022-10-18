#include <gl/glut.h>
#include <windows.h>
float xrot=0;
float yrot=0;
float xdiff=0;
float ydiff=0;
bool mouseDown = false;

void ukur (int lebar, int tinggi){
if (tinggi==0) tinggi=1;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45,lebar/tinggi,5,450);
glTranslatef(0,0,-300);
glMatrixMode(GL_MODELVIEW);

}

void myinit(void){
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glEnable(GL_DEPTH_TEST);

glMatrixMode(GL_MODELVIEW);
glPointSize(10.0);
glLineWidth(7.0f);

}

void tampilan(void){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(0,0,3,0,0,0,0,1,0);
glRotatef(xrot, 1, 0,0);
glRotatef(yrot, 0,1,0);

//Lantai gedung
glBegin(GL_POLYGON);
glColor3f(1,1,0.5);
glVertex3f(-50,-50,30);
glVertex3f(50,-50,30);
glVertex3f(50,-50,-40);
glVertex3f(-50,-50,-40);
glEnd();
}




int main (int argc, char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition(240,80);
glutInitWindowSize(700,600);
glutCreateWindow("Gedungg afh iyh ");
myinit();
glutDisplayFunc(tampilan);
glutMainLoop();
}
