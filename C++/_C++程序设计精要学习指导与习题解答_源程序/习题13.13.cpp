#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
using namespace std;
template <typename T>
class QUEUE {
    T* const  elems;	    			//申请内存用于存放队列的元素
    const  int   max;	    			//队列能存放的最大元素个数
    int   head, tail;		    		//队列头尾，队列空head=tail;初始时head=tail=0
public:
    QUEUE(int m=10);		   		//初始化队列：最多m-1个元素
    QUEUE(const QUEUE& s); 			//用队列s拷贝初始化队列
    QUEUE(QUEUE&& s)noexcept; 		//用队列s拷贝初始化队列
    virtual operator int( ) const noexcept;		//返回队列的实际元素个数
    virtual int size( ) const noexcept;		//返回队列的实际元素个数
    virtual QUEUE&operator<<(T e); 	        	//将e入队列,并返回队列
    virtual QUEUE&operator>>(T& e);	        	//出队列到e,并返回队列
    virtual QUEUE&operator=(const QUEUE&s);	//赋s给队列,返回被赋值队列
    virtual QUEUE&operator=(QUEUE&&s)noexcept;	//赋s给队列返回该队列
    virtual void print( ) const noexcept;		//打印队列
    virtual ~QUEUE( )noexcept;			//销毁队列
};
template <typename T>
class STACK : public QUEUE<T> {
    QUEUE<T> q;
public:
    STACK(int m=10);            			//初始化栈：最多存放2m-2个元素
    STACK(const STACK& s);       		//用栈s初始化栈
    STACK(STACK&& s)noexcept;    		//用栈s初始化栈
    int  size( )const noexcept;		    	//返回p指向的栈的容量即2m
    operator int( ) const noexcept;	      	//返回p指向的栈的实际元素个数
    STACK& operator<<(T e); 	        		//将e入栈，并返回当前栈
    STACK& operator>>(T& e);      		//出栈到e，并返回当前栈
    STACK& operator=(const STACK& s);		//赋s给等号左边栈,并返回该栈
    STACK& operator=(STACK&& s)noexcept;	//赋s给等号左边栈,并返回该栈
    void print( )const noexcept;			//打印栈元素：从栈底到栈顶
    ~STACK( )noexcept;	       		//销毁p指向的栈
};
template <typename T>
QUEUE<T>::QUEUE(int m): elems(new T[m]), max(elems ? m : 0), head(0), tail(0) 
{   if (elems == nullptr) throw "Memory is not enought!"; }
template <typename T>
QUEUE<T>::QUEUE(const QUEUE<T>&s): elems(new T[s.max]), max(elems?s.max:0){
    if (elems == nullptr) throw "Memory is not enought!";
    for (int x = 0; x < max; x++) elems[x] = s.elems[x];
    head = s.head;
    tail = s.tail;
}
template <typename T>
QUEUE<T>::QUEUE(QUEUE<T>&& s)noexcept: elems(s.elems), max(s.max) {
    head = s.head;   tail = s.tail;
    (T*&)s.elems = nullptr;
    (int&)s.max = s.head = s.tail = 0;
}
template <typename T>
QUEUE<T>::~QUEUE( ) noexcept {
    if (elems) { delete[ ]elems; (T*&)elems = 0; (int&)max = 0; head = tail = 0; }
}
template <typename T>
QUEUE<T>::operator int( ) const noexcept {
    int x = tail - head;
    return tail >= head ? x : x + max;
}
template <typename T>
int QUEUE<T>::size( ) const noexcept { return max; }
template <typename T>
QUEUE<T>& QUEUE<T>::operator=(const QUEUE<T>& s) {
    if (this == &s) return *this;			//防止类似a=a的赋值出问题
    if (elems) delete elems;			//不要调~QUEUE( )：破坏子类STACK对象多态
    (T*&)elems=new T[s.max];			//以下语句不要试图写成new(this)QUEUE(s)
    if (elems == nullptr) throw "Memory is not enought!";
    for (int p = 0; p < s.max; p++) elems[p] = s.elems[p];
    (int&)max = s.max; head = s.head; tail = s.tail;
    return *this;
}
template <typename T>
QUEUE<T>& QUEUE<T>::operator=(QUEUE<T>&& s)noexcept {
    if (this == &s) return *this; 			//防止类似a=( QUEUE<T>&&)a的赋值出问题
    if (elems) delete[ ]elems;  			//不要调~QUEUE( )，会破坏STACK对象多态
    (T*&)elems = s.elems;
    (int&)max = s.max;
    head = s.head;
    tail = s.tail;
    (T*&)(s.elems) = nullptr;
    (int&)(s.max) = s.head = s.tail = 0;
    return *this;
}
template <typename T>
QUEUE<T>& QUEUE<T>::operator<<(T v) {
    if ((tail + 1) % max == head) throw "QUEUE is full!";
    elems[tail] = v;
    tail = (tail + 1) % max;
    return *this;
}
template <typename T>
QUEUE<T>& QUEUE<T>::operator>>(T& v) {
    if (head == tail) throw "QUEUE is empty!";
    v = elems[head];
    head = (head + 1) % max;
    return *this;
}
template <typename T>
void QUEUE<T>::print( ) const noexcept {
    for (int t = head; t != tail; t = (t + 1) % max) {
        cout<<elems[t]<<"  ";
    }
}
template <typename T>
STACK<T>::STACK(int m): QUEUE<T>(m), q(m) { }
template <typename T>			//STACK深拷贝函数调用QUEUE深拷贝函数
STACK<T>::STACK(const STACK& s): QUEUE<T>(s), 
q(s.q) { } 					//同STACK构造一致，基类也要使用深拷贝构造
template <typename T>			//STACK移动拷贝函数调用QUEUE移动拷贝函数
STACK<T>::STACK(STACK<T>&&s)noexcept:QUEUE<T>((QUEUE<T>&&)s), 
q((QUEUE<T>&&)(s.q)) { }			//同STACK构造一致，基类也要使用移动语义
template <typename T>
STACK<T>::~STACK( ) noexcept { }
template <typename T>
STACK<T>::operator int( ) const noexcept {
    return QUEUE<T>::operator int( ) + q.operator int( );
}
template <typename T>
int STACK<T>::size( ) const noexcept { return QUEUE<T>::size( ) + q.size( ); }
template <typename T>			//同STACK一致，深拷贝赋值调QUEUE深拷贝赋值
STACK<T>& STACK<T>::operator=(const STACK<T>& s) {
    if (this == &s) return *this;
    QUEUE<T>::operator=(s);			//调深拷贝赋值函数
    q = s.q;					//调深拷贝赋值函数
    return *this;
}
template <typename T>			//同STACK一致，移动赋值调QUEUE移动赋值
STACK<T>& STACK<T>::operator=(STACK<T>&& s)noexcept {
    if (this == &s) return *this;
    QUEUE::operator=(static_cast<QUEUE&&>(s)); 	//强制转换调移动赋值
    q = static_cast<QUEUE&&>(s.q);		//强制转换调移动赋值
    return *this;
}
template <typename T>
STACK<T>& STACK<T>::operator<<(T e) {
    T v;
    if (QUEUE<T>::operator int( ) <= QUEUE<T>::size( ) - 2) {
        QUEUE<T>::operator<<(e);
        return *this;
    }
    //当基类队列（栈顶部分）满时，试图移动其底部到队列q（栈底部分）
    if (q.operator int( ) == q.QUEUE<T>::size( ) - 1) throw "STACK is full!";
    QUEUE<T>::operator>>(v);
    q << v;
    QUEUE<T>::operator<<(e);
    return *this;
}
template <typename T>
STACK<T>& STACK<T>::operator>>(T& e) {
    int n = QUEUE<T>::operator int( );
    T v,s;
    if (n + q == 0) throw "STACK is empty!";
    if (n != 0) {  //基类队列非空要移除n-1个元素，并出最后一个元素
        for (int k = n - 2; k >= 0; k--) {
            QUEUE<T>::operator>> (v);
            if (q.operator int( ) != q.QUEUE<T>::size( ) - 1) {
                q << v;
                continue;
            }
            q >> s;
            QUEUE<T>::operator<<(s);
            q << v;
        }
        QUEUE<T>::operator>>(e);
        //重新移回队列q，以保持栈底和栈顶先后次序不变
        n = QUEUE<T>::operator int( );
        if (n + q > q.size( ) - 1) n = q.size( ) - 1;
        for (int k = n - 1; k >= 0; k--) {
            QUEUE<T>::operator>>(v);
            if (q.operator int( ) != q.QUEUE<T>::size( ) - 1) {
                q << v;
                continue;
            }
            q >> s;
            QUEUE<T>::operator<<(s);
            q << v;
        }
        return *this;
    }
    //基类队列为空时
    if ((n=q.operator int( )) == 0) throw "STACK is empty!";
    //要移除队列q的n-1元素到基类队列，然后出队列q最后一个元素
    for (int k = n - 2; k >= 0; k--) {
        q >> v;
        QUEUE<T>::operator<<(v);
    }
    q >> e;
    //基类队列元素全部移动到队列q，以保持栈底和栈顶先后次序不变
    for (int k = QUEUE<T>::operator int( ) - 1; k >= 0; k--) {
        QUEUE<T>::operator>>(v);
        q << v;
    }
    return *this;
}
template <typename T>
void STACK<T>::print( )const noexcept {
    q.print( );  				//假定队列q的元素始终在栈的底部
    QUEUE<T>::print( ); 			//再打印栈的顶部部分元素
}
int main( ) {
    double x = 0, y = 0;
    STACK<double> s(3);
    s << 1.1 << 2.2 << 3.3 << 4.4;
    STACK<double> t(s);
    s >> x >> y;
    s.print( ); cout << endl;
    t = s;
    t.print( ); cout << endl;
}
