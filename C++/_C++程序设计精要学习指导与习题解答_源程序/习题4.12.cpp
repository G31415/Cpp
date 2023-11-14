#define _CRT_SECURE_NO_WARNINGS //防止strcpy 出现指针使用安全警告
#include <string.h>
class  NODE{
    char  *data;
    NODE  *left, *right;
public:
    NODE(const char * data); //用于构造叶子节点
    NODE(const char *data，NODE *left, NODE *right);
    ~NODE( );
};

NODE::NODE(const char *data){
    if(NODE::data=new char[strlen(data)+1]){
        strcpy(NODE::data, data);
        left=right=nullptr;
    }
}
NODE::NODE(const char *data, NODE *left,  NODE *right){
    if(NODE::data=new char[strlen(data)+1]){
        strcpy(NODE::data, data);
        NODE::left=left;
        NODE::right=right;
    }
}
NODE::~NODE( ){
    if(left) left->~NODE( );
    if(right) right->~NODE( );
    if(data) {delete data; data=nullptr; left=right=nullptr; }
}
