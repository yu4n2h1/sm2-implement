#include "sha256.hpp"



std::string sha256(const std::string& input) {
    std::array<unsigned char, SHA256_DIGEST_LENGTH> hash;

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.length());
    SHA256_Final(hash.data(), &sha256);

    // 将哈希值转换为十六进制字符串
    std::ostringstream hashString;
    for (const auto& byte : hash) {
        hashString << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }

    return hashString.str();
}



