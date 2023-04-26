#include <iostream>
#include <vector>
#include "class.h"

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
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            std::cout << data[i * rows + j];
        }
        std::cout << std::endl;
    }
}

double& Matrix::at(int i, int j){
    return data[i*rows + j];
}

void Matrix::transpose(){
    
}
