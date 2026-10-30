//
//  main.cpp
//  Exemplo 03 - Alterar tamanho da janela com "redimencionamento" da figura.
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

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-100.0f, -30.0f, 0.0f);
    glScalef(1.5f, 0.5f, 1.0f);

    glBegin(GL_QUADS);
        glVertex2i(100,150);
        glVertex2i(100,100);
        // Especifica que a cor corrente é azul
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(150,100);
        glVertex2i(150,150);
    glEnd();

    glFlush();
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
    if (w <= h) {
        gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
    } else {
        gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
    }
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

    glutInitWindowSize(400,350);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Quadrado");

    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);

    Inicializa();

    glutKeyboardFunc(Teclado);
    glutMainLoop();
    return 0;
}
