# The Array class and coefficient-wise operations

This page aims to provide an overview and explanations on how to use Eigen's Array class.

## What is the Array class?

The Array class provides general-purpose arrays, as opposed to the Matrix class which is intended for linear algebra. Furthermore, the Array class provides an easy way to perform coefficient-wise operations, which might not have a linear algebraic meaning, such as adding a constant to every coefficient in the array or multiplying two arrays coefficient-wise.

## Array types

Array is a class template taking the same template parameters as Matrix. As with Matrix, the first three template parameters are mandatory:

```C++
Array<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
```

The last three template parameters are optional. Since this is exactly the same as for Matrix, we won't explain it again here and just refer to The Matrix class.

Eigen also provides typedefs for some common cases, in a way that is similar to the Matrix typedefs but with some slight differences, as the word "array" is used for both 1-dimensional and 2-dimensional arrays. We adopt the convention that typedefs of the form ArrayNt stand for 1-dimensional arrays, where N and t are the size and the scalar type, as in the Matrix typedefs explained on this page. For 2-dimensional arrays, we use typedefs of the form ArrayNNt. Some examples are shown in the following table:

| Type | Typedef |
| --- | --- |
| `Array<float,Dynamic,1> ` | `ArrayXf `|
| `Array<float,3,1>` | `Array3f` |
| `Array<double,Dynamic,Dynamic>`  | `ArrayXXd` |
| `Array<double,3,3>` | `Array33d` |

## Accessing values inside an Array

The parenthesis operator is overloaded to provide write and read access to the coefficients of an array, just as with matrices. Furthermore, the << operator can be used to initialize arrays (via the comma initializer) or to print them.

Example

```C++
#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;
using namespace std;
int main()
{
  ArrayXXf  m(2,2);
  // assign some values coefficient by coefficient
  m(0,0) = 1.0; m(0,1) = 2.0;
  m(1,0) = 3.0; m(1,1) = m(0,1) + m(1,0);
  // print values to standard output
  cout << m << endl << endl;
  // using the comma-initializer is also allowed
  m << 1.0,2.0,
       3.0,4.0;
  // print values to standard output
  cout << m << endl;
}
```

Output

```C++
1 2
3 5

1 2
3 4
```

For more information about the comma initializer, see Advanced initialization.

## Addition and subtraction

Adding and subtracting two arrays is the same as for matrices. The operation is valid if both arrays have the same size, and the addition or subtraction is done coefficient-wise.

Arrays also support expressions of the form array + scalar which add a scalar to each coefficient in the array. This provides a functionality that is not directly available for Matrix objects.

Example:

```C++
#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;
using namespace std;
int main()
{
  ArrayXXf a(3,3);
  ArrayXXf b(3,3);
  a << 1,2,3,
       4,5,6,
       7,8,9;
  b << 1,2,3,
       1,2,3,
       1,2,3;
       
  // Adding two arrays
  cout << "a + b = " << endl << a + b << endl << endl;
  // Subtracting a scalar from an array
  cout << "a - 2 = " << endl << a - 2 << endl;
}
```

Output:

```C++
a + b = 
 2  4  6
 5  7  9
 8 10 12

a - 2 = 
-1  0  1
 2  3  4
 5  6  7
 ```

## Array multiplication

First of all, of course you can multiply an array by a scalar, this works in the same way as matrices. Where arrays are fundamentally different from matrices, is when you multiply two together. Matrices interpret multiplication as matrix product and arrays interpret multiplication as coefficient-wise product. Thus, two arrays can be multiplied if and only if they have the same dimensions.

Example:

```C++
#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;
using namespace std;
int main()
{
  ArrayXXf a(2,2);
  ArrayXXf b(2,2);
  a << 1,2,
       3,4;
  b << 5,6,
       7,8;
  cout << "a * b = " << endl << a * b << endl;
}
```

Output:

```C++
a * b = 
 5 12
21 32
```

## Other coefficient-wise operations

The Array class defines other coefficient-wise operations besides the addition, subtraction and multiplication operators described above. For example, the .abs() method takes the absolute value of each coefficient, while .sqrt() computes the square root of the coefficients. If you have two arrays of the same size, you can call .min(.) to construct the array whose coefficients are the minimum of the corresponding coefficients of the two given arrays. These operations are illustrated in the following example.

Example:

