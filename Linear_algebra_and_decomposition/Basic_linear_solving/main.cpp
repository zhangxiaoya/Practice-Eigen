#include <iostream>
#include <Eigen/Dense>

int main(int argc, char* argv[])
{
	Eigen::Matrix3f A;
	Eigen::Vector3f b;
	A << 1 , 2 , 3,
		4 , 5 , 6,
		7 , 8 , 10;
	b << 3, 3, 4;
	std::cout << "Here is the matrix A :" << std::endl << A << std::endl;
	std::cout << "Here is the vector b :" << std::endl << b << std::endl;

	// Eigen::Vector3f x = A.colPivHouseholderQr().solve(b);
	Eigen::ColPivHouseholderQR<Eigen::Matrix3f> dec(A);
	Eigen::Vector3f x = dec.solve(b);

	std::cout << "The sloution is :" << std::endl << x << std::endl;
	system("Pause");
	return 0;
}
