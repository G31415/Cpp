#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
class DICTIONARY {
    char** words;
    int 	 pos;    				//当前可以存放单词的空闲位置
    const  int max; 				//词典可以存放单词的最大个数
public:
    DICTIONARY(int max);    			//max为能存放的最大单词个数
    DICTIONARY(const DICTIONARY&);		//深拷贝构造
    DICTIONARY(DICTIONARY&&)noexcept;	//移动构造
    virtual ~DICTIONARY()noexcept;
    DICTIONARY& operator=(const DICTIONARY&);	//深拷贝赋值
    DICTIONARY& operator=(DICTIONARY&&)noexcept;//移动赋值
    virtual int operator( ) (const char* w) const;	//未查到w的位置返回-1
    virtual DICTIONARY& operator<< (const char* w);//若w不在词典则加入
    virtual const char* operator[ ] (int n) const;        	//取出第n个单词
};
DICTIONARY::DICTIONARY(int max) : max((words = new char* [max]) ? max : 0), pos(0) {
    if (words = nullptr) throw "memory allocation error!";
}
DICTIONARY::DICTIONARY(const DICTIONARY& d) : max((words = new char* [d.max]) ? d.max : 0), pos(d.pos) {
    if (words = nullptr) throw "memory allocation error!";
    for (int x = 0; x < pos; x++) {
        strcpy(words[x] = new char[strlen(d.words[x]) + 1], d.words[x]);
    }
}
DICTIONARY::DICTIONARY(DICTIONARY&&d)noexcept :
    words(d.words), pos(d.pos), max(d.max) {
    d.words = nullptr;
    (int&)(d.max) = d.pos = 0;
}
DICTIONARY::~DICTIONARY()
{
    if (words) { for (int i = 0; i < pos; i++) delete words[i]; delete words; words = 0; }
}
DICTIONARY& DICTIONARY::operator= (const DICTIONARY& d) {
    if (this == &d) return *this;
    if (words) {
        for (int x = 0; x < pos; x++) delete words[x];
        delete words;
    }
    words = new char* [(int&)max = d.max];
    if (words == nullptr) throw "memory allocation error!";
    pos = d.pos;
    for (int x = 0; x < pos; x++) {
        strcpy(words[x] = new char[strlen(d.words[x]) + 1], d.words[x]);
    }
    return *this;
}
DICTIONARY& DICTIONARY::operator= (DICTIONARY&& d) noexcept {
    if (this == &d) return *this;
    if (words) {
        for (int x = 0; x < pos; x++) delete words[x];
        delete words;
    }
    words = d.words;
    (int&)max = d.max;
    pos = d.pos;
    d.words = nullptr;
    (int&)(d.max) = d.pos = 0;
    return *this;
}
DICTIONARY& DICTIONARY::operator<<(const char* w)
{
    if ((*this)(w) || pos >= max || !(words[pos] = new char[strlen(w) + 1])) return *this;
    strcpy(words[pos++], w);
    return *this;
}
int DICTIONARY::operator( )(const char* w)const
{
    for (int i = 0; i < pos; i++)    if (!strcmp(words[i], w)) return 1;
    return 0;
};
const char* DICTIONARY::operator[ ](int n)const { return n < pos ? words[n] : 0; }
