#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <exception>
using namespace std;
class DEC {
    char* n;   //存放十进制数
public:
    DEC(long);
    DEC(const char* d);
    DEC(DEC const& d);
    virtual ~DEC( );
    virtual DEC operator-( )const;
    virtual DEC operator+(const DEC& d) const;
    virtual DEC operator-(const DEC& d) const;
    virtual DEC operator*(const DEC& d) const;
    virtual DEC operator/(const DEC& d) const;
    virtual DEC operator%(const DEC& d)const;
    virtual int operator>(const DEC& d)const;
    virtual int operator<(const DEC& d)const;
    virtual int operator==(const DEC& d)const;
    virtual DEC& operator=(const DEC& d);
    virtual DEC operator++(int);
    virtual DEC operator--(int);
    virtual DEC& operator--( );
    virtual DEC& operator++( );
    virtual operator const char* ( )const;
};
DEC::DEC(long m) {
    char s[100];
    _ltoa(m, s, 10);
    DEC::n = new char[strlen(s) + 1];
    if (DEC::n == nullptr) throw "memory not enough!";
    strcpy(DEC::n, s);
}
DEC::DEC(const char* n) :n(new char[strlen(n) + 1]) {
    if (DEC::n == nullptr) throw "memory not enough!";
    if (n[0] == '+') strcpy(DEC::n, n + 1);
    else {
        if (n[0] == '-' && n[1] == '0') strcpy(DEC::n, n + 1);
        else strcpy(DEC::n, n);
    }
}
DEC::DEC(const DEC& d) : n(new char[strlen(d.n) + 1]) {
    if (DEC::n == nullptr) throw "memory not enough!";
    strcpy(n, d.n);
}
DEC::~DEC( ) { if (n) { delete n; n = nullptr; } }
DEC DEC::operator-( )const {
    char* t = new char[strlen(n) + 2];
    if (t == nullptr) throw "memory not enough!";
    if (n[0] == '-') strcpy(t, n + 1);
    else strcat(strcpy(t, "-"), n);
    DEC r(t);
    delete [ ]t;
    return r;
}
DEC& DEC::operator=(const DEC& d) {
    if(this==&d) return *this;
    if (n) delete n;
    n = new char[strlen(d.n) + 1];
    if (DEC::n == nullptr) throw "memory not enough!";
    strcpy(n, d.n);
    return *this;
}
int DEC::operator>(const DEC& d)const {
    int h = strlen(n), k = strlen(d.n);
    switch (n[0]) {
    case '-':
        switch (d.n[0]) {
        case '-':
            if (h == k) {
                for (k = 0; k < h; k++) {
                    if (n[k] == d.n[k]) continue;
                    if (n[k] < d.n[k]) return 1;
                    return 0;
                }
                return 0;
            }
            if (h < k) return 1;
            return 0;
        default:
            return 0;
        };
    default:
        switch (d.n[0]) {
        case '-':
            return 1;
        default:
            if (h == k) {
                for (k = 0; k < h; k++) {
                    if (n[k] == d.n[k]) continue;
                    if (n[k] < d.n[k]) return 0;
                    return 1;
                }
                return 0;
            }
            if (h < k) return 0;
            return 1;
        }
    }
}
int DEC::operator< (const DEC& d)const { return (d > *this)||(d == *this); }
int DEC::operator==(const DEC& d)const { return strcmp(n, d.n) == 0; }
DEC DEC::operator+(const DEC& d) const {
    switch (n[0]) {
    case '-':
        switch (d.n[0]) {
        case '-':
            return -(-*this + (-d));
        default:
            return d - (-*this);
        };
    default:
        switch (d.n[0]) {
        case '-':
            return *this - (-d);
        default:
            int m, c = 0, p = strlen(n), q = strlen(d.n);
            if (p > q) m = p; else m = q; m += 2;
            char* t = new char[m]; t[--m] = 0;
            while (p > 0 && q > 0) {
                c = c + n[--p] + d.n[--q] - 2 * '0';
                t[--m] = ((c >= 10) ? c - 10 : c) + '0';
                c = (c >= 10) ? 1 : 0;
            }
            while (p > 0) {
                c = c + n[--p] - '0';
                t[--m] = ((c >= 10) ? c - 10 : c) + '0';
                c = (c >= 10) ? 1 : 0;
            }
            while (q > 0) {
                c = c + d.n[--q] - '0';
                t[--m] = ((c >= 10) ? c - 10 : c) + '0';
                c = (c >= 10) ? 1 : 0;
            }
            if (c > 0) { t[--m] = '1'; }
            DEC x(t + m);
            delete [ ]t;
            return x;
        };
    };
}
DEC DEC::operator-(const DEC& d) const {
    switch (n[0]) {
    case '-':
        switch (d.n[0]) {
        case '-':
            return (-d) - (-*this);
        default:
            return -(-*this + d);
        };
    default:
        switch (d.n[0]) {
        case '-':
            return *this + (-d);
        default:
            if (d > *this) return -(d - *this);
            int m, k, c = 0, p = strlen(n), q = strlen(d.n);
            if (p > q) m = p; else m = q; k = m += 2;
            char* t = new char[m]; t[--m] = 0;
            while (p > 0 && q > 0) {
                c = n[--p] - d.n[--q] - c;
                t[--m] = ((c < 0) ? c + 10 : c) + '0';
                c = (c < 0) ? 1 : 0;
            }
            while (p > 0) {
                c = n[--p] - '0' - c;
                t[--m] = ((c < 0) ? c + 10 : c) + '0';
                c = (c < 0) ? 1 : 0;
            }
            while (q > 0) {
                c = '0' - d.n[--q] - c;
                t[--m] = ((c < 0) ? c + 10 : c) + '0';
                c = (c < 0) ? 1 : 0;
            }
            if (c > 0) { t[--m] = '-'; }
            else for (k = k - 2; m < k && t[m] == '0'; m++);
            DEC x(t + m);
            delete [ ]t;
            while (strlen(x.n) > 1 && x.n[0] == '0') strcpy(x.n, x.n + 1);
            return x;
        };
    };
}
DEC DEC::operator*(const DEC& d) const {
    if (n[0] == '0' || d.n[0] == '0') return DEC("0");
    switch (n[0]) {
    case '-':
        switch (d.n[0]) {
        case '-':
            return (-d) * (-*this);
        default:
            return -(-*this * d);
        };
    default:
        switch (d.n[0]) {
        case '-':
            return -(*this * (-d));
        default:
            int v, w, c, p = strlen(n), q = strlen(d.n);
            DEC r("0");
            DEC b((p > q) ? n : d.n);
            DEC m((p > q) ? d.n : n);
            for (v = 0, w = ((p > q) ? q : p); v < w; v++) {
                char* t = new char[strlen(r.n) + 2];
                r = strcat(strcpy(t, r.n), "0");
                delete [ ]t;
                for (c = m.n[v] - '0'; c > 0; c--)   r = r + b;
            }
            while (strlen(r.n) > 1 && r.n[0] == '0') strcpy(r.n, r.n + 1);
            if (strlen(r.n) == 0) return DEC("0");
            return r;
        }
    }
}
DEC DEC::operator/(const DEC& d) const {
    if (d.n[0] == '0') throw new exception;
    switch (n[0]) {
    case '-':
        switch (d.n[0]) {
        case '-':
            return (-*this) / (-d);
        default:
            return -(-*this / d);
        };
    default:
        switch (d.n[0]) {
        case '-':
            return -(*this / (-d));
        default:
            if (d > *this) return DEC("0");
            int v, w, c, p = strlen(n), q = strlen(d.n);
            char* r = new char[p + 1], * t = new char[p + 1];
            w = p - q + 1;
            for (v = 0; v < q; v++) t[v] = n[v]; t[q] = '\0';
            for (v = 0; v < w; v++) {
                c = 0;
                while (DEC(t) > d) { strcpy(t, (DEC(t) - d).n); c++; }
                r[v] = c + '0';  r[v + 1] = '\0';
                if (t[0] == '0')  t[0] = n[q + v];
                else {
                    c = strlen(t);
                    t[c] = n[q + v];
                    t[c + 1] = 0;
                }
            }
            for (v = 0; v < p && r[v] == '0'; v++);
            DEC s(r + v);
            delete [ ]r;
            delete [ ]t;
            while (strlen(s.n) > 1 && s.n[0] == '0') strcpy(s.n, s.n + 1);
            return s;
        }
    }
}
DEC DEC::operator%(const DEC& d)const { return *this - (*this / d) * d; }
DEC::operator const char* ( ) const { return n; }
DEC& DEC::operator++( ) { return *this = *this + "1"; }
DEC DEC::operator++(int) { DEC r(*this); ++(*this); return r; }
DEC& DEC::operator--( ) { return *this = *this - DEC("1"); }
DEC DEC::operator--(int) { DEC r(*this); --(*this); return r; }
int main( ) {
    DEC w("1"), x("0"), y("1"), z("0");
    ++x = "100";
    x = "0";
    for (int k = 1; k < 5; k++) w = w * k;
    printf("%s\n", (const char*) w);
    for (int k = 1; k < 5; k++) x = x + DEC(k);
    printf("%s\n", (const char*)x);
    for (x = 1; x < DEC("100"); x++) y = y * x;
    printf("%s\n", (const char*)y);
    for (x = "1"; x < DEC("10000000"); x++) z = z + x;
    printf("%s\n", (const char*)z);
    return 0;
}
