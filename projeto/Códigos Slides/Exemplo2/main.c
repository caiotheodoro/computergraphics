#include <windows.h>
#include <GL/glut.h>

void init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //define a cor de fundo

    //habilita o teste de profundidade
    glEnable(GL_DEPTH_TEST);

    //habilita remo��o de faces ocultas
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //carrega a matriz de identidade
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0); //proje��o ortogonal
}

void display(void){
    //limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //define que a matriz � a de modelo
    glMatrixMode(GL_MODELVIEW);

    //tri�ngulo na frente
    glColor3f(1.0f, 0.0f, 0.0f); //N . V < 0 (vis�vel)
    glBegin(GL_TRIANGLES);
        glVertex3f(-2, -2, 0);
        glVertex3f(2, -2, 0);
        glVertex3f(0, 2, 0);
    glEnd();

    //tri�ngulo atr�s
    glColor3f(0.0f, 0.0f, 1.0f); //N . V < 0  (vis�vel)
    glBegin(GL_TRIANGLES);
        glVertex3f(0, 0, -2);
        glVertex3f(4, 0, -2);
        glVertex3f(2, 4, -2);
    glEnd();

    //for�a o desenho das primitivas
    glFlush();
}

int main(int argc, char **argv){
  /* cria uma janela */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH); /* single buffering */
  glutInitWindowSize(400, 400);
  glutCreateWindow("Exemplo 2 - Z-Buffer");

  glutDisplayFunc(display);

  init(); //executa funcao de inicializacao

  glutMainLoop(); //mostre tudo e espere
  return(0);
}
