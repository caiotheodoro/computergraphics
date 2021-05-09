#include <windows.h>
#include <GL/glut.h>

int init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //define a cor de fundo
    glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade

    glMatrixMode(GL_MODELVIEW); //define que a matriz é a model view
    glLoadIdentity(); //carrega a matriz de identidade
    gluLookAt(0.0, 0.0, 1.0, //posição da câmera
              0.0, 0.0, 0.0, //para onde a câmera aponta
              0.0, 1.0, 0.0); //vetor view-up
    glMatrixMode(GL_PROJECTION); //define que a matriz é a de projeção
    glLoadIdentity(); //carrega a matriz de identidade
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

    lighting();
}

void lighting(){
    float position[4] = {2.0f, 2.0f, 2.0f, 1.0f};
    float white[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    //ativa a iluminação
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void display(){
    //limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//define que a matriz é a model view
    glMatrixMode(GL_MODELVIEW);
    glutSolidSphere(1.5, 40, 40);
    //força o desenho das primitivas
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);                           //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);    //configura o modo de display
    glutInitWindowPosition(200,0);                  //seta a posição inicial da janela
    glutInitWindowSize(400,400);                    //configura a largura e altura da janela de exibição
    glutCreateWindow("Projeto 1 - Especificando as Cores da Fonte de Luz");                 //cria a janela de exibição

    init();                                         //executa função de inicialização
    glutDisplayFunc(display);
    glutMainLoop();                                  //mostre tudo e espere
    return 0;
}
