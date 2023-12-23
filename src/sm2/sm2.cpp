#include "sm2.hpp"

// SM2曲线所在的有限域
mpz_class p = mpz_class("8542D69E4C044F18E8B92435BF6FF7DE457283915C45517D722EDB8B08F1DFC3", 16);
FiniteField F = FiniteField(p);

// SM2的参数
FiniteFieldElement a = F(mpz_class("787968B4FA32C3FD2417842E73BBFEFF2F3C848B6831D7E0EC65228B3937E498", 16));
FiniteFieldElement b = F(mpz_class("63E4C6D3B23B0C849CF84241484BFE48F61D59A5B16BA06E6E12D1DA27C5249A", 16));
mpz_class n = mpz_class("8542D69E4C044F18E8B92435BF6FF7DD297720630485628D5AE74EE7C32E79B7", 16);
FiniteFieldElement G_x = F(mpz_class("421DEBD61B62EAB6746434EBC3CC315E32220B3BADD50BDC4C4E6C147FEDD43D", 16));
FiniteFieldElement G_y = F(mpz_class("0680512BCBB42C07D47349D2153B70C4E5D7FDFCBFA36EA1A85841B9E46E09A2", 16));

// 椭圆曲线方程为: y^2 = x^3 + ax + b 
EllipticCurve SM2 = EllipticCurve(a, b, n);
EllipticCurvePoint G = EllipticCurvePoint(SM2, G_x, G_y);

// 公钥
FiniteFieldElement P_x = F(mpz_class("0AE4C7798AA0F119471BEE11825BE46202BB79E2A5844495E97C04FF4DF2548A", 16));
FiniteFieldElement P_y = F(mpz_class("7C0240F88F1CD4E16352A73C17B7F16F07353E53A176D684A9FE0C6BB798E857", 16));
EllipticCurvePoint P = EllipticCurvePoint(SM2, P_x, P_y);

// 私钥
FiniteFieldElement d_A = F(mpz_class("128B2FA8BD433C6C068C8D803DFF79792A519A55171B1B650C23661D15897263", 16));