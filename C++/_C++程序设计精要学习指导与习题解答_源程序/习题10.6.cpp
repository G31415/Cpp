#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
class STRING {
    char* str; 					//用于存储字符串
public:
    int strlen( )const noexcept; 				//用于求字符串的长度
    int strcmp(const STRING&)const noexcept; 		//用于比较两个字符串
    STRING& strcpy(const STRING& s)throw(const char*); 	//拷贝s至目标串
    STRING& strcat(const STRING& s)throw(const char*); 	//连接s至目标串
    STRING(const char* s)throw(const char*); 		//用s 构造字符串
    STRING(const STRING& s)throw(const char*); 		//用s 构造字符串
    STRING(STRING&& s)noexcept; 			//用s 构造字符串
    ~STRING( )noexcept; 				//析构字符串
};
