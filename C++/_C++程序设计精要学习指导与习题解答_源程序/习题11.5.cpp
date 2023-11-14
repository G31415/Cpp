int  x=7;
int  y=::x+5;
struct A{
    int x;
    static int y;
public:
    A &operator +=(A &);
    operator int( ) { return x+y; };
    A(int x=::x+1, int y=::y+11) {
        A::x=x;
        A::y=y;
    }
};
A& A::operator +=(A &a) {
    x+=a.x;
    y+=a.y;
    return *this;
}
int A::y=20;
void main(void) {
    A  a(2, 5), b(6), c;
    int  i, &j=i,*p=&A::y;
    i=b.y;
    j=b.x;
    i=*p;
    j=c;
    i=a+c;
    i=b+=c;
    i=((a+=c)=b)+9;
}

