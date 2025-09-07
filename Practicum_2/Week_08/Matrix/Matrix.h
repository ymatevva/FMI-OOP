#pragma once
#include<fstream>

class Matrix {

	double** data;
	unsigned rows;
	unsigned colls;

	void free();
	void copyFrom(const Matrix& other);
	void moveFrom(Matrix&& other);
	bool areTheSameDimensions(const Matrix& other) const;

public:

	Matrix();
	Matrix(unsigned rows, unsigned colls);
	Matrix(double** data, unsigned rows, unsigned colls);
	Matrix(const Matrix& other);
	Matrix(Matrix&& other)noexcept;
	Matrix& operator=(Matrix&& other)noexcept;
	Matrix&operator=(const Matrix& other);
	~Matrix();

	const double* operator[](size_t index)const;
	double* operator[](size_t index);

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(double num);
	Matrix& operator/=(double num);
	Matrix& operator++();

    Matrix& operator++(int a);
	friend Matrix operator~(const Matrix& mtx);
	friend bool operator!(const Matrix& mtx);
	friend bool operator==(const Matrix& lhs, const Matrix& rhs);
	friend bool operator!=(const Matrix& lhs, const Matrix& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& mtx);
	friend std::istream& operator>>(std::istream& is, Matrix& mtx);
	friend bool iSymmetric(const Matrix& mtx);
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& mtx, double num);
Matrix operator/(const Matrix& mtx, double num);
