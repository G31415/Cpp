#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class PASSWORD {
    char *const p; 			//用于存储口令
    const int t; 			//用于存储最大口令长度
    int c; 				//用于存储口令字符实际个数，不含回车字符
public:
    PASSWORD(int t);			//t为最大口令长度
    virtual char getChar( );		//返回输入的字符并显示'*'，回车不显示
    virtual int input(const char*h); 	//显示h调getChar( )输口令，返回口令字符数
};
class STUDENT: PASSWORD { 		//PASSWORD 用于存储学生姓名
    PASSWORD p; 		   	//p用于存储口令
protected:
    using PASSWORD::getChar;		//用于输入姓名或者口令的一个字符
    using PASSWORD::input;   		//用于输入姓名或者口令
public:
    STUDENT(int n, int p); 		//n为姓名最大长度，p 为口令最大长度
    virtual char getChar( );		//返回并显示输入字符，回车不显示
    int input(const char *n, const char *p); 	//n、p 分别为姓名和口令的输入提示
};
PASSWORD::PASSWORD(int t):p(new char[t]), t(p?t:0), c(0){ }
char PASSWORD::getChar( ){ 
    char ch=getch( ); 
    if (ch!='\r') _putch('*'); 
    return ch; 
}
int PASSWORD::input(const char* h) {
    printf(h);
    int r = 0;
    char ch;
    while (c < t && (ch = getChar( )) != '\r') 
        p[c++] = ch;
    return c;
}
STUDENT::STUDENT(int n, int p):PASSWORD(n), p(p){ }
char STUDENT::getChar( ) { 
    char ch=_getch( ); 
    if (ch!='\r') _putch(ch); 
    return ch; 
}
int STUDENT::input(const char* n, const char* p) {
    PASSWORD::input(n);
    STUDENT::p.input(p);
    return 2;
}
void main( ) {
    STUDENT s(20,10); 	//姓名最大长度为20，口令最大长度为10
    int m=s.input("\nPlease input name:", "\nPlease input password:");
}
