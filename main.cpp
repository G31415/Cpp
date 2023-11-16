#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

// /* 四、指出以下程序的语法错误及其原因 （每错约 1分，共 15 分） */
// class A
// {
//     int a;
// protected:
//     const int &b;
//     ~A() {}

// /* 四、指出以下程序的语法错误及其原因 （每错约 1分，共 15 分） */
// class A
// {
//     int a;

// protected:
//     const int &b;
//     ~A() {}

// public:
//     int c;
//     virtual A (*g)(int);        // 函数声明，不应有virtual
//     A(int x) : b(x) { a = x; }; // b没有初始值
// } x = (4, 3);                   // x初始化语句错误

// class B : A
// {
//     int d;

// public:
//     A::b;                                     // b是引用，没有初始化
//     friend int operator()(int) { return 2; }; // operator必须是成员函数
//     B(int x, int y, int z) { d = x + y + z; };
// } b(5, 6, 7);

// struct C : B
// {
//     int z;

// public:
//     ~C(int x) { z = x; }; // 析构函数不能有参数
// } c;

// void main()
// {
//     int A::*p = &c.z; // 类型指针不能等于int指针
//     int i = x.b;      // 不可访问
//     i = x;            // 没有类型转换函数
//     i = b.b;
//     i = i + c.d; // 不可访问
//     i = b.*p;
//     i = b.*p;
// }

// /* 五、请填入学号最后一位十进制数字 ，指出 main 函数中变量 I 在每条赋值语句执行后的值 （每小题 2.5 分，共 15 分） */
// int x = 7; // 学号最后一位十进制数
// int y = x + 3;
// struct A
// {
//     int x;
//     static int &y;

// public:
//     operator int() const { return x + y; }
//     int &v(int &x)
//     {
//         for (int y = 1; x < 301; x ^= y++)
//         {
//             if (x > 300)
//             {
//                 x -= 31;
//                 y -= 2;
//             }
//             return ++x;
//         }
//     }
//     A &operator++()
//     {
//         ++x;
//         ++y;
//         return *this;
//     }
//     A(int x = A::y + 2, int y = ::x + A::y)
//     {
//         A::x = x + 1;
//         A::y = y + 2;
//     }
// };

// int &A::y = ::y;

// int main()
// {
//     A a(3, 4), b(a), c;
//     int i, &j = i;
//     int A::*p = &A::x;
//     j = a.x;           // i = 4
//     i = a.y;           // i = 15
//     i = a.*p;          // i = 4
//     i = ++a;           // i = 21
//     i = b.y + ::y;     // i = 32
//     (b.v(i) = 3) += 2; // i = 5
//     return 0;
// }

// /* 六、一个 自然数，如果它等于除其本身之外的所有其它不同因子之和，则这个自然数被称为完美数 。例如，6 = 1 + 2 + 3, 28 = 1 + 2 + 4 + 7 + 14。试编写如下完美数类中的所有函数成员的函数体代码（每小题 2.5 分，共15 分） */
// class FER
// {
//     const int n;  // 存放自然数
//     int *const f; // 存放所有有效因子, 所有因子之和等于 n 才是完美数
//     int c;        // 有效因子个数 ：正数表示是完美数 ，负数表示不是
// public:
//     FER(int p);                   // 用自然数 p 初始化 n, f, c
//     FER(const FER &p);            // 深拷贝构造函数
//     FER &operator=(const FER &p); // 深拷贝赋值运算
//     operator int() const;         // 若不是完全数则返回 0，否则返回 c
//     int operator[](int k) const;  // 返回 k 所指示的因子, 若 k < 0 或 k >= c 返回 0
//     ~FER();                       // 析构函数
// };                                // 提示 : f 分配的整型内存单元数量不会超过 n / 2。

// FER::FER(int p) : n(p), f(new int[p / 2])
// {
//     int k = 0;
//     for (int i = 1; i <= p / 2; i++)
//     {
//         if (p % i == 0)
//         {
//             f[k] = i;
//             k++;
//         }
//     }
//     for (int i; i < k; i++)
//     {
//         int p;
//         p += f[i];
//     }
//     if (p == n)
//         c = k;
//     else
//         c = -k;
// }

// FER &FER::operator=(const FER &p)
// {
//     if (this != &p)
//     {
//         delete[] f;
//         *(int *)&n = p.n;
//         *(int **)&f = new int[p.n];
//         c = p.c;
//         for (int i = 0; i < p.n; i++)
//         {
//             f[i] = p.f[i];
//         }
//     }
//     return *this;
// }

// FER::operator int() const
// {
//     return (c > 0) ? c : 0;
// }

// int FER::operator[](int k) const
// {
//     if (k < 0 || k >= c)
//     {
//         return 0;
//     }
//     return f[k];
// }

// FER::~FER()
// {
//     delete[] f;
// }

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// struct A
// {
//     A() { cout << 'A'; }
// };
// struct B
// {
//     B() { cout << 'B'; }
// };
// struct C : A
// {
//     C() { cout << 'C'; }
// };
// struct D : B, virtual C
// {
//     D() { cout << 'D'; }
// };
// // struct E: virtual A, virtual D {
// struct E : A, virtual D
// {
//     D d;
//     E() : A() { cout << 'E'; }
// };
// struct F : B, virtual C, E, virtual D
// {
//     D d;
//     F() { cout << 'F'; }
// };
// void main()
// {
//     A a;
//     cout << "\n"; // 输出=
//     B b;
//     cout << "\n"; // 输出=
//     C c;
//     cout << "\n"; // 输出=
//     D d;
//     cout << "\n"; // 输出=
//     E e;
//     cout << "\n"; // 输出=
//     F f;
//     cout << "\n"; // 输出=
// }

