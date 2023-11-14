#include <math.h>
class GRAPH{
    double x, y, z;		//图形中心基点
public:
    double getx( )const{ return x; }
    double gety( )const{ return y; }
    double getz( )const{ return z; }
    virtual double volume( )const=0;
    virtual double display( )const=0;
    GRAPH(double x, double y, double z): x(x), y(y), z(z) {  }
};
class CUBE: public GRAPH{
    double e;		//立方体的边长
public:
    double gete( )const{ return e; }
    double volume( )const{ return e*e*e; }
    double display( )const{ 
        printf(“(x,y,z,e)=(%lf,%lf,%lf,%lf)”, getx( ), gety( ), getz( ),e); 
    }
    CUBE (double x, double y, double z, double e): GRAPH(x,yz),e(e){ };
};
class SPHERE: public GRAPH{
    double r;		//求体的半径
public:
    double getr( )const{ return r; };
    double volume ( )const{ return 3.1415926536*r*r*r*4/3; };
    double display( )const{ 
        printf(“(x,y,z,r)=(%lf,%lf,%lf,%lf)”, getx( ), gety( ), getz( ),r); 
    }
    SPHERE (double x,double y, double z,double r):GRAPH(x, y,z), r(r) { }
};
