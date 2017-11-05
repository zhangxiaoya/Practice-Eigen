# Matrix and vector arithmetic

This page aims to provide an overview and some details on how to perform arithmetic between matrices, vectors and scalars with Eigen.

## Introduction

Eigen offers matrix/vector arithmetic operations either through overloads of common C++ arithmetic operators such as +, -, *, or through special methods such as dot(), cross(), etc. For the Matrix class (matrices and vectors), operators are only overloaded to support linear-algebraic operations. For example, matrix1 * matrix2 means matrix-matrix product, and vector + scalar is just not allowed. If you want to perform all kinds of array operations, not linear algebra, see the next page.

## Addition and subtraction

The left hand side and right hand side must, of course, have the same numbers of rows and of columns. They must also have the same Scalar type, as Eigen doesn't do automatic type promotion. The operators at hand here are:

- binary operator + as in a+b
- binary operator - as in a-b
- unary operator - as in -a
- compound operator += as in a+=b
- compound operator -= as in a-=b

Example:

```C++
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
int main()
{
  Matrix2d a;
  a << 1, 2,
       3, 4;
  MatrixXd b(2,2);
  b << 2, 3,
       1, 4;
  std::cout << "a + b =\n" << a + b << std::endl;
  std::cout << "a - b =\n" << a - b << std::endl;
  std::cout << "Doing a += b;" << std::endl;
  a += b;
  std::cout << "Now a =\n" << a << std::endl;
  Vector3d v(1,2,3);
  Vector3d w(1,0,0);
  std::cout << "-v + w - v =\n" << -v + w - v << std::endl;
}
```

Output:

```C++
a + b =
3 5
4 8
a - b =
-1 -1
 2  0
Doing a += b;
Now a =
3 5
4 8
-v + w - v =
-1
-4
-6
```

## Scalar multiplication and division

Multiplication and division by a scalar is very simple too. The operators at hand here are:

- binary operator * as in matrix*scalar
- binary operator * as in scalar*matrix
- binary operator / as in matrix/scalar
- compound operator *= as in matrix*=scalar
- compound operator /= as in matrix/=scalar

Example:

```C++
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
int main()
{
  Matrix2d a;
  a << 1, 2,
       3, 4;
  Vector3d v(1,2,3);
  std::cout << "a * 2.5 =\n" << a * 2.5 << std::endl;
  std::cout << "0.1 * v =\n" << 0.1 * v << std::endl;
  std::cout << "Doing v *= 2;" << std::endl;
  v *= 2;
  std::cout << "Now v =\n" << v << std::endl;
}
```

Output:

```C++
a * 2.5 =
2.5   5
7.5  10
0.1 * v =
0.1
0.2
0.3
Doing v *= 2;
Now v =
2
4
6
```

## A note about expression templates

This is an advanced topic that we explain on this page, but it is useful to just mention it now. In Eigen, arithmetic operators such as operator+ don't perform any computation by themselves, they just return an "expression object" describing the computation to be performed. The actual computation happens later, when the whole expression is evaluated, typically in operator=. While this might sound heavy, any modern optimizing compiler is able to optimize away that abstraction and the result is perfectly optimized code. For example, when you do:

```C++
VectorXf a(50), b(50), c(50), d(50);
...
a = 3*b + 4*c + 5*d;
```

Eigen compiles it to just one for loop, so that the arrays are traversed only once. Simplifying (e.g. ignoring SIMD optimizations), this loop looks like this:

```C++
for(int i = 0; i < 50; ++i)
  a[i] = 3*b[i] + 4*c[i] + 5*d[i];
```

Thus, you should not be afraid of using relatively large arithmetic expressions with Eigen: it only gives Eigen more opportunities for optimization.

## Transposition and conjugation

The transpose $ a^T $, conjugate $ \bar{a} $, and adjoint (i.e., conjugate transpose) $ a^* $ of a matrix or vector $ a $ are obtained by the member functions transpose(), conjugate(), and adjoint(), respectively.

Example:
```C++
MatrixXcf a = MatrixXcf::Random(2,2);
cout << "Here is the matrix a\n" << a << endl;
cout << "Here is the matrix a^T\n" << a.transpose() << endl;
cout << "Here is the conjugate of a\n" << a.conjugate() << endl;
cout << "Here is the matrix a^*\n" << a.adjoint() << endl;
```

