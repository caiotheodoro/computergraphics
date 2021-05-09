#include <windows.h>
#include <GL/glut.h>

int init(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //define a cor de fundo
    glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade

    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(0.0, 0.0, 1.0, //posição da câmera
              0.0, 0.0, 0.0, //para onde a câmera aponta
              0.0, 1.0, 0.0); //vetor view􀀀up
    glMatrixMode(GL_PROJECTION); //define que a matrix é a de projeção
    glLoadIdentity(); //carrega a matrix de identidade
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

    lighting();
}

void lighting(){
    //define a posição e parâmetros da luz 0
    float position[4] = {2.0f, 2.0f, 2.0f, 1.0f};
    float white[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    //ativando luz ambiente global
    float global_ambient[4] = {0.7f, 0.7f, 0.7f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    //ativa a iluminação
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void display(){
    //limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //define material da superfície
    float kd[4] = {0.65f, 0.65f, 0.0f, 1.0f};
    float ks[4] = {1.0f, 0.0f, 0.0f, 1.0f};
    float ns = 120.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, kd);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    //define que a matrix é a a model view
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
    glutCreateWindow("Exemplo 4 - Propriedades da Superficie");                 //cria a janela de exibição

    init();                                         //executa função de inicialização
    glutDisplayFunc(display);
    glutMainLoop();                                  //mostre tudo e espere
    return 0;

}
