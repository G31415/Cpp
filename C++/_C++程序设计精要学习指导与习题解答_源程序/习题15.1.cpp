#include <iomanip>
#include <iostream>
using namespace std;

template <typename T>
class MAT {
    T* const e;                 		//指向所有整型矩阵元素的指针
    const int r, c;                 		//矩阵的行r 和列c 大小
public:
    MAT(int r, int c);                 		//矩阵定义
    MAT(const MAT& a);             	//深拷贝构造
    MAT(MAT&& a);                 		//移动构造
    virtual ~MAT() noexcept;
    virtual T* const operator[ ](int r);         	//取矩阵r 行的第一个元素地址
    virtual MAT operator+(const MAT& a)const;	//矩阵加法
    virtual MAT operator-(const MAT& a)const;    	//矩阵减法
    virtual MAT operator*(const MAT& a)const;    	//矩阵乘法
    virtual MAT operator~()const;             //矩阵转置
    virtual MAT& operator=(const MAT& a);         	//深拷贝赋值运算
    virtual MAT& operator=(MAT&& a); 	//移动赋值运算
    virtual MAT& operator+=(const MAT& a);     	//“+=”运算
    virtual MAT& operator-=(const MAT& a);     	//“-=”运算
    virtual MAT& operator*=(const MAT& a);     	//“*=”运算
    virtual void print()const;            	//输出矩阵的r 行c 列元素
};
template <typename T>
MAT<T>::MAT(int r, int c) : e(new T[r * c]{}), r(e ? r : 0), c(e ? c : 0) {
    if (e == nullptr) throw new exception("memory allocation failed!");
}
template <typename T>
MAT<T>::MAT(const MAT<T>& m) : e(new T[m.r * m.c]()), r(e ? m.r : 0), c(e ? m.c : 0) {
    if (e == nullptr) throw new exception("memory allocation failed!");
    for (int x = r * c - 1; x >= 0; x--) e[x] = m.e[x];
}
template <typename T>
MAT<T>::MAT(MAT<T>&& m) : e(m.e), r(m.r), c(m.c) {
    (T*&)(m.e) = nullptr;
    (int&)(m.r) = (int&)(m.c) = 0;
}
template <typename T>
MAT<T>::~MAT()noexcept {
    if (e) {
        delete[]e;
        (T*&)e = nullptr;
        (int&)r = (int&)c = 0;
    }
}
template <typename T>
T* const MAT<T>::operator[ ](int r) {
    if (r < 0 || r >= MAT<T>::r) throw new exception("row is overflowed!");
    return e + r * c;
}
template <typename T>
MAT<T> MAT<T>::operator+(const MAT<T>& m)const {
    if (r != m.r || c != m.c)
        throw new exception("row and column are not eaual when adding!");
    MAT<T> n(r, c);
    MAT<T> s(*this);
    for (int x = r * c - 1; x >= 0; x--) s.e[x] += m.e[x];
    return s;
}
template <typename T>
MAT<T> MAT<T>::operator-(const MAT<T>& m)const {
    if (r != m.r || c != m.c)
        throw new exception("row and column are not eaual when substracting!");
    MAT<T> s(*this);
    for (int x = r * c - 1; x >= 0; x--) s.e[x] -= m.e[x];
    return s;
}
template <typename T>
MAT<T> MAT<T>::operator*(const MAT<T>& m)const {
    if (c != m.r)
        throw new exception("column of multiplicand not eaual to row of multiplicator!");
    MAT<T> s(r, m.c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < m.c; j++)
        {
            s.e[i * m.c + j] = 0;
            for (int k = 0; k < c; k++)  s.e[i * m.c + j] += e[i * c + k] * m.e[k * m.c + j];
        };
    return s;
}
template <typename T>
MAT<T> MAT<T>::operator~()const {
    MAT<T> s(c, r);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)  s.e[j * r + i] = e[i * c + j];
    return s;
}
template <typename T>
MAT<T>& MAT<T>::operator=(const MAT<T>& m)
{
    if (this == &m) return *this;
    if (e) delete[ ]e;    			//若被继承，最好不要调用~MAT( )
    (T*&)e = new T[m.r * m.c];
    if (e == nullptr) throw new exception("memory allocation failed!");
    (int&)r = m.r;  (int&)c = m.c;
    for (int x = r * c - 1; x >= 0; x--) e[x] = m.e[x];
    return *this;
}
template <typename T>
MAT<T>& MAT<T>::operator=(MAT<T>&& m)
{
    if (this == &m) return *this;
    if (e) delete[]e;             		//若被继承，最好不要调用~MAT( )
    (T*&)e = m.e;
    (int&)r = m.r;
    (int&)c = m.c;
    (T*&)(m.e) = nullptr;
    (int&)(m.r) = 0;
    (int&)(m.c) = 0;
    return *this;
}
template <typename T>
MAT<T>& MAT<T>::operator+=(const MAT<T>& a) {
    return *this = *this + a;
}
template <typename T>
MAT<T>& MAT<T>::operator-=(const MAT<T>& a) {
    return *this = *this - a;
}
template <typename T>
MAT<T>& MAT<T>::operator*=(const MAT<T>& a) {
    return *this = *this * a;
}
template <typename T>
void MAT<T>::print()const {
    int len = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << setw(8) << e[i * c + j];
        cout << endl;
    }
}
int main(int argc, char* argv[ ])             	//扩展main( )测试其他运算
{
    MAT<int> a(1, 2), b(2, 2), c(1, 2);
    a[0][0] = 1;             		//类似地初始化矩阵的所有元素
    a[0][1] = 2;             		//等价于“*(a.operator[ ](0)+1)=2;”即等价于“*(a[0]+1)=2;”
    a.print();                 		//初始化矩阵后输出该矩阵
    b[0][0] = 3; b[0][1] = 4;         		//调用T*const operator[ ](int r)初始化数组元素
    b[1][0] = 5; b[1][1] = 6;
    b.print();
    c = a * b;                 		//测试矩阵乘法运算
    c.print( );
    (a + c).print();             		//测试矩阵加法运算
    c = c - a;                 		//测试矩阵减法运算
    c.print( );
    c += a;                 		//测试矩阵“+=”运算
    c.print( );
    c = ~a;                 		//测试矩阵转置运算
    c.print( );
    return 0;
}