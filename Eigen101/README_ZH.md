# 开始使用Eigen

这个中文的Readme文件是不是原文翻译英文的readme，只是简单的总结在如何使用Eigen，这样回顾起来更快。

## 安装Eigen

在学习和使用的过程中，Eigen的安装非常简单，不需要编译，也不需要复杂的安装，更没有什么依赖库，只需要下载压缩文件包，解压到一个目录就行，使用的时候只需要包含对应的头文件就好了。Eigen是跨平台的，在任何平台的安装都是一样的。

下面是解压后Eigen的一个测试程序：

```
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen::MatrixXd;

int main()
{
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(0,1) =2.5;
    m(1,0) = -1;
    m(1,1) = m(0,0) + m(0,0);
    std::cout << m << std::endl;
}
```

上面的程序，首先创建了一个动态矩阵，矩阵的大小是2*2，每个矩阵的元素用圆括号获取，最后输出整个矩阵。

1. 在Windows上运行程序，比较简单，在Visual Studio 2015中创建一个空的工程，然后创建一个源文件，把上面的代码粘贴进去，为了保证在编译的时候，Visual Studio能找到Eigien的头文件和对应的实现，需要配置include目录，这种操作跟opencv一样，创建一个属性表，专门用来配置Eigen的位置。

2. 在Linux编译，这样一个文件的程序，可以直接使用g++命令编译，需要显式的给出头文件的地址，比如下面的命令：

```Shell
g++ -I /path/to/eigen/ my_program.cpp -o my_program 
```

最终的输出结果是：

```Shell
  3  -1
2.5 1.5
```

## Eigen库的基本说明

MatrixXd是Eigen库中最基本的数据类型之一，其中X表示任意维度，也就是说维度是用户自己指定的，d表示double类型。在Eigen的头文件中定义了很多这样的数据类型，以及这些类型对应的方法，Eigen所有的数据类型、类、以及方法都是定义在Eigen命名空间中，所以，在使用Eigen库的时候，只需要包含这个头文件，就可以使用Eigen。

## 矩阵和向量

在Eigen中，有两种基本的数据类型，矩阵和向量，每种类型都是动态的，也就是在运行的时候才能知道矩阵的尺寸或者向量尺寸，也就是MatrixXd中的大写的“X”，表示尺度是任意的。每种类型都提供了基本的初始化方法，比如常量初始化、随机量初始化。Eigen也提供了若干固定尺度的矩阵和向量。

- 带有“X”的向量和矩阵都是尺度动态变化的，其真正的尺度是在程序运行的时候才能确定的；
- “X”被数字替换的，表示尺度是在定义的时候就确定的，也就是在编译期间就确定了，下面是两个程序用来描述动态类型和静态类型。


1. 动态数据类型
```
#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
    MatrixXd m = MatrixXd::Random(3,3);
    m = (m + MatrixXd::Constant(3,3,1.2)) * 30;
    cout << "m = " << endl << m << endl;
    VectorXd v(3);
    v << 1, 2,3;
    cout << "m * v = " << endl << m * v << endl;
}
```

```
#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
    Matrix3d m = Matrix3d::Random();
    m = (m + Matrix3d::Constant(1.2)) * 50;
    cout << "m = " << endl << m <<endl;
    Vector3d v(1,2,3);
    cout << "m * v = " << endl << m * v << endl;
}
```