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

