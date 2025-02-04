#pragma once
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <math.h>
#include <iostream>

GLfloat position_1          = 0.0f;
GLfloat position_2          = 0.0f;
GLfloat speed               = 0.00f;
GLfloat speed_car           = 0.00f;
GLfloat position_car_1      = 0.0f;
GLfloat position_car_3      = 0.0f;
GLfloat position_4          = 0.0f;
GLfloat position_trainover  = 0.0f;
GLfloat position_trainUnder = 0.0f;
GLfloat sun_position        = -40;
GLfloat sun_speed           = .01;

void day()
{
    speed = 0.01f;
    speed_car = 0.01f;

    if (position_1 > 185)
        position_1 = -180.0f;
    position_1 += speed + .01;

    if (position_2 > 120)
        position_2 = -180.0f;
    position_2 += speed;

    if (position_car_1 < -120)
        position_car_1 = 180.0f;
    position_car_1 -= speed_car + .1;

    if (position_car_3 > 160)
        position_car_3 = -180.0f;
    position_car_3 += speed_car + .1;

    if (position_4 < -220)
        position_4 = 180.0f;
    position_4 -= speed_car + .1;

    if (position_trainover > 220)
        position_trainover = -180.0f;
    position_trainover += speed_car + .1;

    if (position_trainUnder < -220)
        position_trainUnder = 220.0f;
    position_trainUnder -= speed_car + .1;
    glutPostRedisplay();

    sun_position += sun_speed;
    if (sun_position >= 5)
        sun_position = 5;
}

void drawQuad(GLint x0, GLint y0, GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3)
{
    glBegin(GL_QUADS);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawTriangle(GLint x0, GLint y0, GLint x1, GLint y1, GLint x2, GLint y2)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}
void drawLine(GLint x0, GLint y0, GLint x1, GLint y1)
{
    glBegin(GL_LINES);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
    glEnd();
}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // get current angle
        float x = r * cosf(theta);                                        // calculate x
        float y = r * sinf(theta);                                        // calculate y
        glVertex2f(x + cx, y + cy);                                       // output vertex
    }
    glEnd();
}

