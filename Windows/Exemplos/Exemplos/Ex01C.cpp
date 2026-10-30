//
//  main.cpp
//  Exemplo 01C - Figuras Geométricas 3D
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

    //GL_CULL_FACE - Reúnem polígonos com base em suas curvas nas coordenadas das janelas.
    //GL_DEPTH_TEST - Se ativado, faz comparações de profundidade e atualize o buffer de profundidade.
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    //R G B Alfa
    // Define a cor de fundo da janela de visualização como preta
    glClearColor (0.0, 0.0, 0.0, 0.0);

    glShadeModel (GL_FLAT);
}

void Desenha(void){

    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix ();
    glRotatef (30.0, 1.0, 0.0, 0.0);
    glPushMatrix ();
    glTranslatef (-0.80, 0.35, 0.0);
    glRotatef (100.0, 1.0, 0.0, 0.0);
    glutSolidTorus (0.275, 0.85, 16, 16);
    //glutWireTorus (0.275, 0.85, 16, 16);
    glPopMatrix ();

    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix ();
    glTranslatef (-0.75, -0.50, 0.0);
    glRotatef (10.0, 0.0, 0.0, 1.0);
    glRotatef (10.0, 1.0, 0.0, 0.0);
    //glutSolidCube (1.5);
    glutWireCube (1.5);
    glPopMatrix ();

    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix ();
    glTranslatef (0.75, 0.60, 0.0);
    glRotatef (30.0, 1.0, 0.0, 0.0);
    //glutSolidSphere (1.0, 16, 16);
    glutWireSphere (1.0, 16, 16);
    glPopMatrix ();

    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix ();
    glTranslatef (0.70, -0.90, 0.25);
    //glutSolidOctahedron ();
    glutWireOctahedron ();
    glPopMatrix ();

    glPopMatrix ();
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
    glutCreateWindow ("Exemplo 01 - Objetos");
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutDisplayFunc(Desenha);

    //A função glMatrixMode() especifica a pilha de matrizes que será o alvo das operações matriciais subseqüentes; neste caso, a pilha de matrizes de projeção. A função glLoadIdentity() inicia a matriz de projeção corrente como a matriz identidade. A função gluPerspective() define a transformação de perspectiva usada no exemplo. Projeções geométricas não são alvo desta lição e por enquanto não serão estudadas.
    glMatrixMode (GL_PROJECTION);
    gluPerspective(65.0, 1.0, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef (0.0, 0.0, -5.0);


    Inicializa();
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
