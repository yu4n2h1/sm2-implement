#ifndef SHA256_H
#define SHA256_H

#include <iostream>
#include <iomanip>
#include <array>
#include <openssl/sha.h>
#include <sstream>

std::string sha256(const std::string& input);

#endif // SHA256_H