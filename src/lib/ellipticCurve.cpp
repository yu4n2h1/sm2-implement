#include <iostream>
#include "finiteFieldElement.hpp"
#include "ellipticCurve.hpp"
#include <gmpxx.h>

EllipticCurve::EllipticCurve() {
    this->a = FiniteFieldElement();
    this->b = FiniteFieldElement();
    this->n = mpz_class(0);
    
}

EllipticCurve::EllipticCurve(FiniteFieldElement a,FiniteFieldElement b,mpz_class n) {
    this->a = a;
    this->b = b;
    this->n = n;
}

std::ostream& operator<<(std::ostream& out, EllipticCurve& E) {
    out << "Elliptic Curve defined by y^2 = x^3 + " << E.a.value << "*x + " << E.b.value << " over Finite Field of size " << E.a.modulus;
    return out;
}   