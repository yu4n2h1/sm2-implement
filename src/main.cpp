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

static void printUsage(const char *prog)
{
    cout << "Usage: " << prog << " [options] [command]\n"
         << "Commands:\n"
         << "  sign            perform signature generation (default)\n"
         << "  verify          perform signature verification only\n"
         << "Options:\n"
         << "  -h, --help      show this help message\n"
         << "  --message <m>   message to sign/verify (hex or ascii)\n"
         << "  --id <ID_A>     user ID in hex\n";
}

int main(int argc, char *argv[])
{
    // default values
    bool doSign = true;
    bool doVerify = true;
    string msg = "nieshangqing_sign";
    string id = "414C494345313233405941484F4F2E434F4D";

    // parse arguments
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            printUsage(argv[0]);
            return 0;
        } else if (arg == "sign") {
            doSign = true;
            doVerify = false;
        } else if (arg == "verify") {
            doVerify = true;
            doSign = false;
        } else if (arg == "--message") {
            if (i + 1 < argc) {
                msg = argv[++i];
            } else {
                cerr << "Error: --message requires an argument\n";
                printUsage(argv[0]);
                return 1;
            }
        } else if (arg == "--id") {
            if (i + 1 < argc) {
                id = argv[++i];
            } else {
                cerr << "Error: --id requires an argument\n";
                printUsage(argv[0]);
                return 1;
            }
        } else {
            cerr << "Unknown option or command: " << arg << '\n';
            printUsage(argv[0]);
            return 1;
        }
    }

    message = msg;
    ID_A = id;

    if (doSign) {
        sign(message, ID_A, r, s);
    }

    if (doVerify) {
        bool ok = verify(message, ID_A, r, s);
        if (doSign) {
            // signed above
            cout << (ok ? "Verification Successful" : "Verification Failed") << endl;
        } else {
            // only verification, assume r/s provided externally?
            cout << (ok ? "Verification Successful" : "Verification Failed") << endl;
        }
    }

    return 0;
}