// platform
void platform()
{
    // pillar garden under wall
    glColor3ub(157, 170, 179);
    drawQuad(-100, -15, 100, -15, 100, -14, -100, -14);

    // below pillar block
    glColor3ub(0, 255, 0);
    drawQuad(-100, -22, 100, -22, 100, -15, -100, -15);

    // pillar 1 sideways line
    glLineWidth(4);
    glColor3ub(0, 0, 0);
    drawLine(-78, -17, -78, 25);
    drawLine(-80, -20, -78, -17);

    // pillar 3 sideways line
    glLineWidth(4);
    glColor3ub(0, 0, 0);
    drawLine(78, -17, 78, 25);
    drawLine(80, -20, 78, -17);

    // pillar 1 sideways
    glColor3ub(122, 132, 143);
    drawQuad(-80, -20, -78, -17, -78, 25, -80, 25); // pillar 1 sideways

    // pillar 3 sideways
    glColor3ub(122, 132, 143);
    drawQuad(80, -20, 78, -17, 78, 25, 80, 25); // pillar 3 sideways

    // pillar 1 lines
    glLineWidth(4);
    glColor3ub(0, 0, 0);
    drawLine(-83, -20, -80, -20);
    glColor3ub(0, 0, 0);
    drawLine(-80, -20, -80, 25);
    glColor3ub(0, 0, 0);
    drawLine(-83, -20, -83, 25);

    // pillar 2 lines
    glColor3ub(0, 0, 0);
    drawLine(-1.5, -20, 2, -20);
    glColor3ub(0, 0, 0);
    drawLine(2, -20, 2, 25);
    glColor3ub(0, 0, 0);
    drawLine(-1.5, -20, -1.5, 25);
    // pillar 3 lines
    glColor3ub(0, 0, 0);
    drawLine(83, -20, 80, -20);
    glColor3ub(0, 0, 0);
    drawLine(80, -20, 80, 25);
    glColor3ub(0, 0, 0);
    drawLine(83, -20, 83, 25);

    // pillars
    glColor3ub(157, 170, 179);
    drawQuad(-83, -20, -80, -20, -80, 25, -83, 25); // pillar 1
    drawQuad(-1.5, -20, 2, -20, 2, 25, -1.5, 25);   // pillar 2
    drawQuad(83, -20, 80, -20, 80, 25, 83, 25);     // pillar 3

    // pillar garden over wall
    glColor3ub(157, 170, 179);
    drawQuad(-100, -22, 100, -22, 100, -18, -100, -18);

    // platform
    glColor3ub(169, 169, 169);
    drawQuad(-100, 24, 100, 24, 100, 31, -100, 31);

    // rail line
    glLineWidth(2);
    glColor3ub(0, 0, 0);
    drawLine(-100, 26.5, 100, 26.5);
    glColor3ub(0, 0, 0);
    drawLine(-100, 29, 100, 29);
}
void road()
{
    // Road
    glColor3ub(47, 47, 47);
    drawQuad(-100, -55, 100, -55, 100, 15, -100, 15);

    // white lines upper
    glLineWidth(5);
    glColor3ub(255, 255, 255);
    drawLine(-100, 2, -85, 2);
    drawLine(-77, 2, -55, 2);
    drawLine(-47, 2, -22, 2);
    drawLine(-14, 2, 8, 2);
    drawLine(16, 2, 38, 2);
    drawLine(46, 2, 68, 2);
    drawLine(76, 2, 100, 2);
    glColor3ub(210, 183, 70);
    drawLine(-100, -13, 100, -13); // long line

    // white lines below
    glLineWidth(5);
    glColor3ub(255, 255, 255);
    drawLine(-100, -37, -85, -37);
    drawLine(-77, -37, -55, -37);
    drawLine(-47, -37, -22, -37);
    drawLine(-14, -37, 8, -37);
    drawLine(16, -37, 38, -37);
    drawLine(46, -37, 68, -37);
    drawLine(76, -37, 100, -37);
    glColor3ub(210, 183, 70);
    drawLine(-100, -23, 100, -23); // long line
}

void footpath()
{
    // footpath below
    glColor3ub(226, 135, 67);
    drawQuad(-100, -61, 100, -61, 100, -55, -100, -55);

    // footpath upper
    glColor3ub(226, 135, 67);
    drawQuad(-100, 15, 100, 15, 100, 23, -100, 23);
    // grey shade upper
    glColor3ub(140, 140, 140);
    drawQuad(-100, 15, 100, 15, 100, 18, -100, 18);
    // grey shade below
    glColor3ub(140, 140, 140);
    drawQuad(-100, -61, 100, -61, 100, -59, -100, -59);

    // dark line
    glLineWidth(2);
    glColor3ub(0, 0, 0);
    drawLine(-100, 18, 100, 18);
    drawLine(-100, 23, 100, 23);
    drawLine(-100, -59, 100, -59);
}

void sun(GLfloat r, GLfloat g, GLfloat b)
{

    glPushMatrix();
    glTranslatef(0.0f, sun_position, 0.0f);
    glColor3ub(r, g, b);
    DrawCircle(5, 70, 10, 25);
    glPopMatrix();
}

void sky(GLfloat r, GLfloat g, GLfloat b)
{
    // sky
    glColor3ub(r, g, b);
    drawQuad(-100, 23, 100, 23, 100, 100, -100, 100);
}

