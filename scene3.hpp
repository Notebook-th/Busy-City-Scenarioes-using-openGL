#pragma once
#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <vector>
#include <utility>
#include <mmsystem.h>
#include "glutil.h"
using namespace std;

void DrawCircle(double x, double y, double radius, int R, int G, int B)
{
    glBegin(GL_POLYGON);
    glColor3ub(R, G, B);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(x + radius * cos(theta), y + radius * sin(theta));
    }
    glEnd();
}

// Animation parameters
float _moveSun = 0.0f;
float _moveCloud = 0.0f;
float _moveBus = 0.0f;
float _moveAmbulance = 0.0f;
float _moveCar = 0.0f;

void HeadlightEffect()
{

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 131);
    glVertex2d(210.3590012512302, 76.5665817179349);
    glVertex2d(269.5623337234856, 95.9958006664856);
    glVertex2d(264.8016436547303, 93.700115596967);
    glVertex2d(261.33058509551, 91.4142965457732);
    glVertex2d(258.2828263605849, 88.112557916271);
    glVertex2d(255.827687379673, 83.3715998841652);
    glVertex2d(254.8117678013646, 78.2920019926234);
    glVertex2d(255.2350676256598, 73.3817240307996);
    glVertex2d(255.9970073093911, 69.9953254364383);
    glVertex2d(257.6055466417126, 67.0322266663722);
    glVertex2d(260.9919452360739, 63.5611681071519);
    glVertex2d(265.9868831627567, 59.6668097236365);
    glVertex2d(268.4420221436686, 58.6508901453281);
    glVertex2d(210.3590012512302, 76.5665817179349);
    glEnd();
}

void CarHeadlightEffect()
{

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 131);
    glVertex2d(1059.0789598906051, 32.4714974104155);
    glVertex2d(1002.8456456316572, 54.124433878267);
    glVertex2d(1005.1521716567928, 52.622509954923);
    glVertex2d(1008.8533413250335, 50.2623437896681);
    glVertex2d(1011.9108293118411, 47.4730565034578);
    glVertex2d(1014.3835368215523, 44.1931163598462);
    glVertex2d(1015.9955620693188, 40.9690658643133);
    glVertex2d(1017.094670192796, 37.4519198691865);
    glVertex2d(1017.755139250382, 32.5775682984649);
    glVertex2d(1017.1465459851754, 28.5411146503879);
    glVertex2d(1016.0299917010082, 24.7378516199432);
    glVertex2d(1014.1947995436684, 20.6708521092205);
    glVertex2d(1011.3569807021119, 17.1959927464361);
    glVertex2d(1008.9559458586706, 15.3058163803229);
    glVertex2d(1004.3226543406477, 12.9738557047042);
    glVertex2d(1059.0789598906051, 32.4714974104155);

    glEnd();
}

// Day Scene parameters Predefined
int sky1R             = 203, sky1G             = 212, sky1B             = 137;  // Sky color 1st shading
int sky2R             = 127, sky2G             = 212, sky2B             = 239;  // Sky color 2nd shading
int SunMoonR          = 252, SunMoonG          = 181, SunMoonB          = 77;   // Sun/Moon color
int windowsR          = 226, windowsG          = 219, windowsB          = 199;  // Windows color
int cloudR            = 255, cloudG            = 255, cloudB            = 255;  // Cloud Colors
int headlightsBusR    = 17,  headlightsBusG    = 22,  headlightsBusB    = 56;   // Headlight of bus
int headlightCarR     = 0,   headlightCarG     = 0,   headlightCarB     = 0;    // Headlight of car
int foodcourtSignR    = 227, foodcourtSignG    = 180, foodcourtB        = 138;
int HospitalWindowR   = 90,  HospitalWindowG   = 117, HospitalWindowB   = 114;
int HouseR            = 145, HouseG            = 189, HouseB            = 247;  // House windows
int HouseWindowShadeR = 118, HouseWindowShadeG = 149, HouseWindowShadeB = 190;  // Shading of windows
int HDoorShade1R      = 100, HDoorShade1G      = 170, HDoorShade1B      = 255;  //(255, 254, 9), (100,170, 255)

void Cloud_Move(int value)
{
    _moveCloud += 2.0;
    if (_moveCloud > 1366.0)
    {
        _moveCloud = -1000.0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, Cloud_Move, 0);
}

