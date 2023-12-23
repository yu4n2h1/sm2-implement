#include <iostream>
#include "finiteField.hpp"
#include "finiteFieldElement.hpp"
#include "ellipticCurve.hpp"
#include "ellipticCurvePoint.hpp"
#include "sm2.hpp"
#include "encrypt.hpp"
#include "typeinfo"
#include "sha256.hpp"
#include "encrypt.hpp"
using namespace std;

int main() {

    EllipticCurve();
    mpz_class p = mpz_class("BDB6F4FE3E8B1D9E0DA8C0D46F4C318CEFE4AFE3B6B8551F", 16);
    mpz_class a = mpz_class("BB8E5E8FBC115E139FE6A814FE48AAA6F0ADA1AA5DF91985", 16);
    mpz_class b = mpz_class("1854BEBDC31B21B7AEFC80AB0ECD10D5B1B3308E6DBF11C1", 16);
    mpz_class n = mpz_class("BDB6F4FE3E8B1D9E0DA8C0D40FC962195DFAE76F56564677", 16);
    mpz_class x = mpz_class("4AD5F7048DE709AD51236DE65E4D4B482C836DC6E4106640", 16);
    mpz_class y = mpz_class("02BB3A02D4AAADACAE24817A4CA3A1B014B5270432DB27D2", 16);
    auto F = FiniteField(p);
    FiniteFieldElement aa, bb ,cc, xx, yy, dB;
    aa = F(a);
    bb = F(b);
    xx = F(x);
    yy = F(y);
    EllipticCurve E = EllipticCurve(aa,bb,n);
    EllipticCurvePoint G = EllipticCurvePoint(E, xx ,yy);
    string M = string("656E6372797074696F6E207374616E64617264");
    // 私钥
    dB = F(mpz_class("58892B807074F53FBF67288A1DFAA1AC313455FE60355AFD", 16));
    // 
    encrypt(M,G);



  

    // cout << E.a << endl;
    // cout << E.b << endl;
    // cout << E.n << endl;
    // cout << E << endl;
    // EllipticCurvePoint EE = EllipticCurvePoint(E, xx, yy);
    // EllipticCurvePoint O = EllipticCurvePoint(E, FiniteFieldElement(p,p),FiniteFieldElement(p,p));
    // // cout << EE + O << endl;
    // cout << O << endl;
    // cout << EE << endl;
    // EllipticCurvePoint W =  EE + O;
    // cout << W << endl;
    // FiniteFieldElement ww =  aa*3;
    // cout <<ww << endl;
    // aa*mpz_class(3);
    // EllipticCurvePoint WW = W + W;
    // cout << E.a << endl;
    // cout << E.b << endl;
    // cout << p << endl;
    // cout << W << endl;
    // cout << WW << endl;
    // EllipticCurvePoint WWW = WW + W;
    // cout << WWW << endl;
    // EllipticCurvePoint WW2 =  WWW - W;
    // cout << WW << endl;
    // cout << WW2 << endl;
    // EllipticCurvePoint WWWW = W * 4;
    // cout << WWWW << endl;

    // cout << (mpz_class(3 ) >> 1) << endl;
    // if (mpz_class(3) >> 1 == 1){
    //     cout << "Dfsdsfdssdfsfdf" << endl;
    //     cout << mpz_sizeinbase(mpz_class(4).get_mpz_t(), 2) << endl;
    //     cout << (mpz_class(2) & 1) << endl;
    // }
    // char jian[10000];
    // cout << mpz_class(3).get_str(16) << endl;
    // cout << mpz_class(5).get_str(16) + mpz_class(65).get_str(16) << endl;
    // string adfdsfs =  mpz_class(3).get_str(16);
    // cout << G.Out_Hex_xy() << endl;
    // cout << sha256(G.Out_Hex_xy()) << endl;
    // cout << (mpz_class(2) ^ mpz_class(3)) << endl;
    return 0;
}


