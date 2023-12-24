#include <iostream>
#include <gmpxx.h>
#include <random>
#include "sign.hpp"
#include <vector>
#include <iomanip>
#include "sha256.hpp"

/*
// SM2曲线所在的有限域
mpz_class p = mpz_class("8542D69E4C044F18E8B92435BF6FF7DE457283915C45517D722EDB8B08F1DFC3", 16);
FiniteField F = FiniteField(p);

// SM2的参数
FiniteFieldElement a = F(mpz_class("787968B4FA32C3FD2417842E73BBFEFF2F3C848B6831D7E0EC65228B3937E498", 16));
FiniteFieldElement b = F(mpz_class("63E4C6D3B23B0C849CF84241484BFE48F61D59A5B16BA06E6E12D1DA27C5249A", 16));
mpz_class n = mpz_class("8542D69E4C044F18E8B92435BF6FF7DD297720630485628D5AE74EE7C32E79B7", 16);
FiniteFieldElement G_x = F(mpz_class("421DEBD61B62EAB6746434EBC3CC315E32220B3BADD50BDC4C4E6C147FEDD43D", 16));
FiniteFieldElement G_y = F(mpz_class("0680512BCBB42C07D47349D2153B70C4E5D7FDFCBFA36EA1A85841B9E46E09A2", 16));

// 椭圆曲线方程为: y^2 = x^3 + ax + b
EllipticCurve SM2 = EllipticCurve(a, b, n);
EllipticCurvePoint G = EllipticCurvePoint(SM2, G_x, G_y);

// 公钥
FiniteFieldElement P_x = F(mpz_class("0AE4C7798AA0F119471BEE11825BE46202BB79E2A5844495E97C04FF4DF2548A", 16));
FiniteFieldElement P_y = F(mpz_class("7C0240F88F1CD4E16352A73C17B7F16F07353E53A176D684A9FE0C6BB798E857", 16));
EllipticCurvePoint P = EllipticCurvePoint(SM2, P_x, P_y);

// 私钥
FiniteFieldElement d_A = F(mpz_class("128B2FA8BD433C6C068C8D803DFF79792A519A55171B1B650C23661D15897263", 16));

// 用户标识符
FiniteFieldElement ID_A = F(mpz_class("414C494345313233405941484F4F2E434F4D", 16))

//

*/

using namespace std;

// 将十六进制字符串转换为字节序列的函数定义
vector<unsigned char> hexStringToBytes(const string &hexString)
{
    vector<unsigned char> bytes;
    for (size_t i = 0; i < hexString.length(); i += 2)
    {
        unsigned char byte = static_cast<unsigned char>(stoi(hexString.substr(i, 2), nullptr, 16));
        bytes.push_back(byte);
    }
    return bytes;
}

// 将用户标识符 ID_A 转换为字节序列
string calculate_ENTL_A(const string &ID_A_hex)
{
    vector<unsigned char> ID_A_bytes = hexStringToBytes(ID_A_hex);

    // 计算 entlen_A
    int entlen_A = ID_A_bytes.size() * 8; // 字节长度转换为比特长度

    // 构造 ENTL_A
    unsigned char ENTL_A[2];
    ENTL_A[0] = static_cast<unsigned char>((entlen_A >> 8) & 0xFF);
    ENTL_A[1] = static_cast<unsigned char>(entlen_A & 0xFF);

    // 将 ENTL_A 转换为字符串表示
    stringstream ss;
    ss << hex << setw(4) << setfill('0') << (int(ENTL_A[0]) << 8 | ENTL_A[1]);

    return ss.str();
}

// 产生随机数 k在 [1, n-1]
mpz_class generateRandomK(const mpz_class &n)
{
    // 初始化 GMP 随机数生成器
    gmp_randclass rng(gmp_randinit_default);

    // 设置种子
    rng.seed(time(NULL));

    // 生成随机数 k，范围在 [1, n-1]
    mpz_class k;
    do
    {
        k = rng.get_z_range(n - 1) + 1;
    } while (k <= 0);

    return k;
}

void sign(string message, string ID_A, FiniteFieldElement &r, FiniteFieldElement &s)
{
    /*
    1. 设置 M*=Z_A||M 并计算 e = H(M*)
     Z_A = H(ENTL_A || ID_A || a || b || G_x || G_y || P_x || P_y)
    */
    string ENTL_A = calculate_ENTL_A(ID_A);
    string a_string = SM2.a.value.get_str(16);
    string b_string = SM2.b.value.get_str(16);
    string G_x_string = G.a.value.get_str(16);
    string G_y_string = G.b.value.get_str(16);
    string P_x_string = P.a.value.get_str(16);
    string P_y_string = P.b.value.get_str(16);
    string Z_A_pre_message = ENTL_A + ID_A + a_string + b_string + G_x_string + G_y_string + P_x_string + P_y_string;
    string Z_A = sha256(Z_A_pre_message);
    string Mmessage = Z_A + message;
    cout << Mmessage << endl;
    string e_msg = sha256(Mmessage);
    FiniteFieldElement e = F(mpz_class(e_msg, 16));
    cout << e << endl;
    /*
    2. 产生随机数k∈[1, n-1]
    */
step2:
    mpz_class n = G.n;
    mpz_class k = generateRandomK(n);
    cout << k << endl;
    /*
    3. 计算椭圆曲线点G1=k ⋅ G= (x1, y1)
    */
    EllipticCurvePoint G1 = G * k;
    cout << G1.a << endl;
    cout << G1.b << endl;
    /*
    4. 计算r=(e+x1) mod n，若r=0或r+k=n则返回 2.
    */
    r = (e + G1.a);
    cout << r << endl;
    FiniteFieldElement k_f = F(k);
    if (r == F(mpz_class(0)) || r + k_f == F(n))
    {
        goto step2;
    }
    /*
    5. 计算s=(1+ dA)^(-1)·(k − r·dA)mod n，若s=0则返回 2.
    */
    FiniteFieldElement one = F(mpz_class(1));
    s = one / (one + d_A) * (k_f - d_A * r);
    cout << s << endl;
    if (s == F(mpz_class(0)))
    {
        goto step2;
    }
    /*
    6. 返回数字签名 (r,s)
    */
    cout << r << endl;
    cout << s << endl;
    return;
}
