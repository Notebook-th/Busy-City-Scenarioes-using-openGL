
#pragma once
#include <GL/glut.h>
#include <cmath>

float bladeAngle = 0.0f;
float cloudX = -1.0f;
float carX = -1.0f, truckX = 1.0f;

void drawCircle(float x, float y, float radius)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; i++)
    {
        float angle = 2.0f * 3.14 * i / 100;
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawGradientSky()
{
    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.81f, 0.92f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.12f, 0.56f, 1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();
}

void drawWindmill(float x, float y)
{

    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.1f, y);
    glVertex2f(x + 0.1f, y);
    glVertex2f(x + 0.07f, y + 0.6f);
    glVertex2f(x - 0.07f, y + 0.6f);
    glEnd();

    glPushMatrix();
    glTranslatef(x, y + 0.6f, 0.0f);
    glRotatef(bladeAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < 4; i++)
    {
        glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.3f, 0.05f);
        glVertex2f(0.3f, -0.05f);
        glEnd();
    }
    glPopMatrix();
}

void drawGrass()
{
    glBegin(GL_QUADS);
    glColor3f(0.19f, 0.8f, 0.19f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glColor3f(0.25f, 0.88f, 0.25f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();
}

void drawHighway()
{

    glColor3f(0.41f, 0.41f, 0.41f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(-1.0f, -0.6f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    for (float i = -1.0f; i < 1.0f; i += 0.2f)
    {
        glBegin(GL_QUADS);
        glVertex2f(i - 0.02f, -0.8f);
        glVertex2f(i + 0.02f, -0.8f);
        glVertex2f(i + 0.02f, -0.78f);
        glVertex2f(i - 0.02f, -0.78f);
        glEnd();
    }
}

void drawCar(float x, float y)
{

    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.1f, y);
    glVertex2f(x + 0.1f, y);
    glVertex2f(x + 0.1f, y + 0.05f);
    glVertex2f(x - 0.1f, y + 0.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x - 0.07f, y + 0.05f);
    glVertex2f(x + 0.07f, y + 0.05f);
    glVertex2f(x + 0.05f, y + 0.1f);
    glVertex2f(x - 0.05f, y + 0.1f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(x - 0.07f, y, 0.02f);
    drawCircle(x + 0.07f, y, 0.02f);
}

void drawTruck(float x, float y)
{

    glColor3f(0.0f, 0.5f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.2f, y);
    glVertex2f(x + 0.2f, y);
    glVertex2f(x + 0.2f, y + 0.1f);
    glVertex2f(x - 0.2f, y + 0.1f);
    glEnd();

    glColor3f(0.0f, 0.3f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.2f, y + 0.1f);
    glVertex2f(x - 0.05f, y + 0.1f);
    glVertex2f(x - 0.05f, y + 0.2f);
    glVertex2f(x - 0.2f, y + 0.2f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(x - 0.15f, y, 0.03f);
    drawCircle(x + 0.15f, y, 0.03f);
}

void drawTree(float x, float y)
{

    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(x - 0.05f, y);
    glVertex2f(x + 0.05f, y);
    glVertex2f(x + 0.05f, y + 0.4f);
    glVertex2f(x - 0.05f, y + 0.4f);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    drawCircle(x, y + 0.5f, 0.2f);
    drawCircle(x - 0.1f, y + 0.4f, 0.15f);
    drawCircle(x + 0.1f, y + 0.4f, 0.15f);
}

void drawClouds(float x, float y)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 0.1f);
    drawCircle(x + 0.1f, y, 0.12f);
    drawCircle(x + 0.2f, y, 0.1f);
}
void timer(int)
{
    bladeAngle += 9.0f;
    if (bladeAngle > 360.0f)
        bladeAngle -= 360.0f;

    cloudX += 0.001f;
    if (cloudX > 1.0f)
        cloudX = -1.0f;

    carX += 0.005f;
    if (carX > 1.0f)
        carX = -1.0f;

    truckX -= 0.004f;
    if (truckX < -1.0f)
        truckX = 1.0f;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void display2()
{
    drawGradientSky();
    drawGrass();
    drawHighway();
    drawCar(carX, -0.85f);
    drawTruck(truckX, -0.95f);
    drawWindmill(-0.7f, -0.5f);
    drawWindmill(0.2f, -0.5f);
    drawTree(0.6f, -0.5f);
    drawClouds(cloudX, 0.8f);
    drawClouds(cloudX + 0.5f, 0.7f);

    glFlush();
}
