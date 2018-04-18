#include <iostream>
#include <Eigen/Dense>

int main(int argc, char* argv[])
{
	Eigen::Matrix2f A, b;
	Eigen::LLT<Eigen::Matrix2f> llt;

	A << 2, -1, -1, 3;
	b << 1, 2, 3, 1;
	std::cout << "Matrix A\n" << A << std::endl;
	std::cout << "Right side b\n" << b << std::endl;
	std::cout << "Compute LLT Decomposition" << std::endl;
	llt.compute(A);
	std::cout << "The solution is " << llt.solve(b) << std::endl;
	A(1, 1)++;
	std::cout << "Now Matrix A is\n" << A << std::endl;
	std::cout << "Computing LLT Decomposition Again\n";
	llt.compute(A);
	std::cout << "The solution is\n" << llt.solve(b) << std::endl;
	system("Pause");
	return 0;
}
