#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
class STACK{
    int *const elems; 		//申请内存用于存放栈的元素
    const int max; 		//栈能存放的最大元素个数
    int pos;	 		//栈实际已有元素个数，栈空时pos=0;
public:
    STACK(int m); 		//初始化栈：栈最多存m 个元素
    STACK(const STACK& s); 	//用栈s 深拷贝构造新栈
    STACK(STACK&& s); 	//用栈s 浅拷贝移动构造新栈
    virtual int size( )const; 	//返回栈的最大元素个数max
    virtual int howMany( )const; 	//返回栈的实际元素个数pos
    virtual int getElem(int x)const;	//取下标为x 的栈元素，x>=0
    virtual STACK& push(int e);	//将e 入栈，并返回原栈
    virtual STACK& pop(int& e);	//出栈到e，并返回原栈
    virtual STACK& assign(const STACK& s); //深拷贝赋s 给栈，返回被赋原栈
    virtual STACK& assign(STACK&& s); 	//浅拷贝移动赋s 给栈，返回被赋原栈
    virtual void print( )const; 	//自顶至底输出栈元素
    virtual ~STACK( ); 		//销毁栈
};
STACK::STACK(int m): elems(new int[m]), max(elems ? m : 0), pos(0) { }
STACK::STACK(const STACK& s): elems(new int[s.max]), 
max(elems? s.max : 0), pos(0){
    for (pos = 0; pos < s.pos; pos++) elems[pos] = s.elems[pos];
}
STACK::STACK(STACK&& s): elems(s.elems), max(s.max), pos(s.pos) {
    (int*&)(s.elems)= nullptr;
    (int&)(s.max)= s.pos=0;
}
int STACK::size( )const { return max; }
int STACK::howMany( )const { return pos; }
int STACK::getElem(int x)const { return elems[x]; }
STACK::~STACK( ) {
    if (!elems) return;
    delete[ ]elems;
    *(int**)&elems = nullptr;
    *(int*)&max = pos = 0;
}
STACK& STACK::push(int e) {
    if (pos >= max) return *this;
    elems[pos++] = e;
    return *this;
}
STACK& STACK::pop(int& e) {
    if (pos==0) return *this;
    e = elems[--pos];
    return *this;
}
STACK& STACK::assign(const STACK& s) {
    if (this == &s) return *this;
    if(elems) delete [ ]elems;
    (int*&)elems = new int[s.max];
    (int&)max = elems?s.max:0; 
    pos = elems ? s.pos:0;
    for (int c = 0; c < pos; c++) 
        elems[c] = s.elems[c];
    return *this;
}
STACK& STACK::assign(STACK&& s) {
    if (this == &s) return *this;
    if (elems) delete[ ]elems;
    (int*&)elems = s.elems;
    (int&)max = s.max;
    pos = s.pos;
    (int*&)(s.elems) = nullptr;
    (int&)(s.max) = s.pos= 0;
    return *this;
}
void STACK::print( )const {
    for (int c = pos - 1; c >= 0; c--) 
        printf("%d ", elems[c]);
}
int main(int a, char* p[ ]) { 
    int x, y;
    STACK s(10),t(20);
    s.push(1);
    s.push(2).push(3);
    x = s.size( );
    y = s.howMany( );
    s.pop(x);
    y = s.howMany( );
    t.assign(s);
    s.print( );
    t.print( );
    s.assign((STACK&&)t);
    s.print( );
    t.print( );
    return t.howMany( );
}
