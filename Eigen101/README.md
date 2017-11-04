# Getting started

This is a very short guide on how to get started with Eigen. It has a dual purpose. It serves as a minimal introduction to the Eigen library for people who want to start coding as soon as possible. You can also read this page as the first part of the Tutorial, which explains the library in more detail; in this case you will continue with The Matrix class.

## How to "install" Eigen?

In order to use Eigen, you just need to download and extract Eigen's source code (see the wiki for download instructions). In fact, the header files in the Eigen subdirectory are the only files required to compile programs using Eigen. The header files are the same for all platforms. It is not necessary to use CMake or install anything.

## A simple first program

Here is a rather simple program to get you started.

```C++
#include <iostream>
#include <Eigen/Dense>
using Eigen::MatrixXd;
int main()
{
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
}
```

We will explain the program after telling you how to compile it.

## Compiling and running your first program

There is no library to link to. The only thing that you need to keep in mind when compiling the above program is that the compiler must be able to find the Eigen header files. The directory in which you placed Eigen's source code must be in the include path. With GCC you use the -I option to achieve this, so you can compile the program with a command like this:

```Shell
g++ -I /path/to/eigen/ my_program.cpp -o my_program 
```

On Linux or Mac OS X, another option is to symlink or copy the Eigen folder into /usr/local/include/. This way, you can compile the program with:

```Shell
g++ my_program.cpp -o my_program 
```

When you run the program, it produces the following output:

```Shell
  3  -1
2.5 1.5
```

## Explanation of the first program

The Eigen header files define many types, but for simple applications it may be enough to use only the MatrixXd type. This represents a matrix of arbitrary size (hence the X in MatrixXd), in which every entry is a double (hence the d in MatrixXd). See the quick reference guide for an overview of the different types you can use to represent a matrix.

The Eigen/Dense header file defines all member functions for the MatrixXd type and related types (see also the table of header files). All classes and functions defined in this header file (and other Eigen header files) are in the Eigen namespace.

The first line of the main function declares a variable of type MatrixXd and specifies that it is a matrix with 2 rows and 2 columns (the entries are not initialized). The statement m(0,0) = 3 sets the entry in the top-left corner to 3. You need to use round parentheses to refer to entries in the matrix. As usual in computer science, the index of the first index is 0, as opposed to the convention in mathematics that the first index is 1.

The following three statements sets the other three entries. The final line outputs the matrix m to the standard output stream.

## Example 2: Matrices and vectors

Here is another example, which combines matrices with vectors. Concentrate on the left-hand program for now; we will talk about the right-hand program later.

Size set at run time:

```C++
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{
  MatrixXd m = MatrixXd::Random(3,3);
  m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
  cout << "m =" << endl << m << endl;
  VectorXd v(3);
  v << 1, 2, 3;
  cout << "m * v =" << endl << m * v << endl;
}
```

Size set at compile time:

```C++
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{
  Matrix3d m = Matrix3d::Random();
  m = (m + Matrix3d::Constant(1.2)) * 50;
  cout << "m =" << endl << m << endl;
  Vector3d v(1,2,3);

  cout << "m * v =" << endl << m * v << endl;
}
```

The output is as follows:

```Shell
m =
  94 89.8 43.5
49.4  101 86.8
88.3 29.8 37.8
m * v =
404
512
261
```

## Explanation of the second example

The second example starts by declaring a 3-by-3 matrix m which is initialized using the Random() method with random values between -1 and 1. The next line applies a linear mapping such that the values are between 10 and 110. The function call MatrixXd::Constant(3,3,1.2) returns a 3-by-3 matrix expression having all coefficients equal to 1.2. The rest is standard arithmetics.

The next line of the main function introduces a new type: VectorXd. This represents a (column) vector of arbitrary size. Here, the vector v is created to contain 3 coefficients which are left unitialized. The one but last line uses the so-called comma-initializer, explained in Advanced initialization, to set all coefficients of the vector v to be as follows:

$$ \[ v = \begin{bmatrix} 1 \\ 2 \\ 3 \end{bmatrix}. \] $$

The final line of the program multiplies the matrix m with the vector v and outputs the result.

Now look back at the second example program. We presented two versions of it. In the version in the left column, the matrix is of type MatrixXd which represents matrices of arbitrary size. The version in the right column is similar, except that the matrix is of type Matrix3d, which represents matrices of a fixed size (here 3-by-3). Because the type already encodes the size of the matrix, it is not necessary to specify the size in the constructor; compare MatrixXd m(3,3) with Matrix3d m. Similarly, we have VectorXd on the left (arbitrary size) versus Vector3d on the right (fixed size). Note that here the coefficients of vector v are directly set in the constructor, though the same syntax of the left example could be used too.

The use of fixed-size matrices and vectors has two advantages. The compiler emits better (faster) code because it knows the size of the matrices and vectors. Specifying the size in the type also allows for more rigorous checking at compile-time. For instance, the compiler will complain if you try to multiply a Matrix4d (a 4-by-4 matrix) with a Vector3d (a vector of size 3). However, the use of many types increases compilation time and the size of the executable. The size of the matrix may also not be known at compile-time. A rule of thumb is to use fixed-size matrices for size 4-by-4 and smaller.

## Where to go from here?

It's worth taking the time to read the long tutorial.

However if you think you don't need it, you can directly use the classes documentation and our Quick reference guide.

Next: The Matrix class