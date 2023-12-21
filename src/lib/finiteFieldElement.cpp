#include "finiteFieldElement.hpp"
#include <gmpxx.h>
#include "finiteField.hpp"
#include <iostream>

FiniteFieldElement::FiniteFieldElement() {
    this->modulus = mpz_class(0);
    this->value = mpz_class(0);

}

FiniteFieldElement::FiniteFieldElement(mpz_class modulus, mpz_class value) {
    this->modulus = modulus;
    this->value = value;
}

FiniteFieldElement operator+(const FiniteFieldElement& a, const FiniteFieldElement& b) {
    if (a.modulus != b.modulus) {
        throw std::logic_error("unsport modulus different operation");
    }
    FiniteFieldElement res(a.modulus, (a.value + b.value) % a.modulus);
    return res;
}

FiniteFieldElement operator-(const FiniteFieldElement& a, const FiniteFieldElement& b) {
    if (a.modulus != b.modulus) {
        throw std::logic_error("unsport modulus different operation");
    }
    FiniteFieldElement res(a.modulus, (a.value - b.value + a.modulus) % a.modulus);
    return res;
}

FiniteFieldElement operator*(const FiniteFieldElement& a, const FiniteFieldElement& b) {
    if (a.modulus != b.modulus) {
        throw std::logic_error("unsport modulus different operation");
    }
    FiniteFieldElement res(a.modulus, (a.value * b.value) % a.modulus);
    return res;
}

FiniteFieldElement operator*(const FiniteFieldElement& a, const int& b) {
    FiniteFieldElement res(a.modulus, (a.value * b) % a.modulus);
    return res;
}

FiniteFieldElement operator*(const FiniteFieldElement& a, const mpz_class& b) {

    FiniteFieldElement res(a.modulus, (a.value * b) % a.modulus);
    return res;
}

FiniteFieldElement operator/(const FiniteFieldElement& a, const FiniteFieldElement& b) {
    if (a.modulus != b.modulus) {
        throw std::logic_error("unsport modulus different operation");
    }
    mpz_class res;
    mpz_invert(res.get_mpz_t(),b.value.get_mpz_t(),b.modulus.get_mpz_t());
    res = (res * a.value) % a.modulus;
    return FiniteFieldElement(a.modulus, res);
}

std::ostream& operator<<(std::ostream& out, FiniteFieldElement& f) {
    out << f.value << " Mod " << f.modulus;
    return out;
}

bool operator==(const FiniteFieldElement & a, const mpz_class & t)
{
    if (a.value == t) return true;
    return false;
}
bool operator==(const FiniteFieldElement& a, const FiniteFieldElement& b)
{
    if (a.value == b.value && a.modulus == b.modulus) return true;
    return false;
}