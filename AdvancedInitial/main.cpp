#include <iostream>
#include <Eigen/Dense>

#include <Eigen/Dense>

using namespace Eigen;

// The comma initializer
//int main(int argc, char* argv[])
//{
//	MatrixXf m(3,3);
//	m << 1, 2, 3,
//		4, 5, 6,
//		7, 8, 9;
//	std::cout << m<< std::endl;
//
//	RowVectorXf v1(3);
//	v1 << 1, 2, 3;
//	std::cout << "Vector v1 = " << v1 <<std::endl;
//	RowVectorXf v2(4);
//	v2 << 4, 5, 6, 7;
//	std::cout << "Vector v2 = " << v2 << std::endl;
//
//	RowVectorXf joined(7);
//	joined << v1, v2;
//	std::cout << "Joined = " << joined << std::endl;
//
//	Matrix2f matA(2, 2);
//	matA << 1, 2,
//		3, 4;
//	MatrixXf matB(4, 4);
//	matB << matA, matA / 10, matA / 10, matA;
//	std::cout << "Mat joined = \n" << matB << std::endl;
//
//	Matrix3f a;
//	a.row(0) << 1, 2, 3;
//	a.block(1, 0, 2, 2) << 4, 5, 7, 8;
//	a.col(2).tail(2) << 6, 9;
//	std::cout << "a = \n" << a << std::endl;
//	system("Pause");
//	return 0;
//}

// Special matrices and arrays
int main(int argc, char* argv[])
{
	std::cout << "A fixed-size array :\n";
	Array33f a1 = Array33f::Zero();
	std::cout <<  a1<<std::endl;

	std::cout << "A one-dimensional dynamic-size array:\n";
	ArrayXf a2 = ArrayXf::Zero(3);
	std::cout << a2<<std::endl;

	std::cout << "A two-dimensional dynamic-size array:\n";
	ArrayXXf a3 = ArrayXXf::Zero(3,4);
	std::cout << a3<<std::endl;

	system("Pause");
	return 0;
}
