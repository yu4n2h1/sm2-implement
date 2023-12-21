#ifndef ELLIPTICCURVEPOINT_H
#define ELLIPTICCURVEPOINT_H
#include <iostream>
#include "ellipticCurve.hpp"
#include "finiteFieldElement.hpp"
#include <iostream>

class EllipticCurvePoint{
    public:
        FiniteFieldElement a,b;
        mpz_class n;
        std::pair<FiniteFieldElement,FiniteFieldElement> point;

        EllipticCurvePoint();
        EllipticCurvePoint(EllipticCurve E, FiniteFieldElement x, FiniteFieldElement y);
        EllipticCurvePoint(EllipticCurve E, std::pair<FiniteFieldElement,FiniteFieldElement> point);

        friend EllipticCurvePoint operator+(const EllipticCurvePoint& a, EllipticCurvePoint& b);
        friend bool operator==(const EllipticCurvePoint& a, EllipticCurvePoint& b);
        friend std::ostream& operator<<(std::ostream& out, EllipticCurvePoint &E);
        friend EllipticCurvePoint operator-(const EllipticCurvePoint& a, const EllipticCurvePoint& b);
        friend EllipticCurvePoint operator*(const EllipticCurvePoint& a, const int& b);
};

#endif