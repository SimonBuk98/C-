#pragma once
#include <iostream>
#include <vector>

class Matrix
{
public:
    Matrix(int rows, int cols, double val = 0.0);
    int getRows();
    int getCols();
    virtual void print();
    double &at(int i, int j);
    virtual void transpose();
    Matrix add(Matrix matrix);
    Matrix multiply(Matrix matrix);
    double &operator()(int i, int j);
    Matrix operator+(Matrix m);
    Matrix operator*(Matrix m);
    Matrix operator*(double v);

private:
    std::vector<double> data;
    int rows;
    int cols;
};
