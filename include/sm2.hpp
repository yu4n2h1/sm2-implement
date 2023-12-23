#ifndef SM2_H
#define SM2_H

#include "ellipticCurve.hpp"
#include "ellipticCurvePoint.hpp"
#include "finiteField.hpp"
#include "finiteFieldElement.hpp"
#include "gmpxx.h"

extern FiniteField F;

extern EllipticCurvePoint G;
extern EllipticCurve SM2;

extern EllipticCurvePoint P;
extern FiniteFieldElement d_A;

#endif // SM2_H