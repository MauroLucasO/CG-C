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

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void Desenha() {
    // Limpa a tela com a cor de fundo definida
    glClear(GL_COLOR_BUFFER_BIT);

    // Define a cor do triângulo como VERMELHO (R=1.0, G=0.0, B=0.0)
    glColor3f(1.0f, 0.0f, 0.0f);

    // Desenha o triângulo
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.0f,  0.5f);
    glEnd();

    glFlush();
}

void Inicializa() {
    // Cor de fundo (mantida em azul; altere os valores se quiser mudar o fundo)
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

// Verifica se a Tecla "esc" foi pressionada para encerrar o programa
void Teclado(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Triangulo Vermelho");

    Inicializa();

    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclado);

    glutMainLoop();
    return 0;
}
