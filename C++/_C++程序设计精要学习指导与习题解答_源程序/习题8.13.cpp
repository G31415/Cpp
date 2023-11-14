#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
class ELEMS{
    char   c;
    ELEMS  *n;
public:
    virtual void print( );
    ELEMS*getn( ){ return n; }
    ELEMS*setn(ELEMS *a){ n=a; return this; }
    ELEMS(char x, ELEMS *y=0){ c=x; n=y; }
};
void ELEMS::print( ){  printf("%c", c);  }
class LISTS: public ELEMS{
    ELEMS  *e;
public:
    void print( );  //自动成为虚函数
    LISTS&join(ELEMS *e);
    LISTS(char x):ELEMS(x){ e=0; }
};
void LISTS::print( ){
    ELEMS::print( );
    printf("(");
    ELEMS *h=e;
    if(h) h->print( );
    while(h=h->getn( )){ printf(","); h->print( ); }
    printf(")");
}
LISTS& LISTS::join(ELEMS *a){
    e=a->setn(e);
    return *this;
}
void main( ){
    ELEMS  a('a'), b('b'), c('c'), d('d'), e('e');
    LISTS   A('A'), B('B');
    A.join(&a);  
    A.join(&b);  
    A.join(&c);
    A.print( );
    B.join(&a);  
    B.join(&A);  
    B.join(&e);
    B.print( );
}
