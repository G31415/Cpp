struct Y;
struct X {
    int i;
    X(int);
    operator int ( );
    X operator +(Y &);
};
struct Y{
    int i;
    Y(int);
    Y(X &);
    operator int ( );
};
void main(void) {
    int ret;
    X x=1;
    Y y=x;
    ret=y+10;
    ret=y+10*y;
    ret=x+y-1;
    ret=x*x+1;
}
