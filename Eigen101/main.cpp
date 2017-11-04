#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

// example 1
//int main(int argc, char* argv[])
//{
//	MatrixXd m(2, 2);
//	m(0, 0) = 1;
//	m(0, 1) = 2.5;
//	m(1, 0) = -1;
//	m(1, 1) = m(0, 1) + m(1, 0);
//	std::cout << m << std::endl;
//	system("Pause");
//	return 0;
//}

// example 2 first part
int main(int argc, char* argv[])
{
	MatrixXd m = MatrixXd::Random(3, 3);
	m = (m + MatrixXd::Constant(3, 3, 1.2)) * 50;
	std::cout << "m = " << std::endl << m << std::endl;
	VectorXd v(3);
	v << 1, 2, 3;
	std::cout << "m * v = " << std::endl << m * v << std::endl;
	system("Pause");
	return 0;
}
