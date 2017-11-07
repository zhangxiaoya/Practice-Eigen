#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

//Accessing values inside an Array
//int main(int argc, char* argv[])
//{
//	ArrayXXd a(2, 2);
//	a(0, 0) = 1.0;
//	a(0, 1) = 2.0;
//	a(1, 0) = 3.0;
//	a(1, 1) = a(0,1) + a(1,0);
//
//	std::cout << "a = : \n" << a << std::endl << std::endl;
//
//	a << 1.0, 2.0,
//		3.0, 4.0;
//
//	std::cout << a <<std::endl;
//
//	system("Pause");
//	return 0;
//}

// Addition and subtraction
//int main(int argc, char* argv[])
//{
//	ArrayXXf a(3, 3);
//	ArrayXXf b(3, 3);
//	a << 1, 2, 3,
//		4, 5, 6,
//		7, 8, 9;
//
//	b << 1, 2, 3,
//		1, 2, 3,
//		1, 2, 3;
//	std::cout << "a = \n" << a <<std::endl;
//	std::cout <<  "b = \n" << b <<std::endl;
//	std::cout << "a + b = \n" << a + b << std::endl;
//	std::cout << "a - 2 = \n" << a - 2 << std::endl;
//
//	system("Pause");
//	return 0;
//}

// Array multiplication
//int main(int argc, char* argv[])
//{
//	ArrayXXf a(2, 2);
//	ArrayXXf b(2, 2);
//
//	a << 1, 2,
//		3, 4;
//	b << 5, 6,
//		7, 8;
//
//	std::cout << "a = \n" << a << std::endl;
//	std::cout << "b = \n" << b << std::endl;
//
//	std::cout << "a * b = \n" << a * b << std::endl;
//
//	system("Pause");
//	return 0;
//}

// Other coefficient-wise operations
//int main(int argc, char* argv[])
//{
//	ArrayXf a = ArrayXf::Random(5);
//	a *= 2;
//	std::cout <<  "a = \n" << a <<std::endl;
//	std::cout << "a.abs() = \n" << a.abs() << std::endl;
//	std::cout <<  "a.abs().sqrt() = \n" << a.abs().sqrt() << std::endl;
//	std::cout << "a.min(a.abs().sqrt()) = \n" << a.min(a.abs().sqrt())<< std::endl;
//	system("Pause");
//	return 0;
//}

// Converting between array and matrix expressions
int main(int argc, char* argv[])
{
	MatrixXf m(2, 2);
	MatrixXf n(2, 2);
	MatrixXf result(2, 2);

	m << 1, 2,
		3, 4;
	n << 5, 6,
		7, 8;

	result = m * n;
	std::cout << "--Matrix a * b : --\n" << result<< std::endl;
	result = m.array()  * n.array();
	std::cout << "-- Array m*n: --" << std::endl << result << std::endl << std::endl;
	result = m.cwiseProduct(n);
	std::cout << "-- With cwiseProduct: --" << std::endl << result << std::endl << std::endl;
	result = m.array() + 4;
	std::cout << "-- Array m + 4: --" << std::endl << result << std::endl << std::endl; std::cout << "--Array m * n : --\n" << result;
	system("Pause");
	return 0;
}
