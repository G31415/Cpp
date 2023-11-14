#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int n, m, A, B, C;  		//车站编号n，火车车次数量m，烦恼函数参数A、B、C
int lastv = 0;      		//最佳线路的最后一次乘坐的火车车次
int annoy = INT_MAX; 	//最佳线路的最小烦恼值
int* pos;           		//凸包计算的优化位置
inline int vexation(int t) { return A * t * t + B * t + C; }
struct Train {//某个火车车次的出发站、到达站、出发时刻与到达时刻
    int departure_station;  	//出发站车站编号
    int arrival_station;    	//到达站车站编号
    int departure_time;     	//出发时刻
    int arrival_time;    		//到达时刻
    int previous_train;  	//乘坐当前火车的前一次最佳转乘火车车次
    int annoyance_value; 	//当前火车车次的烦恼贡献值
    int X( ) { return arrival_time; }//返回的到达时间
    int Y( ) {
        return annoyance_value - A * arrival_time * arrival_time - B * arrival_time;
    }
    int& pretr( ) {
        return previous_train;
    }
    int& value( ) { return annoyance_value; }
    Train(int x = 0, int y = 0, int p = 0, int q = 0):
      departure_station(x), arrival_station(y), departure_time(p), arrival_time(q) {
        previous_train = 0;
        annoyance_value = (INT_MAX >> 1) + (INT_MAX >> 2);
    }
}*T;
struct TimeTable {		//按时间排序的点
    int time, type, train;//type=0为出发时刻，为1到达时刻，id是火车编号
    inline bool operator < (const TimeTable& tmp) const {
        return time < tmp.time;
    }
    TimeTable(int t = 0, int c = 0, int d = 0) :time(t), type(c), train(d) { }
}*D;
struct Convex {		//凸包的点
    int time, cost, train;	//到达时间,已经产生的代价，乘坐的火车
    inline int X( ) { return time; }
    inline int Y( ) { return cost - A * time * time - B * time; }
    Convex(int t, int c, int i) : time(t), cost(c), train(i) { }
};
vector <Convex>* V;	//vector用于维护凸包
inline long long Cross(long long xa, long long xb, long long ya, long long yb) 
{ return xa*yb-xb*ya; }	//叉积用于判断直线的斜率大小
void push(int v)		//插入到凸包中
{
    int t = T[v].arrival_station;
    if (T[v].value( ) >= (INT_MAX >> 1) + (INT_MAX >> 2)) return;
    while (int(V[t].size( )) - pos[t] >= 2)//查找所有可能位置
    {
        int len = V[t].size( );
        if (Cross(T[v].X( ) - V[t][len - 2].X( ), T[v].Y( ) - V[t][len - 2].Y( ), V[t][len - 1].X( ) - V[t][len - 2].X( ), V[t][len - 1].Y( ) - V[t][len - 2].Y( )) < 0) 
            break;		//若p引出的直线斜率大
        V[t].pop_back( );
    }
    V[t].push_back(Convex(T[v].X( ), T[v].value( ), v));	//加入当前凸包坐标点
}
void printp(int v) {
    int p = 0;
    if ((p = T[v].pretr( )) != 0) { printp(p); printf("->"); }
    printf("%d", v);
}
int main( )
{
    freopen("route1.in", "r", stdin);		//cin输入重定向
    //freopen("route.out", "w", stdout);		//cout输出重定向
    scanf("%d%d%d%d%d", &n, &m, &A, &B, &C);	//输入系统参数
    int a, b, c, d, v, u, tot = 0;
    T = new Train[m + 1];
    D = new TimeTable[2 * m + 1];
    V = new vector <Convex>[2 * m + 1];
    pos = new int[2 * m + 1]{};
    for (int i = 1; i <= m; i++)			//输入所有车次信息
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        T[i] = Train(a, b, c, d);
        D[++tot] = TimeTable(c, 0, i);		//拆解成出发时刻点
        D[++tot] = TimeTable(d, 1, i);		//拆解成到达时刻点
    }
    sort(D + 1, D + tot + 1); 			//排序以便算法优化
    V[1].push_back(Convex(0, 0, 0));		//插入初始凸包点
    T[0].value( ) = 0;
    for (int i = 1; i <= tot; i++)			//查找所有可能的出发站点
    {
        v = D[i].train,
        u = T[v].departure_station;
        if (D[i].type) { push(v); continue; }		//以下只分析出发的车次
        while (int(V[u].size( ))-pos[u]>1 && V[u][pos[u]].cost + vexation(D[i].time
        -V[u][pos[u]].time) >=V[u][pos[u]+1].cost+vexation(D[i].time-V[u][pos[u]+1]
        .time)) 				//基于前述优化的核心思想，寻找使公式（4）更小的y	
            pos[u]++;  
        if (pos[u]<int(V[u].size( ))) {//找到使乘坐烦恼值更低的站点更新value
            T[v].value( ) = V[u][pos[u]].cost + vexation(D[i].time - V[u][pos[u]].time);
            T[v].pretr( ) = V[u][pos[u]].train;
        }
        if (T[v].arrival_station == n && T[v].value() < INT_MAX) {
            int temp = annoy;
            annoy = min(annoy, T[v].value( ));
            //若最终在T[v].X( )时刻到达站点v时烦恼再增加T[v].X( )，
            //则annoy应该改为annoy = min(annoy, T[v].value( )+T[v].X( )) 
            if (temp > annoy) lastv = v;
        }
    }
    printp(lastv);
    printf("\nvexation=%d\n", annoy);
    delete[ ]T;
    delete[ ]D;
    delete[ ]V;
    delete[ ]pos;
    return 0;
}
