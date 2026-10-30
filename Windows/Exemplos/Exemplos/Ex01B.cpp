//
//  main.cpp
//  Exemplo 01B - Cubos3D
//  Created by Sandro Fernandes.
//  Copyright © 2026 Sandro Fernandes. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>

#ifdef __APPLE__
    #include <GLUT/glut.h>
#elif defined(_WIN32) || defined(__WIN32__)
    #define GLUT_DISABLE_ATEXIT_HACK
    #include <GL/gl.h>
    #include <GL/glu.h>
    #include <GL/glut.h>
#elif __linux__
    #include <GL/glut.h>
#else
    #error "SO não implementado no exemplo."
#endif

/*
Mesmo sendo o mesmo comando para incluir a biblioteca GLUT
no Windows e Linux, foi mantido a separação caso o
desenvolvedor deseje incluir outras bibliotecas no futuro.
*/

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void Inicializa (void)
{
    //R G B Alfa
    // Define a cor de fundo da janela de visualização como preta
    glClearColor (0.0, 0.0, 0.0, 0.0);

}

void Desenha(void){

    //Uma vez que as transformações geométricas no espaço são representadas por matrizes, o uso de uma pilha de matrizes de transformação ajuda a lembrar a seqüência de transformações realizadas. No OpenGL, esta facilidade é provida pelas funções glPushMatrix(), que insere a matriz de transformação corrente na pilha, e glPopMatrix(), que retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente. Neste exemplo, a função glPushMatrix() serve para lembrar os parâmetros de translação, rotação e escalamento no início das operações de desenho.
    glClear (GL_COLOR_BUFFER_BIT);


    //O conjunto de transformações sobre o primeiro cubo a ser desenhado é delimitado pelo glPushMatrix() e glPopMatrix(). A origem do sistema de coordenadas é levado para o ponto (x,y,z)=(-2.0,0.0,0.0) através da função glTranslatef(), definindo a coordenada de origem (pivô) para o desenho do cubo. Em seguida, usando a função glScalef(), o sistema de coordenadas é ampliado em (Sx,Sy,Sz)=(3.0,2.0,5.0), e, finalmente, desenhado um cubo aramado através de glutWireCube().
    /* Cubo 1 */
    glPushMatrix();
    glTranslatef (-2.0, 0.0, 0.0);
    glScalef (3.0, 2.0, 5.0);
    glutWireCube (1.0);
    glPopMatrix();

    /*
    A função glRotatef() possui o seguinte protótipo:

    void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);

    Quando chamada, glRotatef() efetua uma rotação de angle graus no sistema de coordenadas na direção contra o sentido do relógio em torno de um vetor que vai da origem ao ponto (x,y,z)

    Observe que os cubos 3 e 4 não são também rotacionados mesmo estando após o uso da função glRotatef() sobre o cubo 2, em função da delimitação da pilha de execução delimitada por glPushMatrix() e glPopMatrix().
    */

    /* Cubo 2 */
    glPushMatrix();
    glRotatef (25.0, 0.0, 0.0, 1.0);
    glTranslatef (2.0, 0.0, 0.0);
    glScalef (2.0, 1.0, 4.0);
    glutWireCube (1.0);
    glPopMatrix();

    /* Cubo 3 */
    glPushMatrix();
    glTranslatef (0.0, 2.0, 0.0);
    glScalef (2.0, 1.0, 4.0);
    glutWireCube (1.0);
    glPopMatrix();

    /* Cubo 4 */
    glPushMatrix();
    glTranslatef (0.0, -2.0, 0.0);
    glScalef (2.0, 1.0, 4.0);
    glutWireCube (1.0);
    glPopMatrix();


    //A função glPopMatrix() remove a matriz de transformação do topo da pilha, fazendo-a corrente, retornando assim o sistema de coordenadas original. Quando glutSwapBuffers() é chamada, os buffers de desenho e de apresentação são alternados e a nova imagem dos cubos é apresentada.
    glFlush();
}

//Verifica se a Tecla "esc" foi precionada para encerrar o programa
void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
        exit(0);
        break;
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Exemplo 01 - Cubos");
    glutDisplayFunc(Desenha);

    //A função glMatrixMode() especifica a pilha de matrizes que será o alvo das operações matriciais subseqüentes; neste caso, a pilha de matrizes de projeção. A função glLoadIdentity() inicia a matriz de projeção corrente como a matriz identidade. A função gluPerspective() define a transformação de perspectiva usada no exemplo. Projeções geométricas não são alvo desta lição e por enquanto não serão estudadas.
    glMatrixMode (GL_PROJECTION);
    gluPerspective(65.0, 1.0, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef (0.0, 0.0, -10.0);


    Inicializa();
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}


