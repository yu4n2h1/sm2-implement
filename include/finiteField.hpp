#ifndef FINITEFIELD_H
#define FINITEFIELD_H
#include <gmpxx.h>
#include "finiteFieldElement.hpp"

class FiniteField {
    public:
        mpz_class modulus;
        FiniteField ();
        FiniteField (mpz_class modulus);

        // operator() 这种重载只能在类内完成
        FiniteFieldElement operator() (const mpz_class& value) {
            return FiniteFieldElement(this->modulus, value);
        }

        friend std::ostream& operator<<(std::ostream& out, FiniteField& f);
        
};
#endif