void Bus_Move(int value)
{
    _moveBus += 5.5;
    if (_moveBus > 1366.0)
    {
        _moveBus = -100.0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, Bus_Move, 0);
}
void Ambulance_Move(int value)
{
    _moveAmbulance -= 3.5;
    if (_moveAmbulance < -1366.0)
    {
        _moveAmbulance = 450.0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, Ambulance_Move, 0);
}
void Car_Move(int value)
{
    _moveCar -= 2.5f;
    if (_moveCar < -1366.0)
    {
        _moveCar = 250.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(20, Car_Move, 0);
}

void display3()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //---------------------------Drawing SKY-------------//

    glBegin(GL_QUADS);
    glColor3ub(sky1R, sky1G, sky1B);
    glVertex2f(0.0, 71.0);
    glColor3ub(sky2R, sky2G, sky2B);
    glVertex2f(0.0, 800.0);
    glColor3ub(sky2R, sky2G, sky2B);
    glVertex2f(1366.0, 800.0);
    glColor3ub(sky1R, sky1G, sky1B);
    glVertex2f(1366.0, 71.0);
    glEnd();

    /////////////////////////////////////////////-----Drawing SUN/MOON------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(SunMoonR, SunMoonG, SunMoonB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(535 + 30.25 * cos(theta), 662 + 30.25 * sin(theta));
    }
    glEnd();
    glPopMatrix();

    //--------ROADS------------//
    glBegin(GL_QUADS);
    glColor3ub(31, 30, 31);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 35.0);
    glVertex2f(1366.0, 35.0);
    glVertex2f(1366.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(31, 30, 31);
    glVertex2f(0.0, 35.0);
    glVertex2f(0.0, 70.0);
    glVertex2f(1366.0, 70.0);
    glVertex2f(1366.0, 35.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(70, 116, 37);
    glVertex2f(0.0, 71.0);
    glVertex2f(0.0, 90.0);
    glVertex2f(1366.0, 90.0);
    glVertex2f(1366.0, 71.0);
    glEnd();

    // RoadLines
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2d(35, 35);
    glVertex2d(145, 35);
    glVertex2d(140, 42);
    glVertex2d(30, 42);
    glEnd();

    glPushMatrix();
    glTranslatef(200.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2d(35, 35);
    glVertex2d(145, 35);
    glVertex2d(140, 42);
    glVertex2d(30, 42);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2d(35, 35);
    glVertex2d(145, 35);
    glVertex2d(140, 42);
    glVertex2d(30, 42);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(600.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2d(35, 35);
    glVertex2d(145, 35);
    glVertex2d(140, 42);
    glVertex2d(30, 42);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(800.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2d(35, 35);
    glVertex2d(145, 35);
    glVertex2d(140, 42);
    glVertex2d(30, 42);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(800.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2d(35, 35);
    glVertex2d(145, 35);
    glVertex2d(140, 42);
    glVertex2d(30, 42);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1000.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2d(35, 35);
    glVertex2d(145, 35);
    glVertex2d(140, 42);
    glVertex2d(30, 42);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1200.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2d(35, 35);
    glVertex2d(145, 35);
    glVertex2d(140, 42);
    glVertex2d(30, 42);
    glEnd();
    glPopMatrix();

    //---------------------------Grass----------------------------------//

    glBegin(GL_QUADS);
    glColor3ub(70, 116, 37);
    glVertex2f(0.0, 70.0);
    glVertex2f(0.0, 85.0);
    glVertex2f(1366.0, 85.0);
    glVertex2f(1366.0, 70.0);
    glEnd();

    //////////////////////////---------------Drawing CLOUDS-----------------------\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    ////-----------------------Cloud-1-----------------------------\\\\\\\\\\\\\\\

    glPushMatrix();
    glTranslatef(_moveCloud, 100.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(350 + 21 * cos(theta), 600 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(370 + 25 * cos(theta), 600 + 25 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(395 + 21 * cos(theta), 600 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(360 + 21 * cos(theta), 580 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(390 + 21 * cos(theta), 580 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(410 + 21 * cos(theta), 590 + 21 * sin(theta));
    }
    glEnd();

    //////--------------------------Cloud-2-----------------------\\\\\\\\\\\\\\\\\\\\


    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(700 + 21 * cos(theta), 600 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(720 + 25 * cos(theta), 600 + 25 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(745 + 21 * cos(theta), 600 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(710 + 21 * cos(theta), 580 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(740 + 21 * cos(theta), 580 + 21 * sin(theta));
    }
    glEnd();

    //////--------------------------Cloud-3-----------------------\\\\\\\\\\\\\\\\\\\\

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(135 + 21 * cos(theta), 580 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(115 + 21 * cos(theta), 580 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(90 + 21 * cos(theta), 580 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(100 + 21 * cos(theta), 600 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(125 + 21 * cos(theta), 600 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(145 + 21 * cos(theta), 595 + 21 * sin(theta));
    }
    glEnd();

    ////////////---------Cloud-4----------------\\\\\\\\\\\\\\\

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(975 + 21 * cos(theta), 595 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(1000 + 21 * cos(theta), 595 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(988 + 21 * cos(theta), 610 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(1010 + 21 * cos(theta), 610 + 21 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(cloudR, cloudG, cloudB);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(1030 + 21 * cos(theta), 600 + 21 * sin(theta));
    }
    glEnd();

    glPopMatrix();

    /////////////////////////////////=================Drawing Food court---------------------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    // Structure
    glBegin(GL_POLYGON);
    glColor3ub(33, 46, 47);
    glVertex2d(595, 400);
    glVertex2d(595, 405);
    glVertex2d(765, 405);
    glVertex2d(765, 400);
    glVertex2d(595, 400);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(33, 46, 47);
    glVertex2d(602, 390);
    glVertex2d(602, 400);
    glVertex2d(760, 400);
    glVertex2d(760, 390);
    glVertex2d(602, 390);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2d(605, 390);
    glVertex2d(755, 390);
    glVertex2d(755, 85);
    glVertex2d(605, 85);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2d(605, 275);
    glVertex2d(605, 85);
    glVertex2d(460, 85);
    glVertex2d(460, 275);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(84, 102, 116);
    glVertex2d(609, 391);
    glVertex2d(750, 391);
    glVertex2d(750, 275);
    glVertex2d(609, 275);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2d(615, 385);
    glVertex2d(745, 385);
    glVertex2d(745, 280);
    glVertex2d(615, 280);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2d(595, 385);
    glVertex2d(745, 385);
    glVertex2d(745, 380);
    glVertex2d(595, 380);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2d(595, 366);
    glVertex2d(745, 366);
    glVertex2d(745, 361);
    glVertex2d(595, 361);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(84, 102, 116);
    glVertex2d(609, 266);
    glVertex2d(750, 266);
    glVertex2d(750, 95);
    glVertex2d(609, 95);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(84, 102, 116);
    glVertex2d(465, 266);
    glVertex2d(604, 266);
    glVertex2d(604, 95);
    glVertex2d(465, 95);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2d(475, 250);
    glVertex2d(595, 250);
    glVertex2d(595, 105);
    glVertex2d(475, 105);
    glEnd();

    // Windows (1st floor)

    glBegin(GL_QUADS); // col-1
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(482, 245);
    glVertex2d(507, 245);
    glVertex2d(507, 180);
    glVertex2d(482, 180);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(482, 175);
    glVertex2d(507, 175);
    glVertex2d(507, 110);
    glVertex2d(482, 110);
    glEnd();

    glBegin(GL_QUADS); // col-2
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(509, 245);
    glVertex2d(534, 245);
    glVertex2d(534, 180);
    glVertex2d(509, 180);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(509, 175);
    glVertex2d(534, 175);
    glVertex2d(534, 110);
    glVertex2d(509, 110);
    glEnd();

    glBegin(GL_QUADS); // col-3
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(536, 245);
    glVertex2d(561, 245);
    glVertex2d(561, 180);
    glVertex2d(536, 180);

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(536, 175);
    glVertex2d(561, 175);
    glVertex2d(561, 110);
    glVertex2d(536, 110);

    glBegin(GL_QUADS); // col-4
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(564, 245);
    glVertex2d(588, 245);
    glVertex2d(588, 180);
    glVertex2d(564, 180);

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(564, 175);
    glVertex2d(588, 175);
    glVertex2d(588, 110);
    glVertex2d(564, 110);

    // End of first floor windows

    /// roof
    glBegin(GL_QUADS);
    glColor3ub(27, 44, 58);
    glVertex2d(450, 306);
    glVertex2d(605, 306);
    glVertex2d(605, 302);
    glVertex2d(450, 302);

    glBegin(GL_QUADS);
    glColor3ub(27, 44, 58);
    glVertex2d(450, 298);
    glVertex2d(605, 298);
    glVertex2d(605, 294);
    glVertex2d(450, 294);

    glBegin(GL_QUADS);
    glColor3ub(27, 44, 58);
    glVertex2d(450, 289);
    glVertex2d(605, 289);
    glVertex2d(605, 285);
    glVertex2d(450, 285);

    glBegin(GL_QUADS);
    glColor3ub(20, 41, 40);
    glVertex2d(602, 315);
    glVertex2d(605, 315);
    glVertex2d(605, 270);
    glVertex2d(602, 270);

    glBegin(GL_QUADS);
    glColor3ub(20, 41, 40);
    glVertex2d(572, 315);
    glVertex2d(575, 315);
    glVertex2d(575, 270);
    glVertex2d(572, 270);

    glBegin(GL_QUADS);
    glColor3ub(20, 41, 40);
    glVertex2d(542, 315);
    glVertex2d(545, 315);
    glVertex2d(545, 270);
    glVertex2d(542, 270);

    glBegin(GL_QUADS);
    glColor3ub(20, 41, 40);
    glVertex2d(512, 315);
    glVertex2d(515, 315);
    glVertex2d(515, 270);
    glVertex2d(512, 270);

    glBegin(GL_QUADS);
    glColor3ub(20, 41, 40);
    glVertex2d(482, 315);
    glVertex2d(485, 315);
    glVertex2d(485, 270);
    glVertex2d(482, 270);

    glBegin(GL_QUADS);
    glColor3ub(20, 41, 40);
    glVertex2d(460, 315);
    glVertex2d(463, 315);
    glVertex2d(463, 270);
    glVertex2d(460, 270);

    /// End of roof

    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2d(609, 238);
    glVertex2d(750, 238);
    glVertex2d(750, 235);
    glVertex2d(609, 235);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2d(609, 230);
    glVertex2d(750, 230);
    glVertex2d(750, 227);
    glVertex2d(609, 227);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2d(609, 222);
    glVertex2d(750, 222);
    glVertex2d(750, 219);
    glVertex2d(609, 219);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2d(609, 214);
    glVertex2d(750, 214);
    glVertex2d(750, 211);
    glVertex2d(609, 211);
    glEnd();

    // Door of the food court

    glBegin(GL_QUADS); // 1st
    glColor3ub(33, 46, 47);
    glVertex2d(645, 230);
    glVertex2d(680, 230);
    glVertex2d(680, 100);
    glVertex2d(645, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(650, 225);
    glVertex2d(675, 225);
    glVertex2d(675, 130);
    glVertex2d(650, 130);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(650, 125);
    glVertex2d(675, 125);
    glVertex2d(675, 105);
    glVertex2d(650, 105);
    glEnd();

    glBegin(GL_QUADS); // 2nd
    glColor3ub(33, 46, 47);
    glVertex2d(681, 230);
    glVertex2d(716, 230);
    glVertex2d(716, 100);
    glVertex2d(681, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(686, 225);
    glVertex2d(711, 225);
    glVertex2d(711, 130);
    glVertex2d(686, 130);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(686, 125);
    glVertex2d(711, 125);
    glVertex2d(711, 105);
    glVertex2d(686, 105);
    glEnd();

    // Food court Windows(2nd floor)
    glBegin(GL_QUADS); // W-1
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(622, 378);
    glVertex2d(650, 378);
    glVertex2d(650, 366);
    glVertex2d(622, 366);
    glEnd();

    glBegin(GL_QUADS); // W-2
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(652, 378);
    glVertex2d(680, 378);
    glVertex2d(680, 366);
    glVertex2d(652, 366);
    glEnd();

    glBegin(GL_QUADS); // W-3
    glColor3ub(windowsR, windowsG, windowsB);
    ;
    glVertex2d(682, 378);
    glVertex2d(710, 378);
    glVertex2d(710, 366);
    glVertex2d(682, 366);
    glEnd();

    glBegin(GL_QUADS); // W-4
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(712, 378);
    glVertex2d(740, 378);
    glVertex2d(740, 366);
    glVertex2d(712, 366);
    glEnd();

    glBegin(GL_QUADS); // W-5
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(622, 285);
    glVertex2d(650, 285);
    glVertex2d(650, 297);
    glVertex2d(622, 297);
    glEnd();

    glBegin(GL_QUADS); // W-6
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(652, 285);
    glVertex2d(680, 285);
    glVertex2d(680, 297);
    glVertex2d(652, 297);
    glEnd();

    glBegin(GL_QUADS); // W-7
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(682, 285);
    glVertex2d(710, 285);
    glVertex2d(710, 297);
    glVertex2d(682, 297);
    glEnd();

    glBegin(GL_QUADS); // W-8
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(712, 285);
    glVertex2d(740, 285);
    glVertex2d(740, 297);
    glVertex2d(712, 297);
    glEnd();

    // Middle Windows-2nd Floor

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(622, 303);
    glVertex2d(650, 303);
    glVertex2d(650, 361);
    glVertex2d(622, 361);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(652, 303);
    glVertex2d(680, 303);
    glVertex2d(680, 361);
    glVertex2d(652, 361);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(682, 303);
    glVertex2d(710, 303);
    glVertex2d(710, 361);
    glVertex2d(682, 361);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(windowsR, windowsG, windowsB);
    glVertex2d(712, 303);
    glVertex2d(740, 303);
    glVertex2d(740, 361);
    glVertex2d(712, 361);
    glEnd();

    // Foodcourt sign
    glBegin(GL_QUADS); // structure
    glColor3ub(170, 126, 83);
    glVertex2d(625, 275);
    glVertex2d(735, 275);
    glVertex2d(735, 250);
    glVertex2d(625, 250);
    glEnd();

    glBegin(GL_QUADS); // line
    glColor3ub(foodcourtSignR, foodcourtSignG, foodcourtB);
    glVertex2d(625, 255);
    glVertex2d(735, 255);
    glVertex2d(735, 253);
    glVertex2d(625, 253);
    glEnd();

    glBegin(GL_QUADS); // line
    glColor3ub(foodcourtSignR, foodcourtSignG, foodcourtB);
    glVertex2d(625, 262);
    glVertex2d(735, 262);
    glVertex2d(735, 260);
    glVertex2d(625, 260);
    glEnd();

    glBegin(GL_QUADS);                                      // line
    glColor3ub(foodcourtSignR, foodcourtSignG, foodcourtB); // 227, 180, 138
    glVertex2d(625, 270);
    glVertex2d(735, 270);
    glVertex2d(735, 268);
    glVertex2d(625, 268);
    glEnd();

    staticText("Cafe", 655, 255, 0.14, 2, 0.0, 0.0, 0.0);


    //-------------------------------Drawing Trees---------------------------------

    // Leaves(Tree beside(RIGHT) food court)
    DrawCircle(462, 100, 20.5, 105, 112, 16);
    DrawCircle(475, 105, 13, 105, 112, 16);
    DrawCircle(470, 120, 11.5, 105, 112, 16);
    DrawCircle(453, 118, 11.5, 105, 112, 16);
    DrawCircle(445, 114, 11.5, 105, 112, 16);
    DrawCircle(442, 95, 11.5, 105, 112, 16);

    glBegin(GL_POLYGON);
    glColor3ub(58, 24, 10);
    glVertex2d(457.46505956786, 79.4529305369738);
    glVertex2d(465.7419618073546, 79.8235380999363);
    glVertex2d(470.3127884172247, 115.7724717072936);
    glVertex2d(461.418206906126, 92.5477310949803);
    glVertex2d(453.5119122295939, 107.9897128850822);
    glVertex2d(457.3415237135392, 87.6062969221476);
    glVertex2d(448.076334639478, 92.6712669493011);
    glVertex2d(457.46505956786, 79.4529305369738);
    glEnd();

    // Leaves(Tree Left of food court)
    glPushMatrix();
    glTranslatef(290, 0, 0);
    DrawCircle(462, 100, 20.5, 105, 112, 16);
    DrawCircle(475, 105, 13, 105, 112, 16);
    DrawCircle(470, 120, 11.5, 105, 112, 16);
    DrawCircle(453, 118, 11.5, 105, 112, 16);
    DrawCircle(445, 114, 11.5, 105, 112, 16);
    DrawCircle(442, 95, 11.5, 105, 112, 16);

    glBegin(GL_POLYGON);
    glColor3ub(58, 24, 10);
    glVertex2d(457.46505956786, 79.4529305369738);
    glVertex2d(465.7419618073546, 79.8235380999363);
    glVertex2d(470.3127884172247, 115.7724717072936);
    glVertex2d(461.418206906126, 92.5477310949803);
    glVertex2d(453.5119122295939, 107.9897128850822);
    glVertex2d(457.3415237135392, 87.6062969221476);
    glVertex2d(448.076334639478, 92.6712669493011);
    glVertex2d(457.46505956786, 79.4529305369738);
    glEnd();
    glPopMatrix();

    /////////////////////////////////=================Drawing Hospital---------------------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


    // border

    glBegin(GL_QUADS);
    glColor3ub(241, 241, 241);
    glVertex2d(780, 421);
    glVertex2d(971, 421);
    glVertex2d(971, 85);
    glVertex2d(780, 85);
    glEnd();

    // Structure 1
    glBegin(GL_QUADS);
    glColor3ub(HospitalWindowR, HospitalWindowG, HospitalWindowB);
    glVertex2d(791, 402);
    glVertex2d(956, 402);
    glVertex2d(956, 85);
    glVertex2d(791, 85);
    glEnd();

    // line 1
    glBegin(GL_QUADS);
    glColor3ub(241, 241, 241);
    glVertex2d(841, 402);
    glVertex2d(844, 402);
    glVertex2d(844, 85);
    glVertex2d(841, 85);
    glEnd();

    // line 2
    glBegin(GL_QUADS);
    glColor3ub(241, 241, 241);
    glVertex2d(906, 85);
    glVertex2d(909, 85);
    glVertex2d(909, 402);
    glVertex2d(906, 402);
    glEnd();

    // line 3
    glBegin(GL_QUADS);
    glColor3ub(241, 241, 241);
    glVertex2d(791, 351);
    glVertex2d(791, 348);
    glVertex2d(956, 348);
    glVertex2d(956, 351);
    glEnd();

    // line 4
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2d(792, 300);
    glVertex2d(792, 296);
    glVertex2d(956, 296);
    glVertex2d(956, 300);
    glEnd();

    // line 5
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2d(792, 250);
    glVertex2d(792, 246);
    glVertex2d(956, 246);
    glVertex2d(956, 250);
    glEnd();

    // line 6
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2d(792, 202);
    glVertex2d(792, 199);
    glVertex2d(956, 199);
    glVertex2d(956, 202);
    glEnd();

    // line 7
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2d(792, 156);
    glVertex2d(792, 152);
    glVertex2d(956, 152);
    glVertex2d(956, 156);
    glEnd();

    // templet border
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2d(806, 421);
    glVertex2d(806, 444);
    glVertex2d(942, 444);
    glVertex2d(942, 421);
    glEnd();

    // templet
    glBegin(GL_QUADS);
    glColor3ub(90, 117, 114);
    glVertex2d(808, 442);
    glVertex2d(808, 421);
    glVertex2d(940, 442);
    glVertex2d(940, 421);
    glEnd();

    ///////////////////////////////////////            Drawing Buildings          \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    // Structure
    glBegin(GL_QUADS);
    glColor3ub(207, 192, 202);
    glVertex2d(1240, 260);
    glVertex2d(1300, 260);
    glVertex2d(1300, 450);
    glVertex2d(1240, 525);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(59, 83, 85);
    glVertex2d(1240 + 6, 260 + 6);
    glVertex2d(1300 - 6, 260 - 6);
    glVertex2d(1300 - 6, 450 - 6);
    glVertex2d(1246, 505);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(207, 192, 202);
    glVertex2d(990, 90);
    glVertex2d(1240, 90);
    glVertex2d(1240, 525);
    glVertex2d(990, 525);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(59, 83, 85);
    glVertex2d(990 + 15, 90);
    glVertex2d(1240 - 15, 90);
    glVertex2d(1240 - 15, 525 - 20);
    glVertex2d(990 + 15, 525 - 20);
    glEnd();

    // Glasses
    glBegin(GL_QUADS);
    glColor3ub(HouseR, HouseG, HouseB);
    glVertex2d(1245 + 12, 425);
    glVertex2d(1270 + 12, 400);
    glVertex2d(1270 + 12, 440);
    glVertex2d(1245 + 12, 470);
    glEnd();

    glPushMatrix();
    for (int i = 0; i < 2; i++)
    {
        glTranslatef(0, -65, 0);
        glBegin(GL_QUADS);
        glColor3ub(HouseR, HouseG, HouseB);
        glVertex2d(1245 + 12, 425);
        glVertex2d(1270 + 12, 400);
        glVertex2d(1270 + 12, 440);
        glVertex2d(1245 + 12, 470);
        glEnd();
    }
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(HouseR, HouseG, HouseB);
    glVertex2d(1140, 425);
    glVertex2d(1205, 425);
    glVertex2d(1205, 475);
    glVertex2d(1140, 475);
    glEnd();

    glPushMatrix();
    for (int i = 0; i < 2; i++)
    {
        glTranslatef(0, -75, 0);
        glBegin(GL_QUADS);
        glColor3ub(HouseR, HouseG, HouseB);
        glVertex2d(1140, 425);
        glVertex2d(1205, 425);
        glVertex2d(1205, 475);
        glVertex2d(1140, 475);
        glEnd();
    }
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(HouseR, HouseG, HouseB);
    glVertex2d(1140 - 115, 425);
    glVertex2d(1205 - 115, 425);
    glVertex2d(1205 - 115, 475);
    glVertex2d(1140 - 115, 475);
    glEnd();

    glPushMatrix();
    for (int i = 0; i < 4; i++)
    {
        glTranslatef(0, -75, 0);
        glBegin(GL_QUADS);
        glColor3ub(HouseR, HouseG, HouseB);
        glVertex2d(1140 - 115, 425);
        glVertex2d(1205 - 115, 425);
        glVertex2d(1205 - 115, 475);
        glVertex2d(1140 - 115, 475);
        glEnd();
    }
    glPopMatrix();

    ///////////////////////////////////////------Triangular big tree---------------\\\\\\\\\\\\\\\\\\\\\\\\\\\

    //-------TRUNK-----//
    glBegin(GL_QUADS);
    glColor3ub(58, 24, 10);
    glVertex2d(1010, 85);
    glVertex2d(1010, 105);
    glVertex2d(1020, 105);
    glVertex2d(1020, 85);
    glEnd();
    //---Leaves by triangle----//
    glBegin(GL_TRIANGLES);
    glColor3ub(105, 112, 16);
    glVertex2d(990, 105);
    glVertex2d(1015, 140);
    glVertex2d(1040, 105);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(105, 112, 16);
    glVertex2d(990, 115);
    glVertex2d(1015, 150);
    glVertex2d(1040, 115);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(105, 112, 16);
    glVertex2d(990, 125);
    glVertex2d(1015, 160);
    glVertex2d(1040, 125);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(105, 112, 16);
    glVertex2d(990, 135);
    glVertex2d(1015, 170);
    glVertex2d(1040, 135);
    glEnd();

    /////////////////////////////////////////////        Drawing House             \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    // Structure
    glBegin(GL_QUADS);
    glColor3ub(169, 158, 166);
    glVertex2d(1053.0802662794451, 251.6709455692026);
    glVertex2d(1222.6199405175882, 282.060132460946);
    glVertex2d(1221.4203673508089, 297.2547259068177);
    glVertex2d(1053.0802662794451, 270.8641162376721);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(73, 62, 70);
    glVertex2d(1053.0802662794451, 251.6709455692026);
    glVertex2d(1222.6199405175882, 282.060132460946);
    glVertex2d(1159.4375931564603, 209.9827016903054);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(169, 157, 165);
    glVertex2d(1190, 90);
    glVertex2d(1340, 90);
    glVertex2d(1340, 268);
    glVertex2d(1190, 268);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 94, 107);
    glVertex2d(1190, 90);
    glVertex2d(1190, 268);
    glVertex2d(1070, 250);
    glVertex2d(1070, 90);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(160, 92, 79);
    glVertex2d(1070, 255);
    glVertex2d(1070, 90);
    glVertex2d(1094, 90);
    glVertex2d(1094, 255);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(138, 75, 64);
    glVertex2d(1070, 92);
    glVertex2d(1094, 92);
    glVertex2d(1094, 94);
    glVertex2d(1070, 94);
    glEnd();

    glPushMatrix();
    for (int i = 0; i <= 15; i++)
    {
        glTranslatef(0, 10, 0);
        glBegin(GL_QUADS);
        glColor3ub(138, 75, 64);
        glVertex2d(1070, 92);
        glVertex2d(1094, 92);
        glVertex2d(1094, 94);
        glVertex2d(1070, 94);
        glEnd();
    }
    glPopMatrix();

    // Window-1(Left)
    glBegin(GL_QUADS);
    glColor3ub(73, 64, 75);
    glVertex2d(1105, 180);
    glVertex2d(1175, 180);
    glVertex2d(1175, 245);
    glVertex2d(1105, 245);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(HouseR, HouseG, HouseB);
    glVertex2d(1110, 185);
    glVertex2d(1170, 185);
    glVertex2d(1170, 240);
    glVertex2d(1110, 240);
    glEnd();

    // Shades of windows
    glBegin(GL_POLYGON);
    glColor3ub(HouseWindowShadeR, HouseWindowShadeG, HouseWindowShadeB);
    glVertex2d(1170, 185);
    glVertex2d(1170, 220);
    glVertex2d(1158.2687720875197, 219.5201913279898);
    glVertex2d(1145.2144261992657, 218.1905820245566);
    glVertex2d(1133.6105631874846, 214.2017541142567);
    glVertex2d(1126.1164016590426, 210.4546733500357);
    glVertex2d(1119.5892287149156, 202.3561439563967);
    glVertex2d(1115.4795272315764, 191.4775223828517);
    glVertex2d(1115.7212743776554, 185);
    glVertex2d(1170, 185);
    glEnd();

    // Balcony
    glBegin(GL_QUADS); // 1st horrizontal line
    glColor3ub(72, 61, 74);
    glVertex2d(1062, 196);
    glVertex2d(1190, 196);
    glVertex2d(1190, 199);
    glVertex2d(1062, 199);
    glEnd();

    glBegin(GL_QUADS); // 1st Vertical line Left
    glColor3ub(72, 61, 74);
    glVertex2d(1065, 172);
    glVertex2d(1067, 172);
    glVertex2d(1067, 196);
    glVertex2d(1065, 196);
    glEnd();
    // Vertical lines
    int t = 6;
    glPushMatrix();
    for (int i = 0; i < 20; i++)
    {

        glTranslatef(t, 0, 0);
        glBegin(GL_QUADS);
        glColor3ub(72, 61, 74);
        glVertex2d(1065, 172);
        glVertex2d(1067, 172);
        glVertex2d(1067, 196);
        glVertex2d(1065, 196);
        glEnd();
    }
    glPopMatrix();

    glBegin(GL_QUADS); // 2nd Vertical line Left
    glColor3ub(72, 61, 74);
    glVertex2d(1062, 168);
    glVertex2d(1190, 168);
    glVertex2d(1190, 172);
    glVertex2d(1062, 172);
    glEnd();

    // Doors
    glBegin(GL_QUADS);
    glColor3ub(62, 59, 74);
    glVertex2d(1102, 90);
    glVertex2d(1145, 90);
    glVertex2d(1145, 162);
    glVertex2d(1102, 162);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(HouseR, HouseG, HouseB);
    glVertex2d(1105, 90);
    glVertex2d(1142, 90);
    glVertex2d(1142, 159);
    glVertex2d(1105, 159);
    glEnd();

    glBegin(GL_QUADS); // Shading of doors
    glColor3ub(HDoorShade1R, HDoorShade1G, HDoorShade1B);
    glVertex2d(1105, 90);
    glVertex2d(1142, 125);
    glVertex2d(1142, 145);
    glVertex2d(1105, 110);
    glEnd();

    glBegin(GL_TRIANGLES); // Shading of doors
    glColor3ub(HouseWindowShadeR, HouseWindowShadeG, HouseWindowShadeB);
    glVertex2d(1105, 90);
    glVertex2d(1142, 90);
    glVertex2d(1142, 125);
    glEnd();

    glBegin(GL_QUADS); // 2nd door
    glColor3ub(62, 59, 74);
    glVertex2d(1150, 95);
    glVertex2d(1180, 95);
    glVertex2d(1180, 145);
    glVertex2d(1150, 145);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(HouseR, HouseG, HouseB);
    glVertex2d(1154, 98);
    glVertex2d(1176, 98);
    glVertex2d(1176, 142);
    glVertex2d(1154, 142);
    glEnd();

    // 2nd Floor
    glBegin(GL_QUADS);
    glColor3ub(222, 208, 197);
    glVertex2d(1190, 160);
    glVertex2d(1340, 160);
    glVertex2d(1340, 260);
    glVertex2d(1190, 260);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(73, 64, 75);
    glVertex2d(1190, 260);
    glVertex2d(1340, 260);
    glVertex2d(1340, 267);
    glVertex2d(1190, 267);
    glEnd();

    // lines
    glBegin(GL_QUADS);
    glColor3ub(195, 179, 169);
    glVertex2d(1195, 160);
    glVertex2d(1197, 160);
    glVertex2d(1197, 260);
    glVertex2d(1195, 260);
    glEnd();

    glPushMatrix();

    for (int i = 0; i <= 27; i++)
    {
        glTranslatef(5, 0, 0);
        glBegin(GL_QUADS);
        glColor3ub(195, 179, 169);
        glVertex2d(1195, 160);
        glVertex2d(1197, 160);
        glVertex2d(1197, 260);
        glVertex2d(1195, 260);
        glEnd();
    }
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(161, 93, 77);
    glVertex2d(1230, 200);
    glVertex2d(1340, 200);
    glVertex2d(1340, 230);
    glVertex2d(1230, 230);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(67, 61, 75);
    glVertex2d(1235, 205);
    glVertex2d(1335, 205);
    glVertex2d(1335, 225);
    glVertex2d(1235, 225);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(67, 61, 75);
    glVertex2d(1230, 200);
    glVertex2d(1340, 200);
    glVertex2d(1340, 205);
    glVertex2d(1230, 205);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(HouseR, HouseG, HouseB);
    glVertex2d(1240, 205);
    glVertex2d(1330, 205);
    glVertex2d(1330, 220);
    glVertex2d(1240, 220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(67, 61, 75);
    glVertex2d(1260, 205);
    glVertex2d(1262, 205);
    glVertex2d(1262, 220);
    glVertex2d(1260, 220);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(67, 61, 75);
    glVertex2d(1308, 205);
    glVertex2d(1310, 205);
    glVertex2d(1310, 220);
    glVertex2d(1308, 220);
    glEnd();

    // Garage
    glBegin(GL_QUADS);
    glColor3ub(67, 61, 75);
    glVertex2d(1205, 90);
    glVertex2d(1320, 90);
    glVertex2d(1320, 145);
    glVertex2d(1205, 145);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 94, 107);
    glVertex2d(1210, 95);
    glVertex2d(1315, 95);
    glVertex2d(1315, 140);
    glVertex2d(1210, 140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 94, 107);
    glVertex2d(1210, 95);
    glVertex2d(1315, 95);
    glVertex2d(1315, 140);
    glVertex2d(1210, 140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(67, 61, 75);
    glVertex2d(1245, 95);
    glVertex2d(1248, 95);
    glVertex2d(1248, 140);
    glVertex2d(1245, 140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(67, 61, 75);
    glVertex2d(1280, 95);
    glVertex2d(1283, 95);
    glVertex2d(1283, 140);
    glVertex2d(1280, 140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(67, 61, 75);
    glVertex2d(1205, 116);
    glVertex2d(1320, 116);
    glVertex2d(1320, 118);
    glVertex2d(1205, 118);
    glEnd();

    //////////////////////////////////////////////  Drawing Bus   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    glPushMatrix();
    glTranslatef(_moveBus, 0.0, 0.0);
    //-----------BUS(1)--------------//
    glBegin(GL_POLYGON);
    glColor3ub(33, 43, 107);
    glVertex2d(80.25, 58.0);
    glVertex2d(80.25, 112.5);
    glVertex2d(201.5, 112.5);
    glVertex2d(201.5, 85.5);
    glVertex2d(210.0, 85.5);
    glVertex2d(210.0, 58.0);
    glVertex2d(80.25, 58.0);
    glEnd();

    //----------Bus(1) Windows----------//

    glBegin(GL_QUADS);
    glColor3ub(22, 52, 26);
    glVertex2d(80.25, 85.5);
    glVertex2d(80.25, 112.5);
    glVertex2d(201.5, 112.5);
    glVertex2d(201.5, 85.5);
    glEnd();

    //---------Window-1----------------//
    glBegin(GL_QUADS);
    glColor3ub(176, 196, 196);
    glVertex2d(84.25, 89.0);
    glVertex2d(84.25, 110.0);
    glVertex2d(103.0, 110);
    glVertex2d(103.0, 89);
    glEnd();

    //----------Window-2--------------
    glBegin(GL_QUADS);
    glColor3ub(176, 196, 196);
    glVertex2d(106.0, 89.0);
    glVertex2d(106.0, 110);
    glVertex2d(125.0, 110);
    glVertex2d(125.0, 89.0);
    glEnd();

    //----------Window-3--------------
    glBegin(GL_QUADS);
    glColor3ub(176, 196, 196);
    glVertex2d(128.0, 89.0);
    glVertex2d(128.0, 110);
    glVertex2d(147.0, 110);
    glVertex2d(147.0, 89);
    glEnd();

    //---------------Bus Door----------
    glBegin(GL_QUADS);
    glColor3ub(176, 196, 196);
    glVertex2d(152.5, 65);
    glVertex2d(152.5, 110);
    glVertex2d(171.5, 110);
    glVertex2d(171.5, 65);
    glEnd();

    ///----------Bus Front Window------------
    glBegin(GL_QUADS);
    glColor3ub(176, 196, 196);
    glVertex2d(177.0, 89.0);
    glVertex2d(177.0, 110);
    glVertex2d(196.0, 110);
    glVertex2d(196.0, 89);
    glEnd();

    ///-----------Bus Wheels-------------------//

    glBegin(GL_POLYGON); /// Wheel-1
    glColor3f(0.0, 0.0, 0.0);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(108 + 9.65 * cos(theta), 57.5 + 9.65 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON); /// Wheel-1
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(108 + 4.65 * cos(theta), 57.5 + 4.65 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON); /// Wheel-2
    glColor3f(0.0, 0.0, 0.0);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(188.25 + 9.65 * cos(theta), 57.5 + 9.65 * sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON); /// Wheel-2
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(188.25 + 4.65 * cos(theta), 57.5 + 4.65 * sin(theta));
    }
    glEnd();

    // Headlights
    glBegin(GL_POLYGON);
    glColor3ub(headlightsBusR, headlightsBusG, headlightsBusB);
    glVertex2d(204.0934918895565, 80.9481447309282 + 3);
    glVertex2d(210.0489266603704, 80.9092860382246 + 3);
    glVertex2d(209.932272934926, 71.2816851238187);
    glVertex2d(204.0934918895565, 74.9816074764847);
    glVertex2d(204.0934918895565, 80.9481447309282);
    glEnd();

    if (headlightsBusR == 252 && headlightsBusG == 172 && headlightsBusB == 11)
    {
        HeadlightEffect();
    }

    glPopMatrix();

    ////---------------------------------End of Bus--------------------------///

    /// drawing ambulance
    glPushMatrix();
    glTranslatef(500.0 + _moveAmbulance, 0.0, 0.0);

    glBegin(GL_POLYGON); /// main body
    glColor3ub(255, 255, 255);
    glVertex2d(360, 46);
    glVertex2d(360, 30);
    glVertex2d(357, 27);
    glVertex2d(357, 24);
    glVertex2d(360, 22);
    glVertex2d(512, 22);
    glVertex2d(515, 23);
    glVertex2d(517, 26);
    glVertex2d(518, 30);
    glVertex2d(516, 47);
    glVertex2d(515, 53);
    glVertex2d(514, 64);
    glVertex2d(513, 73);
    glVertex2d(510, 78);
    glVertex2d(508, 80);
    glVertex2d(420, 80);
    glVertex2d(414, 79);
    glVertex2d(409, 78);
    glVertex2d(405, 76);
    glVertex2d(401, 74);
    glVertex2d(371, 51);
    glVertex2d(370, 50);
    glVertex2d(365, 48);
    glVertex2d(362, 48);
    glVertex2d(361, 45);
    glEnd();

    glBegin(GL_POLYGON); /// triangular window
    glColor3ub(135, 208, 241);
    glVertex2d(401, 70);
    glVertex2d(401, 54);
    glVertex2d(386, 54);
    glEnd();

    glBegin(GL_QUADS); /// square window 1
    glColor3ub(135, 208, 241);
    glVertex2d(405, 72);
    glVertex2d(425, 72);
    glVertex2d(425, 54);
    glVertex2d(405, 54);
    glEnd();

    glBegin(GL_QUADS); /// square window 2
    glColor3ub(135, 208, 241);
    glVertex2d(430, 72);
    glVertex2d(447, 72);
    glVertex2d(447, 54);
    glVertex2d(430, 54);
    glEnd();

    glBegin(GL_QUADS); /// square window 3
    glColor3ub(135, 208, 241);
    glVertex2d(450, 72);
    glVertex2d(467, 72);
    glVertex2d(467, 54);
    glVertex2d(450, 54);
    glEnd();

    glBegin(GL_QUADS); /// square window 4
    glColor3ub(214, 214, 214);
    glVertex2d(472, 75);
    glVertex2d(509, 75);
    glVertex2d(509, 52);
    glVertex2d(472, 52);
    glEnd();

    glBegin(GL_QUADS); /// plus sign
    glColor3ub(255, 0, 0);
    glVertex2d(488, 72);
    glVertex2d(493, 72);
    glVertex2d(493, 55);
    glVertex2d(488, 55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2d(480, 66);
    glVertex2d(500, 66);
    glVertex2d(500, 60);
    glVertex2d(480, 60);
    glEnd();

    glBegin(GL_POLYGON); /// red line
    glColor3ub(255, 0, 0);
    glVertex2d(365, 46);
    glVertex2d(516, 46);
    glVertex2d(517, 40);
    glVertex2d(360, 40);
    glVertex2d(360, 45);
    glVertex2d(362, 45);
    glVertex2d(361, 46);
    glEnd();

    glBegin(GL_POLYGON); /// upper blue line
    glColor3ub(0, 0, 255);
    glVertex2d(516, 50);
    glVertex2d(516, 48);
    glVertex2d(366, 48);
    glVertex2d(368, 50);
    glEnd();

    glBegin(GL_POLYGON); /// lower blue line
    glColor3ub(0, 0, 255);
    glVertex2d(360, 38);
    glVertex2d(517, 38);
    glVertex2d(517, 36);
    glVertex2d(360, 36);
    glEnd();

    glBegin(GL_POLYGON); /// gray border
    glColor3ub(88, 90, 91);
    glVertex2d(357, 30);
    glVertex2d(357, 24);
    glVertex2d(360, 22);
    glVertex2d(512, 22);
    glVertex2d(515, 23);
    glVertex2d(517, 26);
    glVertex2d(518, 30);
    glEnd();

    glBegin(GL_POLYGON); /// Wheel-1 black
    glColor3f(0.0, 0.0, 0.0);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(387 + 10 * cos(theta), 21 + 10 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON); /// Wheel-1 white
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(387 + 4.65 * cos(theta), 21 + 4.65 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON); /// Wheel-2 black
    glColor3f(0.0, 0.0, 0.0);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(483 + 10 * cos(theta), 21 + 10 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON); /// Wheel-2 white
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 360; i++)
    {
        double theta;
        theta = i * 3.1416 / 180;
        glVertex2d(483 + 4.65 * cos(theta), 21 + 4.65 * sin(theta));
    }
    glEnd();

    // Siren
    bool Siren = TRUE;
    if (Siren == TRUE)
    {
        glBegin(GL_QUADS);
        glColor3ub(255, 0, 0);
        glVertex2d(415, 75);
        glVertex2d(425, 75);
        glVertex2d(425, 90);
        glVertex2d(415, 90);
        glEnd();
        Siren == FALSE;
    }
    else
    {
        glBegin(GL_QUADS);
        glColor3ub(255, 255, 255);
        glVertex2d(415, 75);
        glVertex2d(425, 75);
        glVertex2d(425, 90);
        glVertex2d(415, 90);
        glEnd();
        Siren == TRUE;
    }

    glPopMatrix();

    ///------------------------------Drawing Car-------------------------------

    glPushMatrix();
    glTranslatef(_moveCar, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(230, 150, 11);
    glVertex2d(1145, 58);
    glVertex2d(1120, 58);
    glVertex2d(1102, 58);
    glVertex2d(1090, 44);
    glVertex2d(1060, 35);
    glVertex2d(1060, 17);
    glVertex2d(1174, 17);
    glVertex2d(1174, 30);
    glVertex2d(1163, 38);
    glVertex2d(1145, 58);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 56, 64);
    glVertex2d(1091, 40);
    glVertex2d(1104, 40);
    glVertex2d(1104, 55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(49, 144, 151);
    glVertex2d(1095, 40);
    glVertex2d(1104, 40);
    glVertex2d(1104, 50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 56, 64);
    glVertex2d(1106, 40);
    glVertex2d(1143, 40);
    glVertex2d(1143, 55);
    glVertex2d(1106, 55);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(49, 144, 151);
    glVertex2d(1106, 40);
    glVertex2d(1139, 40);
    glVertex2d(1139, 50);
    glVertex2d(1106, 50);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 56, 64);
    glVertex2d(1146, 40);
    glVertex2d(1160, 40);
    glVertex2d(1146, 55);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(49, 144, 151);
    glVertex2d(1146, 40);
    glVertex2d(1155, 40);
    glVertex2d(1146, 50);
    glEnd();

    // Wheel-1
    DrawCircle(1078, 11, 8, 0, 0, 0);
    DrawCircle(1078, 11, 4, 255, 255, 255);

    // wheel-2
    DrawCircle(1078 + 80, 11, 8, 0, 0, 0);
    DrawCircle(1078 + 80, 11, 4, 255, 255, 255);

    // Black and White lines
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2d(1060, 28);
    glVertex2d(1175, 28);
    glVertex2d(1175, 30);
    glVertex2d(1060, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2d(1060, 25);
    glVertex2d(1175, 25);
    glVertex2d(1175, 28);
    glVertex2d(1060, 28);
    glEnd();

    // Headlights
    glBegin(GL_QUADS);
    glColor3ub(headlightCarR, headlightCarG, headlightCarB);
    glVertex2d(1060, 36);
    glVertex2d(1060, 33);
    glVertex2d(1064, 33);
    glVertex2d(1064, 36);
    glEnd();

    if (headlightCarR == 252 && headlightCarG == 172 && headlightCarB == 11)
    {
        CarHeadlightEffect();
    }

    glPopMatrix();

    glutSwapBuffers();
}
