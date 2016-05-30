#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
{
    Q_UNUSED(parent);
    p = new std::vector<point>[9];
    for (int i = 0; i < 11; i++)
    {
        pl[i] = planet(i);
        if (i == 0 || i == 10)
            continue;
        p[i - 1].push_back(pl[i].getPos() / 10);
    }
    setAngle(0, 30);
}

myWidget::~myWidget()
{
    delete[] p;
}

void myWidget::reset()
{
    for (int i = 0; i < 11; i++)
        pl[i] = planet(i);
    delete[] p;
    p = new std::vector<point>[9];
    update();
}

void myWidget::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void myWidget::paintGL()
{
    glLoadIdentity();
    glPushMatrix();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 0.01, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x0, y0, z0, 0, 0, 0, 0, y1, z1);


    GLint x = (width() - height()) / 2;
    glViewport(x, 0, width() - x - x, height());
    sun_mat();
    sunBackLight();
    drawSphere(starRadius[0]);

    glDisable(GL_LIGHT0);
    sunLight();
    for (int i = 1; i < 10; i++)
    {
        planet_mat(i);
        glTranslatef(pl[i].getPos().x / 10, pl[i].getPos().y / 10, pl[i].getPos().z / 10);
        drawSphere(starRadius[i]);
        if (i == 3)
        {
            glTranslatef(pl[10].getPos().x / 10, pl[10].getPos().y / 10, pl[10].getPos().z / 10);
            planet_mat(10);
            drawSphere(starRadius[10]);
            glTranslatef(-pl[10].getPos().x / 10, -pl[10].getPos().y / 10, -pl[10].getPos().z / 10);
        }
        glTranslatef(-pl[i].getPos().x / 10, -pl[i].getPos().y / 10, -pl[i].getPos().z / 10);
    }

    drawLine();

    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHTING);
    glPopMatrix();
    glFinish();
}

void myWidget::planetMove()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i != j)
                pl[i].calAcc(pl[j]);
        }
        pl[i].moveDay();
        p[i - 1].push_back(pl[i].getPos() / 10);
    }

    pl[10].calAcc(pl[3]);
    pl[10].moveDay();
    update();
}

void myWidget::drawSphere(GLdouble radius)
{
    GLUquadricObj *quadric = gluNewQuadric();
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluSphere(quadric, radius, 360, 360);
    gluDeleteQuadric(quadric);
}


void myWidget::setAngle(float a, float b)
{
    float r = 2.5;
    a = a / 180 * PI;
    b = b / 180 * PI;
    x0 = -r * cos(b);
    y0 = -r * sin(b) * sin(a);
    z0 = -r * sin(b) * cos(a);
    y1 = -sin(a);
    z1 = cos(a);
    update();
}

void myWidget::eventChange(int mode)
{
    point add;
    switch (mode) {
    case 0:
        pl[0].massChange(2);
        break;
    case 1:
        pl[0].massChange(1);
        break;
    case 2:
        pl[0].massChange(0.5);
        break;
    case 3:
        pl[3].massChange(2);
        break;
    case 4:
        pl[3].massChange(1);
        break;
    case 5:
        pl[3].massChange(0.5);
        break;
    case 6:
        pl[3].massChange(3);
        add = starInitVelocity[3] * 2;
        pl[3].speedChange(add);
        break;
    case 7:
        pl[3].massChange(1.5);
        add = starInitVelocity[3] * .2;
        pl[3].speedChange(add);
        break;
    default:
        break;
    }
}

bool myWidget::isCollide(int &i, int &j)
{
    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            float dis;
            dis = distance(pl[i].getPos() * shrinkCoeff[i], pl[j].getPos() * shrinkCoeff[j]);
            if (dis < 0.1)
                return true;
        }
    }
    return false;
}

bool myWidget::isOut(int& i)
{
    for (i = 1; i < 11; i++)
    {
        float dis;
        dis = distance(starInitPosition[0], pl[i].getPos());
        if (dis > 13)
            return true;
    }
    return false;
}

void myWidget::drawLine()
{
    planet_mat(10);
    for (int j = 0; j < 9; j++)
    {
        glBegin(GL_LINE_STRIP);
        for (int i = 0; i < (int)p[j].size(); i++)
        {
            glVertex3f(p[j][i].x, p[j][i].y, p[j][i].z);
        }
        glEnd();
    }
}
