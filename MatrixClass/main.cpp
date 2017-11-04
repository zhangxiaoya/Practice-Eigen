#include <iostream>
#include <Eigen/Dense>

using Eigen::Matrix3d;
using Eigen::MatrixXd;
using Eigen::VectorXd;

int main(int argc, char** argv)
{
	// use comma initialization
//	Matrix3d m;
//	m << 1, 2, 3,
//		4, 5, 6,
//		7, 8, 9;
//	std::cout << "m =" << std::endl << m << std::endl;

	MatrixXd m(2, 5);
	m.resize(4, 3);
	std::cout << "Matrix size is " << m.rows() << " x " << m.cols() << std::endl;

	VectorXd v(2);
	v.resize(5);
	std::cout << "Vector size is " << v.size() << std::endl;
	std::cout << "As a matrix, vector size is " << v.rows() << " x " << v.cols() << std::endl;

	system("Pause");
	return 0;
}