// /* 5.	实现下面的模板队列类： */
// template <typename T>
// class QUEUE
// {                     // 循环队列
//     int *const elems; // elemss申请内存用于存放队列的元素
//     const int max;    // elemss申请的最大元素个数为max
//     int head, tail;   // 队列头head和尾tail，队空head=tail; 初始head=tail=0
// public:
//     QUEUE(int m) : elems(new int[m]), max(m), head(0), tail(0)
//     { // 初始化队列：最多申请m个元素, 内存不足时抛出异常
//         if (elems == nullptr)
//             throw std::bad_alloc();
//     }
//     QUEUE(const QUEUE &q) : elems(new int[q.max]), max(q.max), head(q.head), tail(q.tail)
//     { // 用q深拷贝初始化队列, 内存不足时抛出异常
//         if (elems == nullptr)
//             throw std::bad_alloc();
//         std::copy(q.elems, q.elems + q.max, elems);
//     }
//     QUEUE(QUEUE &&q) noexcept : elems(q.elems), max(q.max), head(q.head), tail(q.tail)
//     { // 用q移动初始化队列
//         q.elems = nullptr;
//     }
//     virtual operator int() const noexcept
//     { // 返回队列的实际元素个数
//         return (tail - head + max) % max;
//     }
//     virtual int size() const noexcept
//     { // 返回队列申请的最大元素个数max
//         return max;
//     }
//     virtual QUEUE &operator<<(int e)
//     { // 将e入队列尾部，并返回当前队列, 队列满时抛出异常
//         if ((tail + 1) % max == head)
//             throw std::runtime_error("Queue is full");
//         elems[tail] = e;
//         tail = (tail + 1) % max;
//         return *this;
//     }
//     virtual QUEUE &operator>>(int &e)
//     { // 从队首出元素到e，并返回当前队列, 队列空时抛出异常
//         if (head == tail)
//             throw std::runtime_error("Queue is empty");
//         e = elems[head];
//         head = (head + 1) % max;
//         return *this;
//     }
//     virtual QUEUE &operator=(const QUEUE &q)
//     { // 深拷贝赋值, 内存不足时抛出异常
//         if (this != &q)
//         {
//             int *new_elems = new int[q.max];
//             if (new_elems == nullptr)
//             {
//                 throw std::bad_alloc();
//             }
//             std::copy(q.elems, q.elems + q.max, new_elems);
//             delete[] elems;
//             *(int **)&elems = new_elems;
//             *(int *)&max = q.max;
//             head = q.head;
//             tail = q.tail;
//         }
//         return *this;
//     }
//     virtual QUEUE &operator=(QUEUE &&q) noexcept
//     { // 移动赋值并返回被赋值队列
//         if (this != &q)
//         {
//             delete[] elems;
//             *(int **)&elems = q.elems;
//             *(int *)&max = q.max;
//             head = q.head;
//             tail = q.tail;
//             *(int **)&q.elems = nullptr;
//         }
//         return *this;
//     }
//     virtual char *print(char *s) const noexcept
//     {
//         char *p = s;
//         for (int i = head; i != tail; i = (i + 1) % max)
//         {
//             string elementString = to_string(elems[i]);
//             const char *elementChars = elementString.c_str();
//             int len = strlen(elementChars);
//             memcpy(p, elementChars, len);
//             p += len;
//             if (i != (tail - 1 + max) % max)
//             {
//                 *p++ = ' ';
//             }
//         }
//         *p = '\0';
//         return s;
//     }

//     virtual ~QUEUE()
//     { // 销毁当前队列
//         delete[] elems;
//     }
// };

// /* 6.	实现下面的堆栈类：用2个队列（基对列和对象队列q）模拟一个堆栈。 */

// class STACK : public QUEUE
// {
//     QUEUE q;

// public:
//     STACK(int m) : QUEUE(m), q(m) {}                                      // 初始化栈：最多存放2m-2个元素
//     STACK(const STACK &s) : QUEUE(s), q(s.q) {}                           // 用栈s深拷贝初始化栈
//     STACK(STACK &&s) noexcept : QUEUE(std::move(s)), q(std::move(s.q)) {} // 用栈s移动拷贝初始化栈
//     int size() const noexcept
//     { // 返回栈的容量即2m
//         return 2 * QUEUE::size();
//     }
//     operator int() const noexcept
//     { // 返回栈的实际元素个数
//         return static_cast<int>(*this);
//     }
//     STACK &operator<<(int e)
//     { // 将e入栈，并返回当前栈
//         if (q.size() == 0)
//         {
//             q << e;
//             while (QUEUE::operator int() > 0)
//             {
//                 int temp;
//                 QUEUE::operator>>(temp);
//                 q << temp;
//             }
//         }
//         else
//         {
//             QUEUE::operator<<(e);
//         }
//         return *this;
//     }
//     STACK &operator>>(int &e)
//     { // 出栈到e，并返回当前栈
//         if (q.size() > 0)
//         {
//             q >> e;
//         }
//         else
//         {
//             QUEUE::operator>>(e);
//         }
//         return *this;
//     }
//     STACK &operator=(const STACK &s)
//     { // 深拷贝赋值并返回被赋值栈
//         QUEUE::operator=(s);
//         q = s.q;
//         return *this;
//     }
//     STACK &operator=(STACK &&s) noexcept
//     { // 移动赋值并返回被赋值栈
//         QUEUE::operator=(std::move(s));
//         q = std::move(s.q);
//         return *this;
//     }
//     char *print(char *s) const noexcept
//     { // 从栈底到栈顶打印栈元素到缓冲区s, 并返回s
//         char *p = s;
//         p = QUEUE::print(p);
//         p = q.print(p);
//         return s;
//     }
//     ~STACK() noexcept {} // 销毁栈
// };

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// int main(){
// 	long a;
// 	printf("输入:\n");
// 	scanf("%ld", &a);
// 	long a6=0, a7=0, a9=0, a11=0, a0=a;
// 	for(int i=1; i<=11; i++){
// 		a = a * a;
// 		a = a % 3233;
// 		printf("%d  %ld\n", i, a);
// 		switch(i){
// 			case 6: a6=a; break;
// 			case 7: a7=a; break;
// 			case 9: a9=a; break;
// 			case 11: a11=a; break;
// 			default : break;
// 		}
// 		if(i == 11){
// 			long p = (a0 * a6 ) % 3233;
// 			long q = (a7 * a9) % 3233;
// 			a = (p * q) % 3233;
// 			a=(a*a11)%3233;
// 			printf("%d \n", a);
// 		}
// 	}
// 	return 0;
// }

