#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
class fruit {
public:
    virtual char *identify( ) { return  “fruit”; }
};
class tree{
public:
    virtual char identify( ) { return  “tree”; }
};
class Apple: public fruit, public tree{
public:
    char *identify( ) {
        static char s[40];
        strcpy(s, "(apple: ");
        strcat(s, fruit::identify( ));
        strcat(s, ", ");
        strcat(s, tree::identify( ));
        strcat(s, ")");
        return  s;
    };
};
class Pear: public fruit, public tree{
public:
    char *identify( ) {
        static char s[40];
        strcpy(s, "(pear: ");
        strcat(s, fruit::identify( ));
        strcat(s, ", ");
        strcat(s, tree::identify( ));
        strcat(s, ")");
        return  s;
    };
};
class ApplePear: public Apple, public Pear{
public:
    char *identify( ) {
        static char s[60];
        strcpy(s, "(apple pear: ");
        strcat(s, Apple::identify( ));
        strcat(s, ", ");
        strcat(s, Pear::identify( ));
        strcat(s, ")");
        return  s;
    };
};
