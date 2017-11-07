#include <iostream>

#include <Eigen/Dense>
#include <iomanip>

using namespace Eigen;

//Addition and subtraction
//int main(int argc, char** argv)
//{
//	Matrix2d a;
//	a << 1 , 2 ,
//		3 , 4;
//	MatrixXd b(2, 2);
//	b << 2 , 3 ,
//		1 , 4;
//
//	std::cout << "a = " << std::endl << a << std::endl;
//	std::cout << " b = " << std::endl << b << std::endl;
//
//	std::cout << "a + b = " << std::endl << a + b << std::endl;
//	std::cout << "a - b =" << std::endl << a - b << std::endl;
//	std::cout << "Doing a += b;" << std::endl;
//	a += b;
//	std::cout << "Now a = " << std::endl << a << std::endl;
//
//	Vector3d v(1, 2, 3);
//	Vector3d w(1, 0, 0);
//	std::cout << " -v + w -v = " << std::endl << -v + w - v << std::endl;
//
//	system("Pause");
//	return 0;
//}

// Scalar multiplication and division
//int main(int argc, char** argv)
//{
//	Matrix2d a(2, 2);
//	a << 1, 2,
//		3, 4;
//	std::cout << "a = " << std::endl << a << std::endl;
//
//	Vector3d v(1, 2, 3);
//	std::cout << "v = " << std::endl << v << std::endl;
//
//	std::cout << "a * 2.5 = " << std::endl << a * 2.5 << std::endl;
//	std::cout << " 0.1 * v = " << std::endl << 0.1 * v << std::endl;
//	std::cout << "Doing v *= 2;" << std::endl;
//	v *= 2;
//	std::cout << "Now v = " << std::endl << v << std::endl;
//	system("Pause");
//	return 0;
//}

// Scalar multiplication and division
//int main(int argc, char* argv[])
//{
//	MatrixXd a = MatrixXd::Random(2, 2);
//	std::cout << "Here is the matrix a: \n" << a<<std::endl;
//	std::cout << "Here is the matrix a^T: \n" << a.transpose()<<std::endl;
//	std::cout << "Here is the conjugate of a: \n" << a.conjugate()<<std::endl;
//	std::cout << "Here is the matrix a^* \n" << a.adjoint() << std::endl;
//
//	system("Pause");
//	return 0;
//}

//int main(int argc, char* argv[])
//{
//	Matrix2i a;
//	a << 1, 2,
//		3, 4;
//	std::cout << "Here is matrix a: \n" << a<<std::endl;
//	// a = a.transpose(); // DO NOT DO IT , ASSERT ERROR
//	std::cout << "and the result of the aliasing effect:\n" << a << std::endl;
//
//	a.transposeInPlace();
//	std::cout << "after being transpose in pleace:\n" << a<<std::endl;
//	system("Pause");
//	return 0;
//}

// Matrix-matrix and matrix-vector multiplication
//int main(int argc, char* argv[])
//{
//	Matrix2d a;
//	a << 1, 2,
//		3, 4;
//	Vector2d u(-1, 1), v(2, 0);
//	std::cout << "Here is mat * mat \n" << a * a << std::endl;
//	std::cout << "Here is mat * u \n" << a * u<<std::endl;
//	std::cout << "Here is u^T * mat \n" << u.transpose() * a << std::endl;
//	std::cout << "Here is u^T * v \n" << u.transpose() * v<<std::endl;
//	std::cout << "Here is u * v^T \n " << u * v.transpose()<<std::endl;
//	std::cout << "Let's mat multiply itself" << std::endl;
//	a = a * a;
//	std::cout << "Now a is \n" << a <<std::endl;
//	system("Pause");
//	return 0;
//}

// Dot product and cross product
//int main(int argc, char* argv[])
//{
//	Vector3d v(1, 2, 3);
//	Vector3d w(0, 1, 2);
//	std::cout << "Dot product: " << w.dot(v) << std::endl;
//	double dp = v.adjoint() * w;
//	std::cout << "Dot product via a matrix product: " << dp << std::endl;
//	std::cout << "Cross product:\n" << v.cross(w) << std::endl;
//	system("Pause");
//	return 0;
//}

// Basic arithmetic reduction operations
int main(int argc, char* argv[])
{
	Matrix2d mat;
	mat << 1, 2,
		3, 4;
	std::cout << "Here is mat.sum() : " << mat.sum()<<std::endl;
	std::cout << "Here is mat.prod() : " << mat.prod()<<std::endl;
	std::cout << "Here is mat.mean() : " << mat.mean() << std::endl;
	std::cout << "Here is mat.minCoeff() : " << mat.minCoeff() << std::endl;
	std::cout << "Here is mat.maxCoeff() : " << mat.maxCoeff() << std::endl;
	std::cout << "Here is mat.trace() : " << mat.trace() << std::endl;
	system("Pause");
	return 0;
}
