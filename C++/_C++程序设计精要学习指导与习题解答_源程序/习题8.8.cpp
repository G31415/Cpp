#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
class  PERSON{
    char  *name, *SIDN;
    int    age;
    PERSON *next;
public:
    static PERSON *head;
    PERSON(char *name, char *SIDN, int  age);
    virtual void print( );
    virtual ~PERSON( );
};
PERSON *PERSON::head=nullptr;
PERSON::PERSON(char *n, char *S, int  a) {
    if (name=new char[strlen(n)+1]) strcpy(name, n);
    if (SIDN=new char[strlen(S)+1]) strcpy(SIDN, S);
    next=head;
    head=this;
}
PERSON::~PERSON( ){
    PERSON *m, *n=head;
    if (head==nullptr) { return; }
    if (name){delete name; name=nullptr;}
    if (SIDN){delete SIDN; SIDN=nullptr;}
    if(head==this) { head=next; return ; }
    while (n!=this && n!=nullptr){ m=n; n=n->next; }
    m->next=this->next;
}
void PERSON::print( ) {
    printf("name=%s, SIDN=%s, age=%d\n", name, SIDN, age);
}
class  STUDENT: public PERSON{
    int    grade;
    double average;
public:
    STUDENT(char *name, char *SIDN, int age, int grade, double average);
    void print( );
    ~STUDENT( ){ };
};
STUDENT::STUDENT(char *n, char *S, int a, int g, double v):PERSON(n, S, a){
    grade=g;
    average=v;
}
void STUDENT::print( ) {
    PERSON::print( );
    printf("grade=%d, average=%d\n", grade,  average);
}
class  CLERK: public PERSON{
    double wage;
public:
    CLERK(char *name, char *SIDN, int age, double wage);
    void print( );
    ~CLERK( ){ };
};
CLERK::CLERK(char *n, char *S, int a, double w):PERSON(n, S, a){ wage=w; }
void CLERK::print( ) {
    PERSON::print( );
    printf("wage=%lf\n",wage);
}
class  PROFESSOR: public CLERK{
    char   *field;
public:
    PROFESSOR(char *name, char *SIDN, int age, double wage, char *field);
    void print( );
    ~PROFESSOR( ){ };
};
PROFESSOR::PROFESSOR(char *n, char *S, int a, double w, char *f): CLERK(n, S, a, w){
    if(field=new char[strlen(f)+1]) strcpy(field, f);
}
void PROFESSOR::print( ) {
    CLERK::print( );
    printf("field=%s\n", field);
}
void main( ){
    STUDENT s1("s1", "1", 1, 1, 90);
    STUDENT s2("s1", "2", 1, 1, 90);
    CLERK c1("c1", "1", 1, 1000);
    CLERK c2("c2", "2", 1, 1000);
    PROFESSOR p1("p1", "1", 1, 2000, "computer");
    PROFESSOR p2("p2", "2", 1, 2200, "computer");
    s1.print( );
    c1.print( );
    p1.print( );
}
