#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>

class Matrix
{

public:
  int rows;
  int cols;

  Matrix();
  Matrix(int rows, int cols, double val = 0);
  void print();
  void set(int r, int c, double val);
  double read(int r, int c);
  Matrix add(Matrix *matrix);
  Matrix multiply(Matrix *matrix);
  Matrix transpose();

private:
  std::vector<std::vector<double>> data;
};
#endif
