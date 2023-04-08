#include "rotmat.h"
#include <cmath>

RotMat2D::RotMat2D() : Matrix(2,2){
    at(0,0) = 1;
    at(1,1) = 1;
    angle=0;
}
RotMat2D::RotMat2D(double _angle) : Matrix(2,2){
    angle = _angle;
    at(0,0) = cos(angle);
    at(0,1) = -sin(angle);
    at(1,0) = sin(angle);
    at(1,1) = cos(angle);
}

void RotMat2D::print(){ 
    Matrix::print();
    std::cout << angle << std:: endl;
}

void RotMat2D::transpose(){
    Matrix::transpose();
    angle = (-1)*angle;

}