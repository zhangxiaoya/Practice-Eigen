#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main(int argc, char* argv[])
{
	MatrixXd m(2, 2);
	m(0, 0) = 1;
	m(0, 1) = 2.5;
	m(1, 0) = -1;
	m(1, 1) = m(0, 1) + m(1, 0);
	std::cout << m << std::endl;
	system("Pause");
	return 0;
}
