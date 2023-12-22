#ifndef ELLIPTICCURVE_H
#define ELLIPTICCURVE_H
#include <iostream>
#include <gmpxx.h>
#include <finiteFieldElement.hpp>

class EllipticCurve {
public:
    FiniteFieldElement a, b;  // 椭圆曲线的系数
    mpz_class n;  // 参数

    // 默认构造函数
    EllipticCurve();

    // 带参数的构造函数，用于初始化椭圆曲线
    EllipticCurve(FiniteFieldElement a, FiniteFieldElement b, mpz_class n);

    // 友元运算符重载，用于输出椭圆曲线对象
    friend std::ostream& operator<<(std::ostream& out, EllipticCurve& E);
};
#endif