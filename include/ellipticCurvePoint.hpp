#ifndef ELLIPTICCURVEPOINT_H
#define ELLIPTICCURVEPOINT_H
#include <iostream>
#include "ellipticCurve.hpp"
#include "finiteFieldElement.hpp"
#include <iostream>

class EllipticCurvePoint {
public:
    FiniteFieldElement a, b;  // 椭圆曲线的系数
    mpz_class n;  // 参数
    std::pair<FiniteFieldElement, FiniteFieldElement> point;  // 椭圆曲线上的坐标

    // 默认构造函数
    EllipticCurvePoint();

    // 带参数的构造函数，用于初始化椭圆曲线上的点
    EllipticCurvePoint(EllipticCurve E, FiniteFieldElement x, FiniteFieldElement y);

    // 带参数的构造函数，用于初始化椭圆曲线上的点
    EllipticCurvePoint(EllipticCurve E, std::pair<FiniteFieldElement, FiniteFieldElement> point);

    // 友元运算符重载，用于椭圆曲线点的加法
    friend EllipticCurvePoint operator+(const EllipticCurvePoint& a, EllipticCurvePoint& b);
    
    // 友元运算符重载，用于椭圆曲线点的比较
    friend bool operator==(const EllipticCurvePoint& a, EllipticCurvePoint& b);
    
    // 友元运算符重载，用于输出椭圆曲线点对象
    friend std::ostream& operator<<(std::ostream& out, EllipticCurvePoint& E);
    
    // 友元运算符重载，用于椭圆曲线点的减法
    friend EllipticCurvePoint operator-(const EllipticCurvePoint& a, const EllipticCurvePoint& b);
    
    // 友元运算符重载，用于椭圆曲线点的标量乘法
    friend EllipticCurvePoint operator*(const EllipticCurvePoint& a, const int& b);
};

#endif