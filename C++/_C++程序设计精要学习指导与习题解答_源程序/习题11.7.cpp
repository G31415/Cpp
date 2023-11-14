#include <iostream>
using namespace std;
class QUEUE{
    int *const elems; 					//申请内存用于存放队列的元素
    const int length; 					//队列的长度，最多存放length􀀐1 个元素
    int front, tail; 					//队列首尾指针，队列空时front==tail;
public:
    QUEUE(int m); 					//初始化循环队列：长度length=m
    QUEUE(const QUEUE&q); 				//用队列q 深拷贝构造新队列
    QUEUE(QUEUE&& q)noexcept; 			//移动构造：浅拷贝构造新队列
    virtual int Empty( )const;		 		//队列为空时返回1，否则返回0
    virtual int Full( )const; 				//队列为满时返回1，否则返回0
    virtual int Length( )const;				//返回队列长度即length
    virtual int Front( )const; 				//返回队列的队首即front
    virtual int Tail( )const; 				//返回队列的队尾即tail
    virtual int operator[ ] (int x)const; 			//取下标为x 的队列元素
    virtual QUEUE& operator<<(int e); 			//将e 入队列，并返回原队列
    virtual QUEUE& operator>>(int& e); 			//出队列到e，并返回原队列
    virtual QUEUE& operator=(const QUEUE& q); 		//深拷贝赋q 给被赋值队列
    virtual QUEUE &operator=(QUEUE&& q)noexcept; 	//移动赋值：浅拷贝赋值
    virtual void print( )const; 				//输出队列
    virtual ~QUEUE( )noexcept; 				//销毁队列
};

