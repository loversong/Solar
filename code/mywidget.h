#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QPalette>
#include "material.h"
#include "light.h"
#include "planet.h"
#include <QMessageBox>
#include <vector>

class myWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    myWidget(QWidget *parent = 0);
    ~myWidget();
    void planetMove();
    void reset();
    void setAngle(float a, float b);
    void eventChange(int mode);
    bool isCollide(int& i, int& j);
    bool isOut(int& i);
protected:
    virtual void initializeGL();
    virtual void paintGL();
private:
    void drawSphere(GLdouble radius);
    planet pl[11];
    float x0, y0, z0, y1, z1;

    void drawLine();
    std::vector<point> *p;
};

#endif // MYWIDGET_H
