#include <openssl/sha.h>
#include <openssl/evp.h>
// #include <openssl/sm3.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

std::vector<unsigned char> hexToBytes(const std::string& hexString) {
    std::vector<unsigned char> bytes;
    for (std::size_t i = 0; i < hexString.length(); i += 2) {
        std::string byteString = hexString.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(std::stoi(byteString, nullptr, 16));
        bytes.push_back(byte);
    }
    return bytes;
}

std::string sm3(const std::string& oinput) {
    std::vector<unsigned char> bytes = hexToBytes(oinput);
    std::string input(bytes.begin(), bytes.end());
    EVP_MD_CTX* mdctx;
    const EVP_MD* md;
    std::vector<unsigned char> digest(EVP_MAX_MD_SIZE);
    unsigned int digestLen;

    OpenSSL_add_all_digests();
    md = EVP_sm3();
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, nullptr);
    EVP_DigestUpdate(mdctx, input.c_str(), input.length());
    EVP_DigestFinal_ex(mdctx, digest.data(), &digestLen);
    EVP_MD_CTX_free(mdctx);

    std::ostringstream hashString;
    for (const auto& byte : digest) {
        hashString << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }

    return hashString.str().substr(0,64);
}