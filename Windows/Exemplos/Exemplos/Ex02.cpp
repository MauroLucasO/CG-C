//
//  main.cpp
//  Exemplo 02 - Linhas simples formando um quadrado colorido.
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

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Especifica que a cor corrente é vermelha
    //         R     G     B
    glColor3f(1.0f, 0.0f, 0.0f);

    // Desenha um quadrado preenchido com a cor corrente
    glPointSize(3);
    glLineWidth(3);
    //glBegin(GL_POINTS);
    //glBegin(GL_LINES);
    //glBegin(GL_LINE_STRIP);
    glBegin(GL_LINE_LOOP);
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
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (left, right, bottom, top)
    if (w <= h)
        gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
    else
        gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

//Verifica se a Tecla "esc" foi prescionada para encerrar o programa
void Teclado(unsigned char key, int x, int y){
    switch (key) {
        case 27:
        exit(0);
        break;
    }
}

// Programa Principal
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(200,200);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Quadrado");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutKeyboardFunc(Teclado);
    glutMainLoop();
    return 0;
}
