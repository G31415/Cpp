#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <typeinfo>
using namespace std;
template <class T>
class COMP {			//用于类型“装箱”的类模板
    T  d;				//被装箱的T类型及其数据
public:
    COMP(T t) : d(t) { };		//自动转换T类型为类模板实例类的构造函数
    int operator ==(const T& x)const;
};
template <class T>			//类型“装箱”后的this参数代表一个对象
int COMP<T>::operator ==(const T& x)const
{//若x的类型为char*或const char*类型就进行字符串内容比较
    if (typeid(x) == typeid(const char*) || typeid(x) == typeid(char*)) {
        return strcmp((const char*)x, (const char*)d) == 0;
    }
    return x == d;			//T非指针类型的比较
}
template <class T>			//用类型T调用==函数时，强制对实参进行类型装箱
int operator ==(const COMP<T>& x, const T& y)
{
    return x.operator==(y);
}
void main(void)
{
    int m = operator==<const char*>("ab", "cd"); // const char*的"ab"被装箱
    m = operator==<int>(3, 4); //3装箱为const COMP<int>，4的类型默认为int
    m = operator==<long>(3L, 4L);	//类似以上，4L的类型为long
    m = operator==<char>('A', 'B');	//类似以上，'B'的类型为char
}