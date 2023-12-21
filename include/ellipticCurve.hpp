#ifndef ELLIPTICCURVE_H
#define ELLIPTICCURVE_H
#include <iostream>
#include <gmpxx.h>
#include <finiteFieldElement.hpp>

class EllipticCurve {
    public:
        FiniteFieldElement a,b;
        mpz_class n;
        // std::pair<FiniteFieldElement, FiniteFieldElement> point;
        EllipticCurve();
        EllipticCurve(FiniteFieldElement a,FiniteFieldElement b,mpz_class n);
        friend std::ostream& operator<<(std::ostream& out, EllipticCurve& E);
};
#endif