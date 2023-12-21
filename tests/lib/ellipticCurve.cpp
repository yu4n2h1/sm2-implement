#include <iostream>
#include <gmpxx.h>
#include <string>


class SM2_EllipticCurve {
    public:
        mpz_class p = mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFF", 16);
        mpz_class a = mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFC", 16);
        mpz_class b = mpz_class("28E9FA9E9D9F5E344D5A9E4BCF6509A7F39789F515AB8F92DDBCBD414D940E93", 16);
        mpz_class n = mpz_class("FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFF7203DF6B21C6052B53BBF40939D54123", 16);
        std::pair<mpz_class,mpz_class> point(mpz_class("32C4AE2C1F1981195F9904466A39C9948FE30BBFF2660BE1715A4589334C74C7", 16), mpz_class("BC3736A2F4F6779C59BDCEE36B692153D0A9877CC62A474002DF32E52139F0A0", 16));
};


// 椭圆曲线
class EllipticCurve {
    private:
        mpz_class p,a,b,n;

    public:
        EllipticCurve(mpz_class p,mpz_class a,mpz_class b,mpz_class n) {
            this->p = p;
            this->a = a;
            this->b = b;
            this->n = n;
            
        }
    
        ~EllipticCurve() {
            delete this->a;
            delete this->b;
            delete this->p;
            delete this->n;
        }


}

// 椭圆曲线上的点
class EllipticCurve_point:EllipticCurve 
{
    private:
        // 实际存储椭圆曲线点的位置
    public:
        std::pair<mpz_class,mpz_class> point;
        EllipticCurve_point(std::pair<mpz_class,mpz_class> point) {
            this->point = point;
        }
        EllipticCurve_point(mpz_class x,mpz_class y) {
            this->point.first = x;
            this->point.second = y;
        }
        EllipticCurve_point(mpz_class p, mpz_class a,mpz_class b, mpz_class n, std::pair<mpz_class,mpz_class> point):EllipticCurve(p,z,b,n){
            this->point = point;
        }
        EllipticCurve_point(mpz_class p, mpz_class a,mpz_class b, mpz_class n, mpz_class x, mpz_class y):EllipticCurve(p,z,b,n){
            this->point.first = x;
            this->point.second = y;
        }
        

        ~EllipticCurve_point() {
            delete this->point;
        }
        EllipticCurve_point operator+ (const EllipticCurve &a) {
            this->point.first 
        }

};

EllipticCurve::EllipticCurve(mpz_class p,mpz_class a,mpz_class b,mpz_class n)
{
    this->p = p;
    
}

EllipticCurve::~EllipticCurve()
{
}






