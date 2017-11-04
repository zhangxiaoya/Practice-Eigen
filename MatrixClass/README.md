# The Matrix class

[Dense matrix and array manipulation](http://eigen.tuxfamily.org/dox/group__DenseMatrixManipulation__chapter.html)

In Eigen, all matrices and vectors are objects of the Matrix template class. Vectors are just a special case of matrices, with either 1 row or 1 column.

## The first three template parameters of Matrix

The Matrix class takes six template parameters, but for now it's enough to learn about the first three first parameters. The three remaining parameters have default values, which for now we will leave untouched, and which we discuss below.

The three mandatory template parameters of Matrix are:

``` C++
Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
```

1. Scalar is the scalar type, i.e. the type of the coefficients. That is, if you want a matrix of floats, choose float here. See Scalar types for a list of all supported scalar types and for how to extend support to new types.

1. RowsAtCompileTime and ColsAtCompileTime are the number of rows and columns of the matrix as known at compile time (see below for what to do if the number is not known at compile time).

We offer a lot of convenience typedefs to cover the usual cases. For example, Matrix4f is a 4x4 matrix of floats. Here is how it is defined by Eigen:

```C++
typedef Matrix<float, 4, 4> Matrix4f;
```

We discuss below these convenience typedefs.

## Vectors

As mentioned above, in Eigen, vectors are just a special case of matrices, with either 1 row or 1 column. The case where they have 1 column is the most common; such vectors are called column-vectors, often abbreviated as just vectors. In the other case where they have 1 row, they are called row-vectors.

For example, the convenience typedef Vector3f is a (column) vector of 3 floats. It is defined as follows by Eigen:

```C++
typedef Matrix<float, 3, 1> Vector3f;
```

We also offer convenience typedefs for row-vectors, for example:

```C++
typedef Matrix<int, 1, 2> RowVector2i;
```

## The special value Dynamic

Of course, Eigen is not limited to matrices whose dimensions are known at compile time. The RowsAtCompileTime and ColsAtCompileTime template parameters can take the special value Dynamic which indicates that the size is unknown at compile time, so must be handled as a run-time variable. In Eigen terminology, such a size is referred to as a dynamic size; while a size that is known at compile time is called a fixed size. For example, the convenience typedef MatrixXd, meaning a matrix of doubles with dynamic size, is defined as follows:

```C++
typedef Matrix<double, Dynamic, Dynamic> MatrixXd;
```

And similarly, we define a self-explanatory typedef VectorXi as follows:

```C++
typedef Matrix<int, Dynamic, 1> VectorXi;
```

You can perfectly have e.g. a fixed number of rows with a dynamic number of columns, as in:

```C++
Matrix<float, 3, Dynamic>
```

## Constructors

A default constructor is always available, never performs any dynamic memory allocation, and never initializes the matrix coefficients. You can do:

```C++
Matrix3f a;
MatrixXf b;
```

Here,

- a is a 3-by-3 matrix, with a plain float[9] array of uninitialized coefficients,
- b is a dynamic-size matrix whose size is currently 0-by-0, and whose array of coefficients hasn't yet been allocated at all.

Constructors taking sizes are also available. For matrices, the number of rows is always passed first. For vectors, just pass the vector size. They allocate the array of coefficients with the given size, but don't initialize the coefficients themselves:

```C++
MatrixXf a(10,15);
VectorXf b(30);
```

Here,

- a is a 10x15 dynamic-size matrix, with allocated but currently uninitialized coefficients.
- b is a dynamic-size vector of size 30, with allocated but currently uninitialized coefficients.

In order to offer a uniform API across fixed-size and dynamic-size matrices, it is legal to use these constructors on fixed-size matrices, even if passing the sizes is useless in this case. So this is legal:

```C++
Matrix3f a(3,3);
```

and is a no-operation.

Finally, we also offer some constructors to initialize the coefficients of small fixed-size vectors up to size 4:

```C++
Vector2d a(5.0, 6.0);
Vector3d b(5.0, 6.0, 7.0);
Vector4d c(5.0, 6.0, 7.0, 8.0);
```

## Coefficient accessors

The primary coefficient accessors and mutators in Eigen are the overloaded parenthesis operators. For matrices, the row index is always passed first. For vectors, just pass one index. The numbering starts at 0. This example is self-explanatory:

Example:

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

Output:

```C++
Here is the matrix m:
  3  -1
2.5 1.5
Here is the vector v:
4
3
```

Note that the syntax m(index) is not restricted to vectors, it is also available for general matrices, meaning index-based access in the array of coefficients. This however depends on the matrix's storage order. All Eigen matrices default to column-major storage order, but this can be changed to row-major, see Storage orders.

The operator[] is also overloaded for index-based access in vectors, but keep in mind that C++ doesn't allow operator[] to take more than one argument. We restrict operator[] to vectors, because an awkwardness in the C++ language would make matrix[i,j] compile to the same thing as matrix[j] !

## Comma-initialization

Matrix and vector coefficients can be conveniently set using the so-called comma-initializer syntax. For now, it is enough to know this example:

Example:

```C++
Matrix3f m;
m << 1, 2, 3,
     4, 5, 6,
     7, 8, 9;
std::cout << m;
```

Output:

```C++
1 2 3
4 5 6
7 8 9
```

The right-hand side can also contain matrix expressions as discussed in this page.

## Resizing

The current size of a matrix can be retrieved by rows(), cols() and size(). These methods return the number of rows, the number of columns and the number of coefficients, respectively. Resizing a dynamic-size matrix is done by the resize() method.

Example:

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
```

Output:

```C++
The matrix m is of size 4x3
It has 12 coefficients
The vector v is of size 5
As a matrix, v is of size 5x1
```

The resize() method is a no-operation if the actual matrix size doesn't change; otherwise it is destructive: the values of the coefficients may change. If you want a conservative variant of resize() which does not change the coefficients, use conservativeResize(), see this page for more details.

All these methods are still available on fixed-size matrices, for the sake of API uniformity. Of course, you can't actually resize a fixed-size matrix. Trying to change a fixed size to an actually different value will trigger an assertion failure; but the following code is legal:

Example:

```C++
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
int main()
{
  Matrix4d m;
  m.resize(4,4); // no operation
  std::cout << "The matrix m is of size "
            << m.rows() << "x" << m.cols() << std::endl;
}
```

Output:

```C++
The matrix m is of size 4x4
```

## Assignment and resizing

Assignment is the action of copying a matrix into another, using operator=. Eigen resizes the matrix on the left-hand side automatically so that it matches the size of the matrix on the right-hand size. For example:

Example:

```C++
MatrixXf a(2,2);
std::cout << "a is of size " << a.rows() << "x" << a.cols() << std::endl;
MatrixXf b(3,3);
a = b;
std::cout << "a is now of size " << a.rows() << "x" << a.cols() << std::endl;
```

Output:

```C++
a is of size 2x2
a is now of size 3x3
```

Of course, if the left-hand side is of fixed size, resizing it is not allowed.

If you do not want this automatic resizing to happen (for example for debugging purposes), you can disable it, see this page.

## Fixed vs. Dynamic size

When should one use fixed sizes (e.g. Matrix4f), and when should one prefer dynamic sizes (e.g. MatrixXf)? The simple answer is: use fixed sizes for very small sizes where you can, and use dynamic sizes for larger sizes or where you have to. For small sizes, especially for sizes smaller than (roughly) 16, using fixed sizes is hugely beneficial to performance, as it allows Eigen to avoid dynamic memory allocation and to unroll loops. Internally, a fixed-size Eigen matrix is just a plain array, i.e. doing

```C++
Matrix4f mymatrix; 
```

really amounts to just doing

```C++
float mymatrix[16]; 
```

so this really has zero runtime cost. By contrast, the array of a dynamic-size matrix is always allocated on the heap, so doing

```C++
MatrixXf mymatrix(rows,columns); 
```

amounts to doing

```C++
float *mymatrix = new float[rows*columns]; 
```

and in addition to that, the MatrixXf object stores its number of rows and columns as member variables.

The limitation of using fixed sizes, of course, is that this is only possible when you know the sizes at compile time. Also, for large enough sizes, say for sizes greater than (roughly) 32, the performance benefit of using fixed sizes becomes negligible. Worse, trying to create a very large matrix using fixed sizes inside a function could result in a stack overflow, since Eigen will try to allocate the array automatically as a local variable, and this is normally done on the stack. Finally, depending on circumstances, Eigen can also be more aggressive trying to vectorize (use SIMD instructions) when dynamic sizes are used, see Vectorization.

## Optional template parameters

We mentioned at the beginning of this page that the Matrix class takes six template parameters, but so far we only discussed the first three. The remaining three parameters are optional. Here is the complete list of template parameters:

```C++
Matrix<typename Scalar,
       int RowsAtCompileTime,
       int ColsAtCompileTime,
       int Options = 0,
       int MaxRowsAtCompileTime = RowsAtCompileTime,
       int MaxColsAtCompileTime = ColsAtCompileTime>
```

Options is a bit field. Here, we discuss only one bit: RowMajor. It specifies that the matrices of this type use row-major storage order; by default, the storage order is column-major. See the page on storage orders. For example, this type means row-major 3x3 matrices:

```C++
Matrix<float, 3, 3, RowMajor>
```

MaxRowsAtCompileTime and MaxColsAtCompileTime are useful when you want to specify that, even though the exact sizes of your matrices are not known at compile time, a fixed upper bound is known at compile time. The biggest reason why you might want to do that is to avoid dynamic memory allocation. For example the following matrix type uses a plain array of 12 floats, without dynamic memory allocation:

```C++
Matrix<float, Dynamic, Dynamic, 0, 3, 4>
```

## Convenience typedefs

Eigen defines the following Matrix typedefs:

```C++
1. MatrixNt for Matrix<type, N, N>. For example, MatrixXi for Matrix<int, Dynamic, Dynamic>.
2. VectorNt for Matrix<type, N, 1>. For example, Vector2f for Matrix<float, 2, 1>.
3. RowVectorNt for Matrix<type, 1, N>. For example, RowVector3d for Matrix<double, 1, 3>.
```

Where:

1. N can be any one of 2, 3, 4, or X (meaning Dynamic).
2. t can be any one of i (meaning int), f (meaning float), d (meaning double), cf (meaning complex<float>), or cd (meaning complex<double>). The fact that typedefs are only defined for these five types doesn't mean that they are the only supported scalar types. For example, all standard integer types are supported, see Scalar types.