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

//int main(int argc, char* argv[])
//{
//	Array22f m;
//	m << 1, 2,
//		3, 4;
//
//	Array44f a = Array44f::Constant(0.6);
//	std::cout << "Here is the array a:" << std::endl << a<< std::endl;
//	a.block<2, 2>(1, 1) = m;
//	std::cout << "Here is now with m copied into its central 2x2 block:" << std::endl << a << std::endl;
//	a.block(0, 0, 2, 3) = a.block(2, 1, 2, 3);
//	std::cout << "Here is now a with bottom-right 2x3 block copied into top-left  2x2 block:" << std::endl << a << std::endl;
//	system("Pause");
//	return 0;
//}

// Columns and rows
//int main(int argc, char* argv[])
//{
//	MatrixXf m(3, 3);
//	m << 1, 2, 3,
//		4, 5, 6,
//		7, 8, 9;
//	std::cout << "Here is matrix m :" << std::endl << m << std::endl;
//	std::cout << "2nd Row : " << m.row(1) << std::endl;
//	m.col(2) += 3 * m.col(0);
//	std::cout << "After adding 3 times the first column into the third column, the matrix m is :\n"<< m << std::endl;
//
//	system("Pause");
//	return 0;
//}

//// Corner-related operations
//int main(int argc, char* argv[])
//{
//	MatrixXf m(4, 4);
//	m << 1, 2, 3, 4,
//		5, 6, 7, 8,
//		9, 10, 11, 12,
//		13, 14, 15, 16;
//	std::cout << "m.leftCols(2) = " << std::endl << m.leftCols(2) << std::endl;
//
//	std::cout << "m.bottomRow(2) = " << std::endl << m.bottomRows(2) << std::endl;
//	m.topLeftCorner(1, 3) = m.bottomRightCorner(3, 1).transpose();
//	std::cout << "After Assignement m = " << std::endl << m << std::endl;
//
//	system("Pause");
//	return 0;
//}

// Block operations for vectors
int main(int argc, char* argv[])
{
	ArrayXf a(6);
	a << 1, 2, 3, 4, 5, 6;
	std::cout << "a.head(3) = " << std::endl << a.head(3) << std::endl << std::endl;
	std::cout << "a.tail(3) = " << std::endl << a.tail(3) << std::endl << std::endl;

	a.segment(1, 4) *= 4;
	std::cout << "after a.segment(1,4) *= 4, a = " << a << std::endl << std::endl;
	system("Pause");
	return 0; 
}
