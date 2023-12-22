#include <iostream>
#include <gmpxx.h>
#include <random>
#include "sm2.hpp"

//SM2曲线所在的有限域 F = 
// mpz_class p = mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFF", 16);
// FiniteField F = FiniteField(p);

// // SM2的参数
// FiniteFieldElement a = F(mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFC", 16));
// FiniteFieldElement b = F(mpz_class("28E9FA9E9D9F5E344D5A9E4BCF6509A7F39789F515AB8F92DDBCBD414D940E93", 16));
// mpz_class n = mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFF7203DF6B21C6052B53BBF40939D54123", 16);
// FiniteFieldElement G_x = F(mpz_class("32C4AE2C1F1981195F9904466A39C9948FE30BBFF2660BE1715A4589334C74C7", 16));
// FiniteFieldElement G_y = F(mpz_class("BC3736A2F4F6779C59BDCEE36B692153D0A9877CC62A474002DF32E52139F0A0", 16));
// // 椭圆曲线方程为: y^2 = x^3 + ax + b 
// EllipticCurve SM2 = EllipticCurve(a, b, n);
// EllipticCurvePoint SM2Point = EllipticCurvePoint(SM2, G_x, G_y);

// 随机数生成器
std::random_device rd;
unsigned int seed = rd();
std::mt19937 engine(seed);

std::string message;

void sm2_signature(std::string message, FiniteFieldElement &r, FiniteFieldElement &s, EllipticCurvePoint G, FiniteFieldElement pri_key) {

}

bool sm2_verify(std::string message, FiniteFieldElement r, FiniteFieldElement s, mpz_class pub_key) {

}

int main() {

    
    std::cout << "SM2: " << SM2 << std::endl;
    std::cout << "SM2Point: " << SM2Point << std::endl << std::endl;
    std::cout << engine() << std::endl;
    message = "nieshangqing";

    return 0;
}