void ground()
{
    // sky
    glColor3ub(38, 139, 7);
    drawQuad(-100, -100, 100, -100, 100, -61, -100, -61);
    // pathway
    glColor3ub(226, 135, 67);
    drawQuad(-20, -85, 100, -85, 100, -77, -20, -77);
    drawQuad(38, -100, 42, -100, 42, -61, 38, -61);
    // tree
    glLineWidth(30);
    glColor3ub(166, 123, 81);
    drawLine(-90, -95, -90, -83);
    drawLine(-85, -90, -85, -73);
    drawLine(-80, -85, -80, -68);
    drawLine(-75, -80, -75, -63);

    glColor3ub(12, 174, 91);
    drawTriangle(-95, -86, -85, -86, -90, -81);
    drawTriangle(-95, -83, -85, -83, -90, -78);
    drawTriangle(-95, -80, -85, -80, -90, -75);
    drawTriangle(-95, -77, -85, -77, -90, -70);

    drawTriangle(-90, -83, -80, -83, -85, -78);
    drawTriangle(-90, -80, -80, -80, -85, -75);
    drawTriangle(-90, -77, -80, -77, -85, -72);
    drawTriangle(-90, -74, -80, -74, -85, -67);

    drawTriangle(-85, -80, -75, -80, -80, -75);
    drawTriangle(-85, -77, -75, -77, -80, -72);
    drawTriangle(-85, -74, -75, -74, -80, -69);
    drawTriangle(-85, -71, -75, -71, -80, -63);

    drawTriangle(-80, -77, -70, -77, -75, -72);
    drawTriangle(-80, -74, -70, -74, -75, -69);
    drawTriangle(-80, -71, -70, -71, -75, -64);
    drawTriangle(-80, -68, -70, -68, -75, -58);

    // tree2
    glLineWidth(30);
    glColor3ub(166, 123, 81);
    drawLine(90, -95, 90, -83);
    drawLine(85, -90, 85, -73);
    // drawLine(80,-85,80,-68);
    // drawLine(75,-80,75,-63);
    glColor3ub(12, 174, 91);
    drawTriangle(95, -86, 85, -86, 90, -81);
    drawTriangle(95, -83, 85, -83, 90, -78);
    drawTriangle(95, -80, 85, -80, 90, -75);
    drawTriangle(95, -77, 85, -77, 90, -70);

    drawTriangle(90, -83, 80, -83, 85, -78);
    drawTriangle(90, -80, 80, -80, 85, -75);
    drawTriangle(90, -77, 80, -77, 85, -72);
    drawTriangle(90, -74, 80, -74, 85, -67);

    // pond

    glColor3ub(89, 192, 249);
    drawQuad(-68, -95, -20, -95, -20, -66, -64, -66);
    glLineWidth(3);
    glColor3ub(0, 0, 0);
    drawLine(-68, -95, -20, -95);
    drawLine(-68, -94, -20, -94);
    drawLine(-68, -93, -20, -93);
    drawLine(-68, -92, -20, -92);

    drawLine(-20, -95, -20, -66);
    drawLine(-21, -95, -21, -66);
    drawLine(-22, -95, -22, -66);
    drawLine(-23, -95, -23, -66);

    drawLine(-20, -66, -64, -66);
    drawLine(-20, -67, -64, -67);
    drawLine(-20, -68, -64, -68);
    drawLine(-20, -69, -64, -69);

    drawLine(-64, -66, -68, -95);
    drawLine(-63, -66, -67, -95);
    drawLine(-62, -66, -66, -95);
    drawLine(-61, -66, -65, -95);
    // bench
    glLineWidth(5);
    glColor3ub(255, 205, 0);
    drawLine(-10, -70, -0, -70);
    drawLine(-10, -72, -0, -72);
    drawLine(-10, -66, -0, -66);
    drawLine(-10, -64, -0, -64);
    glLineWidth(3);
    drawLine(-8, -72, -8, -77);
    drawLine(-2, -72, -2, -77);
    drawLine(-6, -66, -7, -72);
    drawLine(-4, -66, -3, -72);
    drawLine(-6, -66, -7, -72);
    drawLine(-7, -72, -7, -74);
    drawLine(-3, -72, -3, -74);

    // bench2
    glLineWidth(5);
    glColor3ub(255, 205, 0);
    drawLine(46, -70, 56, -70);
    drawLine(46, -72, 56, -72);
    drawLine(46, -66, 56, -66);
    drawLine(46, -64, 56, -64);
    glLineWidth(3);
    drawLine(48, -72, 48, -77);
    drawLine(54, -72, 54, -77);
    drawLine(50, -66, 49, -72);
    drawLine(52, -66, 53, -72);
    drawLine(50, -66, 49, -72);
    drawLine(49, -72, 49, -74);
    drawLine(53, -72, 53, -74);
}

