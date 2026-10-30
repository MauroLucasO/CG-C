//
//  main.cpp
//  Esqueleto para OpenGL
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
    //
}

void Inicializa(){
    //
}

//Verifica se a Tecla "esc" foi precionada para encerrar o programa
void Teclado(unsigned char key, int x, int y){
    switch (key) {
        case 27:
        exit(0);
        break;
    }
}

int main(int argc, char** argv) {
    //
    return 0;
}
