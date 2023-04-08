#include "matrix.h"

Matrix::Matrix(int _rows, int _cols, double _val)
{
  rows = _rows;
  cols = _cols;
  for (int i = 0; i < rows * cols; i++)
  {
    data.push_back(_val);
  }
}

int Matrix::getRows()
{
  return rows;
}

int Matrix::getCols()
{
  return cols;
}

void Matrix::print()
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      std::cout << data[i * cols + j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

double &Matrix::at(int i, int j)
{
  return data[i * cols + j];
}

Matrix Matrix::add(Matrix matrix)
{
  Matrix tempM(rows, cols);
  if (rows == matrix.rows && cols == matrix.cols)
  {

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        tempM.at(i, j) = data[i * cols + j] + matrix.data[i * cols + j];
      }
    }
  }
  return tempM;
}

Matrix Matrix::multiply(Matrix matrix)
{
  Matrix tempM(rows, matrix.cols);
  if (cols == matrix.rows)
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < matrix.cols; j++)
      {
        double sum = 0;
        for (int k = 0; k < matrix.rows; k++)
        {
          sum += (data[i * cols + k] * matrix.data[k * matrix.cols + j]);
        }
        tempM.at(i, j) = sum;
      }
    }
  }
  return tempM;
}

Matrix Matrix::skalar(double v)
{
  Matrix temp(rows,cols);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      temp.at(i,j) = data[i*cols+j]*v;
    }
  }
  return temp;
}

void Matrix::transpose()
{
  Matrix tempM(rows, cols);

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      tempM.data[i * cols + j] = data[i * cols + j];
    }
  }
  rows = cols;
  cols = tempM.rows;
  for (int r = 0; r < tempM.rows; r++)
  {
    for (int c = 0; c < tempM.cols; c++)
    {
      data[c * tempM.rows + r] = tempM.data[r * tempM.cols + c];
    }
  }
}

double &Matrix::operator()(int i, int j)
{
  return at(i, j);
}

Matrix Matrix::operator+(Matrix m)
{
  return add(m);
}

Matrix Matrix::operator*(Matrix m)
{
  return multiply(m);
}

Matrix Matrix::operator*(double v)
{
  return skalar(v);
}