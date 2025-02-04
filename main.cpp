#include "scene1.hpp"
#include <GL/glut.h>
#include "scene2.hpp"
#include "scene3.hpp"
#include <iostream>

int state = 1;

void myInit()
{
    glClearColor(1., 1., 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void glutimercallback1(int x)
{
    if (state != 2)
        return; // Stop updating when not in Scene 2

    bladeAngle += 2.0f;
    if (bladeAngle > 360.0f)
        bladeAngle -= 360.0f;

    cloudX -= 0.001f;
    if (cloudX < -1.0f)
        cloudX = 1.0f;

    carX += 0.005f;
    if (carX > 1.0f)
        carX = -1.0f;

    truckX -= 0.004f;
    if (truckX < -1.0f)
        truckX = 1.0f;

    glutPostRedisplay();
    glutTimerFunc(10, glutimercallback1, 0);
}

void keyboardcallback(unsigned char key, int x, int y)
{
    if (key == '1')
        state = 1;
    else if (key == '2')
    {
        state = 2;
        glutTimerFunc(10, glutimercallback1, 0); // Restart timer for Scene 2
    }
    else if (key == '3')
        state = 3;

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (state == 1)
        gluOrtho2D(-100, 100, -100, 100);
    else if (state == 2)
        gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    else if (state == 3)
        gluOrtho2D(0, 1366.0, 0.0, 780.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (state == 1)
    {
        glutIdleFunc(day);
        display1();
    }
    else if (state == 2)
    {
        glutIdleFunc(nullptr);
        display2();
    }
    else if (state == 3)
    {
        glutIdleFunc(nullptr);
        display3();
    }

    glFlush();
}

void mouseCallback(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        PlaySound("sounds.wav", NULL, SND_ASYNC | SND_FILENAME);
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        PlaySound(NULL, NULL, 0); // Stops the sound
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Busy city scenario");
    glutTimerFunc(20,Cloud_Move,0);
    glutTimerFunc(20,Bus_Move,0);
    glutTimerFunc(20,Ambulance_Move,0);
    glutTimerFunc(20,Car_Move,0);
    //sndPlaySoundA("sounds.wav", SND_ASYNC);

    myInit();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardcallback);
    glutMouseFunc(mouseCallback);
    //PlaySound("sounds.wav", NULL, SND_ASYNC|SND_FILENAME);
    glutTimerFunc(10, glutimercallback1, 0);

    glutMainLoop();
    return 0;
}
