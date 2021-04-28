#include <GL/glut.h>
#include <math.h>
 
GLfloat xf=0, yf=0, graus=0,flag=0;
 
int init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);     //define a cor de fundo
 
    glMatrixMode(GL_PROJECTION);          //carrega a matriz de projeção
    gluOrtho2D(0,100,0,100);      //define projeção ortogonal 2D
 
}
 
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);         //desenha o fundo (limpa a janela)
 
 
    glColor3f(1.0,0.0,0.0);      //altera o atributo de cor

    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity(); //posiciona a matriz identidade
 


    glTranslatef(yf+5,xf+5, 0);           //responsavel pela transação do objeto
    glRotatef(graus, 0, 0, 1);                //responsavel pela rotacão do objeto
    glTranslatef(-5,-5, 0);          //responsavel pela transação do objeto
  
    glBegin(GL_QUADS);                    //quadrado
               glVertex2f(10,  10);
               glVertex2f(10, 0);
               glVertex2f(0,0);
               glVertex2f(0, 10);
 
    glEnd();
 
    glFlush();                            //desenha os comandos não executados
}
void GerenciaTecladoEspecial(unsigned char key, int x, int y){}
void GerenciaTeclado(unsigned char key, int x, int y)//funcao responsaver pelo controle do teclado
{}
 
int main(int argc, char** argv) {
 
    glutInit(&argc,argv);                                     //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);               //configura o modo de display
    glutInitWindowSize(500,500);                              //configura a largura e altura da janela de exibição
    glutInitWindowPosition(200,200);
    glutCreateWindow("Quadrado");           //cria a janela de exibição
    // glutKeyboardFunc(GerenciaTeclado);      //estabelece comunicação com o teclado
    //glutSpecialFunc(GerenciaTecladoEspecial);
    init();                          //executa função de inicialização
    glutDisplayFunc(display);        //estabelece a função "display" como a função callback de exibição.
    glutMainLoop();                  //mostre tudo e espere
    return 0;
}
 
 

