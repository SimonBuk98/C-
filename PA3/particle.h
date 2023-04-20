#ifndef particle_H
#define particle_H
#include <iostream>
#include <vector>
#include "matrix.h"

// Opencv
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

// Deklaration
class Particle
{
private:
    Matrix p;
    Matrix v;
    Matrix f;
    float m;

public:
    particle(float m, Matrix p = Matrix(2, 1), Matrix v = Matrix(2, 1));
    void setPosition(Matrix p);
    void setVelocity(Matrix v);
    void setForce(Matrix f);

    void update(float dt);
    void print();

    Matrix getPosition();
    Matrix getVelocity();
    float getMass();
};

#endif