void clouds(GLfloat r, GLfloat g, GLfloat b)
{

    glPushMatrix();
    glTranslatef(position_1, 0.0f, 0.0f);
    // clouds
    glLineWidth(6);
    glColor3ub(r, g, b);
    drawLine(-70, 70, -68, 70);
    drawLine(-71, 71, -67, 71);
    drawLine(-72, 72, -66, 72);
    drawLine(-71, 73, -67, 73);
    drawLine(-70, 74, -68, 74);

    drawLine(-58, 76, -57, 76);
    drawLine(-59, 77, -56, 77);
    drawLine(-60, 78, -55, 78);
    drawLine(-59, 79, -56, 79);
    drawLine(-58, 80, -57, 80);

    drawLine(70, 70, 68, 70);
    drawLine(71, 71, 67, 71);
    drawLine(72, 72, 66, 72);
    drawLine(71, 73, 67, 73);
    drawLine(70, 74, 68, 74);

    drawLine(58, 76, 57, 76);
    drawLine(59, 77, 56, 77);
    drawLine(60, 78, 55, 78);
    drawLine(59, 79, 56, 79);
    drawLine(58, 80, 57, 80);

    drawLine(-95, 80, -94, 80);
    drawLine(-96, 81, -93, 81);
    drawLine(-97, 82, -92, 82);
    drawLine(-96, 83, -93, 83);
    drawLine(-95, 84, -94, 84);

    drawLine(95, 80, 94, 80);
    drawLine(96, 81, 93, 81);
    drawLine(97, 82, 92, 82);
    drawLine(96, 83, 93, 83);
    drawLine(95, 84, 94, 84);

    drawLine(23, 70, 22, 70);
    drawLine(24, 71, 21, 71);
    drawLine(25, 72, 20, 72);
    drawLine(24, 73, 21, 73);
    drawLine(23, 74, 22, 74);

    drawLine(-23, 80, -22, 80);
    drawLine(-24, 81, -21, 81);
    drawLine(-25, 82, -20, 82);
    drawLine(-24, 83, -21, 83);
    drawLine(-23, 84, -22, 84);

    glPopMatrix();
}

