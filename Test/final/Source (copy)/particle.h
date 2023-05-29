#pragma once
#include <iostream>
#include "matrix.h"
#include <cmath>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


class Particle{
    private:
    Matrix p;
    Matrix v;
    Matrix f;
    float m;

public:
Particle(float m, Matrix p = Matrix(2,1), Matrix v = Matrix(2,1));
void setPosition(Matrix p);
void setVelocity(Matrix v);
void setForce (Matrix f);

void update(float dt);
void print();

Matrix getPosition();
Matrix getVelocity();
float getMass();

};