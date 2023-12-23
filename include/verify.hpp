#ifndef VERIFY_H
#define VERIFY_H
#include "sm2.hpp"
#include <iostream>
#include <gmpxx.h>
#include <random>

bool verify(std::string message, std::string ID_A, FiniteFieldElement &r, FiniteFieldElement &s);

#endif // VERIFY_H