void buildings()
{
    // 1st building
    glColor3ub(112, 128, 144);
    drawQuad(-100, 23, -92, 23, -92, 50, -100, 50);

    glColor3ub(204, 255, 255); // window
    drawQuad(-100, 46, -92, 46, -92, 48, -100, 48);
    drawQuad(-100, 42, -92, 42, -92, 44, -100, 44);
    drawQuad(-100, 38, -92, 38, -92, 40, -100, 40);
    drawQuad(-100, 34, -92, 34, -92, 36, -100, 36);
    drawQuad(-100, 30, -92, 30, -92, 32, -100, 32);

    // 2nd building
    glColor3ub(0, 0, 0);
    drawQuad(-91, 23, -75, 23, -75, 60, -91, 60);

    glColor3ub(204, 255, 255); // window
    drawQuad(-91, 54, -75, 54, -75, 57, -91, 57);
    drawQuad(-91, 48, -75, 48, -75, 51, -91, 51);
    drawQuad(-91, 42, -75, 42, -75, 45, -91, 45);
    drawQuad(-91, 36, -75, 36, -75, 39, -91, 39);
    drawQuad(-91, 30, -75, 30, -75, 33, -91, 33);

    // 3rd building
    glColor3ub(0, 0, 0);
    drawQuad(-64, 23, -54, 23, -54, 55, -64, 55);

    glColor3ub(204, 255, 255); // window
    drawQuad(-63, 49, -62, 49, -62, 53, -63, 53);
    drawQuad(-61, 49, -60, 49, -60, 53, -61, 53);
    drawQuad(-59, 49, -58, 49, -58, 53, -59, 53);
    drawQuad(-57, 49, -56, 49, -56, 53, -57, 53);

    drawQuad(-63, 45, -60, 45, -60, 47, -63, 47);
    drawQuad(-58, 45, -55, 45, -55, 47, -58, 47);

    drawQuad(-63, 41, -60, 41, -60, 43, -63, 43);
    drawQuad(-58, 41, -55, 41, -55, 43, -58, 43);

    drawQuad(-63, 37, -60, 37, -60, 39, -63, 39);
    drawQuad(-58, 37, -55, 37, -55, 39, -58, 39);

    drawQuad(-63, 33, -60, 33, -60, 35, -63, 35);
    drawQuad(-58, 33, -55, 33, -55, 35, -58, 35);

    drawQuad(-63, 33, -60, 33, -60, 35, -63, 35);
    drawQuad(-58, 33, -55, 33, -55, 35, -58, 35);

    drawQuad(-63, 29, -60, 29, -60, 31, -63, 31);
    drawQuad(-58, 29, -55, 29, -55, 31, -58, 31);

    // 4th building
    glColor3ub(0, 0, 0);
    drawQuad(-44, 23, -36, 23, -36, 60, -44, 53);
    glColor3ub(204, 255, 255); // window
    drawQuad(-43, 50, -41, 50, -41, 53, -43, 53);
    drawQuad(-43, 46, -41, 46, -41, 49, -43, 49);
    drawQuad(-43, 42, -41, 42, -41, 45, -43, 45);
    drawQuad(-43, 38, -41, 38, -41, 41, -43, 41);
    drawQuad(-43, 34, -41, 34, -41, 37, -43, 37);
    drawQuad(-43, 30, -41, 30, -41, 33, -43, 33);
    drawQuad(-43, 26, -41, 26, -41, 29, -43, 29);
    drawQuad(-43, 24, -41, 24, -41, 27, -43, 27);

    drawQuad(-39, 50, -37, 50, -37, 53, -39, 53);
    drawQuad(-39, 46, -37, 46, -37, 49, -39, 49);
    drawQuad(-39, 42, -37, 42, -37, 45, -39, 45);
    drawQuad(-39, 38, -37, 38, -37, 41, -39, 41);
    drawQuad(-39, 34, -37, 34, -37, 37, -39, 37);
    drawQuad(-39, 30, -37, 30, -37, 33, -39, 33);
    drawQuad(-39, 26, -37, 26, -37, 29, -39, 29);
    drawQuad(-39, 24, -37, 24, -37, 27, -39, 27);

    // 5th building
    glColor3ub(0, 0, 0);
    drawQuad(-12, 23, -2, 23, -2, 60, -12, 60);
    glColor3ub(204, 255, 255); // window
    drawQuad(-11, 24, -9, 24, -9, 58, -11, 58);
    drawQuad(-8, 24, -6, 24, -6, 58, -8, 58);
    drawQuad(-5, 24, -3, 24, -3, 58, -5, 58);

    // 6th building

    glColor3ub(139, 125, 107);
    drawQuad(100, 23, 92, 23, 92, 70, 100, 70);
    glColor3ub(204, 255, 255); // window
    drawQuad(100, 65, 92, 65, 92, 68, 100, 68);
    drawQuad(100, 59, 92, 59, 92, 62, 100, 62);
    drawQuad(100, 53, 92, 53, 92, 56, 100, 56);
    drawQuad(100, 47, 92, 47, 92, 50, 100, 50);
    drawQuad(100, 41, 92, 41, 92, 44, 100, 44);
    drawQuad(100, 35, 92, 35, 92, 38, 100, 38);
    drawQuad(100, 29, 92, 29, 92, 32, 100, 32);
    drawQuad(100, 24, 92, 24, 92, 27, 100, 27);

    // 7th building
    glColor3ub(139, 125, 107);
    drawQuad(74, 23, 65, 23, 65, 55, 74, 55);
    glColor3ub(204, 255, 255); // window
    drawQuad(67, 49, 69, 49, 69, 53, 67, 53);
    drawQuad(70, 49, 72, 49, 72, 53, 70, 53);
    drawQuad(65, 45, 74, 45, 74, 47, 65, 47);
    drawQuad(65, 41, 74, 41, 74, 43, 65, 43);
    drawQuad(65, 37, 74, 37, 74, 39, 65, 39);
    drawQuad(66, 23, 69, 23, 69, 35, 66, 35);
    glColor3ub(0, 206, 209);
    drawQuad(70, 23, 73, 23, 73, 35, 70, 35);

    // 8th building

    glColor3ub(0, 0, 0);
    drawQuad(44, 23, 36, 23, 36, 60, 44, 53);
    glColor3ub(204, 255, 255); // window
    drawQuad(37, 53, 38, 53, 38, 58, 37, 58);
    drawQuad(37, 50, 38, 50, 38, 52, 37, 52);
    drawQuad(42, 48, 43, 48, 43, 53, 42, 53);
    drawQuad(42, 45, 43, 45, 43, 47, 42, 47);
    drawQuad(39, 44, 40, 44, 40, 40, 39, 40);
    drawQuad(39, 37, 40, 37, 40, 39, 39, 39);
    drawQuad(36, 34, 44, 34, 44, 36, 36, 36);
    drawQuad(36, 31, 44, 31, 44, 33, 36, 33);
    drawQuad(36, 28, 44, 28, 44, 30, 36, 30);
    drawQuad(36, 24, 44, 24, 44, 27, 36, 27);

    // 9th building

    glColor3ub(105, 105, 105);
    drawQuad(23, 23, 11, 23, 11, 60, 23, 60);
    glColor3ub(204, 255, 255); // window
    drawQuad(12, 56, 18, 56, 18, 58, 12, 58);
    drawQuad(12, 52, 18, 52, 18, 54, 12, 54);
    drawQuad(12, 48, 18, 48, 18, 50, 12, 50);
    drawQuad(12, 44, 18, 44, 18, 46, 12, 46);
    drawQuad(12, 40, 18, 40, 18, 42, 12, 42);
    drawQuad(12, 36, 18, 36, 18, 38, 12, 38);
    drawQuad(12, 32, 18, 32, 18, 34, 12, 34);
    drawQuad(12, 28, 18, 28, 18, 30, 12, 30);
    drawQuad(12, 24, 18, 24, 18, 26, 12, 26);

    glColor3ub(0, 206, 209);
    drawQuad(18, 56, 22, 56, 22, 58, 18, 58);
    drawQuad(18, 52, 22, 52, 22, 54, 18, 54);
    drawQuad(18, 48, 22, 48, 22, 50, 18, 50);
    drawQuad(18, 44, 22, 44, 22, 46, 18, 46);
    drawQuad(18, 40, 22, 40, 22, 42, 18, 42);
    drawQuad(18, 36, 22, 36, 22, 38, 18, 38);
    drawQuad(18, 32, 22, 32, 22, 34, 18, 34);
    drawQuad(18, 28, 22, 28, 22, 30, 18, 30);
    drawQuad(18, 24, 22, 24, 22, 26, 18, 26);
}

