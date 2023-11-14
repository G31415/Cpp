#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
using namespace std;
class MANAGER;				//前向引用声明
class CLERK {
    char   name[10];				//员工姓名
    char   flag; 				//员工正式'f'和临时't'标志
    MANAGER* monitor;			//员工的经理：老板无人管辖
    double balance;				//员工工资结余
public:
    virtual double drawwage(double m);		//取工资
    virtual double savewage(double w);		//发工资
    CLERK(const char* n, MANAGER* m, double b, char f = 't');
};
class MANAGER : public CLERK {
    char  title[10];				//经理职务
public:
    virtual void paywage(CLERK&, double w);	//支付工资
    MANAGER(const char* n, const char* t, MANAGER* m, double b);
};
double CLERK::drawwage(double m) { balance -= m; return balance; }
double CLERK::savewage(double w) { balance += w; return balance; }
CLERK::CLERK(const char* n, MANAGER* m, double b, char f) : monitor(m) {
    strcpy(name, n);
    balance = b;
    flag = f;
}
void  MANAGER::paywage(CLERK&c, double w) { c.savewage(w); }
MANAGER::MANAGER(const char* n, const char* t, MANAGER* m, double b): CLERK(n, m, b, 'f') {
    strcpy(title, t);
}
int main(int argc, char *argv[ ]) {
    MANAGER boss("Wang", "Tycon", nullptr, 100000);
    MANAGER man1("Yang", "Monitor", &boss, 20000);
    MANAGER man2("Zang", "Manager", &boss, 30000);
    CLERK   form("Cang", &man2, 1000, 'f');
    CLERK   temp("Tang", &man2, 1000, 't');
    boss.paywage(man1, 10000);
    man2.paywage(form, 10000);
    man2.paywage(temp, 10000);
}
