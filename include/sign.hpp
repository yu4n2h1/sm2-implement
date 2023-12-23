#ifndef SIGN_H
#define SIGN_H
#include "sm2.hpp"
#include <iostream>
#include <gmpxx.h>
#include <random>

void sign(std::string message, std::string ID_A, FiniteFieldElement &r, FiniteFieldElement &s);

#endif // SIGN_H