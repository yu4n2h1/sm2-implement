#ifndef VERIFY_H
#define VERIFY_H
#include "sm2.hpp"
#include <iostream>
#include <gmpxx.h>
#include <random>

bool verify(std::string message, FiniteFieldElement r, FiniteFieldElement s, mpz_class pub_key);

#endif // VERIFY_H