void car1()
{
    glPushMatrix();
    glTranslatef(position_car_1, 0.0f, 0.0f);
    // car 1
    glColor3ub(239, 119, 43);
    glBegin(GL_POLYGON);
    glVertex2f(7.0f, -48.0f);  // 8
    glVertex2f(13.0f, -48.0f); // 7
    glVertex2f(14.0f, -42.0f); // 6
    glVertex2f(19.0f, -42.0f); // 5
    glVertex2f(21.0f, -48.0f); // 4
    glVertex2f(24.0f, -48.0f); // 3
    glVertex2f(24.0f, -42.0f);
    glVertex2f(22.0f, -42.0f);
    glVertex2f(20.0f, -38.0f);
    glVertex2f(15.0f, -38.0f);
    glVertex2f(13.0f, -42.0f);
    glVertex2f(7.0f, -42.0f);
    glEnd();

    // car 1 detail
    glColor3ub(155, 209, 225);
    drawQuad(12, -46, 22, -46, 20, -42, 15, -42);
    drawQuad(12, -46, 15, -42, 15, -38, 12, -42);
    drawQuad(20, -42, 22, -46, 22, -42, 20, -38);

    glLineWidth(2);
    glColor3ub(0, 0, 0);
    drawLine(12, -46, 22, -46);
    drawLine(22, -46, 20, -42);
    drawLine(20, -42, 15, -42);
    drawLine(12, -46, 15, -42);
    drawLine(18, -48, 18, -42);

    drawLine(15, -42, 15, -38);
    drawLine(15, -38, 12, -42);
    drawLine(12, -42, 12, -46);

    drawLine(22, -46, 22, -42);
    drawLine(22, -42, 20, -38);
    drawLine(20, -38, 20, -42);
    // car 1 wheel
    glColor3ub(0, 0, 0);
    DrawCircle(12, -48, 2, 200);
    DrawCircle(20, -48, 2, 200);
    glColor3ub(210, 224, 237);
    DrawCircle(12, -48, 1, 200);
    DrawCircle(20, -48, 1, 200);
    glPopMatrix();
}

