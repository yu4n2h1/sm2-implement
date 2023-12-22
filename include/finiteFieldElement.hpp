#ifndef FINITEFIELDELEMENT_H
#define FINITEFIELDELEMENT_H
#include <gmpxx.h>

class FiniteFieldElement
{
public:
    mpz_class value;  // 有限域元素的值
    mpz_class modulus;  // 有限域的模数

    // 默认构造函数
    FiniteFieldElement();

    // 带参数的构造函数，用于初始化有限域元素
    FiniteFieldElement(mpz_class modulus, mpz_class value);

    // 以下是运算符重载和友元声明
    friend FiniteFieldElement operator+(const FiniteFieldElement& a, const FiniteFieldElement& b);
    friend FiniteFieldElement operator-(const FiniteFieldElement& a, const FiniteFieldElement& b);
    friend FiniteFieldElement operator*(const FiniteFieldElement& a, const FiniteFieldElement& b);
    friend FiniteFieldElement operator*(const FiniteFieldElement& a, const int& b);
    friend FiniteFieldElement operator*(const FiniteFieldElement& a, const mpz_class& b);
    friend FiniteFieldElement operator/(const FiniteFieldElement& a, const FiniteFieldElement& b);
    friend bool operator==(const FiniteFieldElement& a, const mpz_class &t);
    friend bool operator==(const FiniteFieldElement& a, const FiniteFieldElement &t);
    friend std::ostream& operator<<(std::ostream& out, FiniteFieldElement& f);
};

#endif