#include <iostream>

std::ostream &operator<<(std::ostream &out, FiniteField &f)
{
    out << "FiniteField: Ring of integers modulo " << f.modulus
    return out;
};

class FiniteFieldElement:FiniteField {
    private:
        mpz_class value;
    public:
        FiniteFieldElement(mpz_class modulus, mpz_class value):FiniteField(modulus) {
            this->value = value;
        }


        FiniteFieldElement operator+(const FiniteFieldElement& other) const {
            mpz_class res = (this->value + other.value) % this->modulus;
            return FiniteFieldElement(this->modulus, res);
        }

        FiniteFieldElement operator-(const FiniteFieldElement& other) const {
            mpz_class res = (this->value - other.value) % this->modulus;
            return FiniteFieldElement(this->modulus, res);
        }

        // FiniteFieldElement operator*(const FiniteFieldElement& other) const {
        //     mpz_class res = (this->value - other.value) % this->modulus;
        //     return FiniteFieldElement(this->modulus.get_mpz_t(), res);
        // }

        // FiniteFieldElement operator/(const FiniteFieldElement& other) const {
        //     mpz_class res;
        //     mpz_invert(res.get_mpz_t(), this->modulus.get_mpz_t(), other)

        //     return FiniteFieldElement(this->modulus, y);
        // }
};


