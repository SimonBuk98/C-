#include <iostream>
#include "matrix.h"
// #include "rotmat.h"
#include <math.h>
#include <sstream>
#include <string>
void setMatrixValues(Matrix *m, std::vector<double> v)
{
	for (int r = 0; r < m->getRows(); r++)
	{
		for (int c = 0; c < m->getCols(); c++)
		{
			m->at(r, c) = v[r * m->getCols() + c];
		}
	}
}
std::string mat2str(Matrix m)
{
	std::stringstream ss;
	for (int r = 0; r < m.getRows(); r++)
	{
		for (int c = 0; c < m.getCols(); c++)
		{
			ss << m(r, c);
			if (c < m.getCols() - 1)
			{
				ss << " ";
			}
		}
		ss << ";";
		if (r < m.getRows() - 1)
		{
			ss << " ";
		}
	}
	return ss.str();
}
void test(Matrix test, std::string target, std::string msg)
{
	std::string mStr = mat2str(test);
	std::string equal = mStr == target ? "Success: " : "Failed: ";
	std::cout << equal << msg << "\t " << mStr << " " << target << std::endl;
}
template <class T1>
void test(T1 test, T1 target, std::string msg)
{
	std::string equal = test == target ? "Success: " : "Failed: ";
	std::cout << equal << msg << "\t " << test << " " << target << std::endl;
}

int main()
{
	// Construction and index access
	Matrix mat(3, 4);
	test(mat, "0 0 0 0; 0 0 0 0; 0 0 0 0;", "simple constructor");
	Matrix mat2(3, 4, 3); /*  */
	test<double>(mat2.at(0, 0), 3, "at method");
	test<double>(mat2(2, 3), 3, "() operator");

	setMatrixValues(&mat, std::vector<double>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
	Matrix mat3 = mat; // Make a copy of mat
	test(mat3, "0 1 2 3; 4 5 6 7; 8 9 10 11;", "creation of mat3");
	mat3.transpose();
	test(mat3, "0 4 8; 1 5 9; 2 6 10; 3 7 11;", "transpose()");
}