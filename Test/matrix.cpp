#include <iostream>
#include <vector>
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
}

double &Matrix::at(int i, int j)
{
    return data[i * cols + j];
}

void Matrix::transpose()
{
    Matrix result(cols, rows);
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            result.at(i, j) = at(j, i);
        }
    }
    *this = result;
}

Matrix Matrix::add(Matrix matrix)
{
    if (rows != matrix.getRows() || cols != matrix.getCols())
    {
        throw std::invalid_argument("Matrix dimensions must match");
    }

    Matrix result(rows, matrix.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.at(i, j) = at(i, j) + matrix.at(i, j);
        }
    }
    return result;
}

Matrix Matrix::multiply(Matrix matrix)
{
    Matrix result(rows, matrix.getCols());

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            double sum = 0;
            for (int k = 0; k < cols; k++)
            {
                sum += at(i, k) * matrix.at(k, j);
            }
            result.at(i, j) = sum;
        }
    }

    return result;
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
    Matrix result(rows, cols);
    double sum = 0.0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum = at(i, j) * v;
            result.at(i, j) = sum;
        }
    }
    return result;
}