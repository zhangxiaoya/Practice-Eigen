# 使用Eigen进行矩阵分解和求解线性问题

使用Eigen解决矩阵分解问题，顺便解决线性方程问题。

$$ Ax=b $$

Eigen提供了若干进行矩阵分解的类，如下表所示：

 | Decomposition | Method | Requirements on the matrix | Speed (small-to-medium) | Speed (large)	|Accuracy |
 | - | - | - | - | - | - |
PartialPivLU	| partialPivLu()	| Invertible |	++ |	++ |	+
FullPivLU	| fullPivLu()	| None|	-|	- | -	| +++
HouseholderQR|	householderQr()	None|	++	| ++ |	+
ColPivHouseholderQR	 | colPivHouseholderQr() |	None	| +	| - |	+++
FullPivHouseholderQR |	fullPivHouseholderQr() |	None |	-	| - | - |	+++
CompleteOrthogonalDecomposition |	completeOrthogonalDecomposition()|	None |	+	| - |	+++
LLT	| llt() |	Positive definite |	+++ |	+++ |	+
LDLT	| ldlt() |	Positive or negative semidefinite	| +++ |	+	| ++
BDCSVD	| bdcSvd()|	None|	-|	-|	+++
JacobiSVD	|jacobiSvd()|	None|	-	| -- |	+++

比如有一个3*3的矩阵A，一个3-维的列向量b。定义如下：
```
Eigen::Matrix3f A;
	Eigen::Vector3f b;
	A << 1 , 2 , 5 ,
		2 , 1 , 4 ,
		3 , 0 , 3;
	b << 1 , 2 , 3;
```
在例程中，有两种方式使用Eigen进行矩阵分解。
第一种，直接调用分解对象，使用默认的构造函数，隐式构造，然后分解或者求解，比如下面的这段代码：
```
Eigen::LLT<Eigen::Matrix3f> llt = A.llt();
```
使用默认的构造函数，隐式的创建一个矩阵分解对象llt。
然后可以用矩阵分解对象求解线性方程：
```
Eigen::Vector3f x = llt.solve(b);
```

第二种，使用显示的定义方式：
```
Eigen::Matrix2f A, b;
Eigen::LLT<Eigen::Matrix2f> llt;

A << 2, -1, -1, 3;
b << 1, 2, 3, 1;
```
这里创建了两个矩阵和一个LLT分解对象。使用的时候如下所示：
```
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
```

## 关于矩阵的逆和行列式

求解矩阵的逆和行列式是在线性代数中很基础的操作，但是在具体使用的时候不常计算矩阵的逆和行列式，常被solve()操作取代，用求解行列不为0的方式判断矩阵是否可逆并不是一个很好的方式。但是对于小的矩阵，这两个操作可以直接使用。

一些矩阵分解类回提供求解行列式和逆矩阵的方法，每个矩阵也提供求解行列式和逆矩阵的函数。对于小的矩阵，建议直接使用矩阵直接提供的函数进行操作，避免使用矩阵分解的类，还需要进行分解。
```
 Matrix3f A;
   A << 1, 2, 1,
        2, 1, 0,
        -1, 1, 2;
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "The determinant of A is " << A.determinant() << endl;
   cout << "The inverse of A is:\n" << A.inverse() << endl;
```

## 计算特征值与特征向量
这时候需要一个特征分解的类，比如判断一个矩阵是否是共轭的，可以使用SelfAdjointEigenSolver，对于一般的矩阵可以使用 EigenSolver or ComplexEigenSolver。
```
 Matrix2f A;
   A << 1, 2, 2, 3;
   cout << "Here is the matrix A:\n" << A << endl;
   SelfAdjointEigenSolver<Matrix2f> eigensolver(A);
   if (eigensolver.info() != Success) abort();
   cout << "The eigenvalues of A are:\n" << eigensolver.eigenvalues() << endl;
   cout << "Here's a matrix whose columns are eigenvectors of A \n"
        << "corresponding to these eigenvalues:\n"
        << eigensolver.eigenvectors() << endl;
```

## 矩阵分解还可以求解最小二乘法
使用奇异值分解求解最小二乘法，Eigen提供了两个类，一个是BDCSVD，针对的是大的矩阵，另一个是JacobiSVD，针对的是小的矩阵。
比如下面的例子：
```
   MatrixXf A = MatrixXf::Random(3, 2);
   cout << "Here is the matrix A:\n" << A << endl;
   VectorXf b = VectorXf::Random(3);
   cout << "Here is the right hand side b:\n" << b << endl;
   cout << "The least-squares solution is:\n"
        << A.bdcSvd(ComputeThinU | ComputeThinV).solve(b) << endl;
```