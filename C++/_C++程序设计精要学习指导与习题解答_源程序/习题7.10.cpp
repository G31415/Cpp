#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <malloc.h>
class HASH{
    class NODE{	//Hash 表存放的节点元素
        int value;
        NODE *next;
    public:
        int getvalue( ){ return value;}
        NODE *getnext( ){ return next;}
        NODE *setnext(NODE *n){ next=n; return this;}
        NODE(int v, NODE *n){ value=v; next=n; }
        ~NODE( ){ if(next) delete next; }
    };
    struct BARREL{ char *s; NODE *n;}*h;
    const int  t;	//Hash 表存放的最大元素个数
    int  c;		//Hash 表存放的实际元素个数
public:
    HASH(int m);	//Hash 表最多存放m个元素
    NODE *lookup(const char *s, int v);
    int insert(const char *s, int v);
    int remove(const char *s, int v);
    ~HASH( );
};
HASH::HASH(int m): h(new BARREL[m]),t(h?m:0),c(0){ }
HASH::NODE *HASH::lookup(const char *s, int v){
    for(int k=0; k<c; k++)
        if(strcmp(s, h[k].s)==0){
            NODE *p=h[k].n;
            while(p!=0){
                if(p->getvalue( )==v) return p;
                p=p->getnext( );
            }
        }
    return 0;
}
int HASH::insert(const char *s, int v){
    for(int k=0; k<c; k++)
        if(strcmp(s, h[k].s)==0){
            h[k].n=new NODE(v, h[k].n);
            return 1;
        }
    if(c<t){
        h[c].s=new char[strlen(s)+1];
        strcpy(h[c].s, s);
        h[c++].n=new NODE(v, 0);
        return 1;
    }
    return 0;
}
int HASH::remove(const char *s, int v){
    for(int k=0; k<c; k++)
        if(strcmp(s, h[k].s)==0){
            NODE *p,*q=h[k].n;
            if((p=q)==0) return 0;
            if(p->getvalue( )==v){
                h[k].n=p->getnext( );
                free(p);
                return 1;	//返回1表示成功
            }
            while(p=p->getnext( )){
                if(p->getvalue( )==v) {
                    q->setnext(p->getnext( ));
                    free(p);
                    return 1;
                }
                q=p;
            }
        }
    return 0;	//返回0表示失败
}
HASH::~HASH( ){
    if(h==nullptr) return;
    for(int k=0; k<c; k++)  delete h[k].n;
    delete h;
    h=nullptr;
    (int &)t=c=0;
}
void main( ){
    HASH h(10);
    h.insert("A", 1);
    h.insert("A", 2);
    h.remove("A", 1);
    h.insert("A", 3);
    h.insert("B", 1);
    h.insert("B", 2);
}
