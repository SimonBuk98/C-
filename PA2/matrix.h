#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>

class Matrix
{

public:
  Matrix();
  Matrix(int rows, int cols, double val = 0);
  int getRow();
  int getCols();
  virtual void print();
  void set(int r, int c, double val);
  double& at(int r, int c);
  Matrix add(Matrix matrix);
  Matrix multiply(Matrix matrix);
  Matrix transpose();

private:
  int rows;
  int cols;
  std::vector<std::vector<double>> data;
};
#endif
