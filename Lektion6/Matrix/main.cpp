#include <iostream>
#include "matrix.h"

int main()
{
	Matrix mat(3, 4);
	Matrix test(4, 4);
	mat.print();
	Matrix matCopy(mat); // Make a copy of mat
	for (int r = 0; r < mat.rows; r++)
	{
		for (int c = 0; c < mat.cols; c++)
		{
			mat.set(r, c, r * c);
		}
	}
	
	mat.print();
	matCopy.print();
	Matrix matAdd = mat.add(&mat);
	matAdd.print();
	Matrix matOnes(4, 2, 1.0);
	matOnes.print();
	Matrix matMul = mat.multiply(&matOnes);
	matMul.print();
	Matrix matTrans = mat.transpose();
	matTrans.print();
	test.print();

	return 0;
}