Output:

```C+++
Here is the matrix a
 (-0.211,0.68) (-0.605,0.823)
 (0.597,0.566)  (0.536,-0.33)
Here is the matrix a^T
 (-0.211,0.68)  (0.597,0.566)
(-0.605,0.823)  (0.536,-0.33)
Here is the conjugate of a
 (-0.211,-0.68) (-0.605,-0.823)
 (0.597,-0.566)    (0.536,0.33)
Here is the matrix a^*
 (-0.211,-0.68)  (0.597,-0.566)
(-0.605,-0.823)    (0.536,0.33)
```

For real matrices, conjugate() is a no-operation, and so adjoint() is equivalent to transpose().

As for basic arithmetic operators, transpose() and adjoint() simply return a proxy object without doing the actual transposition. If you do b = a.transpose(), then the transpose is evaluated at the same time as the result is written into b. However, there is a complication here. If you do a = a.transpose(), then Eigen starts writing the result into a before the evaluation of the transpose is finished. Therefore, the instruction a = a.transpose() does not replace a with its transpose, as one would expect:

Example:

```C++
Matrix2i a; a << 1, 2, 3, 4;
cout << "Here is the matrix a:\n" << a << endl;
a = a.transpose(); // !!! do NOT do this !!!
cout << "and the result of the aliasing effect:\n" << a << endl;
```

Output:

```C++
Here is the matrix a:
1 2
3 4
and the result of the aliasing effect:
1 2
2 4
```

This is the so-called aliasing issue. In "debug mode", i.e., when assertions have not been disabled, such common pitfalls are automatically detected.

For in-place transposition, as for instance in a = a.transpose(), simply use the transposeInPlace() function:

Example:

```C++
MatrixXf a(2,3); a << 1, 2, 3, 4, 5, 6;
cout << "Here is the initial matrix a:\n" << a << endl;
a.transposeInPlace();
cout << "and after being transposed:\n" << a << endl;
```

Output:

```C++
Here is the initial matrix a:
1 2 3
4 5 6
and after being transposed:
1 4
2 5
3 6
```

There is also the adjointInPlace() function for complex matrices.

Matrix-matrix and matrix-vector multiplication

Matrix-matrix multiplication is again done with operator*. Since vectors are a special case of matrices, they are implicitly handled there too, so matrix-vector product is really just a special case of matrix-matrix product, and so is vector-vector outer product. Thus, all these cases are handled by just two operators:

- binary operator * as in a*b
- compound operator *= as in a*=b (this multiplies on the right: a*=b is equivalent to a = a*b)

Example:

```C++
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
int main()
{
  Matrix2d mat;
  mat << 1, 2,
         3, 4;
  Vector2d u(-1,1), v(2,0);
  std::cout << "Here is mat*mat:\n" << mat*mat << std::endl;
  std::cout << "Here is mat*u:\n" << mat*u << std::endl;
  std::cout << "Here is u^T*mat:\n" << u.transpose()*mat << std::endl;
  std::cout << "Here is u^T*v:\n" << u.transpose()*v << std::endl;
  std::cout << "Here is u*v^T:\n" << u*v.transpose() << std::endl;
  std::cout << "Let's multiply mat by itself" << std::endl;
  mat = mat*mat;
  std::cout << "Now mat is mat:\n" << mat << std::endl;
}
```

Output:

```C++
Here is mat*mat:
 7 10
15 22
Here is mat*u:
1
1
Here is u^T*mat:
2 2
Here is u^T*v:
-2
Here is u*v^T:
-2 -0
 2  0
Let's multiply mat by itself
Now mat is mat:
 7 10
15 22
```

Note: if you read the above paragraph on expression templates and are worried that doing m=m*m might cause aliasing issues, be reassured for now: Eigen treats matrix multiplication as a special case and takes care of introducing a temporary here, so it will compile m=m*m as:

```C++
tmp = m*m;
m = tmp;
```

If you know your matrix product can be safely evaluated into the destination matrix without aliasing issue, then you can use the noalias() function to avoid the temporary, e.g.:

```C++
c.noalias() += a * b;
```

For more details on this topic, see the page on aliasing.

