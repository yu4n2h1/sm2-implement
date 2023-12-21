#include <iostream>
#include "finiteField.hpp"
#include "finiteFieldElement.hpp"
#include "ellipticCurve.hpp"
#include "ellipticCurvePoint.hpp"

using namespace std;

int main() {

    auto F = FiniteField(17);
    cout << F << endl;
    EllipticCurve();
    mpz_class p = mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFF", 16);
    mpz_class a = mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFC", 16);
    mpz_class b = mpz_class("28E9FA9E9D9F5E344D5A9E4BCF6509A7F39789F515AB8F92DDBCBD414D940E93", 16);
    mpz_class n = mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFF7203DF6B21C6052B53BBF40939D54123", 16);
    mpz_class x = mpz_class("32C4AE2C1F1981195F9904466A39C9948FE30BBFF2660BE1715A4589334C74C7", 16);
    mpz_class y = mpz_class("BC3736A2F4F6779C59BDCEE36B692153D0A9877CC62A474002DF32E52139F0A0", 16);
    F = FiniteField(p);

    FiniteFieldElement aa, bb ,cc, xx, yy;
    aa = F(a);
    bb = F(b);
    xx = F(x);
    yy = F(y);
    cout << (xx == x) << endl;
    EllipticCurve E = EllipticCurve(aa,bb,n);
    cout << E.a << endl;
    cout << E.b << endl;
    cout << E.n << endl;
    cout << E << endl;
    EllipticCurvePoint EE = EllipticCurvePoint(E, xx, yy);
    EllipticCurvePoint O = EllipticCurvePoint(E, FiniteFieldElement(p,p),FiniteFieldElement(p,p));
    // cout << EE + O << endl;
    cout << O << endl;
    cout << EE << endl;
    EllipticCurvePoint W =  EE + O;
    cout << W << endl;
    FiniteFieldElement ww =  aa*3;
    cout <<ww << endl;
    aa*mpz_class(3);
    EllipticCurvePoint WW = W + W;
    cout << E.a << endl;
    cout << E.b << endl;
    cout << p << endl;
    cout << W << endl;
    cout << WW << endl;
    EllipticCurvePoint WWW = WW + W;
    cout << WWW << endl;
    EllipticCurvePoint WW2 =  WWW - W;
    cout << WW << endl;
    cout << WW2 << endl;
    EllipticCurvePoint WWWW = W * 4;
    cout << WWWW << endl;
    return 0;
}