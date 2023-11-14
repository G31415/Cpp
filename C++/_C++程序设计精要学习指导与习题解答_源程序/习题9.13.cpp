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
    virtual int getElem(int x)const;//取下标为x 的栈元素，x>=0
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
class QUEUE：public STACK{
    STACK s;
public:
    QUEUE(int m); 			//栈最多m个元素，队列最多能入2m 个元素
    QUEUE(const QUEUE&q); 		//用队列q 深拷贝构造新队列
    QUEUE(QUEUE&& q); 		//浅拷贝移动构造新队列
    virtual int howMany( )const; 		//返回队列的实际元素个数
    virtual int full ( )const; 		//队列已满返回1，否则返回0
    virtual int getElem(int x)const; 	//自队首取下标为x 的元素，x>=0
    virtual QUEUE& push(int e); 		//将e 入队列，并返回原队列
    virtual QUEUE& pop(int &e); 	//出队列到e，并返回原队列
    virtual QUEUE&assign(const QUEUE&q); //深拷贝赋q 给被返回原队列
    virtual QUEUE &assign(QUEUE &&q); //浅拷贝移动赋q 给被返回原队列
    virtual void print( )const; 		//自首至尾输出队列元素
    ~QUEUE( ); 			//销毁队列
};
QUEUE::QUEUE(int m): STACK(m), s(m) { }
QUEUE::QUEUE(const QUEUE& q): STACK(q), s(q.s) { }
QUEUE::QUEUE(QUEUE&&q): STACK((STACK&&)q),s((STACK&&)(q.s)) { }
int QUEUE::howMany( )const { return STACK::howMany( ) + s.howMany( ); }
int QUEUE::full( )const { return howMany( ) == 2* STACK::size( ); }
int QUEUE::getElem(int x)const {
    if (x<0 || x>howMany( )) throw "Qubscription is wrong!";
    int c=s.howMany( );
    if (x < c) return s.getElem(c-x-1);
    return STACK::getElem(x-c);
}
QUEUE& QUEUE::assign(const QUEUE& q) { //赋s给队列,并返回被赋队列
    if (this == &q) return *this;
    STACK::assign(q);			//q深拷贝赋值时，q的成员也应深拷贝
    s.assign(q.s);			//q深拷贝赋值时，q的成员也应深拷贝
    return *this;
}
QUEUE& QUEUE::assign(QUEUE&& q) { //赋s给队列,并返回被赋值的队列
    if (this == &q) return *this;
    STACK::assign((STACK&&)q);		//注意q用移动语义时，成员也应移动语义
    s.assign((STACK&&)(q.s)); 	  	//注意q用移动语义时，成员也应移动语义
    return *this;
}
QUEUE& QUEUE::push(int e) {		//将e入队列,并返回队列
    if (STACK::howMany( )<STACK::size( )){	//栈s1未满
        STACK::push(e);
        return *this;
    }
    if (s.howMany( ) != 0) 		//第一个栈已满，第二个栈非为空
        throw "Can not push when queue is full!";
    //第一个栈已满，第二个栈为空，将第一个栈中元素倒入s2
    for (int i = 0; i < s.size( ); i++) {
        int temp;
        STACK::pop(temp);
        s.push(temp);
    }
    STACK::push(e);
    return *this;
}
QUEUE& QUEUE::pop(int& e) {		//出队列到e,并返回队列
    int number;			//第一个栈元素个数
    if (s.howMany( )> 0){		//第二个栈非空
        s.pop(e); 
        return *this;
    }
    if ((number=STACK::howMany( ))==0) 	//第二个栈为空，第一个栈为空
        throw "Can not pop when queue is empty!";
    //将第一个栈中元素倒入s2
    for (int i = 0; i < number; i++)
    {
        int temp;
        STACK::pop(temp);
        s.push(temp);
    }
    s.pop(e);
    return *this;
}
void QUEUE::print( ) const {	    	//打印队列
    for (int x =0, y=howMany( ); x <y; x++)
        printf("%d ",getElem(x));
}
QUEUE::~QUEUE( ) {  } 		//销毁队列
int main(int a, char** s)
{
    QUEUE  q(2);			//构造队列，最多10个元素
    q.push(1).push(2).push(3); 		//入队列
    q.print( );   			//打印队列
    QUEUE  r(q); 			//拷贝构造队列
    r.print( );   			//打印队列
    int x=0,y=q.howMany( ); 		//得到队列元素个数
    q.pop(x).pop(y);     		//出队列
    q.print( );   			//打印队列
    x = q.howMany( );    		//得到队列元素个数
    r.assign(q);         			//赋值运算
    r.print( );   			//打印队列
    q.assign((QUEUE&&)r);  		//赋值运算
    q.print( );   			//打印队列
    return r.howMany( );		//返回元素个数0
}
