#ifndef RotMat2D_H
#define RotMat2D_H
#include <iostream>
#include <vector>
#include "matrix.h"

class RotMat2D : public Matrix
{
public:
    RotMat2D();
    RotMat2D(double angle);
    virtual void print() override;
    virtual void transpose()override;

private:
    double angle;
};
#endif
