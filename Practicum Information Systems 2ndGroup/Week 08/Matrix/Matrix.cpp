#include "Matrix.h"
#include<utility>
#include<fstream>
#include<exception>
#include<iostream>

void Matrix::free(){
	for (size_t i = 0; i < rows; i++){
		delete[] data[i];
	}
	delete[] data;
}

void Matrix::copyFrom(const Matrix& other)
{
	rows = other.rows;
	colls = other.colls;

	data = new double*[rows];
	for (size_t i = 0; i < rows; i++){
		
		data[i] = new double[colls];
		for (size_t j = 0; j < colls; j++){
			data[i][j] = other.data[i][j];
		}
	}
}

void Matrix::moveFrom(Matrix&& other)
{
	rows = other.rows;
	other.rows = 0;

	colls = other.colls;
	other.colls = 0;

	data = other.data;
	other.data = nullptr;
}

bool Matrix::areTheSameDimensions(const Matrix& other) const
{
	return rows == other.rows && colls == other.colls;
}

Matrix::Matrix():Matrix(2,2){
}

Matrix::Matrix(unsigned rows, unsigned colls) : Matrix(nullptr,rows,colls){}

Matrix::Matrix(double** data, unsigned rows, unsigned colls)
{
	this->rows = rows;
	this->colls = colls;
	this->data = new double*[rows];
	
	for (size_t i = 0; i < rows; i++){
		
		this->data[i] = new double[colls]{0};
		
		if (data && data[i])
		{
			for (size_t j = 0; j < colls; j++)
			{
				this->data[i][j] = data[i][j];
			}
		}
	}
}

Matrix::Matrix(const Matrix& other){
	copyFrom(other);
}

Matrix::Matrix(Matrix&& other)noexcept{
	moveFrom(std::move(other));
}

Matrix& Matrix::operator=(Matrix&& other) noexcept{
	
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Matrix::~Matrix()
{
	free();
}

const double* Matrix::operator[](size_t index) const{
	return data[index];
}

double* Matrix::operator[](size_t index){
	return data[index];
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	if (areTheSameDimensions(other)) {
		
		for (size_t i = 0; i < rows; i++){
			
			for (size_t j = 0; j < colls; j++){
				data[i][j] += other.data[i][j];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	if (areTheSameDimensions(other)) {

		for (size_t i = 0; i < rows; i++){
			for (size_t j = 0; j < colls; j++)
			{
				data[i][j] -= other.data[i][j];
			}
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	if (colls == other.rows) {

		Matrix res(rows, other.colls);

		for (size_t i = 0; i < rows; i++) {

			for (size_t j = 0; j < other.colls; j++) {
				
				res.data[i][j] = 0; 
				for (size_t k = 0; k < colls; k++) {
					res.data[i][j] += data[i][k] * other.data[k][j];
				}
			}
		}
		*this = std::move(res);
	}
	return *this;
}

Matrix& Matrix::operator*=(double num)
{
	for (size_t i = 0; i < rows; i++){
		for (size_t j = 0; j < colls; j++){
			data[i][j] *= num;
		}
	}
	return *this;
}

Matrix& Matrix::operator/=(double num)
{
	if (num == 0) {
		return *this;
	}
	
	return *this *= (1 / num);
}

Matrix& Matrix::operator++()
{
	if (rows == colls) {
		
		for (size_t i = 0; i < rows; i++){
			
			for (size_t j = 0; j < colls; j++){
				if (i == j) {
					data[i][j]++;
				}
			}
		}
	}
	return *this;
}

bool operator!(const Matrix& mtx)
{
	bool isTheNullMtx = true;
	for (size_t i = 0; i < mtx.rows; i++)
	{
		for (size_t j = 0; j < mtx.colls; j++)
		{
			if (mtx.data[i][j] != 0) {
				isTheNullMtx = false;
				break;
			}
		}
	}
	return !isTheNullMtx;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
	if (!lhs.areTheSameDimensions(rhs)) {
		return false;
	}
	
	for (size_t i = 0; i < lhs.rows; i++)
	{
		for (size_t j = 0; j < lhs.colls; j++)
		{
			if (lhs.data[i][j] != rhs.data[i][j]) {
				return false;
			}
		}
		return true;
	}
}

bool operator!=(const Matrix& lhs, const Matrix& rhs)
{
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const Matrix& mtx)
{
	os << mtx.rows << " " << mtx.colls << std::endl;

	for (size_t i = 0; i < mtx.rows; i++)
	{
		for (size_t j = 0; j < mtx.colls; j++)
		{
			os << mtx.data[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Matrix& mtx)
{

	is >> mtx.rows >> mtx.colls;
	mtx.free();
	mtx.data = new double* [mtx.rows];

	for (size_t i = 0; i < mtx.rows; i++)
	{
		mtx.data[i] = new double[mtx.colls];
		for (size_t j = 0; j < mtx.colls; j++)
		{
			is >> mtx.data[i][j];
		}
	}
	return is;
}

bool iSymmetric(const Matrix& mtx)
{
	if (mtx.rows == mtx.colls) {
		
		for (size_t i = 0; i < mtx.rows; i++)
		{
			for (size_t j = 0; j < mtx.colls; j++)
			{
				if (mtx.data[i][j] != mtx.data[j][i]) {
					return false;
				}
			}
		}
	}
	else {
		return false;
	}
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
	Matrix res(lhs);
	res += rhs;
	return res;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs)
{
	Matrix res(lhs); 
	res -= rhs;
	return res;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
	Matrix res(lhs);
	res *= rhs;
	return res;
}

Matrix operator*(const Matrix& mtx, double num)
{
	return  mtx * num;
}

Matrix operator/(const Matrix& mtx, double num)
{
	if (num == 0) {
		throw std::invalid_argument("Canot divide by zero.");
	}

	return mtx * (1 / num);
}

Matrix& Matrix::operator++(int a)
{
	Matrix result(*this);
	++* this;
	return result;
}

Matrix operator~(const Matrix& mtx)
{
	Matrix res(mtx.colls,mtx.rows);

	for (size_t i = 0; i < mtx.colls; i++)
	{
		for (size_t j = 0; j < mtx.rows; j++)
		{
			res[i][j] = mtx.data[j][i];
		}
	}
	return res;
}

static void freeMemory(double** matrix, size_t rows)
{
	if (!matrix)
	{
		return;
	}
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main() {
	
	double** m1Data = new double* [3] {new double[3] {2, 3, 4}, new double[3] {1, 2, 3}, new double[3] {0, 1, 0}};
	Matrix m1(m1Data, 3, 3);
	double** m2Data = new double* [3] {new double[4] {0, 1, 1, 0}, new double[4] {2, 3, 4, 1}, new double[4] {1, 1, 1, 0}};
	Matrix m2(m2Data, 3, 4);

	freeMemory(m1Data, 3);
	freeMemory(m2Data, 3);
	std::cout << m1 * m2 << std::endl;

	std::cout << m1 << std::endl;
	std::cout << ~m1 << std::endl;

	std::cout << m2 << std::endl;
	std::cout << ~m2 << std::endl;

	m1 += m2;
	std::cout << m1 << std::endl;

	std::cout << !m1 << std::endl;
	std::cout << !(m1 * 0) << std::endl;

	std::cout << std::endl << m1 << std::endl;
	std::cout << m1++ << std::endl;
	std::cout << ++m1 << std::endl;

	return 0;
}
