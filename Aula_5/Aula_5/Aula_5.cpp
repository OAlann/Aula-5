#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>

float angle = 0.0f;
float scale = 1.0f;
float translateX = 0.0f;
float translateXNave = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Rotacionar cubo
    glPushMatrix();
    glRotatef(angle, 1.0f, 1.0f, 1.0f);
    glutWireCube(1.0);
    glPopMatrix();

    // Escalar esfera
    glPushMatrix();
    glScalef(scale, scale, scale);
    glTranslatef(0.0f, 0.0f, 0.0f);
    glutWireSphere(0.5, 20, 20);
    glPopMatrix();

    // Transladar teapot
    glPushMatrix();
    glTranslatef(translateX, 0.0f, 0.0f);
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glutWireTeapot(0.5);
    glPopMatrix();

    // Desenhar nave espacial
    glPushMatrix();
    glTranslatef(translateXNave, 0.0f, 0.0f);
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    // Corpo da nave
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    // Asas da nave
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(-0.7f, -0.3f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.7f, -0.3f, 0.0f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'r': // Rotacionar cubo
        angle += 5.0f;
        break;
    case 's': // Escalar esfera
        scale += 0.1f;
        break;
    case 't': // Transladar teapot
        translateX += 0.1f;
        break;
    case 'n': // Transladar nave
        translateXNave += 0.1f;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Transformações em OpenGL");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}