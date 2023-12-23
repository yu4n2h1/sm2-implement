#ifndef SIGN_H
#define SIGN_H
#include "sm2.hpp"
#include <iostream>
#include <gmpxx.h>
#include <random>

void sign(std::string message, std::string ID_A, FiniteFieldElement &r, FiniteFieldElement &s);

std::vector<unsigned char> hexStringToBytes(const std::string &hexString);

std::string calculate_ENTL_A(const std::string &ID_A_hex);

#endif // SIGN_H