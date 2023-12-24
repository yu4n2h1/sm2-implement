
#ifndef SM3_SM3_H
#define SM3_SM3_H

#include <cstdint>
#include <vector>
#include <iostream>
typedef uint32_t Word;
typedef uint8_t Byte;

// Byte HextoByte(std::string input);


std::string sm3(const std::string& oinput);
#endif //SM3_SM3_H