#include <gmpxx.h>

#include <iostream>
#include "finiteField.hpp"


FiniteField::FiniteField() {
    this->modulus = mpz_class(0);
}

FiniteField::FiniteField(mpz_class modulus) {
    this->modulus = modulus;
}

std::ostream &operator<<(std::ostream &out, FiniteField &f)
{
    out << "FiniteField: Ring of integers modulo " << f.modulus;
    return out;
}
