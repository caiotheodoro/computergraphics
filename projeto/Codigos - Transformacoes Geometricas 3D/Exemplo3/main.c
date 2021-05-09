#include <windows.h>
#include <GL/glut.h>

float dia = 0, hora = 0;

void Timer(int value){
    hora += 1.0f;
    if (hora >= 24.0f){
        hora = 0.0f;
        dia += 1.0f;
        if (dia >= 360.0f){
            dia = 0.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(40,Timer, 1);
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);     //define a cor de fundo
    glMatrixMode(GL_PROJECTION);          //define que a matriz é a de projeção
    glLoadIdentity();
    glOrtho(-5.2,5.2,-5.2,5.2,-5.2,5.2);          //define uma projeção ortográfica
}

void display(void){
    //limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,1.0,0.0, //posição da câmera
              0.0,0.0,0.0, //para onde a câmera aponta
              1.0,0.0,0.0); //vetor view-up

    glPushMatrix(); //desenha sol
        glColor4f(1.0, 1.0, 0.0, 1.0);
        glRotatef(360.0f/28.0f*dia,0,1,0);
        glutWireSphere(1,20,20);
    glPopMatrix();

    glPushMatrix(); //desenha terra
        glColor4f(0.0, 0.0, 1.0, 1.0);
        glRotatef(dia,0,1,0);
        glTranslatef(4,0,0);
        glRotatef(360.0f/24.0f*hora,0,1,0);
        glutWireSphere(0.5,10,10);

        glColor4f (0.81, 0.78, 0.79, 1.0); // cor da lua
        glRotatef(360.0f/28.0f*dia,0.0,1.0,0.0);
        glTranslatef(1.0,0.0,0.0);
        glutWireSphere(0.2,5,5);
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posição inicial da janela
    glutInitWindowSize(800,800);                    //configura a largura e altura da janela de exibição
    glutCreateWindow("Projeto 3 - Sistema Solar");                 //cria a janela de exibição

    init();                                         //executa função de inicialização
    glutDisplayFunc(display);
    glutTimerFunc(40,Timer, 1);
    glutMainLoop();                                  //mostre tudo e espere
    return 0;
}
