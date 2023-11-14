class LIST {
    struct NODE {
        int  value;
        NODE* next;
        NODE(int, NODE*);
    } *head;
public:
    LIST(void);
    LIST(const LIST&);
    int find(int value)const;//查找元素value，若找到则返回1，否则返回0
    NODE* operator [ ](int k)const;			//取表的第k个元素
    virtual LIST operator +(const LIST&)const;	//表的合并运算
    virtual LIST& operator +(int value);		//插入一个元素
    virtual LIST& operator -(int value);		//删除一个元素
    virtual LIST& operator +=(const LIST&);	//表的合并运算
    virtual LIST& operator +=(int value);		//插入一个元素
    virtual LIST& operator -= (int value);		//删除一个元素
    virtual LIST& operator =(const LIST&);
    virtual ~LIST(void);
};
LIST::NODE::NODE(int v, NODE* n) {
    value = v;
    next = n;
}
LIST::LIST(void) { head = 0; }
LIST::LIST(const LIST& t) {
    NODE*& p = head, * h = t.head;
    while (h != 0) {
        p = new NODE(h->value, 0);
        h = h->next;
        p = p->next;
    }
}
int LIST::find(int value)const {
    NODE* h = head;
    while (h != 0 && h->value != value) {
        h = h->next;
    }
    return h != 0;
}
LIST::NODE* LIST::operator [ ](int k)const {
    NODE* h = head;
    for (int i = 0; i < k; i++) if (h) h = h->next;
    return h;
}
LIST LIST::operator +(const LIST& t)const {
    LIST r(t);
    NODE*& p = r.head, * q = r.head, * h = head;
    while (h != 0) {
        p = new NODE(h->value, 0);
        h = h->next;
        p = p->next;
    }
    p = q;
    return r;
}
LIST& LIST::operator +(int value) {
    head = new NODE(value, head);
    return *this;
}
LIST& LIST::operator -(int value) {
    NODE*& h = head, * p;
    while (h != 0 && h->value != value) h = h->next;
    if (h) { p = h; h = h->next; delete p; }
    return *this;
}
LIST& LIST::operator +=(const LIST& t) { return *this = *this + t; }
LIST& LIST::operator +=(int value) { return *this = *this + value; }
LIST& LIST::operator -=(int value) { return *this = *this - value; }
LIST& LIST::operator =(const LIST& t) {
    if (this == &t) return *this;
    NODE*& p = head, * m = head, * n, * h = t.head;
    while (m != 0) {
        n = m->next;
        delete m;
        m = n;
    }
    while (h != 0) {
        p = new NODE(h->value, 0);
        h = h->next;
        p = p->next;
    }
    return *this;
}
LIST::~LIST(void) {
    NODE* m = head, * n;
    while (m != 0) {
        n = m->next;
        delete m;
        m = n;
    }
}