**Note:** for BLAS users worried about performance, expressions such as c.noalias() -= 2 * a.adjoint() * b; are fully optimized and trigger a single gemm-like function call.

## Dot product and cross product

For dot product and cross product, you need the dot() and cross() methods. Of course, the dot product can also be obtained as a 1x1 matrix as u.adjoint()*v.

Example:

```C++
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{
  Vector3d v(1,2,3);
  Vector3d w(0,1,2);
  cout << "Dot product: " << v.dot(w) << endl;
  double dp = v.adjoint()*w; // automatic conversion of the inner product to a scalar
  cout << "Dot product via a matrix product: " << dp << endl;
  cout << "Cross product:\n" << v.cross(w) << endl;
}
```

Output:

```C++
Dot product: 8
Dot product via a matrix product: 8
Cross product:
 1
-2
 1
 ```

Remember that cross product is only for vectors of size 3. Dot product is for vectors of any sizes. When using complex numbers, Eigen's dot product is conjugate-linear in the first variable and linear in the second variable.

## Basic arithmetic reduction operations

Eigen also provides some reduction operations to reduce a given matrix or vector to a single value such as the sum (computed by sum()), product (prod()), or the maximum (maxCoeff()) and minimum (minCoeff()) of all its coefficients.

Example:

```C++

#include <iostream>
#include <Eigen/Dense>
using namespace std;
int main()
{
  Eigen::Matrix2d mat;
  mat << 1, 2,
         3, 4;
  cout << "Here is mat.sum():       " << mat.sum()       << endl;
  cout << "Here is mat.prod():      " << mat.prod()      << endl;
  cout << "Here is mat.mean():      " << mat.mean()      << endl;
  cout << "Here is mat.minCoeff():  " << mat.minCoeff()  << endl;
  cout << "Here is mat.maxCoeff():  " << mat.maxCoeff()  << endl;
  cout << "Here is mat.trace():     " << mat.trace()     << endl;
}

```

Output:

```C++

Here is mat.sum():       10
Here is mat.prod():      24
Here is mat.mean():      2.5
Here is mat.minCoeff():  1
Here is mat.maxCoeff():  4
Here is mat.trace():     5

```

The trace of a matrix, as returned by the function trace(), is the sum of the diagonal coefficients and can also be computed as efficiently using a.diagonal().sum(), as we will see later on.

There also exist variants of the minCoeff and maxCoeff functions returning the coordinates of the respective coefficient via the arguments:

Example:

```C++

  Matrix3f m = Matrix3f::Random();
  std::ptrdiff_t i, j;
  float minOfM = m.minCoeff(&i,&j);
  cout << "Here is the matrix m:\n" << m << endl;
  cout << "Its minimum coefficient (" << minOfM 
       << ") is at position (" << i << "," << j << ")\n\n";
  RowVector4i v = RowVector4i::Random();
  int maxOfV = v.maxCoeff(&i);
  cout << "Here is the vector v: " << v << endl;
  cout << "Its maximum coefficient (" << maxOfV 
       << ") is at position " << i << endl;
```

Output:

```C++
Here is the matrix m:
  0.68  0.597  -0.33
-0.211  0.823  0.536
 0.566 -0.605 -0.444
Its minimum coefficient (-0.605) is at position (2,1)

Here is the vector v:  1  0  3 -3
Its maximum coefficient (3) is at position 2
```

## Validity of operations

Eigen checks the validity of the operations that you perform. When possible, it checks them at compile time, producing compilation errors. These error messages can be long and ugly, but Eigen writes the important message in UPPERCASE_LETTERS_SO_IT_STANDS_OUT. For example:

```C++

Matrix3f m;
Vector4f v;
v = m*v;      // Compile-time error: YOU_MIXED_MATRICES_OF_DIFFERENT_SIZES

```

Of course, in many cases, for example when checking dynamic sizes, the check cannot be performed at compile time. Eigen then uses runtime assertions. This means that the program will abort with an error message when executing an illegal operation if it is run in "debug mode", and it will probably crash if assertions are turned off.

```C++
MatrixXf m(3,3);
VectorXf v(4);
v = m * v; // Run-time assertion failure here: "invalid matrix product"
```
For more details on this topic, see this page.