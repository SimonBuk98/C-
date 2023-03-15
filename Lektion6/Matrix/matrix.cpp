#include "matrix.h"

Matrix::Matrix(int _rows, int _cols, double _val)
{
  rows = _rows;
  cols = _cols;
  for (int i = 0; i < rows; i++)
  {
    std::vector<double> tempV;
    for (int j = 0; j < cols; j++)
    {
      tempV.push_back(_val);
    }
    data.push_back(tempV);
  }
}

void Matrix::print()
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      std::cout << data[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void Matrix::set(int r, int c, double val)
{
  data[r][c] = val;
}

double Matrix::read(int r, int c)
{
  return data[r][c];
}

Matrix Matrix::add(Matrix *matrix)
{
  Matrix tempM(rows, cols);
  if (rows == matrix->rows && cols == matrix->cols)
  {

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        tempM.set(i, j, data[i][j] + matrix->data[i][j]);
      }
    }
  }
  return tempM;
}

Matrix Matrix::multiply(Matrix *matrix)
{
  Matrix tempM(rows, matrix->cols);
  if (cols == matrix->rows)
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < matrix->cols; j++)
      {
        int sum = 0;
        for (int k = 0; k < matrix->rows; k++)
        {

          sum += (data[i][k] * matrix->data[k][j]);
        }
        tempM.set(i, j, sum);
      }
    }
  }
  return tempM;
}

Matrix Matrix::transpose()
{
  Matrix tempM(cols, rows);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      tempM.data[j][i] = data[i][j];
    }
  }
  return tempM;
}
