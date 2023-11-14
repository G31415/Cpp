#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
using namespace std;
class STRING{
    char *str; 			//用于存储字符串
public:
    int strlen( )const; 			//用于求字符串的长度
    int strcmp(const STRING &)const; 	//用于比较两个字符串
    STRING &strcpy(const STRING &s); 	//用于拷贝s 至当前字符串
    STRING &strcat(const STRING &s); 	//用于连接s 至当前字符串
    STRING(const char *s); 		//用s 构造字符串
    ~STRING( );	 		//析构字符串
};
int STRING::strlen( )const{ return ::strlen(str); }
int STRING::strcmp(const STRING &s)const{return ::strcmp(str, s.str); }
STRING &STRING::strcat(const STRING &s){
    int  len=::strlen(str)+::strlen(s.str)+1;
    char *t=str;
    if(str=new char[len]) {
        ::strcat(::strcpy(str, t), s.str);
    }
    delete t;
    return *this;
}
STRING &STRING::strcpy(const STRING &s){
    int  len=::strlen(s.str)+1;
    delete str;
    if(str=new char[len]) ::strcpy(str, s.str);
    return *this;
}
STRING::STRING(const char *s){ 
    if(str=new char[::strlen(s)+1])
        ::strcpy(str, s); 
}
STRING::~STRING( ){ if (str) { delete str;  str=nullptr; } }
void main(void)
{
    STRING s1("I like apple");
    STRING s2(" and pear");
    STRING s3(" and orange");
    cout<<"Length of s1="<<s1.strlen( )<<"\n";
    s1.strcat(s2).strcat(s3);
    cout<<"Length of s1="<<s1.strlen( )<<"\n";
    s3.strcpy(s2).strcpy(s1);
    cout<<"Length of s3="<<s3.strlen( )<<"\n";
}
