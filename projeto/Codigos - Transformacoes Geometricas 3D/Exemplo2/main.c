#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

float alpha=0, beta=0, delta=1;

int init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);     //define a cor de fundo
    glEnable(GL_DEPTH_TEST);           //remoção de superfície oculta

    glMatrixMode(GL_PROJECTION);          //define que a matriz é a de projeção
    glLoadIdentity();                     //carrega a matriz de identidade
    glOrtho(-5,5,-5,5,-5,5);          //define uma projeção ortográfica
}

void display(void){
    //limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //define que a matrix é a de modelo
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glScalef(delta, delta, delta); //faça a escala de todos objetos

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

    //força o desenho das primitivas
    glFlush();
}


// Função que trata teclas especiais do teclado
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
    glutInitWindowPosition(200,0);                  //seta a posição inicial da janela
    glutInitWindowSize(800,800);                    //configura a largura e altura da janela de exibição
    glutCreateWindow("3D");                 //cria a janela de exibição

    init();                                         //executa função de inicialização
    glutSpecialFunc(keyPressed_special);
    glutDisplayFunc(display);
    glutMainLoop();                                  //mostre tudo e espere
    return 0;
}
