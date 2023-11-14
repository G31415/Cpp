#include <iostream>
#include <math.h>
using namespace std;
class CIRCLE{
    double x, y, r;
public:
    double getx( ) { return x; };
    double gety( ) { return y; };
    double getr( ) { return r; };
    CIRCLE(double x, double y, double r):x(x), y(y), r(r) { };
    void draw( ) { 
cout<<"draw circle at("<<x<<","<<y<<") with radius "<<r<<"\n";
};
};
class TRIANGLE{
    double x1, y1, x2, y2, x3, y3;
public:
    double getx1( ) { return x1; };
    double gety1( ) { return y1; };
    double getx2( ) { return x2; };
    double gety2( ) { return y2; };
    double getx3( ) { return x3; };
    double gety3( ) { return y3; };
    TRIANGLE(double x1, double y1, double x2, double y2, double x3, 
double y3):  x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) { };
    void draw( ) {
        cout<<"draw triangle at("<<x1<<","<<y1<<"),(";
        cout<<x2<<","<<y2<<"),("<<x3<<","<<y3<<")";
    }
};
class INSCRIBED: CIRCLE, TRIANGLE{
public:
    INSCRIBED(double x1, double y1, double x2, double y2, double x3, double y3);
    void draw( ) {
        cout<<"draw inscribed triangle at("<<getx1( )<<","<<gety1( ) <<"),(";
        cout<<getx2( )<<","<<gety2( )<<"),("<<getx3( )<<","<<gety3( )<<")";
    }
};
INSCRIBED::INSCRIBED (double x1,double y1,double x2,double y2,
double x3,double y3): CIRCLE((x1*x1*y2+x2*x2*y3+x3*x3*y1+y1*y1*y2
+y2*y2*y3+y3*y3*y1-x1*y3*y3-x2*y1*y1-x3*y2*y2-y1*y1*y3-y2*y2*y1-
y3*y3*y2)/(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2)/2,(x1*x2*x2
+x2*x3*x3+x3*x1*x1+x1*y2*y2+x2*y3*y3+x3*y1*y1-x1*y3*y3-x2*y1*y1
-x3*y2*y2-x1*x3*x3-x2*x1*x1-x3*x2*x2)/(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1
-x3*y2)/2,sqrt(pow(x1-(x1*x1*y2+x2*x2*y3+x3*x3*y1+y1*y1*y2+y2*y2*y3
+y3*y3*y1-x1*y3*y3-x2*y1*y1-x3*y2*y2-y1*y1*y3-y2*y2*y1-y3*y3*y2)
/(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2)/2,2)+pow(y1-(x1*x2*x2+x1*y2*y2
+x2*x3*x3+x2*y3*y3+x3*x1*x1+x3*y1*y1-x1*x3*x3-x1*y3*y3-x2*x1*x1
-x2*y1*y1-x3*x2*x2-x3*y2*y2)/(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2)
/2,2))), TRIANGLE(x1, y1, x2, y2, x3, y3) { }
