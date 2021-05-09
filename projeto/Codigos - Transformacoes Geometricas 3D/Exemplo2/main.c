#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

float alpha=0, beta=0, delta=1;

int init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);     //define a cor de fundo
    glEnable(GL_DEPTH_TEST);           //remo��o de superf�cie oculta

    glMatrixMode(GL_PROJECTION);          //define que a matriz � a de proje��o
    glLoadIdentity();                     //carrega a matriz de identidade
    glOrtho(-5,5,-5,5,-5,5);          //define uma proje��o ortogr�fica
}

void display(void){
    //limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //define que a matrix � a de modelo
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glScalef(delta, delta, delta); //fa�a a escala de todos objetos

    glColor3f(1, 1, 0);
    glPushMatrix(); //armazena a matriz corrente
        glTranslatef(-3, 0, 0);
        glRotatef(beta, 0, 1, 0);
        glRotatef(alpha, 1, 0, 0);
        glutWireSphere(1, 20, 20);
    glPopMatrix(); //restaura a matriz anterior

    glColor3f(1, 0, 0);
    glPushMatrix(); //armazena a matriz corrente
        glTranslatef(3, 0, 0);
        glRotatef(beta, 0, 1, 0);
        glRotatef(alpha, 1, 0, 0);
        glutWireSphere(1, 20, 20);
    glPopMatrix(); //restaura a matriz anterior

    //for�a o desenho das primitivas
    glFlush();
}


// Fun��o que trata teclas especiais do teclado
void keyPressed_special(int key, int x, int y){
    if(key == GLUT_KEY_PAGE_UP){//faz zoom-in
        delta = delta * 1.1f;
    }
    if(key == GLUT_KEY_PAGE_DOWN){//faz zoom-out
        delta = delta * 0.809f;
    }
    if(key == GLUT_KEY_RIGHT){//gira sobre o eixo-y
        beta = beta - 1;
    }
    if(key == GLUT_KEY_LEFT){//gira sobre o eixo-y
        beta = beta + 1;
    }
    if(key == GLUT_KEY_UP){ //gira sobre o eixo-x
        alpha = alpha - 1;
    }
    if(key == GLUT_KEY_DOWN){ //gira sobre o eixo-x
         alpha = alpha + 1;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posi��o inicial da janela
    glutInitWindowSize(800,800);                    //configura a largura e altura da janela de exibi��o
    glutCreateWindow("3D");                 //cria a janela de exibi��o

    init();                                         //executa fun��o de inicializa��o
    glutSpecialFunc(keyPressed_special);
    glutDisplayFunc(display);
    glutMainLoop();                                  //mostre tudo e espere
    return 0;
}
