#include <iostream>
#include <Eigen/Dense>

int main(int argc, char* argv[])
{
	Eigen::Matrix3f A;
	A << 1, 2, 3,
		4, 5, 6,
		7, 8, 10;
	Eigen::Vector3f b;
	b << 3, 3, 4;

	std::cout << "Matrix A :\n" << A << std::endl;
	std::cout << "Vector b :\n" << b << std::endl;
	Eigen::Vector3f x = A.ldlt().solve(b);
	std::cout << "Result x :\n" << x << std::endl;

	double relative_error = (A*x - b).norm() / b.norm();
	std::cout << "Relative Error is " << relative_error << std::endl;
	system("Pause");
	return 0;
}
