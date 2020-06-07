#include"Matrix.h"

Matrix::Matrix(size_t rows, size_t cols)
	: m_rows(rows)
	, m_cols(cols)
{
	m_mat = initMat(m_rows, m_cols);
}

Matrix::Matrix(const Matrix& other)
{
	copy(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}

Matrix::~Matrix()
{
	clear();
}

int** Matrix::initMat(size_t rows, size_t cols)
{
	int** res = new int* [rows];
	for (size_t i = 0; i < rows; i++) {
		res[i] = new int[cols];
		for (size_t j = 0; j < cols; j++)
			res[i][j] = 0;
	}
	return res;
}

std::istream& operator>>(std::istream& in, Matrix& obj)
{
	for (size_t i = 0; i < obj.m_rows; i++)
		for (size_t j = 0; j < obj.m_cols; j++)
			in >> obj[i][j];
	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& obj)
{
	for (size_t i = 0; i < obj.m_rows; i++) {
		for (size_t j = 0; j < obj.m_cols; j++)
			out << obj[i][j] << " ";
		out << std::endl;
	}
	return out;
}

void Matrix::clearMatrix()
{
	for (size_t i = 0; i < m_rows; i++)
		delete[] m_mat[i];
	delete[] m_mat;
	m_mat = nullptr;
}

void Matrix::copy(const Matrix& other)
{
	this->m_rows = other.m_rows;
	this->m_cols = other.m_cols;
	m_mat = initMat(m_rows, m_cols);
	for (size_t i = 0; i < m_rows; i++) {
		for (size_t j = 0; j < m_cols; j++) {
			m_mat[i][j] = other.m_mat[i][j];
		}
	}
}

void Matrix::clear()
{
	clearMatrix();
}
