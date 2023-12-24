#include <iostream>
#include <gmpxx.h>
#include <random>
#include "sm2.hpp"
#include "encrypt.hpp"
#include "sign.hpp"
#include "verify.hpp"

using namespace std;
string message;
string ID_A;
FiniteFieldElement r;
FiniteFieldElement s;

int main()
{
    message = "nieshangqing_sign";
    ID_A = "414C494345313233405941484F4F2E434F4D";
    // string enc_msg = encrypt(message, G, P);
    // cout << message << endl << enc_msg << endl;
    sign(message, ID_A, r, s);
    if (verify(message, ID_A, r, s))
    {
        cout << "Verification Successful" << endl;
    }
    else
    {
        cout << "Verification Failed" << endl;
    }
    return 0;
}