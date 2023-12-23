#ifndef SIGN_H
#define SIGN_H
#include "sm2.hpp"
#include <iostream>
#include <gmpxx.h>
#include <random>

void sign(std::string message, EllipticCurvePoint &RS, std::string ID_A);

#endif // SIGN_H