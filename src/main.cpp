#include <iostream>
#include <gmpxx.h>
#include <random>
#include "sm2.hpp"
#include "sign.hpp"
#include "verify.hpp"

using namespace std;
string message;

EllipticCurvePoint RS = EllipticCurvePoint();s


int main() {
    message = "nieshangqing_sign";
    sign(message, RS, "414C494345313233405941484F4F2E434F4D");
    cout << RS << endl;
    return 0;
}