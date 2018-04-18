#include <iostream>
#include <Eigen/Dense>

int main(int argc, char* argv[])
{
	int width = 4;
	int height = 4;
	Eigen::MatrixXi A(width, height);
	A << 1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16;
	std::cout << "Original matrix a\n" << A << std::endl;

	int radius = 1;
	int kernelSize = 2 * radius + 1;

	Eigen::MatrixXi extendedA(width + 2 * radius, height + 2 * radius);
	extendedA = Eigen::MatrixXi::Zero(width + 2 * radius, height + 2 * radius);

	extendedA.block(radius, radius, height, width) = A;

	std::cout << extendedA << std::endl;

	for(int r = radius;r < radius + height; ++ r)
	{
		for(int c = radius; c < radius + width; ++ c)
		{
			auto b = extendedA.block(r - radius, c - radius, kernelSize, kernelSize);
			std::cout << "Block is\n" << b << std::endl;
			auto mean = b.sum() / (kernelSize * kernelSize * 1.0);
			std::cout << "Mean is " << mean << std::endl;;
			A(r - radius, c - radius) = mean;
		}
	}

	std::cout << "After Mean filter\n" << A << std::endl;
	system("Pause");
	return 0;
}