// /* 四、	指出以下程序的语法错误及其原因 (每错约1分，共15分) */
// class A {
// 	int &a;	//引用类型的成员变量必须在声明时初始化，否则会导致编译错误
// protected:
// 	const int &b;  //引用类型的成员变量必须在声明时初始化，否则会导致编译错误
// 	~A( ) { }
// public:
// 	int  c;
// 	virtual A&  (*g)( );
// 	A(int x) { b=x; };	// b为const不能在里边修改
// } a=(1, 2, 3);	// 构造a时不能用 =	（没有赋值函数将A(3)赋给a
// class B: A {
// 	int  d;
// public:
// 	A::b;
// 	static int operator( )(int) { return 3; }; //运算符重载不能时静态
// 	B(int x, int y, int z):A(x) { d=x+y+z; };
// }b(2, 3, 7);
// struct C: B {
// 	int z;
// protected:
// 	virtual ~C( ) {  };
// }c;
// void  main( ) {
// 	int * A::*p=&c.z;
// 	int  i=a.b;	//a.b不可访问
// 	i=a;	//A中没有强制类型转换函数
// 	i=b.b;
// 	i=c.d;	//c不能访问B中的d
// 	i=b.*p;	//b是对象，p是指向C类的成员变量z的指针，无法通过B类的对象b来访问C类的成员变量z。应该修改为：i=c.*p;
// 	return 1;	//main函数没有返回值
// }

// /* 五、请填入学号最后一位十进制数字，指出main函数中变量i在每条赋值语句执行后的值 (每小题2.5分，共15分) */
// int   x = 2   ,  y=x+3;
// struct A {
// 	int  x;
// 	static int &y;
// public:
// 	operator int( ) const { return x+y; }
// 	int &v(int &x) {
// 		for(int y=1; x<201; x^=y, y++)
// 			if(x>200) { x-=31; y-=2;}
// 		 return ++x;
// 	}
// 	A &operator++( ){ ++x; ++y; return *this; }
// 	A(int x=::x+2, int y=::y+3){ A::x=x;  A::y=y; }
// };
// int & A::y=::x;
// int main( ){
// 	A  a(2, 3),  b(a),  c;
// 	int  i,  &j=i,  A::*p=&A::x;
// 	i=a.y; 			printf("%d\n",i);	//i=13
// 	j=a.x++; 		printf("%d\n",i);	//i=2
// 	i=a.*p;			printf("%d\n",i);    //i=3
// 	i=++a; 			printf("%d\n",i);    //i=18
// 	i=b.y+::y;		printf("%d\n",i);	//i=24
// 	(b.v(i)=2)+=3;	printf("%d\n",i);    //i=5
//     return 0;
// }

// /* 六、N个顶点的无向图MAP最多有N*(N-1)条边，设顶点的编号为0, 1, …, N-1，每条边由
// 其中任意两个顶点连接而成，试定义如下无向图类中的成员函数。(每小题2.5分，共15分) */
// class MAP {
//     int (*const e)[2];	//边集指针e,边x的顶点为e[x][0]和e[x][1]
//     const int n;       	//图的顶点个数
//     int c;             	//图实际已有的边的个数
// public:
//     MAP(int n):e(new int [n*(n-1)/2][2]),n(n),c(0) {}//图最多n个顶点，假设图初始时无边
//     MAP(const MAP& m):e(new int [m.n*(m.n-1)/2][2]),n(m.n),c(m.c) {//深拷贝构造函数
//         for(int i=0;i<c;i++){
//             e[i][0]=m.e[i][0];
//             e[i][1]=m.e[i][1];
//         }
//     }
//     MAP& operator=(const MAP& m){ //深拷贝赋值函数
//         if (this != &m) {
//             delete[] e;
//             *(int **)&e =(int *) new int[m.n*(m.n-1)/2][2];
//             *(int*)&n = m.n;
//             c = m.c;
//             for (int i = 0; i < c; i++){
//                 e[i][0] = m.e[i][0];
//                 e[i][1] = m.e[i][1];
//             }
//         }
//         return *this;
//     }
//     MAP& operator( )(int v0, int v1){//连接顶点v0和v1成边,设v0<v1
//         e[c][0] = v0;
//         e[c][1] = v1;
//         c++;
//         return *this;
//     }
//     int(*operator[ ](int x))[2]{//取图中的边x
//         return &e[x];
//     }
//     ~MAP( ){//析构函数
//         delete[] e;
//     }
// };

// struct A { A( ) { cout<<'A'; } };
// struct B { B( ) { cout<<'B'; } };
// struct C: virtual A { C( ) { cout<<'C'; }} ;
// struct D: B, virtual C { D( ) { cout<<'D'; } };
// struct E: virtual A, virtual D {
//     D  d;
//     E( ): A( ) { cout<<'E'; }
// };
// struct F: virtual C, B, virtual D, virtual E {
// 	D d;  E e;
// 	F( ) { cout<<'F'; }
// };
// int main( ) {
//     A  a;  cout<<'\n'; 	//输出=A
//     B  b;  cout<<'\n';	//输出=B
//     C  c;  cout<<'\n';	//输出=AC
//     D  d;  cout<<'\n';	//输出=ACBD
//     E  e;  cout<<'\n';	//输出=ACDBDAE
//     F  f;  cout<<'\n';	//输出=ACDBDEBBDDAEF
// }

