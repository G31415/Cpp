class A {
    int* p;
public:
    A(int n) : p(new int[n]) { }
    ~A( ) { if (p) { delete p; p = nullptr; } }
    int& operator[ ](int x) { return p[x]; }
}a(10);
int f(A x) { return x[0]; }
int main(int n, char** s) {
    a[0] = 2;
    n=f(a);	//n=2，实参a值参传给形参x时，调拷贝构造函数A(const &A)
    n=a[0];	//对VS 2019，n可能是随机值，可能不等于2
    return n;
}