QUEUE::QUEUE(int m): elems(new int[m]), length(elems?m:0), 
front(0), tail(0) { }
QUEUE::QUEUE(const QUEUE& s): elems(new int[s.length]), 
length(elems?s.length:0){
    for (int x = 0; x < length; x++) elems[x] = s.elems[x];
    front = s.front;
    tail = s.tail;
}
QUEUE::QUEUE(QUEUE&& q)noexcept: elems(q.elems), length(q.length) {
    front=q.front;  tail=q.front;
    (int*&)(q.elems) = nullptr; (int&)(q.length) = q.front = q.tail = 0;
}
QUEUE::~QUEUE( ) noexcept {
    if (elems) { delete elems; (int*&)elems = nullptr; (int&)length=front=tail=0; }
}
int QUEUE::Empty( )const { return front == tail; }
int QUEUE::Full( )const { return (tail + 1) % length == front; }
int QUEUE::Length( )const { return length; }
int QUEUE::Front( )const { return front; }
int QUEUE::Tail( )const { return tail; }
int QUEUE::operator[ ] (int x)const {
    if (x < 0 || x >= (tail-front+length) % length) throw "subscription overflowed!";
    return elems[(front + x) % length];
}
QUEUE& QUEUE::operator=(const QUEUE& q) {
    if (this == &q) return *this;				//对于QUEUE x(20); 避免“x=x;”语句出错
    if (elems) delete[ ]elems;				//别用~QUEUE(), 破坏STACK多态性
    (int*&)elems=new int[q.length];			//别用new(this)QUEUE(q); 破坏多态性
    if (elems == nullptr) throw "memory not enough!";
    for (int p = 0; p < q.length; p++) elems[p] = q.elems[p];	//深拷贝赋值
    (int&)length = q.length; front = q.front; tail = q.tail;
    return *this;
}
QUEUE& QUEUE::operator=(QUEUE&& q)noexcept {
    if (this == &q) return *this;
    if (elems) delete[ ]elems;				//别用~QUEUE(), 破坏STACK多态性
    (int*&)elems = q.elems;				//移动语义
    (int&)length = q.length;				//移动语义
    front = q.front;					//移动语义
    tail = q.tail;					//移动语义
    (int*&)(q.elems) = nullptr;				//移动语义
    (int&)(q.length)=q.front=q.tail= 0;			//移动语义
    return *this;
}
QUEUE& QUEUE::operator<<(int v) {
    if ((tail + 1) % length == front) throw "queue is full!" ;
    elems[tail] = v;
    tail = (tail + 1) % length;
    return *this;
}
QUEUE& QUEUE::operator>>(int& v) {
    if (front == tail) throw "queue is empty!";
    v = elems[front];
    front = (front + 1) % length;
    return *this;
}
void QUEUE::print( ) const{
    for (int t = front; t != tail; t = (t + 1) % length)
        cout << elems[t] << "  ";
}
class STACK: public QUEUE{
    QUEUE q;
public:
    STACK(int m); 					//每个队列长度为m
    STACK(const STACK& s); 				//用栈s 深拷贝构造栈
    STACK(STACK&& s) noexcept; 			//浅拷贝移动构造新栈
    virtual operator int ( )const; 				//返回栈的实际元素个数
    virtual int Empty ( )const; 				//返回栈是否已空，空返回1，否则返回0
    virtual int Full ( )const; 				//返回栈是否已满，满返回1，否则返回0
    int operator[ ](int x)const;				//取下标为x的元素，自动成为虚函数
    STACK& operator<<(int e); 				//将e 入栈，并返回栈，自动成为虚函数
    STACK& operator>>(int& e); 			//出栈到e，并返回栈，自动成为虚函数
    virtual STACK& operator=(const STACK& s); 		//深拷贝赋s 并返回被赋值栈
    virtual STACK& operator=(STACK&& s)noexcept; 		//移动赋值：浅拷贝
    void print( )const; 					//输出栈，自动成为虚函数
    ~STACK( )noexcept; 				//销毁栈，自动成为虚函数
};
STACK::STACK(int m) : QUEUE(m), q(m) { }
STACK::STACK(const STACK& s): QUEUE(s), q(s.q) { }
STACK::STACK(STACK&&s)noexcept: QUEUE((QUEUE&&)s), q((QUEUE&&)(s.q)) { }
STACK::~STACK( ) noexcept { }
STACK::operator int( ) const {
    int b=(QUEUE::Tail( )-QUEUE::Front( )+QUEUE::Length( )) % QUEUE::Length( );
    int d=(q.Tail( )-q.Front( )+q.Length( )) % q.Length( );
    return b+d;
}
int STACK::Empty( )const { return operator int( )==0; }
int STACK::Full( )const {
    int b=(QUEUE::Tail( )-QUEUE::Front( )+QUEUE::Length( ))%QUEUE::Length( );
    int d=(q.Tail( )-q.Front( )+q.Length( ))%q.Length( );
    return (b==QUEUE::Length( )-1) && (d==q.Length( )-1);
}
int STACK::operator[ ](int x)const {
    int b=(QUEUE::Tail( )-QUEUE::Front( )+QUEUE::Length( )) % QUEUE::Length( );
    int d=(q.Tail( ) - q.Front( ) + q.Length( )) % q.Length( );
    if (x < 0 || x >= b + d) throw "subscription overflowed!";
    if (x < d) return q[x];
    return QUEUE::operator[ ](x - d);
}
STACK& STACK::operator=(const STACK& s) { 		//栈的深拷贝赋值
    if (this == &s) return *this;				//防止出现a=a的赋值
    QUEUE::operator=(s);				//调用深拷贝赋值，微观和宏观一致
    q = s.q;						//调用深拷贝赋值，微观和宏观一致
    return *this;
}
STACK& STACK::operator=(STACK&& s)noexcept { //栈的移动赋值
    if (this == &s) return *this;				//防止出现a=(STACK&&)a的赋值
    QUEUE::operator=((QUEUE&&)s);			//调用队列的移动赋值，微观和宏观一致
    q = static_cast<QUEUE&&>(s.q);			//调用队列的移动赋值，微观和宏观一致
    return *this;
}
STACK& STACK::operator<<(int e) {
    int v;
    int b=(QUEUE::Tail( )-QUEUE::Front( )+QUEUE::Length( )) % QUEUE::Length( );
    int d=(q.Tail( )-q.Front( )+q.Length( )) % q.Length( );
    if (b < QUEUE::Length( ) - 1) {
        QUEUE::operator<<(e);
        return *this;
    }
    //当队列一满时，试图移动到队列二
    if (d == q.Length( ) - 1) throw "STACK is full!";
    QUEUE::operator>>(v);
    q << v;
    QUEUE::operator<<(e);
    return *this;
}
STACK& STACK::operator>>(int& e) {
    int b=(QUEUE::Tail( )-QUEUE::Front( )+QUEUE::Length( )) % QUEUE::Length( );
    int d=(q.Tail( )-q.Front( )+q.Length( )) % q.Length( );
    int v, p;
    if (b+d == 0) throw "STACK is empty!";
    if (b != 0) {  //队列一非空要移除b-1个元素，出其最后一个元素
        for (int k = b - 2; k >= 0; k--) {
            QUEUE::operator>> (v);
            if ((q.Tail( )-q.Front( )+q.Length( )) % q.Length( ) != q.Length( )-1) {
                q << v;
                continue;
            }
            q >> p;
            QUEUE::operator<<(p);
            q << v;
        }
        QUEUE::operator>>(e);
        //重新移回队列二，以保持宏观上的栈底栈顶先后关系
        b=(QUEUE::Tail( )-QUEUE::Front( )+QUEUE::Length( )) % QUEUE::Length( );
        d=(q.Tail( )-q.Front( )+q.Length( )) % q.Length( );
        if (b + d > q.Length( ) - 1) b = q.Length( ) - 1;
        for (int k = b - 1; k >= 0; k--) {
            QUEUE::operator>>(v);
            if ((q.Tail( )-q.Front( )+q.Length( ))%q.Length( )!=q.Length( ) -1) {
                q << v;
                continue;
            }
            q >> p;
            QUEUE::operator<<(p);
            q << v;
        }
        return *this;
    }
    //队列一空时，试图到队列二q出一个元素
    d = (q.Tail( ) - q.Front( ) + q.Length( )) % q.Length( );
    if (d == 0) throw "STACK is empty!";
    //要移除对列二n-1元素到队一,出队列二最后一个
    for (int k = d - 2; k >= 0; k--) {
        q >> v;
        QUEUE::operator<<(v);
    }
    q >> e;
    //队列一全部移动到队列二q，保持栈底栈顶先后次序
    b=(QUEUE::Tail( )-QUEUE::Front( )+QUEUE::Length( )) 
% QUEUE::Length( );
    for (int k = b - 1; k >= 0; k--) {
        QUEUE::operator>>(v);
        q << v;
    }
    return *this;
}
void STACK::print( )const{
    q.print( );  					//假定队列二q的元素始终在队列一的底部
    QUEUE::print( );  					//再打印栈的顶部队列一的元素
}