// struct A { virtual int f( ) { return 1; } } a;
// struct B: A {
//         int f( ) const { return 2; }
//     int f( ) volatile { return 3; }
//         int f( ) const volatile { return 4; }
// } c;
// int main(int argc, char *argv[ ]) { A *p=&c;printf("%d",p->f( )); return p->f( ); }

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// /* 3. 分析如下定义是否正确，并指出错误原因。 */
// struct A {
// 	char *a, b, *geta( );
// 	char A::*p;
// 	char *A::*q( );  //函数指针声明时要加(),char *(A::*q)( );
// 	char *(A::*r)( );
// };
// char* A::geta(){}
// int main(void) {
// 	A a;
// 	//a.p = &A::a;	a是char*类型的，p是char类型的指针（也可将a定义成char类型）
// 	a.p = &A::b;
// 	//a.q = &A::geta;	函数指针q声明错误
// 	//a.r = a.geta;   函数指针r不能等于a.geta的返回值
// 	char **l;
// 	//a.r = &a.geta;	应用类名来取函数指针，用对象是错的
// 	a.r = &A::geta;
// }

// /* 4. 分析如下定义是否正确，并指出错误原因。 */
// //静态变量不能在定义时设置缺省值，改后：
// struct A {
// 	static int x; 	//不能在类中直接赋值
// 	static const int y;
// 	static const volatile int z;
// 	static volatile int w;
// 	static const float u;
// };
// 	static int A::x = 11;	//不能指明 static
// 	int A::y = 22; 	//要加const
// 	int volatile A::z = 33;	//要加const
// 	int volatile A::w = 44;
// 	const float A::u = 55.0f;

// /* 5. 分析如下定义是否正确，并指出错误原因。 */
// struct A {
// 	static int *j, A::*a, i[5];
// public:
// 	int x;
// 	static int &k, *n;
// };
// int y = 0;
// int A::i[5] = {1, 2, 3};
// int *A::j = &y;
// int A::*j = &A::x;
// int A::*A::a = &A::x;
// int &A::k = y;
// int *A::n = &y;

// int main(){
// 	printf("%d ",y);
// 	printf(" %d %d %d  ",A::i[0],A::i[1],A::i[2]);
// 	printf("%d ",*A::j);
// 	printf("%d ",::j);
// 	printf("%d ",A::k);
// 	printf("%d ",*A::n);
// 	return 0;
// }
// //输出0  1 2 3  0 0 0 0 （好像没问题）

// /* 6. 分析如下定义是否正确，并指出错误原因。 */
// class A {
// 	int a;
// 	static friend int f( );
// 	//静态函数不能成为友元函数，因为静态函数不依赖于任何对象，
// 	//而友元函数需要访问对象的非公有成员,可以去掉static
// 	friend int g( );
// public:
// 	friend int A( );//A是新函数的话没有函数体。A是构造函数的话，这个语句应去掉。
// 	A(int x): a(x) { };
// } a(5);
// int f( ) { return a.a; }
// int g( ) { return a.a; }

// /* 7. 分析如下定义是否正确，并指出错误原因。 */
// struct A {
//     int x = 1;
//     volatile mutable int y = 2;
//     const mutable int z = 3;	//const与mutable相矛盾
//     static mutable int q = 4;	//static与mutable相矛盾
//     extern int p = 5;	//类成员的存储类无效
//     static int t;
//     int f( ) { return ++x; }
// 	int g( ) const { return ++y; }
// 	int h( ) const { return ++x; }	//函数用const修饰，x的值不能改变
// 	mutable int e( ) { return x; }	//mutable不能修饰函数成员
// } a;
// extern int p1 = 0;
// a.f( );	//在全局作用域中调用成员函数是错误的，应该在main函数中调用。
// int main( ) {
//     const A b;
//     a.t = -1;
//     a.x = 10;
//     a.y = 11;
//     a.f( );
//     b.x = 20;	//b是一个const对象，x不能改变。
//     b.y = 21;
//     b.f( );	//b是一个const对象，不能调用非const成员函数。
// }

// /* 8. 一个程序由2个模块1.cpp和2.cpp组成。分析下面的程序，指出错误原因，并指出m( )和main( )中每条正确的语句所访问的内容。 */
// //1.CPP
// namespace A {
// 	int y = 2;
// 	int g( ) { return -2; }
// 	extern int f( );
// }
// using namespace A;
// int x = 11;
// int y = 22;
// int f( ) { return 1; }
// int g( ) { return 2; }
// namespace A {
// 	int z = 3;
// 	int f(int x) { return x; }
// 	extern int f( );
// }
// void m( ) {
//     h( );	//没有h()函数
// 	f(1);
// 	f( );	//f()函数多次定义，应加修饰::或A::
//     g( );	//有多个g()函数，应加修饰::或A::
// 	::f( );
// 	A::g( );
// 	cout << y;	//应加修饰::或A::
// 	cout << z;
// }

// //2.CPP
// namespace A {
// 	int x = -1;
// 	int y = -2;
// 	int f( ) { return 1; }
// 	int h( ) { return 0; }
// }
// using A::h;
// using A::x;
// using A::t;
// using A::g;
// float x = 0;
// namespace A {
// 	int h(int x) { return x; }
// 	int t;
// }
// int main( ) {
// 	h(1);
// 	return z;	//没有z
// }

// /* 9. 完成下面堆栈类STACK和REVERSE类的函数成员定义。  */
// class STACK {
// 	const int max; 		//栈能存放的最大元素个数
// 	int  top; 			//栈顶元素位置
// 	char *stk;
// public:
// 	STACK(int max): max(max), top(-1) {
// 		stk = new char[max];
// 	}
// 	~STACK( ){ delete[] stk; }
// 	int push(char v){	//将v压栈，成功时返回1，否则返回0
// 		if(top<max-1){
// 			stk[++top]=v;
// 			return 1;
// 			}
// 		else return 0;
// 	}
// 	int pop(char &v){	//弹出栈顶元素，成功时返回1，否则返回0
// 		if (top == -1) return 0;
// 		v = stk[top--];
// 		return 1;
// 	}
// };
// class REVERSE: STACK {
// public:
// 	REVERSE(const char *str):STACK(strlen(str)){ //将字符串的每个字符压栈
// 		for (int i = 0; i < strlen(str); i++) push(str[i]);
// 	}
// 	~REVERSE( ){	 //按逆序打印字符串
// 		char v;
// 		while (pop(v)) cout << v;
// 		cout << endl;
// 	}
// };
// int main() {
// 	REVERSE a("abcdefg");
// 	return 0;
// }
// //输出：gfedcba

