//
//  main.cpp
//  Exemplo 01A - Quadrado com cores
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

//Callback: Código executável que é passado como um argumento para outro código, deverá chamar de volta (callback) o argumento em um determinado momento.

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    //glMatrixMode: Especifica a pilha de matrizes que será o alvo das operações matriciais. Neste caso, GL_MODELVIEW.
    //GL_MODELVIEW: Pilha de matrizes deusadas para definir translação, rotação e escalamento.
    glMatrixMode(GL_MODELVIEW);

    //Inicia a matriz de projeção corrente como a matriz identidade.
    glLoadIdentity();

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Especifica que a cor corrente é vermelha
    //         R     G     B
    glColor3f(1.0f, 0.0f, 0.0f);

    // Desenha um quadrado preenchido com a cor corrente
    //Lista dos parâmetros de figuras primitivas: https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glBegin.xml

    glBegin(GL_QUADS);
        glVertex2i(100,150);
        glVertex2i(100,100);
        // Especifica que a cor corrente é azul
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(150,100);
        glVertex2i(150,150);
    glEnd();


    // Executa os comandos OpenGL
    glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    //R G B Alfa

    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Define a cor de fundo da janela de visualização como branca
    //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

//Verifica se a Tecla "esc" foi precionada para encerrar o programa
void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
        exit(0);
        break;
    }
}

// Programa Principal
int main(int argc, char **argv)
{
    //glutInit: Inicializa a biblioteca Glut
    glutInit(&argc, argv);

    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Exemplo 01 - Quadrado");
    glutDisplayFunc(Desenha);

    //glViewport: Define a área dentro da janela de desenho no sistema de coordenadas atual, origem (x,y), largura (w) e altura (h), que OpenGL pode utilizar para efetuar desenhos. Este trecho de código permite que toda a área da janela possa ser utilizada quando a janela sofrer redimensionamento.
    glViewport(0, 0, 0, 1);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //gluOrtho2D: Usada para determinar que a projeção ortográfica (2D) será utilizada para exibir na tela a imagem 2D que está na janela de seleção definida através dos parâmetros passados para esta função.
    gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f);

    Inicializa();
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
