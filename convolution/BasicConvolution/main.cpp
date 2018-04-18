#include <iostream>
#include <Eigen/Dense>

void MaxFilterBasic(Eigen::Matrix4i& A, int width, int height, int radius, int kernelSize)
{
	Eigen::MatrixXi extendA(width + 2 * radius, height + 2 * radius);
	extendA = Eigen::MatrixXi::Zero(width + 2 * radius, height + 2 * radius);
	extendA.block(radius, radius, height, width) = A;

	// 核处理
	for(int r = radius; r < radius + height; ++r)
	{
		for(int c = radius; c < radius + width; ++ c)
		{
			auto b = extendA.block(r-radius, c-radius, kernelSize,kernelSize);
			A(r - radius, c - radius) = b.maxCoeff();
		}
	}
}

int main(int argc, char* argv[])
{
	// 原始矩阵A
	Eigen::Matrix4i A;
	A << 1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16;
	std::cout << "Original Matrix A is\n" << A << std::endl;

	// 参数设置
	int width = 4;
	int height = 4;
	// 最大值滤波核
	int radius = 1;
	int kernelSize = 2 * radius + 1;
	// 最大值滤波
	MaxFilterBasic(A, width, height, radius, kernelSize);
	std::cout << "After max-value filter\n" << A << std::endl;

	system("Pause");
	return 0;
}
