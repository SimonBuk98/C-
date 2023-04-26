#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>

class Matrix
{
public:
    Matrix();
    Matrix(int rows, int cols, double val = 0.0);
    int getRows();
    int getCols();
    virtual void print();
    double&  at(int i, int j);
    virtual void transpose();

private:
    std::vector<double> data;
    int rows;
    int cols;
};
#endif