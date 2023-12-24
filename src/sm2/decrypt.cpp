#include "decrypt.hpp"
#include <gmpxx.h>
#include "encrypt.hpp"
#include "sm3.hpp"

std::string decrypt(FiniteFieldElement d, EllipticCurvePoint C1, std::string C) {
    EllipticCurvePoint C2 = C1*d;
    std::string out2 = C2.Out_Hex_xy();
    std::string t = KDF(out2,38);
    mpz_class M_mpz_class = (mpz_class(t ,16) ^ mpz_class(C, 16));
    
    std::string M = M_mpz_class.get_str(16);
    std::string stringC3 = sm3(out2.substr(0,48) + M + out2.substr(48,96));
    return M;
}

