class ABSL{
    const int size;
    int numb;
public:
    int &getn( ){ return numb; };
    int gets( ){ return size; };
    virtual int insert(int v)=0;
    virtual int remove(int&v)=0;
    ABSL(int s):size(s){ numb=0; }
};
class LIST: public ABSL{
    int *a;
public:
    int insert(int v);
    int remove(int&v);
    LIST(int t):ABSL((a=new int[t])?t:0){ };
};
int LIST::insert(int v){
    int k, m, &c=getn( );
    if(c==gets( )) return 0;
    for(k=0; k<c && a[k]<=v; k++);
    for(m=c; m>k; m--) a[m]=a[m-1];
    a[m]=v;
    c++;
    return 1;
}
int LIST::remove(int&v){
    int k, c=getn( );
    if(c==0) return 0;
    for(k=0; k<c && a[k]!=v; k++);
    if(k==c) return 0;
    for(c--; k<c; k++) a[k]=a[k+1];
    return 1;
}
