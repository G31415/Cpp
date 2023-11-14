#include <iostream>
using namespace std;
class base {
public:
    base( ) { cout<<"Constructing base\n"; }
    virtual void isa( ) {cout<<"base\n";}
    ~base( ) { cout<<"Constructing base\n"; }
}；
class  derive: public base {//构成父子关系
public:
    derive( ) { cout<<"Constructing derive\n"; }
    virtual void isa( ) {cout<<"derive\n";}
    ~derive( ) { cout<<"Constructing derive\n"; }
};
class  clique: public base {//构成父子关系
public:
    clique ( ) { cout<<"Constructing clique \n"; }
    virtual void isa( ) {cout<<"clique\n";}
    ~ clique ( ) { cout<<"Constructing clique \n"; }
};
void main( ){
    base    *p, b;
    clique  　c;
    derive  　d;
    b.isa( );  c.isa( ); 　d.isa( );
    p=&b;   p->isa( );  //调用base的isa( )
    p=&c;   p->isa( );  //调用clique的isa( )
    p=&d;   p->isa( );  //调用derive的isa( )
}

