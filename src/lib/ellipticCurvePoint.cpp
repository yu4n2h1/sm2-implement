#include <iostream>
#include "ellipticCurve.hpp"
#include "ellipticCurvePoint.hpp"
#include <gmpxx.h>
#include "finiteFieldElement.hpp"
#include <string>

EllipticCurvePoint::EllipticCurvePoint() {}

EllipticCurvePoint::EllipticCurvePoint(EllipticCurve E, FiniteFieldElement x, FiniteFieldElement y) {
    this->a = E.a;
    this->b = E.b;
    this->n = E.n;
    this->point.first = x;
    this->point.second = y;
}

EllipticCurvePoint add(EllipticCurvePoint a, EllipticCurvePoint b) {
    mpz_class p = a.a.modulus;
    FiniteFieldElement lambda;
    if (a.point.first.value == p && a.point.second.value == p) {
        return b;
    } else if (b.point.first.value == p && b.point.second.value == p) {
        return a;
    } else if (a == b) {
        lambda = ((a.point.first * a.point.first)* 3 + a.a)/(a.point.second * 2);
    } else {
        lambda = (b.point.second - a.point.second) / (b.point.first - a.point.first);
    }
    FiniteFieldElement xr = lambda * lambda - a.point.first - b.point.first;
    FiniteFieldElement yr = lambda * (a.point.first - xr) - a.point.second;
    return EllipticCurvePoint(EllipticCurve(a.a,a.b,a.n), xr, yr);
}

EllipticCurvePoint::EllipticCurvePoint(EllipticCurve E, std::pair<FiniteFieldElement,FiniteFieldElement> point) {
    this->a = E.a;
    this->b = E.b;
    this->n = E.n;
    this->point = point;
}

EllipticCurvePoint operator+(const EllipticCurvePoint &a, EllipticCurvePoint &b)
{
    return add(a, b);
}


bool operator==(const EllipticCurvePoint & a, EllipticCurvePoint & b)
{
    if (a.point== b.point) {
        if (a.a == b.a && a.b == b.b && a.n == b.n) {
            return true;
        }
    }
    return false;
}

EllipticCurvePoint operator-(const EllipticCurvePoint& a, const EllipticCurvePoint& b) {
    EllipticCurvePoint res = b;
    res.point.second.value = b.a.modulus - b.point.second.value;
    return add(a , res);
}

EllipticCurvePoint operator*(const EllipticCurvePoint& a, const int& b) {
    EllipticCurvePoint res = EllipticCurvePoint(EllipticCurve(a.a,a.b,a.n), FiniteFieldElement(a.a.modulus,a.a.modulus),FiniteFieldElement(a.a.modulus,a.a.modulus));
    EllipticCurvePoint type = a;
    mpz_class k = mpz_class(b);
    while (k != 0) {
        if ((1 & k) == 1) {
            res = add (res, type);
        }
        type = add(type, type);
        k >>= 1;
    }
    return res;
}


std::ostream& operator<<(std::ostream& out , EllipticCurvePoint &E) {
    out << "(" << E.point.first.value << " , " << E.point.second.value << ")";
    return out; 
}


EllipticCurvePoint operator*(const EllipticCurvePoint& a, const mpz_class& b) {
    EllipticCurvePoint res = EllipticCurvePoint(EllipticCurve(a.a,a.b,a.n), FiniteFieldElement(a.a.modulus,a.a.modulus),FiniteFieldElement(a.a.modulus,a.a.modulus));
    EllipticCurvePoint type = a;
    mpz_class k = b;
    while (k != 0) {
        if ((1 & k) == 1) {
            res = add (res, type);
        }
        type = add(type, type);
        k >>= 1;
    }
    return res;
}

EllipticCurvePoint operator*(const EllipticCurvePoint & a, const FiniteFieldElement & b)
{
    EllipticCurvePoint res = EllipticCurvePoint(EllipticCurve(a.a,a.b,a.n), FiniteFieldElement(a.a.modulus,a.a.modulus),FiniteFieldElement(a.a.modulus,a.a.modulus));
    EllipticCurvePoint type = a;
    mpz_class k = b.value;
    while (k != 0) {
        if ((1 & k) == 1) {
            res = add (res, type);
        }
        type = add(type, type);
        k >>= 1;
    }
    return res;
}


std::string EllipticCurvePoint::Out_Hex_xy() {
    std::string x_str = this->point.first.value.get_str(16);
    std::string y_str = this->point.second.value.get_str(16);

    // 补零至192位
    x_str = std::string(48 - x_str.length(), '0') + x_str;
    y_str = std::string(48 - y_str.length(), '0') + y_str;

    // 拼接并返回结果
    return x_str + y_str;
}