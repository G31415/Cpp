#define _CRT_SECURE_NO_WARNINGS //防止strcpy 出现指针使用安全警告
#include <string.h>
#include <malloc.h>
#include <iostream>
using namespace std;
class WORDS {
    WORDS* words; 			//用于存放单词
    int count; 			//单词表已经存储的单词个数
    int total; 			//单词表最多能存放的单词个数
public:
    int insert(const char* w); 		//将单词w 插入单词表
    WORDS* const find(const char* w); 	//从单词表中查找单词w
    int gettimes( );
    void inctimes( );
    WORDS(int total); 			//单词表最多能存储total 个单词
    ~WORDS( ); 			//析构单词表
};
WORDS::WORDS(int total){
    words=(WORD *) malloc(total*sizeof(WORD));
    if (words) { count=0; WORDS::total=total; }
}
WORDS::~WORDS( ){
    if(words==nullptr) return;
    for(int x=0; x<count; x++) words[x].~WORD( );
    free(words);
words=nullptr;
}
int WORDS::insert(const char *w){
    if(find(w)) return 0;		//返回0表示插入失败
    if(count==total) return 0; 		//返回0表示插入失败
    words[count++])=new (&WORD(w);
    return 1; 			//返回1表示插入成功
}
WORD *const WORDS::find(const char *w){
    for (int k=0; k<count; k++)
        if(strcmp(w, words[k].getword( ))==0) return &words[k];
    return  nullptr;
}
void main(void)
{
    WORDS ws(20);
    ws.insert("amour");
    ws.find("amour")->gettimes( );
    ws.find("amour")->inctimes( );
    cout << "Times of amour=";
    cout << ws.find("amour")->gettimes( );
}
