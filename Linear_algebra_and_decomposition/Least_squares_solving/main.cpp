#include <iostream>
#include <Eigen/Dense>

int main(int argc, char* argv[])
{
	Eigen::MatrixXf A = Eigen::MatrixXf::Random(3, 2);
	std::cout << "Matrix A\n" << A << std::endl;
	Eigen::VectorXf b = Eigen::VectorXf::Random(3);
	std::cout <<  "Vector b\n" << b << std::endl;
	Eigen::VectorXf x = A.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(b);
	std::cout << "The least-squares solution is\n" << x << std::endl;
	system("Pause");
	return 0;
}