// /* 10. 找出下面的错误语句，说明错误原因。然后，删除错误的语句，指出类A、B、C可访问的成员及其访问权限。 */
// class A {
// 	int a1;	//private
// protected:
// 	int a2; //protected
// public:
// 	int a3; //public
// 	~A( ) { }; 	//public
// };
// class B: protected A { //可访问a2,a3
// 	int b1; //private
// protected:
// 	int b2; //protected
// public:
// 	// A::a1;
// 	// A::a2; a1,a2不可访问，要用using修改访问权限
// 	int b3; //public
// 	~B( ) { }; //public
// };
// struct C: private B { //不可访问A和B类（之后修改了b2的访问权限）
// 	int c1; //private
// protected:
// 	int c2; //protected
// 	//B::A::a2;  A::a2不可访问，要用using修改访问权限
// 	//A::a3; A::a3不可访问，要用using修改访问权限
// public:
// 	using B::b2; //修改了b2的访问权限为public
// 	int c3; //public
// 	int a3; //将上面a3去掉则可通过，覆盖了a3 public
// 	~C( ) { };//public
// };
// int main() {
// 	C c;
// 	cout << c.b2;
// 	//cout << c.B::b2; c对B是私有继承，不可访问
// }

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// /* 1.	分析下面的程序，指出错误之处（解释错误原因），并写出main()函数中每条正确的指令的屏幕输出结果。 */
// struct A {
// 	int a = 0;
// 	int x = 1;
// 	void f() { cout << "A::f()"; }
// 	virtual void g() { cout << "A::g()"; }
// 	A(int x) { }
// };
// struct B: A {
// 	int x = 11;
// 	int y = 12;
// 	virtual void f() { cout << "B::f()"; }
// 	void g() { cout << "B::g()"; }
// 	void h() { cout << "B::h()"; }
// 	B(int x): A(x) { }
// };
// struct C: B {
// 	int x = 21;
// 	int y = 22;
// 	int z = 23;
// 	void f() { cout << "C::f()"; }
// 	void g() { cout << "C::g()"; }
// 	virtual void h() { cout << "C::h()"; }
// 	C(int x): B(x) { }
// } c(1);
// int main() {
// 	A *p = &c;
// 	p->f();
// 	p->g();
// 	//p->h(); 类 "A" 中没有h函数  改为：
// 	c.h();
//  	cout << p->a;
// 	cout << p->x;
// 	//cout << p->y;  类 "A" 没有成员 "y"
// 	//cout << p->z;  类 "A" 没有成员 "z"  改为：
// 	cout << c.y;
// 	cout << c.z;
// 	B *q = &c;
// 	q->f();
// 	q->g();
// 	q->h();
// 	cout << p->a;
// 	cout << q->x;
// 	cout << q->y;
// 	//cout << q->z;	类 "B" 没有成员 "z"
// 	cout << c.z;
// }
// // 输出:	A::f()C::g()C::h()012223C::f()C::g()B::h()0111223

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// /* 2.	指出如下各类可访问的成员及成员的访问权限。 */
// class A {
// 	int  a; //	private
// protected:
// 	int  b; //	protected
// public:
// 	int  c; //	public
// 	~A( ); //	public
// };
// class B: A { //继承A的 a,b,c  private
// 	int  a; //	private
// protected:
// 	using A::b; 	//修改A中b访问权限为 protected
// public:
// 	int  c, d; 	//	public
// };
// class C: protected A { //继承A的 a private  b protected  c protected
// 	int  a; // private
// protected:
// 	int  b, e; // protected
// public:
// 	int  g; //	public
// 	using A::c; //修改A中c访问权限为 public
// };
// struct D: B, C {  //继承B和C的数据成员且权限不变
// 	int a; // private
// protected:
// 	int b, f; // protected
// public:
// 	int e, g; // public
// };

// /* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// /* 3.	指出如下程序的错误之处及其原因：  */
// class A {
// 	int x;
// 	virtual int f( ) { return 0; }
// 	virtual int g( ) = 0;
// protected:
// 	int  y;
// public:
// 	virtual A( ) { } //构造函数不能用virtual修饰, 执行构造函数前对象尚未完成创建，虚函数表还不存在。
// } a; //有纯虚函数，类不完整，是抽象类，不能构造对象。
// struct B: A {
// 	A::x;		//x是A的私有成员
// 	using A::y;
// 	long f()  { return 1L; }; //函数与基类A中的虚函数f的返回类型不一致，导致函数重写错误。
// 	int g(int) { return 1; }
// } b; //A::g( )函数没重写，导致B为抽象类，不能构造对象。
// A *p = new A; //不允许使用抽象类类型 "A" 的对象:
// B *q = new B; //不允许使用抽象类类型 "B" 的对象
// int f(A, B); //不允许使用抽象类类型 "A" 和 "B" 的参数
// A g(B &); //函数返回值不能是抽象类型 "A"
// int h(B *);

// /* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// /* 4. 指出如下程序中main()中每行语句的输出结果。 */
// struct A { A( ) { cout << 'A'; } };
// struct B { B( ) { cout << 'B'; } };
// struct C: A { C( ) { cout << 'C'; } };
// struct D: A, virtual B { D( ) { cout << 'D'; } };
// struct E: A, virtual B, virtual C {
// 		D d;
// 		E( ) { cout << 'E'; }
// };
// struct F: A, virtual B, virtual C, D, E {
// 	C  c;
// 	E  e;
// 	F( ) { cout << 'F'; }
// };
// int main()
// {
// A  a;	// A
// B  b;	// B
// C  c;	// A C
// D  d;	// B A D
// E  e;	// B AC A BAD E
// F  f;	// B AC A AD ABADE AC BACABADE F(字母中间都没有括号)
// }
// //输出:		ABACBADBACABADEBACAADABADEACBACABADEF

