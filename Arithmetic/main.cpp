#include <iostream>

#include <Eigen/Dense>

using namespace Eigen;

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