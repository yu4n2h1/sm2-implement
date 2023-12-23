#include <iostream>
#include <gmpxx.h>
#include <random>
#include "verify.hpp"
#include "sign.hpp"
#include "sha256.hpp"

using namespace std;

bool verify(string message, string ID_A, FiniteFieldElement &r, FiniteFieldElement &s)
{
    mpz_class n = G.n;
    /**
     * 1. 检验r′∈[1, n-1]是否成立，若不成立则验证不通过
    */
    if (r.value < mpz_class(1) || r.value >= n) {
        return false;
    }
    /**
     * 2. 检验s′∈[1, n-1]是否成立，若不成立则验证不通过
    */
    if (s.value < mpz_class(1) || s.value >= n) {
        return false;
    }
    /**
     * 3. 设置M*=Z_A||M′，计算e′= H(M*)
    */
    string ENTL_A = calculate_ENTL_A(ID_A);
    string a_string = SM2.a.value.get_str(16);
    string b_string = SM2.b.value.get_str(16);
    string G_x_string = G.a.value.get_str(16);
    string G_y_string = G.b.value.get_str(16);
    string P_x_string = P.a.value.get_str(16);
    string P_y_string = P.b.value.get_str(16);
    string Z_A_pre_message = ENTL_A + ID_A + a_string + b_string + G_x_string + G_y_string + P_x_string + P_y_string;
    string Z_A = sha256(Z_A_pre_message);
    string Mmessage = Z_A + message;
    string e_msg = sha256(Mmessage);
    FiniteFieldElement e = F(mpz_class(e_msg, 16));
    /**
     * 4. 计算t= (r′ + s′) mod n，若t=0，则验证不通过
    */
    FiniteFieldElement t = r + s;
    if (t == F(mpz_class(0))) {
        return false;
    }
    /**
     * 5. 计算椭圆曲线点 (x1′，y1′)= s′ · G + t · PA
    */
    EllipticCurvePoint temp1 = (G * s.value);
    EllipticCurvePoint temp2 = (P * t.value);
    EllipticCurvePoint G1 = temp1 + temp2;
    FiniteFieldElement x1 = G1.a;
    /**
     * 6. 计算v=(e′+ x1′) mod n，检验v=r′是否成立，若成立则验证通过；否则验证不通过
    */
    FiniteFieldElement v = e + x1;
    if (v == r) {
        return true;
    }
    return false;
}