# 矩阵类

在Eigen中，所有的数据类型的基类是Matrix类，向量的基类也是Matrix类，只不过是行数或者列数限定为1.

矩阵类的模板定义如下所示：


``` C++
Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
```

1. Scalar表示数据存储的类型，比如是float类型还是double类型
2. 后面的两个参数表示矩阵类型的行数和列数

比如定义一个4*4的浮点数矩阵类型。

```C++
typedef Matrix<float, 4, 4> Matrix4f;
```

向量是一个特殊的矩阵，只有一行或者一列，通常情况下，表示的列向量，只有一列，定义方式如下：

```C++
typedef Matrix<float, 3, 1> Vector3f;
```

行向量的定义会在类型前添加“Row”，比如一个长度为2的行向量的定义如下：

```C++
typedef Matrix<int, 1, 2> RowVector2i;
```

## 动态尺度
Eigen并没有显示矩阵的维度，矩阵的两个维度可以是在运行时确定的，当矩阵的两个维度是动态的类型的时，类型被称作动态类型；当矩阵的两个尺度都是固定时，being称作固定尺度。

比如下面两个类型的定义：

```C++
typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
```

```C++
typ edef Matrix<int, Dynamic, 1> VectorXi;
```

也可以定义一个维度固定的矩阵类型：

```C++
Matrix<float, 3, Dynamic>
```

## 初始化

对于动态类型矩阵和向量，类型实例初始化的时候需要显示指定尺度， 比如：

```C++
MatrixXf a(10,15);
VectorXf b(30);
```

对于静态类型，不需要显示指定尺寸，不过给定尺寸也没有用， 比如：

```C++
Matrix3f a;
MatrixXf b;
```

也可以给定静态类型指定尺度：

```C++
Matrix3f a(3,3);
```

常见的两种初始化矩阵和向量的方式，一种就是通过圆括号下标进行初始化，另外一种是初始化方式通过逗号表达式初始化。

第一种：

```C++
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
int main()
{
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << "Here is the matrix m:\n" << m << std::endl;
  VectorXd v(2);
  v(0) = 4;
  v(1) = v(0) - 1;
  std::cout << "Here is the vector v:\n" << v << std::endl;
}
```

第二种：

```C++
Matrix3f m;
m << 1, 2, 3,
     4, 5, 6,
     7, 8, 9;
std::cout << m;
```

## Resize

动态类型的矩阵可以Resize，静态类型不能Resize，会触发一个assertion错误

```C++
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
int main()
{
  MatrixXd m(2,5);
  m.resize(4,3);
  std::cout << "The matrix m is of size "
            << m.rows() << "x" << m.cols() << std::endl;
  std::cout << "It has " << m.size() << " coefficients" << std::endl;
  VectorXd v(2);
  v.resize(5);
  std::cout << "The vector v is of size " << v.size() << std::endl;
  std::cout << "As a matrix, v is of size "
            << v.rows() << "x" << v.cols() << std::endl;
}