#include <iostream>
#include <gmpxx.h>
#include <random>
#include "sm2.hpp"
#include "sign.hpp"
#include "verify.hpp"

using namespace std;
string message;
string ID_A;

FiniteFieldElement r;
FiniteFieldElement s;


int main() {
    message = "nieshangqing_sign";
    ID_A = "414C494345313233405941484F4F2E434F4D";
    sign(message, ID_A, r, s);
    cout << r << endl << s << endl;
    return 0;
}