// /* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// /* 4. 写出下面main()函数中每条指令的执行结果。 */
// struct A {
//         int  i;
//         A(int v) { i=v; printf("A(%d) ",i); }  //构。
// 		A(const A &a) { i=a.i; printf("A(A&) "); } //拷贝
// 		~A( ) { printf("~A(%d) ",i); } //析构
//         operator int() const { printf("int() "); return i; } //强制类型转换为int
//         A &operator=(const A &a) {  // =运算符重。
//             printf("=() ");
//             i=a.i;
//             return *this;
//         }
// };
// int main(void)
// {
//     A x=1;  //创建一个A对象x，调用A(int v)构造函数，输出 "A(1) "。
//     x=1;   //。1转换成A型，输出"A(1) ",调用operator=(const A& a)函数，给x赋值，输出 "=() "，最后将A(1)析构，输。"~A(1) "。
//     A y=x; //创建一个A对象y，调用A(const A& a)拷贝构造函数，输出 "A(A&) "。
//     y=x;   //将y赋值为x，调用operator=(const A& a)函数，输。 "=() "。
//     x=1+x;  //将x强制类型转换为int，输。"int() ",再构造A(1+x),输出"A(2) ",调用=重载函数,给x赋值，输出"=() ",最后将A(2)析构,输出"~A(2) "。
//     A z(x+y);  //创建一个A对象z，强制转换x和y，输出两。"int() ",调用A(int v)构造函数，输出 "A(3) "。
//     printf("%d %d", y, (int)y);  //先类型转换，后传值，会用拷贝函数，输出y的值和将y转换为int类型的值，输出 "431243 3"，最后析构拷贝进来的A(1)。
// 	//最后析。 z y x
//     return 0;
// }
// // 输出:A(1) A(1) =() ~A(1) A(A&) =() int() A(2) =() ~A(2) int() int() A(3) int() A(A&) 一堆数 1~A(1) ~A(3) ~A(1) ~A(2)

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// /* 5. 字符串类的类型声明如。   *//* 试定义字符串复制及连接等函数成员（尽量调用C的字符串函数）。 */
// class strlen {
//     char *str;
// public:
// 	int strlen() const{ //返回字符串的长度
// 		int i;
// 		for(i=0;this->str[i]!='\0';i++) ;
// 		return i;
// 	}
// 	int strcmp(const strlen &s) const{ //字符串比。
// 		int i=0;
// 		for(;this->str[i]!='\0'&&s.str[i]!='\0';i++){
// 			i=this->str[i]-s.str[i];
// 			if(i!=0) return i;
// 		}
// 		if(this->str[i]=='\0'&&s.str[i]=='\0') return 0;
// 		else if(this->str[i]!='\0'&&s.str[i]=='\0') return 1;
// 		else return -1;
// 	}
// 	strlen &strcpy(const strlen &s){ //深拷贝赋。
// 		delete[] str;
// 		int len=s.strlen();
// 		str=new char[len+1];
// 		for(int i=0;i<=len;i++) str[i]=s.str[i];
// 		return *this;
//  	}
// 	strlen &strcat(const strlen &s){ //将字符串s尾加到当前字符串
// 		int i=s.strlen();
// 		int I=this->strlen();
// 		str=(char*)realloc(str, (I+i+1)*sizeof(char));
// 		for(int n=I;n<=I+i;n++) this->str[n]=s.str[n-I];
// 		return *this;
// 	}
// 	strlen &operator+=(const strlen &s){ //实现strcat()的功。
// 		this->strcat(s);
// 		return *this;
// 	}
// 	strlen(const char *s){
// 		int i;
// 		for(i=0;s[i]!='\0';i++) ;
// 		str=new char[i+1];
// 		for(int I=0;I<=i;I++) this->str[I]=s[I];
// 	}
// 	~strlen(){
// 		delete[] str;
// 	}
// };
// int main()
// {
// 	strlen s1("I like apple");
// 	strlen s2(" and pear");
// 	strlen s3(" and orange");
// 	std::cout << "Length of s1=" << s1.strlen( ) << "\n";
// 	s1.strcat(s2) += s3;
// 	std::cout << "Length of s1=" << s1.strlen( ) << "\n";
// 	s3.strcpy(s2).strcpy(s1);
// 	std::cout << "Length of s3=" << s3.strlen( ) << "\n";
// 	return 0;
// }

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

