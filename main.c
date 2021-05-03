#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static int width;
static int height;
float graus = 45;

void Timer(int value){

    graus += 1.0f;
    glutPostRedisplay();
    glutTimerFunc(33,Timer, 1);

}
static void display(void) {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //define a cor de fundo
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, width/2, height/2);//Viewport esquerda baixo
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50.0); //define uma proje��o ortogonal
    gluLookAt(0.0, 0.0, 3.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(1);



    glViewport(width/2, 0, width/2, height/2);//Viewport direita baixo
    glLoadIdentity();
    glPushMatrix(); //armazena a matriz corrente
    glRotatef(graus, 1, 0, 0);                //responsavel pela rotac�o do objeto
    gluPerspective(70.0, 1.0, 2.5, 50.0); //define uma proje��o perspectiva
    gluLookAt(0.0, 0.0, 4.5,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(1);
    glPopMatrix(); //restaura a matriz anterior



    glViewport(0, height/2, width/2, height/2);//Viewport esquerda encima
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50.0); //define uma proje��o ortogonal
    gluLookAt(0.0, 3.0, 0.0,
              0.0, 0.0, 0.0,
              0.0,  0.0,-3.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(1);



    glViewport(width/2, height/2, width/2, height/2);//Viewport direita encima
    glLoadIdentity();
    glOrtho(-3.0, 3.0, -3.0, 3.0, 1.0, 50.0); //define uma proje��o ortogonal
    gluLookAt(-3.0, 0.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireTeapot(1);

    glFlush();
}

static void reshape(int w, int h) {
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);

    glutDisplayFunc(display);
    glutTimerFunc(20,Timer, 1);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return EXIT_SUCCESS;
}
