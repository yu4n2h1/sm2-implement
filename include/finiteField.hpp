#ifndef FINITEFIELD_H
#define FINITEFIELD_H
#include <gmpxx.h>
#include "finiteFieldElement.hpp"

class FiniteField {
public:
    mpz_class modulus;  // 有限域的模数

    // 默认构造函数
    FiniteField();

    // 带参数的构造函数，用于初始化有限域
    FiniteField(mpz_class modulus);

    // 重载调用运算符，用于创建有限域中的元素
    FiniteFieldElement operator()(const mpz_class& value) {
        return FiniteFieldElement(this->modulus, value);
    }

    // 友元运算符重载，用于输出有限域对象
    friend std::ostream& operator<<(std::ostream& out, FiniteField& f);
};
#endif