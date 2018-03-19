# Eigen 几何模块
-- 空间变换

这一模块主要介绍了在Eigen几何模块中常见的集中二维和三维的旋转、映射或者仿射变换等。
Eigen的几何模块主要提供了两种不同的几何变换类型：
1. 抽象变换，即旋转，变换，放缩等不是由矩阵表示的，而是由角轴表示，或者是思源书表示，但是可以在表达式中混用矩阵和向量。
2. 提供矩阵和向量的变换或者仿射变换。

## 创建一个变换

由下面几种方式：

1. 第一种
```
Transform t(AngleAxis(angle, axis));
```
2. 第二种
```
Transform t;
t = AngleAxis(angle, axis);
```

但是下面的这种方式是错误的：
```
Transform t = AngleAxis(angle ,axis);
```
这种方式会引起一个从AngleAxis类到Transform类的一个非显示的变换构造，但是在这不希望由一个隐式的类型变换。

## 变换类型



变换类型 | 初始化代码
---| --- 
二维角度旋转 | Rotation2D<float> rot2(angle_in_radian);
三维旋转（角轴）  | AngleAxis<float> aa(angle_int_radian, Vector3f(ax.ay,az)); // 轴向量必须正则化
三维旋转（四元数）| Quaternion<float> q; q = AngleAxis(angle_in_radian, axis);
N维放缩 | Scaling(sx, sy); Scaling(sx, sy, sz); Scaling(s); Scaling(vecN);
N维变换 | Translation<float, 2>(tx, ty); Translation<float, 3>(tx, ty, tz); Translation<float, N>(s);  Translation<float, N>(vecN);
N维放射变换 | Transform<float, N, Affine> t = concatenation_of_ang_transform; Transform<float, 3 Affine> t = Translation3f(p) * AngleAxisf(a, axis) * Scaling(s)

N维线性变换 | Matrix<float, N> t = concatenation_of_rotations_and_scalings; Matrix<float, 2> t = Rotation2Df(a) * Scaling(s); Matrix<float, 3> t = AngleAxisf(a, axis) * Scalings(s);


### 旋转
对于旋转，一个旋转向量就能表示，但是旋转矩阵是更形象的，使用四元数表示旋转更紧凑、高效、稳定。使用二维旋转和角轴定义个旋转对象是最方便的。

### 变换和放缩
类似于角轴，这些类被设计成能够简单的创建和初始化一个线性或者仿射变换，但是，不同于角轴，这些类在使用起来不是高效的，这些类在写一个通用的高效算法仍然是感兴趣的。

上面的这些类都是能够被转换成具有同样属性的类型，或者更通用的类型。

## 通用API
Eigen允许使用通用的API进行变换操作，比如矩阵的乘法：

操作 | 代码
--- | ---
两个变换的乘积 | gen1 * gen2;
对一个向量进行变换 | vec2 = gen1 * vec1;
对一个变换求逆 | gen2 = gen2.inverse();
球形差值 | rot3 = rot2.slerp(alpha, rot2);

## 仿射变换
仿射变换使用Transform类，内部表示使用（N+1）×（N+1）的矩阵，在具体使用的时候，不区分点和向量表示。

操作 | 代码
--| ---
对点做变换 | VectorNf p1, p2; p2 = t * p1;
对向量做变换 | VectorNf vec1, vec2; vec2 = t * vec1;


等等。。。




       

