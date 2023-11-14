#include <iostream>
using namespace std;
class SET{
    int *elem;							//存放集合元素的动态内存
    int count;							//目前元素个数
const int total;							//最大元素个数
public:
    SET(int total);			
    SET(const SET &);
    int find(int val)const;					//找到val元素返回1，否则返回0
    int full(void)const;					//集合满时返回1，否则返回0
    int empty(void)const;					//集合空时返回1，否则返回0
    virtual SET operator +(const SET &)const;	//集合的并集
    virtual SET operator –(const SET &)const;	//集合的差集
    virtual SET operator *(const SET &)const;	//集合的交集
    virtual SET &operator <<(int value);		//增加一个元素
    virtual SET &operator >>(int value);		//删除一个元素
    virtual SET &operator + =(const SET &);	//集合的并集
    virtual SET &operator – =(const SET &);	//集合的差集
    virtual SET &operator * =(const SET &);	//集合的交集
    virtual SET &operator <<=(int value);	//增加一个元素
    virtual SET &operator >>=(int value);	//删除一个元素
    virtual SET &operator =(const SET &);
    virtual ~SET(void);
};
SET::SET(int total):total((elem=new int[total])?total:0){ count=0; }
SET::SET(const SET &s):total((elem=new int[s.total])?s.total:0){
    int k;
    count=0;
    if(elem){ for(count=s.count, k=0; k<count; k++) elem[k]=s.elem[k]; }
}
int SET::find(int val)const{
    int k;
    for(k=0; k<count; k++) if(elem[k]==val) return 1;
    return 0;
}
int SET::full(void)const{ return count==total; }
int SET::empty(void)const{ return count==0; }
SET SET::operator +(const SET &s)const{
    int k;
    SET r(total+s.total);
    for(k=0; k<s.count; k++) r.elem[k]=s.elem[k];
    for(k=0; k<count; k++) r<<elem[k];
    return r;
}
SET SET::operator -(const SET &s)const{
    int k;
    SET r(*this);
    for(k=0; k<s.count; k++) r>>s.elem[k];
    return r;
}
SET SET::operator *(const SET &s)const{ return *this-(*this-s); }
SET &SET::operator <<(int value){
    if(find(value)) return *this;
    if(count<total)elem[count++]=value;
    return *this;
}
SET &SET::operator >>(int value){
    int k;
    for(k=0; k<count; k++)
        if(elem[k]==value){
            for(count--; k<count; k++) elem[k]=elem[k+1];
            return *this;
        }
    return *this;
}
SET &SET::operator +=(const SET &s){ return *this=*this+s; }
SET &SET::operator -=(const SET &s){ return *this=*this-s; }
SET &SET::operator *=(const SET &s){ return *this=*this*s; }
SET &SET::operator <<=(int value){ return *this=*this<<value; }
SET &SET::operator >>=(int value){ return *this=*this>>value; }
SET &SET::operator =(const SET &s){
    if(this==&s) return *this;
    this->~SET( );	  	//如SET不被继承则SET是安全的。提倡用if(elem) delete elem;
    new (this) SET(s);  //利用当前对象结构重新构造
    return *this;
}
SET::~SET(void){ if(elem) { delete elem, elem=0; }}

