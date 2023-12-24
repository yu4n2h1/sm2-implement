#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <gmpxx.h>
#include "sm2.hpp"
#include <iostream>

extern mpz_class k;

// G表示基点，P表示公钥点
std::string encrypt(std::string M, EllipticCurvePoint& G ,EllipticCurvePoint& P);
std::string KDF(const std::string input, uint32_t klen);
#endif // ENCRYPT_H