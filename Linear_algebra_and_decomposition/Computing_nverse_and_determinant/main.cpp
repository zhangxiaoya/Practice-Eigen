#include <iostream>
#include <Eigen/Dense>

int main(int argc, char* argv[])
{
	Eigen::Matrix3f A;
	A << 1 , 2 , 1 ,
		2 , 1 , 0 ,
		-1 , 1 , 2;
	std::cout << "Matrix A \n" << A << std::endl;
	std::cout << "Inverse of A\n" << A.inverse() << std::endl;
	std::cout << "Determinant of A " << A.determinant() << std::endl;

	system("Pause");
	return 0;
}
