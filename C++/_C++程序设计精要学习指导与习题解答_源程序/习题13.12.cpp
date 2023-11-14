template <class T>
class ARRAY {
    T* const a;
    const int r, c;
public:
    ARRAY(int x = 1, int y = 1);
    ARRAY(const ARRAY&);
    ARRAY(ARRAY&&)noexcept;
    virtual T& operator( )(int x, int y);
    virtual ARRAY& operator=(const ARRAY&);
    virtual ARRAY& operator=(ARRAY&&)noexcept;
    virtual ARRAY operator+(const ARRAY&)const;
    virtual ARRAY operator-(const ARRAY&)const;
    virtual ARRAY operator*(const ARRAY&)const;
    virtual ARRAY operator!()const;
    virtual ~ARRAY()noexcept;
};
template <class T>
ARRAY<T>::ARRAY(int x, int y) : a(new T[x * y]), r(a ? x : 0), c(a ? y : 0) {
    if (a == nullptr) throw "memory not enough!";
}
template <class T>
ARRAY<T>::ARRAY(const ARRAY<T>& m) : a(new T[m.r * m.c]),
r(a ? m.r : 0), c(a ? m.c : 0) {
    if (a == nullptr) throw "memory not enough!";
    for (int h = r * c - 1; h >= 0; h--)  a[h] = m.a[h];
}
template <class T>
ARRAY<T>::ARRAY(ARRAY<T>&& m) noexcept : a(m.a), r(m.r), c(m.c) {
    (T*&)(m.a) = nullptr;
    (int&)(m.r) = (int&)(m.c) = 0;
}
template <class T>
ARRAY<T>::~ARRAY()noexcept { if (a) { delete[]a; (T*&)a = 0; (int&)r = (int&)c = 0; } }
template <class T>
T& ARRAY<T>::operator( )(int x, int y) {
    if (x<0 || x>r || y<0 || y>c) throw "subscription overflowed!";
    return a[x * c + y];
}
template <class T>
ARRAY<T>& ARRAY<T>::operator=(const ARRAY<T>& m) {
    if (this == &m) return *this;
    if (a) delete[]a;
    (T*&)a = new T[m.r * m.c];
    if (a == nullptr) throw "memory not enough!";
    if (a) { (int&)r = m.r; (int&)c = m.c; }
    for (int h = r * c - 1; h >= 0; h--)  a[h] = m.a[h];
    return *this;
}
template <class T>
ARRAY<T>& ARRAY<T>::operator=(ARRAY<T>&& m)noexcept {
    if (this == &m) return *this;
    if (a) delete[] a;
    (T*&)a = m.a; 		(int&)r = m.r; 		(int&)c = m.c;
    (T*&)(m.a) = nullptr;	(int&)(m.r) = 0;	(int&)(m.c) = 0;
    return *this;
}
template <class T>
ARRAY<T> ARRAY<T>::operator+(const ARRAY<T>& m)const {
    if (r != m.r || c != m.c) throw "can not add!";
    ARRAY<T> v(m);
    for (int h = r * c - 1; h >= 0; h--)  v.a[h] += a[h];
    return v;
}
template <class T>
ARRAY<T> ARRAY<T>::operator-(const ARRAY<T>& m)const {
    if (r != m.r || c != m.c) throw "can not substract!";
    ARRAY<T> v(*this);
    for (int h = r * c - 1; h >= 0; h--)  v.a[h] -= m.a[h];
    return v;
}
template <class T>
ARRAY<T> ARRAY<T>::operator*(const ARRAY<T>& m)const {
    if (c != m.r) throw "can not multiply!";
    ARRAY<T> v(r, m.c);
    for (int h = 0; h < r; h++)
        for (int k = 0; k < m.c; k++) {
            v.a[h * m.c + k] = 0;
            for (int p = 0; p < c; p++)
                v.a[h * m.c + k] += a[h * c + p] * m.a[p * m.c + k];
        }
    return v;
}
template <class T>
ARRAY<T> ARRAY<T>::operator!()const {
    ARRAY<T> v(c, r);
    for (int h = 0; h < r; h++)
        for (int k = 0; k < c; k++)
            v.a[h * r + k] = a[h * c + k];
    return v;
}
void main() {
    ARRAY<int>  a(10, 20), b(20, 30), c(10, 20), d(1, 1);
    a(1, 2) = 3;  b(2, 4) = 6;  c(1, 2) = 10;
    d = a * b;
    d = a + c;
    d = !a;
}
