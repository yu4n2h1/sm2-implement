#ifndef DECRYPT_H
#define DECRYPT_H
#include <iostream>
#include "finiteFieldElement.hpp"
#include "ellipticCurvePoint.hpp"

std::string decrypt(FiniteFieldElement d, EllipticCurvePoint C1, std::string C);

#endif