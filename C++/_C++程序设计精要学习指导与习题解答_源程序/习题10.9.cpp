#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <exception>
using namespace std;
class  DIVEXCEPTION : public exception {
public:
    const char* what( ) const throw( ) { return "Divided by zero!"; }
};
class  COMPLEX { 				//real, imag分别为复数的实部和虚部，
    double   real, imag; 			//若x=3+5i，则x.real=3，x.imag=5
public:
    COMPLEX(double r=0, double i=0) noexcept(true);
    COMPLEX neg ( ) const noexcept(true);	//将实部和虚部的符号求反
    COMPLEX add (const COMPLEX& c) const noexcept(true);
    COMPLEX sub (const COMPLEX& c) const noexcept(true);
    COMPLEX mul (const COMPLEX& c) const noexcept(true);
    COMPLEX div (const COMPLEX& c) const noexcept(false);
};
COMPLEX::COMPLEX(double r, double i) noexcept(true) { real = r;  imag = i; }
COMPLEX COMPLEX::neg( ) const noexcept(true)
{ return COMPLEX(-real, -imag); }
COMPLEX COMPLEX::add (const COMPLEX& c) const noexcept(true)
{   return COMPLEX(real + c.real, imag + c.imag);  }
COMPLEX COMPLEX::sub (const COMPLEX& c) const noexcept(true)
{   return COMPLEX(real - c.real, imag - c.imag);   }
COMPLEX COMPLEX::mul (const COMPLEX& c) const noexcept(true)
{   return COMPLEX(real *c.real-imag*c.imag, imag*c.real+c.imag*real); }
COMPLEX COMPLEX::div (const COMPLEX& c) const noexcept(false) {
    double d = c.real * c.real + c.imag * c.imag;
    if (d == 0) throw DIVEXCEPTION( );
    return COMPLEX((real*c.real+imag*c.imag)/d, (imag*c.real-c.imag*real)/d);
}
void main(void) {
    try {
        COMPLEX  a, b(4), c(6, 7), d;
        d = a.neg( );
        d = a.sub(b.div(c));
    }
    catch (DIVEXCEPTION  m) {
        printf(m.what( ));
    }
}
