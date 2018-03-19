#include "matrix.h"
#include <string>
#include <cmath>
#include <iomanip>

// Parameterized constructor
matrix::matrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols)
{
	if (rows < 1 || cols < 1)
	{
		throw matrixException("p-constructor bad arguments");
	}

	the_matrix = new double *[rows];
	for (int i = 0; i < rows; i++)
	{
		the_matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			the_matrix[i][j] = 0;
		}
	}
}

// Copy constructor
matrix::matrix(const matrix &from) : rows(from.rows), cols(from.cols)
{
	// stub
	the_matrix = new double *[rows];
	for (int i = 0; i < rows; i++)
	{
		the_matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			the_matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			the_matrix[i][j] = from.the_matrix[i][j];
		}
	}
}

// Destructor
matrix::~matrix()
{
	// stub
	for (int i = 0; i < rows; i++)
	{
		delete[] the_matrix[i];
	}
	delete[] the_matrix;
}

// Assignment operator
matrix &matrix::operator=(const matrix &rhs)
{
	rows = rhs.rows;
	cols = rhs.cols;
	the_matrix = new double *[rows];
	for (int i = 0; i < rows; i++)
	{
		the_matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			the_matrix[i][j] = 0;
		}
	}
	// stub
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			the_matrix[i][j] = rhs[i][j];
		}
	}
	return *this;
}

// Named constructor (static)
matrix matrix::identity(unsigned int size)
{
	// use p-constructor
	matrix retval(size, size);
	for (int i = 0; i < size; i++)
	{
		retval.the_matrix[i][i] = 1;
	}
	return retval;
}

// Binary operations
matrix matrix::operator+(const matrix &rhs) const
{

	matrix retVal(rhs);
	if (rhs.cols != cols && rhs.rows != rows)
	{
		throw matrixException("Martix Add- not same size matrix");
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			retVal.the_matrix[i][j] = the_matrix[i][j] + rhs.the_matrix[i][j];
		}
	}
	return retVal;
}

matrix matrix::operator*(const matrix &rhs) const
{
	// stub
	matrix retVal(rows, rhs.cols);
	if (cols != rhs.rows)
	{
		throw matrixException("Martix *- Columns Rows Don't match");
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rhs.cols; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				retVal.the_matrix[i][j] = the_matrix[i][k] * rhs.the_matrix[k][j];
			}
		}
	}

	return retVal;
}

matrix matrix::operator*(const double scale) const
{
	// stub
	matrix retVal(*this);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			retVal.the_matrix[i][j] = the_matrix[i][j] * scale;
		}
	}
	return retVal;
}

// Unary operations
matrix matrix::operator~() const
{
	// stub
	matrix retVal(*this);
	if (rows != cols)
	{
		throw matrixException("Martix ~- not square matrix");
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			retVal.the_matrix[i][j] = the_matrix[j][i];
		}
	}
	return retVal;
}

void matrix::clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			the_matrix[i][j] = 0;
		}
	}
	return;
}

matrixrow matrix::operator[](unsigned int row)
{
	if (row < rows)
	{
		return matrixrow(the_matrix[row], cols);
	}
	else
	{
		throw matrixException("invalid row on index operator");
	}
}

matrixrow matrix::operator[](unsigned int row) const
{
	if (row < rows)
	{
		return matrixrow(the_matrix[row], cols);
	}
	else
	{
		throw matrixException("invalid row on index operator");
	}
}

std::ostream &matrix::out(std::ostream &os) const
{
	for (int i = 0; i < rows; i++)
	{
		os << "|" << std::setw(3);
		for (int j = 0; j < cols; j++)
		{
			os << the_matrix[i][j] << std::setw(3);
		}
		os << "|" << std::endl;
	}
	return os;
}

// Global insertion and operator
std::ostream &operator<<(std::ostream &os, const matrix &rhs)
{
	return rhs.out(os);
}

// Global scalar multiplication
matrix operator*(const double scale, const matrix &rhs)
{
	matrix retval(rhs);
	return (retval * scale);
}
