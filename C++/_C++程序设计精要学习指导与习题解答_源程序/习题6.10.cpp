class BAG {
    int *const e; 		//用于存放整型数值
    const int m; 		//能够存放的最大数值个数
    int n; 			//包中数值的个数
public:
    BAG(int m=0); 		//构造一个最多能放m 个数值的包
    BAG(const BAG&b);	//按照已有包深拷贝构造一个包
    int have(int v); 		//判断数值是否在包中，若在则返回1，否则返回0
    BAG& put(int &v); 	//将数值v 放入包中，如失败则设置v=0，成功则设置v=1
    BAG& remove(int &v);	//将数值v从包中去除，如失败则设置v=0，成功则设置v=1
    ~BAG( ); 		//析构函数
};
class SET : public BAG{	//BAG 和SET 满足父子关系
public:
    using BAG::have; 		//判断数值是否在集合中，若在则返回1，否则返回0
    SET(int m = 0);  		//构造一个最多能放m 个数值的集合
    SET(const SET&s); 	//深拷贝构造，BAG(const BAG&b)的b 可直接引用s
    SET& put(int &v);  	//将v 放入集合，如失败则设置v=0，成功则置v=1
    SET& remove(int &v); 	//将v从集合去除，如失败则设置v=0，成功则置v=1
    ~SET( );			//可删除，因SET没定义数据成员，未申请资源
};
BAG::BAG(int m) : e(new int[m]), m(e?m : 0) { n = 0; }
BAG::BAG(const BAG& s) : e(new int[s.m]), m(e ? s.m : 0) {
    if (e == 0) throw "Memory allocation failed\n";
    for (n = 0; n < s.n; n++) e[n] = s.e[n];
}
int BAG::have(int v) {
    for (int k = 0; k < n; k++)
        if (v == e[k]) return 1;
    return 0;
}
BAG& BAG::put(int &v) {
    if (n >= m) { v = 0;  return *this; }
    e[n++] = v;  v = 1;
    return *this;
}
BAG& BAG::remove(int&v) {
    for (int x = 0; x < n; x++) 
        if (e[x] == v) {
            for (n--; x < n; x++) e[x] = e[x + 1];
            v = 1;
            return *this;
        }
    v = 0;
    return *this;
}
BAG::~BAG( ) { if (e) { delete e; (int*&)e = nullptr; (int&)m = n = 0; } }
SET::SET(int m) : BAG(m) { }
SET::SET(const SET& s) : BAG(s) { }
SET& SET::put(int& v) {
    if (have(v)) { v = 1;  return *this;  }
    BAG::put(v);
    return *this;
}
SET& SET::remove (int&v){
    BAG::remove(v);
    return *this;
}
SET::~SET( ) { }		//若未自定义析构函数，编译程序会默认生成一个