void car3()
{
    glPushMatrix();
    glTranslatef(position_car_3, 0.0f, 0.0f);
    // car 3
    glColor3ub(59, 137, 213);
    glBegin(GL_POLYGON);
    glVertex2f(-77.0f, 7.0f);  // 8
    glVertex2f(-60.0f, 7.0f);  // 7
    glVertex2f(-60.0f, 10.0f); // 6
    glVertex2f(-65.0f, 10.0f); // 6
    glVertex2f(-68.0f, 12.0f); // 5
    glVertex2f(-72.0f, 12.0f); // 4
    glVertex2f(-74.0f, 10.0f); // 3
    glVertex2f(-77.0f, 10.0f);
    glEnd();
    // car 3 detail
    glColor3ub(155, 209, 225);
    drawQuad(-74.0, 10.0, -65.0, 10.0, -68.0, 12.0, -72.0, 12.0);

    glLineWidth(2);
    glColor3ub(0, 0, 0);
    drawLine(-74.0, 10.0, -65.0, 10.0);
    drawLine(-65.0, 10.0, -68.0, 12.0);
    drawLine(-68.0, 12.0, -72.0, 12.0);
    drawLine(-68.0, 12.0, -72.0, 12.0);
    drawLine(-70, 7, -70, 12);
    // car 3 wheel
    glColor3ub(0, 0, 0);
    DrawCircle(-74, 7, 1.5, 200);
    DrawCircle(-65, 7, 1.5, 200);
    glColor3ub(210, 224, 237);
    DrawCircle(-74, 7, 1, 200);
    DrawCircle(-65, 7, 1, 200);
    glPopMatrix();
}

