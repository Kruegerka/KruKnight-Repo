#include "matrix.h"
#include <string>
#include <cmath>
#include <iomanip>

// Parameterized constructor
matrix::matrix(unsigned int rows, unsigned int cols):rows(rows),cols(cols) 
{  
	if (rows < 1 || cols < 1)
	{
		throw matrixException("p-constructor bad arguments");
	}
	
	the_matrix = new double* [rows];
	for(int i=0; i < rows; i++){
		the_matrix[i] = new double [cols];
		for(int j=0; j < cols; j++){
			the_matrix[i][j] = 0;
		}

	}
}

// Copy constructor
matrix::matrix(const matrix& from):rows(from.rows),cols(from.cols)
{
	// stub
	the_matrix = from;
	
}

// Destructor
matrix::~matrix()
{
	// stub
	for(int i=0; i < rows; i++){
		delete[] the_matrix[i];
	}
	delete[] the_matrix;
}

// Assignment operator
matrix& matrix::operator=(const matrix& rhs)
{
	// stub
	for(int i=0; i < rows; i++){
		for(int j=0; j < cols; j++){
			the_matrix[i][j] = rhs[i][j];
		}
	}
	return *this;
}

// Named constructor (static)
matrix matrix::identity(unsigned int size)
{
	// use p-constructor
	return matrix(size,size);
}


// Binary operations
matrix matrix::operator+(const matrix& rhs) const
{
	// stub
	if(rhs.cols != cols && rhs.rows != rows){
		throw matrixException("Martix Add- not same size matrix");
	}
	for(int i=0; i < rows; i++){
		for(int j=0; j < cols; j++){
			the_matrix[i][j] = the_matrix[i][j] + rhs[i][j];
		}

	}
	matrix retVal(rhs);
	return retVal;
}


matrix matrix::operator*(const matrix& rhs) const
{
	// stub
	matrix retVal(rhs);
	return retVal;
}

matrix matrix::operator*(const double scale) const
{
	// stub
	matrix retVal(*this);
	return retVal;
}


// Unary operations
matrix matrix::operator~() const
{
	// stub
	matrix retVal(*this);
	return retVal;
}
	

void matrix::clear()
{
	// stub
	for(int i=0; i < rows; i++){
		for(int j=0; j < cols; j++){
			the_matrix[i][j] = 0;
		}

	}
	return;
}

double* matrix::operator[](unsigned int row)
{
	// stub
	return NULL;
}

double* matrix::operator[](unsigned int row) const
{
	// stub
	return NULL;
}


std::ostream& matrix::out(std::ostream& os) const
{
	// stub
	for(int i=0; i < rows; i++){
		os<< "|" << std::setw(3);
		for(int j=0; j < cols; j++){
			os<< the_matrix[i][j] << std::setw(3); 
		}
		os<< "|" << std::endl;

	}
	return os;	
}



// Global insertion and operator
std::ostream& operator<<(std::ostream& os, const matrix& rhs)
{
	// stub
	return rhs.out(os);
}

// Global scalar multiplication
matrix operator*(const double scale, const matrix& rhs)
{
	// stub
	matrix retval(rhs);
	return retval;
}


