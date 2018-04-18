#include <iostream>
#include <Eigen/Dense>

int main(int argc, char* argv[])
{
	Eigen::Matrix3f A;
	A << 1, 2, 5,
		2, 1, 4,
		3, 0, 3;
	std::cout << "Matrix A\n" << A << std::endl;

	Eigen::FullPivLU<Eigen::Matrix3f> lu_decomp;
	lu_decomp.compute(A);
	std::cout << "The rank of A is\n" << lu_decomp.rank() << std::endl;
	std::cout << "Null-Space \n" <<  lu_decomp.kernel() << std::endl;
	std::cout << "Image-space \n" << lu_decomp.image(A) << std::endl;
	system("Pause");
	return 0;
}
