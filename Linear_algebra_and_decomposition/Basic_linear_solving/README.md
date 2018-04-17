#  利用矩阵分解求解线性系统

这整个目录中用来练习线性系统求解和矩阵分级，比如LU分解，QR分解，SVD分解，以及特征分解等操作。矩阵分解同样能用来求解线性系统，一个典型的线性系统如下面的公式描述：

$$ Ax=b $$

对于这样的线性系统，根据对速度和精度的要求，以及矩阵A的情况，选择不同的矩阵分解方法来求解。

比如下面这个利用QR分解求解线性方程：
```
#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
   Matrix3f A;
   Vector3f b;
   A << 1,2,3,  4,5,6,  7,8,10;
   b << 3, 3, 4;
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "Here is the vector b:\n" << b << endl;
   Vector3f x = A.colPivHouseholderQr().solve(b);
   cout << "The solution is:\n" << x << endl;
```

关于矩阵分解的几个类的性能及精度如下表所示：
 Decomposition | Method | Requirements on the matrix | Speed (small-to-medium) | Speed (large)	|Accuracy
 - | - | - | - | - | - 
 - PartialPivLU	| partialPivLu()	| Invertible |	++ |	++ |	+
FullPivLU	| fullPivLu()	| None|	-|	- | -	| +++
HouseholderQR|	householderQr()	None|	++	| ++ |	+
ColPivHouseholderQR	 | colPivHouseholderQr() |	None	| +	| - |	+++
FullPivHouseholderQR |	fullPivHouseholderQr() |	None |	-	| - | - |	+++
CompleteOrthogonalDecomposition |	completeOrthogonalDecomposition()|	None |	+	| - |	+++
LLT	| llt() |	Positive definite |	+++ |	+++ |	+
LDLT	| ldlt() |	Positive or negative semidefinite	| +++ |	+	| ++
BDCSVD	| bdcSvd()|	None|	-|	-|	+++
JacobiSVD	|jacobiSvd()|	None|	-	| -- |	+++

所有的矩阵分解都有一个solve函数，用来求解上面的线性系统问题。
如果矩阵是正定的，可以使用LLT或者LDLT来求解。
