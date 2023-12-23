#include "encrypt.hpp"
#include <gmpxx.h>
#include <iostream>
#include "sm2.hpp"





EllipticCurvePoint encrypt(string M ,int klen) {
    gmp_randclass randObj(gmp_randinit_default);
    mpz_class k = randObj.get_z_range(G.a.modulus); 
    EllipticCurvePoint C1 = G * k;
    std::string out1 = C1.Out_Hex_xy();
    EllipticCurvePoint kP = P * k; 
    std::string out2 = kP.Out_Hex_xy();
    std::string out256 = sha256(out2);
    mpz_class mpzC2 = mpz_class(M,16) ^ mpz_class(out2, 16);
    std::string stringC2 = mpzC2.get_str();
    
    
}
