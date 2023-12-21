#ifndef FINITEFIELDELEMENT_H
#define FINITEFIELDELEMENT_H
#include <gmpxx.h>

class FiniteFieldElement
{
public:
    mpz_class value;
    mpz_class modulus;
    FiniteFieldElement();
    FiniteFieldElement(mpz_class modulus, mpz_class value);

    friend FiniteFieldElement operator+(const FiniteFieldElement& a, const FiniteFieldElement& b);
    friend FiniteFieldElement operator-(const FiniteFieldElement& a, const FiniteFieldElement& b);
    friend FiniteFieldElement operator*(const FiniteFieldElement& a, const FiniteFieldElement& b);
    friend FiniteFieldElement operator*(const FiniteFieldElement& a, const int& b);
    friend FiniteFieldElement operator*(const FiniteFieldElement& a, const mpz_class& b);
    friend FiniteFieldElement operator/(const FiniteFieldElement& a, const FiniteFieldElement& b);
    friend bool operator==(const FiniteFieldElement& a, const mpz_class &t);
    friend bool operator==(const FiniteFieldElement& a, const FiniteFieldElement &t);
    friend std::ostream& operator<<(std::ostream& out, FiniteFieldElement& f);

};

#endif