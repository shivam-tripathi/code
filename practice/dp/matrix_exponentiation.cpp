// Matrix exponentiation

#include <iostream>
using namespace std;

template<class T>
class Matrix{
public:
	int m, n;
	T* data;
	Matrix(int m, int n);
	Matrix(const Matrix<T> &matrix);

	const Matrix<T> &operator=(const Matrix<T> &matrix);
	const Matrix<T> operator*(const Matrix<T> &matrix);
	const Matrix<T> operator^(int p);

	~Matrix();
};

template<class T>
Matrix<T> :: Matrix(int m, int n){
	this->m = m;
	this->n = n;
	data = new int[m*n];
}  

template<class T>
Matrix<T> :: Matrix(const Matrix<T> &matrix){
	this->m = matrix.m;
	this->n = matrix.n;
	for(int i=0; i<(m*n); i++){
		
	}
}