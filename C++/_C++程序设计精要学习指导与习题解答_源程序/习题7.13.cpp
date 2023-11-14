class STACK{
    char *stk;	//用于存放字符元素
    const int max; 	//栈能存放的最大元素个数
    int top; 	//栈顶元素位置
public:
    STACK(int max);
    ~STACK( );
    int push(char v);	//将v 压入栈，成功时返回1，否则返回0
    int pop(char&v); 	//弹出栈顶元素，成功时返回1，否则返回0
};
STACK::STACK(int max): max((stk = new char[max]) ? max : 0), top(0){  }
STACK::~STACK( ){
    if(stk) { 
        delete  stk;  
        stk=0;  
        *(int *)&max=top=0;  
    } 
}
int STACK::push(char  v){
    if (top>=max) return 0;
    stk[top++]=v;
    return 1;
}
int STACK::pop(char &v){
    if (top<=1) return 0;
    v=stk[--top]=v;
    return 1;
}
 