/* 6. 完成下面字典类的成员函数。 */
// class DICT {
// 	char **const words;			//存放单词
// 	const int max;				//字典可以存放单词的个。
// 	int pos;					//当前可以存放单词的空闲位。
// public:
// 	DICT(int max):words(new char*[max]),max(max),pos(0)	//max为最大单词个。
// 	{
// 		for (int i=0; i<max; i++)words[i]=0;
// 	}
// 	DICT(const DICT &d):words(new char*[d.max]),max(d.max),pos(d.pos)	//深拷贝构造。
// 	{
// 		for (int i=0; i<pos; i++) {
// 			int len=strlen(d.words[i]);
// 			words[i]=new char[len+1];
// 			strcpy(words[i], d.words[i]);
// 		}
// 		for (int i=pos; i<max; i++)	words[i]=0;
//     }
// 	DICT(DICT &&d) noexcept:words(d.words),max(d.max),pos(d.pos)	//移动构造。
// 	{
//         *(char***)&d.words=0;
//         *(int *)&d.max=0;
// 		d.pos=0;
// 	}
// 	virtual ~DICT( ) noexcept	//析构
// 	{
// 		for (int i=0; i<pos; i++) {delete[] words[i];}
// 		delete[] words;
// 	}
// 	virtual DICT &operator=(const DICT &d)	//深拷贝赋值。
// 	{
// 		if (this == &d) return *this;
// 		for (int i=0; i<pos; i++) delete[] words[i];
// 		delete[] words;
//         *(char***)&words=new char*[d.max];
//         *(int *)&max=d.max;
//         pos=d.pos;
// 		for (int i=0; i<pos; i++) {
// 			int len=strlen(d.words[i]);
// 			words[i]=new char[len+1];
// 			strcpy(words[i], d.words[i]);
// 		}
// 		return *this;
// 	}
// 	virtual DICT &operator=(const DICT &&d) noexcept	//移动赋值。
// 	{
// 		if (this == &d) return *this;
// 		for (int i=0; i<pos; i++) delete[] words[i];
// 		delete[] words;
//         *(char***)&words=d.words;
// 		*(char***)&d.words=0;
// 		*(int *)&max=d.max;
//         *(int *)&d.max=0;
//         pos=d.pos;
//         *(int *)&d.pos=0;
// 		return *this;
// 	}
// 	virtual int operator()(const char *word) const	//查找单词位置,-1表示没找到。
// 	{
// 		for (int i=0; i<pos; i++) if(!strcmp(words[i], word)) return i;
// 		return -1;
// 	}
// 	virtual DICT &operator<<(const char *word)	//若字典中没有该单词则加入。
// 	{
// 		if (pos<max) {
// 			if((*this)(word)==-1){
// 				words[pos]=new char[strlen(word)+1];
// 				strcpy(words[pos], word);
// 				pos++;
// 			}
// 	    }
// 		return *this;
//     }
// 	virtual DICT &operator>>(const char *word)	//删除字典中的这个单词,后面的单词往前移。 //字典中的单词保持连续存放
// 	{
// 		int index=(*this)(word);
// 		if (index != -1) delete[] words[index];
// 		for (int i=index; i<pos-1; i++){
// 			words[i]=words[i+1];
// 		}
// 		words[pos-1]=nullptr;
// 		pos--;
// 		return *this;
// 	}
// 	virtual const char *operator[](int n) const	//取出第n(n>=0)个单词.
// 	{
// 		if (n>=0&&n<pos) return words[n];
// 		return nullptr;
// 	}
// };
// int main(){
//     DICT a(10);
//     a.words[0]=(char*)"hello";
//     a.words[1]=(char*)"world";
//     a.pos=2;
//     for(int i=0;i<a.pos;i++) cout<<a.words[i]<<" ";
//     return 0;
// }

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// /* 7. 分析mian( )函数中每条语句的变量i的值。 */
// int x=1;
// int y=::x+1;	//y=2
// struct A {
// 	int x;
// 	static int y;
// 	A &operator+=(A &a) { x += a.x; y += a.y; return *this; }
// 	operator int() { return x+y; }
// 	A(int x=::x+1, int y=::y+10): x(x) { this->y=y; }
// };
// int A::y=100;	//类的y。100
// int main() {
// 	A a(1,2), b(3), c;	//a(x=1,y=2)类中的y变成2  b(x=3,y=12)类中的y变成12  c(x=2,y=12)类中的y变成12
// 	/* 此时 a(x=1,y=12) b(x=3,y=12) c(x=2,y=12) */
// 	int i, *p=&A::y;
// 	i=b.x+b.y;	//b中的x和共有y的和 i=3+12=15
// 	i=*p;	//*p是公共y的别。 i=12
// 	i=c;	//强制类型转换。 i=2+12=14
// 	i=a+c;	//两个强制类型转换  i=(1+12)+(2+12)=27
// 	i=b += c;	//+=符号重载，再类型转换 b(x=5,y=24) 类中的y变成24 i=5+24=29
// 	/* 此时 a(x=1,y=24) b(x=5,y=24) c(x=2,y=24) */
// 	i=((a+=c)=b)+10;	//a(x=3，y=48) y变成48 后拷贝b给a，a(x=5，y=48) 再强制类型转。 i=(5+48)+10=63
// }

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// /* 假设有一个类A和一些语。  //分析这个程序缺少哪些函数？写出这些缺失函数的所有可能的原型（函数声明），并将main( )函数翻译成函数调用的形式。 */
// struct A {
//     A() {}
//     float operator+(const A& x,int y){}
//     float operator-(const A& x,A y){}
// };
// float A::operator+(int y,A x){}
// int A::operator(const char* s,int x,float y){}
// int main(){
//     A a1, a2;
//     float x=operator+(a1, 1);
//     float y=operator+(1, a1);
//     float z=operator-(operator-(a1, a2), 1);
//     int k=a1.operator()("abc", 1, 1.0);
// }

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// /*  下面是二叉树类的定义，请完成各个成员函数。 */
// class TREE {
// 	int  item; //节点的。
// 	TREE  *left, *right; //左、右子树
// 	public:
// 	TREE(int item); //构造树  //item为根节点、左右子树为null
// 	TREE(int item, TREE *left, TREE *right); //构造树  //item为根节点、左右子树为left、right
// 	~TREE( );
// 	int  getNodeNum( );	//返回节点总数
// 	int  getNodes(int items[ ]); //将所有的节点的值保存到items[ ]。
// };
// TREE::TREE(int item){
// 	this->item=item;
// 	left=right=NULL;
// }
// TREE::TREE(int item, TREE *left, TREE *right){
// 	this->item=item;
// 	this->left=left;
// 	this->right=right;
// }
// TREE::~TREE() {
// 	delete left;
// 	delete right;
// }
// int TREE::getNodeNum(){
// 	int count=1;
// 	if (left != NULL) count += left->getNodeNum();
// 	if (right != NULL) count += right->getNodeNum();
// 	return count;
// }
// int TREE::getNodes(int items[]){
// 	static int index=0;
// 	items[index++]=item;
// 	if (left != NULL) left->getNodes(items);
// 	if (right != NULL) right->getNodes(items);
// 	return index;
// }

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// /*  线性表通常提供元素查找、插入和删除等功能。以下线性表是一个整型线性表。
//      表元素存放在动态申请的内存中，请编程定义整型线性表的函数成员。 */
// class INTLIST {
// 	int  *list; 			//动态申请的内存的指。
// 	int  size; 			//线性表能够存放的元素个。
// 	int  used; 			//线性表已经存放的元素个。
// 	public:
// 	INTLIST(int s); 		//s为线性表能够存放的元素个。
// 	int insert(int v); 		//插入元素v成功时返。1，否则返。0
// 	int remove(int v); 	//删除元素v成功时返。1，否则返。0
// 	int find(int v); 		//查找元素v成功时返。1，否则返。0
// 	int get(int k); 		//取表的第k个元素的值作为返回。
// 	~INTLIST( );
// };
// INTLIST::INTLIST(int s) : size(s), used(0) {
//     list=new int[size];
// }
// INTLIST::~INTLIST() {
//     delete[] list;
// }
// int INTLIST::insert(int v) {
//     if (used >= size) {
//         return 0; // 线性表已满，插入失。
//     }
//     list[used]=v;
//     used++;
//     return 1; // 插入成功
// }
// int INTLIST::remove(int v) {
//     for (int i=0; i<used; i++) {
//         if (list[i] == v)            {
//             // 将后面的元素向前移动一个位置，覆盖要删除的元素
//             for (int j=i; j<used-1; j++) {
//                 list[j]=list[j+1];
//             }
//             used--;
//             return 1; // 删除成功
//         }
//     }
//     return 0; // 元素不存在，删除失败
// }
// int INTLIST::find(int v) {
//     for (int i=0; i<used; i++) {
//         if (list[i] == v) {
//             return 1; // 元素存在
//         }
//     }
//     return 0; // 元素不存。
// }
// int INTLIST::get(int k) {
//     if (k >= 0 && k<used) {
//         return list[k]; // 返回第k个元素的。
//     }
//     // 若k超出有效范围，返。0
//     return 0;
// }

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// // 集合类的头文件set.h如下，请定义其中的函数成员。
// class SET {
// 	int *set; 			//set用于存放集合元素
// 	int card; 			//card为能够存放的元素个数
// 	int used; 			//used为已经存放的元素个数
// 	public:
// 	SET(int card); 		//card为能够存放的元素个数
// 	~SET( );
// 	int size( ); 			//返回集合已经存放的元素个。
// 	int insert(int v); 		//插入v成功时返。1，否则返。0
// 	int remove(int v); 	//删除v成功时返。1，否则返。0
// 	int has(int v); 		//元素v存在时返。1，否则返。0
// };
// SET::SET(int card):card(card),used(0)//card为能够存放的元素个数
// {
// 	int *set=new int(card);
// }
// SET::~SET( ){
// 	delete[] set;
// }
// int SET::size( )//返回集合已经存放的元素个。
// {
// 	int i;
// 	for(i=0;set[i]!=0;i++) ;
// 	return i;
// }
// int SET::insert(int v)//插入v成功时返。1，否则返。0
// {
//     if (used >= card) {
//         return 0; // 集合已满，插入失。
//     }
//     for (int i=0; i<used; i++) {
//         if (set[i] == v) return 0; // 元素已存在，插入失败
//     }
//     set[used]=v;
//     used++;
//     return 1; // 插入成功
// }
// int SET::remove(int v)//删除v成功时返。1，否则返。0
// {
// 	for (int i=0; i<used; i++){
//         if (set[i] == v){
//             // 将最后一个元素移到当前位置，覆盖要删除的元素
//             set[i]=set[used-1];
//             used--;
//             return 1; // 删除成功
//         }
//     }
//     return 0; // 元素不存在，删除失败
// }
// int SET::has(int v)//元素v存在时返。1，否则返。0
// {
//     for (int i=0; i<used; i++){
//         if (set[i] == v) {
//             return 1; // 元素存在
//         }
//     }
//     return 0; // 元素不存。
// }

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

