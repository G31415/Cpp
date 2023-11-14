#include <iostream>
using namespace std;
struct A{A( ) { cout<<'A';}};
struct B{B( ) { cout<<'B';}};
struct C: A{C( ) { cout<<'C';}};
struct D: A, B{D( ) { cout<<'D';}};
struct E: A, B, virtual C{
    D  d;
    E( ) { cout<<'E';}
};
struct F: A, virtual B, virtual C, D, E{
    C  c, d;
    E  e;
    F( ) { cout<<'F';}
};
void main(void) 
{
    A  a;  cout<<'\n';
    B  b;  cout<<'\n';
    C  c;  cout<<'\n';
    D  d;  cout<<'\n';
    E  e;  cout<<'\n';
    F  f;  cout<<'\n';
}
