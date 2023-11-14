#define _CRT_SECURE_NO_WARNINGS //防止strcpy 出现指针使用安全警告
#include <stdio.h>
#include <string.h>
class PERSON{
    char name[10];
    char IDnumber[18];
public:
    void print( ){printf("Name=%s, IDnumber=%s\n", name, IDnumber);};
    PERSON(const char *n, const char *i);
};
PERSON::PERSON(const char *n, const char *i)
{
    strcpy(name, n);
    strcpy(IDnumber, i);
}
class TEACHER: public PERSON{  //派生方式public，构成父子关系
    char title[20];
    double wage;
public:
    void print( );
    TEACHER(const char *n, const char *i, const char *t, double w);
};
TEACHER::TEACHER(const char*n, const char*i, const char*t, double w):PERSON(n, i){
    strcpy(title, t);
    wage=w;
};
void TEACHER::print( ){
    PERSON::print( );
    printf("Title=%s, Wage=%d\n", title, wage);
}
void main( ){
    PERSON   *q, p("Liu", "420106641107538");
    TEACHER  t("Wei", "420106641107168", "Professor", 3000);
    q=&p; q->print( ); 	//输出姓名和编号，q定义为指向PERSON对象
    q=&t; q->print( ); 	//输出姓名和编号，但q实际指向的是TEACHER对象
    t.print( );		//输出姓名、编号、职称和工资，t为TEACHER对象
}
