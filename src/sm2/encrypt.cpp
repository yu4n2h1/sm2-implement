#include "encrypt.hpp"
#include <gmpxx.h>
#include <iostream>
#include "sm2.hpp"
#include "sha256.hpp"
#include "sha256.hpp"
#include "sm3.hpp"
#include <string>


std::string encrypt(std::string M, EllipticCurvePoint& G ,EllipticCurvePoint& P ) {
    gmp_randclass randObj(gmp_randinit_default);
    mpz_class k = randObj.get_z_range(G.a.modulus); 
    // mpz_class k = mpz_class("384F30353073AEECE7A1654330A96204D37982A3E15B2CB5",16);
    EllipticCurvePoint C1 = G * k;
    std::string stringC1 = C1.Out_Hex_xy();
    EllipticCurvePoint kP = P * k; 
    std::string out2 = kP.Out_Hex_xy();
    std::string out256 = KDF(out2,M.length());
    mpz_class mpzC2 = mpz_class(M,16) ^ mpz_class(out256, 16);
    std::string stringC2 = mpzC2.get_str(16);
    std::string stringC3 = sm3(out2.substr(0,48) + M + out2.substr(48,96));
    return stringC1 + stringC3 + stringC2;
}

std::string uint32ToHex(uint32_t value) {
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << value;
    return ss.str();
}

std::string KDF(const std::string input, uint32_t klen) {
    uint32_t ct = 0x1;
    uint32_t v = 32;
    std::string key;
    while (key.length() < klen) {
        key += sm3(input + uint32ToHex(ct));
        ct ++;
    }

    return key.substr(0,klen);
}