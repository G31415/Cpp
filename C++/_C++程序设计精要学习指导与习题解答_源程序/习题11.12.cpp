class QUEUE {
    struct NODE {
        int  value;
        NODE* next;
        NODE(int, NODE*);
    } *head;
public:
    QUEUE(void);
    QUEUE(const QUEUE&);
    virtual operator int(void)const;	//返回队列元素个数
    virtual volatile QUEUE& operator>>(int&)volatile;	//从队列中取出一个元素
    virtual volatile QUEUE& operator<<(int) volatile;	//往队列中加入一个元素
    virtual ~QUEUE(void);
};
QUEUE::NODE::NODE(int v, NODE* n) :value(v), next(n) {}
QUEUE::QUEUE(void) { head = 0; }
QUEUE::QUEUE(const QUEUE& q) {
    NODE*& p = head, * h = q.head;
    if (q.head) { head = 0; return; }
    while (h) {
        p = new NODE(h->value, 0);
        h = h->next;
    }
}
QUEUE::operator int(void)const {
    int c = 0;
    NODE* h = head;
    while (h) {
        c++;
        h = h->next;
    }
    return c;
}
volatile QUEUE& QUEUE::operator>>(int& v) volatile {
    NODE* volatile& h = head;
    if (!h) return *this;
    while (h->next)   h = h->next;
    v = h->value;
    delete h;
    h = 0;
    return *this;
}
volatile QUEUE& QUEUE::operator<<(int v) volatile {
    NODE* h = head;
    if (!(h = new NODE(v, head))) return *this;
    head = h;
    return *this;
}
QUEUE::~QUEUE(void) {
    NODE* q;
    while (head) {
        q = head;
        head = head->next;
        delete q;
    }
}
