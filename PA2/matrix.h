#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>

class Matrix
{

public:
  Matrix();
  Matrix(int rows, int cols, double val = 0);
  int getRows();
  int getCols();
  virtual void print();
  double& at(int r, int c);
  virtual void transpose();
  Matrix add(Matrix matrix);
  Matrix multiply(Matrix matrix);
  double& operator() (int i, int j);
  Matrix operator+ (Matrix m);
  Matrix operator* (Matrix m);

private:
  int rows;
  int cols;
  std::vector<double> data;
};
#endif