```C++
#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;
using namespace std;
int main()
{
  ArrayXf a = ArrayXf::Random(5);
  a *= 2;
  cout << "a =" << endl 
       << a << endl;
  cout << "a.abs() =" << endl 
       << a.abs() << endl;
  cout << "a.abs().sqrt() =" << endl 
       << a.abs().sqrt() << endl;
  cout << "a.min(a.abs().sqrt()) =" << endl 
       << a.min(a.abs().sqrt()) << endl;
}
```

Output:

```C++
a =
  1.36
-0.422
  1.13
  1.19
  1.65
a.abs() =
 1.36
0.422
 1.13
 1.19
 1.65
a.abs().sqrt() =
1.17
0.65
1.06
1.09
1.28
a.min(a.abs().sqrt()) =
  1.17
-0.422
  1.06
  1.09
  1.28
```

More coefficient-wise operations can be found in the Quick reference guide.

## Converting between array and matrix expressions

When should you use objects of the Matrix class and when should you use objects of the Array class? You cannot apply Matrix operations on arrays, or Array operations on matrices. Thus, if you need to do linear algebraic operations such as matrix multiplication, then you should use matrices; if you need to do coefficient-wise operations, then you should use arrays. However, sometimes it is not that simple, but you need to use both Matrix and Array operations. In that case, you need to convert a matrix to an array or reversely. This gives access to all operations regardless of the choice of declaring objects as arrays or as matrices.

Matrix expressions have an .array() method that 'converts' them into array expressions, so that coefficient-wise operations can be applied easily. Conversely, array expressions have a .matrix() method. As with all Eigen expression abstractions, this doesn't have any runtime cost (provided that you let your compiler optimize). **Both .array() and .matrix() can be used as rvalues and as lvalues.**

Mixing matrices and arrays in an expression is forbidden with Eigen. For instance, you cannot add a matrix and array directly; the operands of a + operator should either both be matrices or both be arrays. However, it is easy to convert from one to the other with .array() and .matrix(). The exception to this rule is the assignment operator: it is allowed to assign a matrix expression to an array variable, or to assign an array expression to a matrix variable.

The following example shows how to use array operations on a Matrix object by employing the .array() method. For example, the statement result = m.array() * n.array() takes two matrices m and n, converts them both to an array, uses to multiply them coefficient-wise and assigns the result to the matrix variable result **(this is legal because Eigen allows assigning array expressions to matrix variables).**

> As a matter of fact, this usage case is so common that Eigen provides a const .cwiseProduct(.) method for matrices to compute the coefficient-wise product. This is also shown in the example program.

Example:

```C++
#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;
using namespace std;
int main()
{
  MatrixXf m(2,2);
  MatrixXf n(2,2);
  MatrixXf result(2,2);
  m << 1,2,
       3,4;
  n << 5,6,
       7,8;
  result = m * n;
  cout << "-- Matrix m*n: --" << endl << result << endl << endl;
  result = m.array() * n.array();
  cout << "-- Array m*n: --" << endl << result << endl << endl;
  result = m.cwiseProduct(n);
  cout << "-- With cwiseProduct: --" << endl << result << endl << endl;
  result = m.array() + 4;
  cout << "-- Array m + 4: --" << endl << result << endl << endl;
}
```

Output:

```C++
-- Matrix m*n: --
19 22
43 50

-- Array m*n: --
 5 12
21 32

-- With cwiseProduct: --
 5 12
21 32

-- Array m + 4: --
5 6
7 8
```

Similarly, if array1 and array2 are arrays, then the expression array1.matrix() * array2.matrix() computes their matrix product.

Here is a more advanced example. The expression (m.array() + 4).matrix() * m adds 4 to every coefficient in the matrix m and then computes the matrix product of the result with m. Similarly, the expression (m.array() * n.array()).matrix() * m computes the coefficient-wise product of the matrices m and n and then the matrix product of the result with m.

Example:

```C++
#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;
using namespace std;
int main()
{
  MatrixXf m(2,2);
  MatrixXf n(2,2);
  MatrixXf result(2,2);
  m << 1,2,
       3,4;
  n << 5,6,
       7,8;
  
  result = (m.array() + 4).matrix() * m;
  cout << "-- Combination 1: --" << endl << result << endl << endl;
  result = (m.array() * n.array()).matrix() * m;
  cout << "-- Combination 2: --" << endl << result << endl << endl;
}
```

Output:

```C++
-- Combination 1: --
23 34
31 46

-- Combination 2: --
 41  58
117 170
```