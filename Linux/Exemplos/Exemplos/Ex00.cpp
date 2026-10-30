//
//  main.cpp
//  Exemplo 00 - Instalação do OpenGL
//  Created by Sandro Fernandes.
//  Copyright © 2026 Sandro Fernandes. All rights reserved.
//


#include <iostream> 
#include <stdlib.h> 
#include <fstream>

#ifdef __APPLE__
    #include <GLUT/glut.h>
#elif _WIN32
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

void Desenha(){
    glClearColor(0, 0, 0, 0); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.7f, 1.0f, 0.5f);
    glBegin(GL_TRIANGLES); 
        glVertex3f(-0.5, -0.5, 0); 
        glVertex3f(0, 0.5, 0); 
        glVertex3f(0.5, -0.5, 0);
    glEnd();
    glFlush(); 
}

void Inicializa(){ 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
    glMatrixMode(GL_MODELVIEW);
}

//Verifica se a Tecla "esc" foi precionada para encerrar o programa
void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 27:
        exit(0);
        break;
    } 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500); 
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("Exemplo 00 - Instalação"); 
    glutDisplayFunc(Desenha);
    Inicializa();
    glutKeyboardFunc(keyboard);
    glutMainLoop(); 
    return 0;
}
