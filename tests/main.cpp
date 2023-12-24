#include <iostream>
#include "finiteField.hpp"
#include "finiteFieldElement.hpp"
#include "ellipticCurve.hpp"
#include "ellipticCurvePoint.hpp"
#include "sm2.hpp"
#include "encrypt.hpp"
#include "typeinfo"
#include "sha256.hpp"
#include "encrypt.hpp"
#include "sm3.hpp"
#include "decrypt.hpp"
using namespace std;


// int main() {
//     std::string input = "48656c6c6f2c20776f726c6421"; // 十六进制字符串
    
//     // std::vector<unsigned char> bytes = hexToBytes(hexString);
//     // std::string input(bytes.begin(), bytes.end()); // 将字节转换为字符串

//     std::string hash = sm3(input);

//     std::cout << "SM3 Hash: " << hash << std::endl;

//     return 0;
// }

// uint8_t* HextoByte(std::string input) {
//     uint8_t resww[input.length()/2];
//     for(int i=0;i< input.length(); i+= 2) {
//         resww[i/2] = (int)(input.at(i) << 8) + (int)(input.at(i+1));
//     }
//     return resww;
// }
int main() {

    EllipticCurve();
    mpz_class p = mpz_class("BDB6F4FE3E8B1D9E0DA8C0D46F4C318CEFE4AFE3B6B8551F", 16);
    mpz_class a = mpz_class("BB8E5E8FBC115E139FE6A814FE48AAA6F0ADA1AA5DF91985", 16);
    mpz_class b = mpz_class("1854BEBDC31B21B7AEFC80AB0ECD10D5B1B3308E6DBF11C1", 16);
    mpz_class n = mpz_class("BDB6F4FE3E8B1D9E0DA8C0D40FC962195DFAE76F56564677", 16);
    mpz_class x = mpz_class("4AD5F7048DE709AD51236DE65E4D4B482C836DC6E4106640", 16);
    mpz_class y = mpz_class("02BB3A02D4AAADACAE24817A4CA3A1B014B5270432DB27D2", 16);
    auto F = FiniteField(p);
    FiniteFieldElement aa, bb ,cc, xx, yy, dB;
    aa = F(a);
    bb = F(b);
    xx = F(x);
    yy = F(y);
    EllipticCurve E = EllipticCurve(aa,bb,n);
    EllipticCurvePoint G = EllipticCurvePoint(E, xx ,yy);
    string M = string("656E6372797074696F6E207374616E64617264");
    // 私钥
    dB = F(mpz_class("58892B807074F53FBF67288A1DFAA1AC313455FE60355AFD", 16));
    // 又私钥产生公钥
    EllipticCurvePoint PB = G * dB;
    


    cout << "encrypt:" << encrypt(M, G, PB) << endl;
    mpz_class k = mpz_class("384F30353073AEECE7A1654330A96204D37982A3E15B2CB5",16);
    EllipticCurvePoint C1 = G*k;
    string C2 = string("610567DBD4854F51F4F00ADCC01CFE90B1FB1C");
    
    cout << "decrypt: " << decrypt(dB, C1, C2) << endl;
    
    return 0;
}