// class Numstrlen {
// 	const char *s;	    //s[]为N进制整数字符。(字母都是大写),。"9AB6"(N=16)
// 	const int N;		//2 <= N <= 16
// 	int  decNum; 	//在构造函数中,将s[]转换。10进制数保存到该变。
// public:
// 	Numstrlen(const char *s, int N=10);  //构造函。, s[]是N进制整数字符。,含有大小写字。
// 	~Numstrlen( );	  //析构函数
// 	char *tostrlen(int M); //将s[]中的N进制字符串转换为M进制字符。,返回M进制字符串的首地址
// private:
// 	void toNum( );  //将s[]中的N进制整数字符串转换为10进制数并保存到decNum
// };
// Numstrlen::Numstrlen(const char *s, int N) : s(s), N(N) { toNum(); }
// Numstrlen::~Numstrlen( ){ }
// char *Numstrlen::tostrlen(int M){
// 	int num=decNum;
// 	int length;
// 	for(length=0;num != 0;num /= M) length++;// 计算转换后字符串的长。
// 	char *result=new char[length+1];
// 	result[length]='\0';  // 字符串结尾添。'\0'
// 	for (int i=length-1,num=decNum;i>=0;i--)//转化为M进制
// 	{
// 		int remainder=num% M;
// 		if (remainder<10) {
// 			result[i]=remainder+'0';
// 		} else {
// 			result[i]=remainder-10+'A';
// 		}
// 		num /= M;
// 	}
// 	return result;
// }
// void Numstrlen::toNum() {
// 	int length=strlen(s);
// 	decNum=0;
// 	int power=1;
// 	for (int i=length-1; i>=0; i--) {
// 		if (s[i]>='0' && s[i] <= '9'){
// 			decNum += (s[i]-'0') * power;
// 			}
// 		else {
// 			decNum += (s[i]-'A'+10) * power;
// 			}
// 		power *= N;
// 	}
// }
// int main() { Numstrlen s("A4",16); printf("%s %s\n", s.tostrlen(10), s.tostrlen(2)); }
