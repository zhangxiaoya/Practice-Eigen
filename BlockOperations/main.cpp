#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

// Using block operations 
//int main(int argc, char* argv[])
//{
//	MatrixXd m(4, 4);
//	m << 1, 2, 3, 4,
//		5, 6, 7, 8,
//		9, 10, 11, 12,
//		13, 14, 15, 16;
//
//	std::cout << "Block in the middle" << std::endl;
//	std::cout << m.block<2,2>(1,1) << std::endl;
//	for(auto i = 1; i <= 3; ++i)
//	{
//		std::cout << "Block size is " << i << " x " << i << std::endl;
//		std::cout << m.block(0, 0, i, i) << std::endl;
//	}
//	system("Pause");
//	return 0;
//}


int main(int argc, char* argv[])
{
	Array22f m;
	m << 1, 2,
		3, 4;

	Array44f a = Array44f::Constant(0.6);
	std::cout << "Here is the array a:" << std::endl << a<< std::endl;
	a.block<2, 2>(1, 1) = m;
	std::cout << "Here is now with m copied into its central 2x2 block:" << std::endl << a << std::endl;
	a.block(0, 0, 2, 3) = a.block(2, 1, 2, 3);
	std::cout << "Here is now a with bottom-right 2x3 block copied into top-left  2x2 block:" << std::endl << a << std::endl;
	system("Pause");
	return 0;
}
