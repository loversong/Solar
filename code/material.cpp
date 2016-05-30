#include "material.h"

void sun_mat()
{
    GLfloat sun_mat_ambient[] = { 0.8f, 0.0f, 0.0f, 1.0f };
    GLfloat sun_mat_diffuse[] = { 0.6f, 0.0f, 0.0f, 1.0f };
    GLfloat sun_mat_specular[] = { 0.6f, 0.0f, 0.0f, 1.0f };
    GLfloat sun_mat_emission[] = { 0.5f, 0.0f, 0.0f, 1.0f };
    GLfloat sun_mat_shininess = 30.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT, sun_mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, sun_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, sun_mat_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);
    glMaterialf(GL_FRONT, GL_SHININESS, sun_mat_shininess);
}

void planet_mat(int m)
{
    GLfloat planet_mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat planet_mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat planet_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat planet_mat_shininess = 30.0f;
    switch (m) {
    case 1:
        planet_mat_ambient[2] = 0.8f;
        planet_mat_specular[2] = 0.7f;
        planet_mat_emission[2] = 0.6f;
        planet_mat_ambient[1] = 0.3f;
        planet_mat_specular[1] = 0.3f;
        planet_mat_emission[1] = 0.3f;
        break;
    case 2:
        planet_mat_ambient[0] = 0.8f;
        planet_mat_specular[0] = 0.8f;
        planet_mat_emission[0] = 0.5f;
        planet_mat_ambient[1] = 0.5f;
        planet_mat_specular[1] = 0.4f;
        planet_mat_emission[1] = 0.3f;
        break;
    case 3:
        planet_mat_ambient[2] = 0.8f;
        planet_mat_specular[2] = 0.7f;
        planet_mat_emission[2] = 0.4f;
        break;
    case 4:
        planet_mat_ambient[0] = 0.8f;
        planet_mat_specular[0] = 0.6f;
        planet_mat_emission[0] = 0.3f;
        planet_mat_ambient[1] = 0.2f;
        planet_mat_specular[1] = 0.1f;
        planet_mat_emission[1] = 0.1f;
        break;
    case 5:
        planet_mat_ambient[0] = 0.8f;
        planet_mat_specular[0] = 0.7f;
        planet_mat_emission[0] = 0.6f;
        planet_mat_ambient[1] = 0.5f;
        planet_mat_specular[1] = 0.4f;
        planet_mat_emission[1] = 0.3f;
        planet_mat_ambient[2] = 0.2f;
        planet_mat_specular[2] = 0.1f;
        planet_mat_emission[2] = 0.1f;
        break;
    case 6:
        planet_mat_ambient[0] = 0.7f;
        planet_mat_specular[0] = 0.3f;
        planet_mat_emission[0] = 0.2f;
        planet_mat_ambient[1] = 0.5f;
        planet_mat_specular[1] = 0.1f;
        planet_mat_emission[1] = 0.1f;
        planet_mat_ambient[2] = 0.3f;
        break;
    case 7:
        planet_mat_ambient[0] = 0.5f;
        planet_mat_specular[0] = 0.2f;
        planet_mat_emission[0] = 0.1f;
        planet_mat_ambient[1] = 0.5f;
        planet_mat_specular[1] = 0.2f;
        planet_mat_emission[1] = 0.1f;
        planet_mat_ambient[2] = 0.5f;
        planet_mat_specular[2] = 0.2f;
        planet_mat_emission[2] = 0.1f;
        break;
    case 8:
        planet_mat_ambient[2] = 0.5f;
        planet_mat_specular[2] = 0.4f;
        planet_mat_emission[2] = 0.3f;
        break;
    case 9:
        planet_mat_ambient[0] = 0.7f;
        planet_mat_specular[0] = 0.2f;
        planet_mat_emission[0] = 0.1f;
        planet_mat_ambient[1] = 0.5f;
        planet_mat_specular[1] = 0.2f;
        planet_mat_emission[1] = 0.1f;
        planet_mat_ambient[2] = 0.3f;
        planet_mat_specular[2] = 0.2f;
        planet_mat_emission[2] = 0.1f;
        break;
    case 10:
        planet_mat_ambient[0] = 0.7f;
        planet_mat_specular[0] = 0.2f;
        planet_mat_emission[0] = 0.1f;
        planet_mat_ambient[1] = 0.7f;
        planet_mat_specular[1] = 0.2f;
        planet_mat_emission[1] = 0.1f;
        planet_mat_ambient[2] = 0.7f;
        planet_mat_specular[2] = 0.2f;
        planet_mat_emission[2] = 0.1f;
        break;
    }

    glMaterialfv(GL_FRONT, GL_AMBIENT, planet_mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, planet_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, planet_mat_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, planet_mat_emission);
    glMaterialf(GL_FRONT, GL_SHININESS, planet_mat_shininess);
}

void comet_mat()
{
    GLfloat comet_mat_ambient[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat comet_mat_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
    GLfloat comet_mat_specular[] = { 0.6f, 0.6f, 0.6f, 1.0f };
    GLfloat comet_mat_emission[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat comet_mat_shininess = 30.0f;

    glMaterialfv(GL_FRONT, GL_AMBIENT, comet_mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, comet_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, comet_mat_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, comet_mat_emission);
    glMaterialf(GL_FRONT, GL_SHININESS, comet_mat_shininess);
}
