#include "matrix.h"
#include <string>
#include <cmath>
#include <iomanip>

/**
 * @brief Default constructor for matrix object
 * @param  rows: numbers of matrix rows
 * @param  cols: number of matrix columns
 */
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

/**
 * @brief  constructor used to copy a matrix into a new matrix object
 * @param  &from: Matrix to be copied
 */
matrix::matrix(const matrix &from) : rows(from.rows), cols(from.cols)
{
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

/**
 * @brief  Used to delete the matrix array
 */
matrix::~matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] the_matrix[i];
	}
	delete[] the_matrix;
}

/**
 * @brief  assigns a matrix to the current objects
 * @param  &rhs: matrix being asigned
 * @retval current object's matrix
 */
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
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			the_matrix[i][j] = rhs[i][j];
		}
	}
	return *this;
}

/**
 * @brief  Generates an identity matrix of a given size
 * @param  size: size of the matrix
 * @retval returns the generated matrix
 */
matrix matrix::identity(unsigned int size)
{
	matrix retval(size, size);
	for (int i = 0; i < size; i++)
	{
		retval.the_matrix[i][i] = 1;
	}
	return retval;
}

/**
 * @brief  Used to added two matries
 * @param  &rhs: matrix to added to the current object
 * @retval return sum of two matries
 */
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

/**
 * @brief  used to multiply two matrixes
 * @param  &rhs: matrix to be multplied
 * @retval return the multiplied matrixed
 */
matrix matrix::operator*(const matrix &rhs) const
{
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
				retVal.the_matrix[i][j] += the_matrix[i][k] * rhs.the_matrix[k][j];
			}
		}
	}

	return retVal;
}

/**
 * @brief  multiplies the matrix by the scale
 * @param  scale: scale to multiply each number in the matrix
 * @retval scaled matrix
 */
matrix matrix::operator*(const double scale) const
{
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

/**
 * @brief  Transulates the Matrix
 * @retval Translated matrix
 */
matrix matrix::operator~() const
{
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

/**
 * @brief  Clears the matrix
 */
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

/**
 * @brief  returns the value at that index
 * @param  row: row with of the value
 * @retval value
 */
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

/**
 * @brief  returns the value at that index
 * @param  row: row with of the value
 * @retval value
 */
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

/**
 * @brief  Prints out the matrix
 * @param  &os:  output stream
 * @retval output stream
 */
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
