#include <iostream>
#include <gmpxx.h>
#include "sm2.hpp"

//SM2曲线所在的有限域
mpz_class p = mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFF", 16);
FiniteField F = FiniteField(p);

// SM2的参数
FiniteFieldElement a = F(mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFC", 16));
FiniteFieldElement b = F(mpz_class("28E9FA9E9D9F5E344D5A9E4BCF6509A7F39789F515AB8F92DDBCBD414D940E93", 16));
mpz_class n = mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFF7203DF6B21C6052B53BBF40939D54123", 16);
FiniteFieldElement G_x = F(mpz_class("32C4AE2C1F1981195F9904466A39C9948FE30BBFF2660BE1715A4589334C74C7", 16));
FiniteFieldElement G_y = F(mpz_class("BC3736A2F4F6779C59BDCEE36B692153D0A9877CC62A474002DF32E52139F0A0", 16));

EllipticCurve SM2 = EllipticCurve(a, b, n);
EllipticCurvePoint SM2Point = EllipticCurvePoint(SM2, G_x, G_y);

int main() {
    std::cout << p << "\n";
    std::cout << F << "\n";
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << n << "\n";
    std::cout << G_x << "\n";
    std::cout << G_y << "\n";
    std::cout << SM2 << "\n";
    std::cout << SM2Point << "\n";
    return 0;
}