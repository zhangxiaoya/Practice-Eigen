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

	double M_PI = 3.14;
	ArrayXXf table(10, 4);
	table.col(0) = ArrayXf::LinSpaced(10, 0, 90);
	table.col(1) = M_PI / 180 * table.col(0);
	table.col(2) = table.col(1).sin();
	table.col(3) = table.col(1).cos();
	std::cout << " Degress Radians Sine Coise\n";
	std::cout << table<< std::endl;

	const int size = 6;
	MatrixXd mat1(size, size);
	mat1.topLeftCorner(size / 2, size / 2) = MatrixXd::Zero(size / 2, size / 2);
	mat1.topRightCorner(size / 2, size / 2) = MatrixXd::Identity(size / 2, size / 2);
	mat1.bottomLeftCorner(size / 2, size / 2) = MatrixXd::Identity(size / 2, size / 2);
	mat1.bottomRightCorner(size / 2, size / 2) = MatrixXd::Zero(size / 2, size / 2);

	std::cout << mat1 << std::endl;
	std::cout << std::endl;

	MatrixXd mat2(size, size);
	mat2.topLeftCorner(size / 2, size / 2).setZero();
	mat2.topRightCorner(size / 2, size / 2).setIdentity();
	mat2.bottomLeftCorner(size / 2, size / 2).setIdentity();
	mat2.bottomRightCorner(size / 2, size / 2).setZero();
	std::cout << mat2<< std::endl<<std::endl;

	MatrixXd mat3(size, size);
	mat3 << MatrixXd::Zero(size / 2, size / 2), MatrixXd::Identity(size / 2, size / 2), MatrixXd::Identity(size / 2, size / 2), MatrixXd::Zero(size / 2, size / 2);
	std::cout << mat3<< std::endl;

	system("Pause");
	return 0;
}
