class SET{
    int *elem;  	//set 用于存放集合元素
    int card; 	//card 为能够存放的元素个数
    int used; 	//used 为已经存放的元素个数
public:
    SET(int card); 	//card 为能够存放的元素个数
    ~SET( );
    int size( ); 	//返回集合已经存放的元素个数
    int insert(int v); 	//插入v 成功时返回1，否则返回0
    int remove(int v); 	//删除v 成功时返回1，否则返回0
    int has(int v); 	//元素v 存在时返回1，否则返回0
};
SET::SET(int  card): elem(new int[card]), card(elem?card:0), used(0){ }
SET::~SET( ){ if(elem) { delete[ ] elem; elem =nullptr; card=used=0; } }
int SET::size( ){ return used; }
int SET::insert(int v){ return  used<card? (elem[used]=v, ++used): 0; }
int SET::remove(int v){
    for(int x=0; x<used; x++)
        if(elem[x]==v){
            for(used--; x<used; x++)  elem[x]=set[x+1];
            return 1;
        }
    return 0; 
}
int SET::has(int v){
    for(int x=0; x<used; x++) if(elem[x]==v) return 1;
    return 0;
}