void trainOver()
{
    glPushMatrix();
    glTranslatef(position_trainover, 0.0f, 0.0f);
    // train body
    glColor3ub(234, 235, 239);
    drawQuad(-95, 26, -20, 26, -20, 36.5, -95, 36.5);

    // train head
    glColor3ub(234, 235, 239);
    glBegin(GL_POLYGON);
    glVertex2f(-20.0f, 26.0f);
    glVertex2f(-8.0f, 26.0f);
    glVertex2f(-8.0f, 31.0f);
    glVertex2f(-12.0f, 36.0f);
    glVertex2f(-20.0f, 36.0f);
    glEnd();

    // train head door
    glColor3ub(131, 132, 127);
    drawQuad(-19, 27, -17.25, 27, -17.25, 35.5, -19, 35.5);

    // train head window
    glColor3ub(155, 209, 225);
    drawQuad(-15.5, 31, -9.8, 31, -12, 35, -15.5, 35);

    // train compartment doors
    glColor3ub(131, 132, 127);
    drawQuad(-44, 27, -42.25, 27, -42.25, 35.5, -44, 35.5);
    drawQuad(-48, 27, -46.0, 27, -46.0, 35.5, -48, 35.5);
    drawQuad(-73, 27, -71.25, 27, -71.25, 35.5, -73, 35.5);

    // train compartment windows
    glColor3ub(155, 209, 225);
    drawQuad(-41, 30.5, -21.0, 30.5, -21.0, 35.5, -41.25, 35.5);
    drawQuad(-69, 30.5, -49.0, 30.5, -49.0, 35.5, -69.25, 35.5);
    drawQuad(-93.5, 30.5, -74.0, 30.5, -74.0, 35.5, -93.50, 35.5);

    // decorate red line
    glLineWidth(4);
    glColor3ub(170, 3, 3);
    drawLine(-95, 36.5, -12, 36.5);
    drawLine(-12, 36.5, -8, 31);
    drawLine(-8, 31, -8, 26);
    drawLine(-95, 36.5, -95, 32);

    // decorate green line
    glLineWidth(4);
    glColor3ub(23, 143, 82);
    drawLine(-95, 26, -8, 26);
    drawLine(-95, 26, -95, 32);

    // compartment line
    glLineWidth(5);
    glColor3ub(0, 0, 0);
    drawLine(-70, 26, -70, 36.5);
    glColor3ub(0, 0, 0);
    drawLine(-45, 26, -45, 36.5);
    glColor3ub(0, 0, 0);
    drawLine(-20, 26, -20, 36.5);
    glPopMatrix();
}

void trainUnder()
{
    glPushMatrix();
    glTranslatef(position_trainUnder, 0.0f, 0.0f);
    // train body
    glColor3ub(234, 235, 239);
    drawQuad(95, 29.5, 20, 29.5, 20, 38.5, 95, 38.5);

    // train head
    glColor3ub(234, 235, 239);
    glBegin(GL_POLYGON);
    glVertex2f(20.0f, 29.0f);
    glVertex2f(8.0f, 29.0f);
    glVertex2f(8.0f, 33.0f);
    glVertex2f(12.0f, 38.0f);
    glVertex2f(20.0f, 38.0f);
    glEnd();

    // train head door
    glColor3ub(131, 132, 127);
    drawQuad(19, 30, 17.25, 30, 17.25, 37, 19, 37);

    // train head window
    glColor3ub(155, 209, 225);
    drawQuad(9.8, 33, 16, 33, 16, 37, 12, 37);

    // train compartment doors
    glColor3ub(131, 132, 127);
    drawQuad(44, 30, 42.25, 30, 42.25, 37, 44, 37);
    drawQuad(48, 30, 46.0, 30, 46.0, 37, 48, 37);
    drawQuad(73, 30, 71.25, 30, 71.25, 37, 73, 37);

    // train compartment windows
    glColor3ub(155, 209, 225);
    drawQuad(41, 33, 21.0, 33, 21.0, 37.0, 41.25, 37);
    drawQuad(69, 33, 49.0, 33, 49.0, 37, 69.25, 37);
    drawQuad(93.5, 33, 74.0, 33, 74.0, 37, 93.50, 37);

    // decorate red line
    glLineWidth(4);
    glColor3ub(170, 3, 3);
    drawLine(95, 38, 12, 38);
    drawLine(12, 38, 8, 33);
    drawLine(8, 33, 8, 29);
    drawLine(95, 38, 95, 32);

    // decorate green line
    glLineWidth(4);
    glColor3ub(23, 143, 82);
    drawLine(95, 29, 8, 29);
    drawLine(95, 29, 95, 33);

    // compartment line
    glLineWidth(3);
    glColor3ub(0, 0, 0);
    drawLine(70, 29.5, 70, 38.5);
    glColor3ub(0, 0, 0);
    drawLine(45, 29.5, 45, 38.5);
    glColor3ub(0, 0, 0);
    drawLine(20, 29.5, 20, 38.5);
    glPopMatrix();
}

void display1()
{
    road();
    sky(135, 206, 255);
    sun(255, 255, 0);
    clouds(245, 245, 245);
    car1();
    car3();
    footpath();
    buildings();
    platform();
    trainUnder();
    trainOver();
    ground();
    glutIdleFunc(day);

    glFlush();
}

