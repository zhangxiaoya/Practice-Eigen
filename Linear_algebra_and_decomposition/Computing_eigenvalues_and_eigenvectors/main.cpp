#include <iostream>
#include <Eigen/Dense>

int main(int argc, char* argv[])
{
	Eigen::Matrix2f A;
	A << 1, 2, 3, 4;
	std::cout << "Matrix A is :" << std::endl;
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix2f> eigenSoler(A);
	if (eigenSoler.info() != Eigen::Success) abort();
	std::cout << "Eigenvalues of A :\n" << eigenSoler.eigenvalues() << std::endl;
	std::cout << "Eigen Vector is \n" << eigenSoler.eigenvectors() << std::endl;
	system("Pause");
	return 0;
}
