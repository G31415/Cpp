class WORD {
    char *word; 			//节点的值存放字符串
    int count; 			//单词的重复次数
public:
    int gettimes( )const; 		//得到重复次数
    int inctimes( ); 			//重复次数增1
    const char *getword( )const;		//得到单词word
    WORD (const char *);
    ~WORD( );
};
int WORD::gettimes( )const{ return count; }
int WORD::inctimes( ){ return ++count; }
const char *WORD::getword( )const{ return word; }
WORD::WORD(const char *w){
    if (word=new char[strlen(w)+1]) strcpy(word, w);
    count=0;
}
WORD::~WORD( ){ if (word) {delete word; word=nullptr; count=0; }}
