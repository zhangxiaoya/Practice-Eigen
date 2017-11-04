#include <iostream>
#include <Eigen/Dense>

using Eigen::Matrix3d;

int main(int argc, char** argv)
{
	// use comma initialization
	Matrix3d m;
	m << 1, 2, 3,
		4, 5, 6,
		7, 8, 9;
	std::cout << "m =" << std::endl << m << std::endl;

	system("Pause");
	return 0;
}