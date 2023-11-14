#define _CRT_SECURE_NO_WARNINGS //防止strcpy 出现指针使用安全警告
#include <string.h>
#include <iostream>
using namespace std;
class STATE; 			//前向声明
class LIST { 			//状态节点列表
    LIST *next; 			//下一状态转移节点
    char input; 			//输入动作
    STATE *output; 			//转移的新状态
public:
    LIST(char a, STATE *o); 
    ~LIST( );
    LIST *&getNext( ); 		//返回next
    char getInput( ); 			//返回input
    STATE *getOutput( ); 		//返回output
};
class STATE {
    char *name; 			//状态名
    LIST *list; 			//状态转移列表
    static STATE*error; 		//错误陷阱：一旦进入，永不转出
public:
    void enlist(char in, STATE *out); 	//将状态转移节点插入list
    const STATE *next(char in)const; 	//输入in 转移到下一个状态
    const STATE *start(const char *)const; 	//启动有限自动机，并返回最终状态
    STATE(const char *name);
    ~STATE( );
};
STATE* STATE::error = 0;
LIST::LIST(char in, STATE* out) :input(in), output(out), next(nullptr) { }
LIST::~LIST( ) { if (next) { delete next; next = nullptr; } }
LIST*& LIST::getNext( ) { return next; }
char LIST::getInput( ) { return input; }
STATE* LIST::getOutput( ) { return output; }
STATE::STATE(const char* name):name(nullptr), list(nullptr) {
    if (name == nullptr) { error = this; return; }
    STATE::name = new char[strlen(name) + 1];
    strcpy(STATE::name, name);
}
void STATE::enlist(char in, STATE* out) {	//插入list
    LIST* temp;
    if (list == nullptr) {
        list = new LIST(in, out);
        return;
    }
    temp = new LIST(in, out);
    temp->getNext( ) = list;
    list = temp;
}
const STATE* STATE::next(char in)const {	//输入in转移到下一个状态
    LIST* temp = list;
    if (this == error) return error;
    while (temp)
        if (temp->getInput( ) == in) return temp->getOutput( );
        else temp = temp->getNext( );
    return error;
}
const STATE* STATE::start(const char* s)const {//启动有限自动机
    const STATE* temp = this;
    while (*s) temp = temp->next(*s++);
    return temp;
}
STATE::~STATE( ) {
    if (name) { delete name; name = nullptr; }
    if (list) { delete list; list = nullptr; }
}
void main( ){
    STATE start("WSGM_"); 		//有限自动机的启动状态
    STATE stop("_WSGM"); 		//有限自动机的停止状态
    STATE error(0); 			//有限自动机的出错状态
    STATE WG_SM("WG_SM");
    STATE WGM_S("WGM_S");
    STATE G_WSM("G_WSM");
    STATE SGM_W("SGM_W");
    STATE W_SGM("W_SGM");
    STATE WSM_G("WSM_G");
    STATE S_WGM("S_WGM");
    STATE SM_WG("SM_WG");
    start.enlist('s', &WG_SM);
    WG_SM.enlist('s', &start);
    WG_SM.enlist('m', &WGM_S);
    WGM_S.enlist('m', &WG_SM);
    WGM_S.enlist('w', &G_WSM);
    WGM_S.enlist('g', &W_SGM);
    G_WSM.enlist('w', &WGM_S);
    W_SGM.enlist('g', &WGM_S);
    G_WSM.enlist('s', &SGM_W);
    SGM_W.enlist('s', &G_WSM);
    SGM_W.enlist('g', &S_WGM);
    S_WGM.enlist('g', &SGM_W);
    W_SGM.enlist('s', &WSM_G);
    WSM_G.enlist('s', &W_SGM);
    WSM_G.enlist('w', &S_WGM);
    S_WGM.enlist('w', &WSM_G);
    S_WGM.enlist('m', &SM_WG);
    SM_WG.enlist('m', &S_WGM);
    SM_WG.enlist('s', &stop);
    stop.enlist('s', &SM_WG);
    if(start.start("smwsgms")==&stop) cout<<"OK";
}
