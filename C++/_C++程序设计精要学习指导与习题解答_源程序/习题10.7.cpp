#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <exception>
using namespace std;
class  MEMEXCEPTION : public exception {
public:
    const char* what( ) const throw( ) { return "Memory not enough!"; }
};
class  DIFEXCEPTION : public exception {
public:
    const char* what( ) const throw( ) { return "Added matrix differ in size!"; }
};
class  SUBEXCEPTION : public exception {
public:
    const char* what( ) const throw( ) { return "Subscription of matrix overflowed!"; }
};
class  MATEXCEPTION : public exception {
public:
    const char* what( ) const throw( ) { return "Multiplied matrix not match!"; }
};
class ARRAY {
    int*  a;
    int   r, c;
public:
    ARRAY(int x, int y) noexcept(false);
    ARRAY(const ARRAY&) noexcept(false);
    ~ARRAY( )noexcept;
    int& operator( )(int x, int y)noexcept(false);
    ARRAY& operator=(const ARRAY&)noexcept(false);
    ARRAY operator+(const ARRAY&) const noexcept(false);
    ARRAY operator-(const ARRAY&) const noexcept(false);
    ARRAY operator*(const ARRAY&) const noexcept(false);
    ARRAY operator!( ) const noexcept(noexcept(ARRAY::ARRAY(c, r)));
};
ARRAY::ARRAY(int x, int y) noexcept(false) {
    if (!(a = new int[x * y])) throw MEMEXCEPTION( );
    r = x; c = y;
}
ARRAY::ARRAY(const ARRAY& m) noexcept(false) {
    if (!(a = new int[m.r * m.c])) throw MEMEXCEPTION( );
    r = m.r; c = m.c;
    for (int h = 0; h < r; h++)
        for (int k = 0; k < c; k++)
            a[h * c + k] = m.a[h * c + k];
}
ARRAY::~ARRAY( ) noexcept { if (a) { delete a; a = 0; r = c = 0; } }
int& ARRAY::operator( )(int x, int y) noexcept(false) {
    if (x < 0 || x >= r || y < 0 || y >= c) throw SUBEXCEPTION( );
    return a[x * c + y];
}
ARRAY& ARRAY::operator=(const ARRAY& m) noexcept(false) {
    if(this==&m) return *this;
    if(a) delete a;
    if (!(a = new int[m.r * m.c])) throw MEMEXCEPTION( );
    r = m.r; c = m.c;
    for (int h = 0; h < r; h++)
        for (int k = 0; k < c; k++)
            a[h * c + k] = m.a[h * c + k];
    return *this;
}
ARRAY ARRAY::operator+(const ARRAY& m)const noexcept(false) {
    if (r != m.r || c != m.c) throw DIFEXCEPTION( );
    ARRAY v(m);
    for (int h = 0; h < r; h++)
        for (int k = 0; k < c; k++)
            v.a[h * c + k] += a[h * c + k];
    return v;
}
ARRAY ARRAY::operator-(const ARRAY& m)const noexcept(false) {
    if (r != m.r || c != m.c) throw DIFEXCEPTION( );
    ARRAY v(*this);
    for (int h = 0; h < r; h++)
        for (int k = 0; k < c; k++)
            v.a[h * c + k] -= m.a[h * c + k];
    return v;
}
ARRAY ARRAY::operator*(const ARRAY& m)const noexcept(false) {
    if (c != m.r) throw MATEXCEPTION( );
    ARRAY v(r, m.c);
    for (int h = 0; h < r; h++)
        for (int k = 0; k < m.c; k++)
            for (int p = 0; p < c; p++)
                v.a[h * m.c + k] += a[h * c + p] * m.a[p * m.c + k];
    return v;
}
ARRAY ARRAY::operator!( )const noexcept(noexcept(ARRAY::ARRAY(c,r))) {
    ARRAY v(c, r);
    for (int h = 0; h < r; h++)
        for (int k = 0; k < c; k++)
            v.a[h * r + k] -= a[h * c + k];
    return v;
}
void main( ) {
    try {
        ARRAY  a(10, 20), b(20, 30), c(10, 20), d(1, 1);
        a(1, 2) = 3; b(2, 4) = 6; c(1, 2) = 10;
        d = a * b;
        d = a + c;
        d = !a;
    }
    catch (DIFEXCEPTION  d) {
        printf(d.what( ));
    }
    catch (MATEXCEPTION  m) {
        printf(m.what( ));
    }
    catch (MEMEXCEPTION  m) {
        printf(m.what( ));
    }
    catch (SUBEXCEPTION  s) {
        printf(s.what( ));
    }
}
