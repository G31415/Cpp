#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int &f( ) {int i=10; int &j=i; return j; }
int g ( ) {int j=20; return j; }
void main (void) {
    int &ri=f( );
    int rj=g( );
    printf("ri=%d\trj=%d\n", ri, rj, 1, 2, 3, 4, 5, 6, 7, 8);
    int &gi=f( );
    int gj=g( );
    printf ("gi=%d\tgj=%d\n", gi, gj);
}

