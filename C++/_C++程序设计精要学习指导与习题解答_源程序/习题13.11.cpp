template <class T = int>
struct NODE {
    T     value;
    NODE* next;
    NODE(T, NODE*);
};
template <class T> NODE<T>::NODE(T t, NODE* n) :value(t), next(n) { }
template <class T = int>
class LIST {
    NODE<T> *head;
public:
    LIST( )noexcept;
    LIST(const LIST&);
    int find(T value)const noexcept;		//若找到value则返回1，否则返回0
    NODE<T>* operator [ ](int k)const;		//取表的第k个元素
    virtual LIST operator +(const LIST&)const;	//表的合并运算
    virtual LIST& operator +(T value);		//插入一个元素
    virtual LIST& operator -(T value);		//删除一个元素
    virtual LIST& operator +=(const LIST&);	//表的合并运算
    virtual LIST& operator +=(T value);		//插入一个元素
    virtual LIST& operator -=(T value);		//删除一个元素
    virtual LIST& operator =(const LIST&);
    virtual ~LIST( )noexcept;
};
template <class T> LIST<T>::LIST( ) noexcept { head = 0; }
template <class T>
LIST<T>::LIST(const LIST& t) {
    NODE*& p = head, * h = t.head;
    while (h != 0) {
        p = new NODE(h->value, nullptr);
        if (p == nullptr) throw "memory not enough!";
        h = h->next;
        p = p->next;
    }
}
template <class T>
int LIST<T>::find(T value)const noexcept{
    NODE* h = head;
    while (h != nullptr && h->value != value) {
        h = h->next;
    }
    return h != nullptr;
}
template <class T> NODE<T>* LIST<T>::operator[ ](int k)const
{
    NODE* h = head;
    if (h == nullptr) throw "subscription overflowed!";
    for (int i = 0; i < k; i++) {
        h = h->next;
        if (h == nullptr) throw "subscription overflowed!";
    }
    return h;
};
template <class T>
LIST<T> LIST<T>::operator +(const LIST& t)const {
    LIST r(t);
    NODE*& p = r.head, * q = r.head, * h = head;
    while (h != nullptr) {
        p = new NODE(h->value, nullptr);
        if (p == nullptr) throw "memory not enough!";
        h = h->next;
        p = p->next;
    }
    p = q;
    return r;
}
template <class T>
LIST<T>& LIST<T>::operator +(T value) {
    head = new NODE(value, head);
    if (head == nullptr) throw "memory not enough!";
    return *this;
}
template <class T>
LIST<T>& LIST<T>::operator -(T value) {
    NODE*& h = head, * p;
    while (h != nullptr && h->value != value) h = h->next;
    if (h) { p = h; h = h->next; delete p; }
    return *this;
}
template <class T>
LIST<T>& LIST<T>::operator +=(const LIST& t) { return *this = *this + t; }
template <class T>
LIST<T>& LIST<T>::operator +=(T value) { return *this = *this + value; }
template <class T>
LIST<T>& LIST<T>::operator -=(T value) { return *this = *this - value; }
template <class T>
LIST<T>& LIST<T>::operator =(const LIST& t) {
    NODE*& p = head, * m = head, * n, * h = t.head;
    while (m != nullptr) {
        n = m->next;
        delete m;
        m = n;
    }
    while (h != nullptr) {
        p = new NODE(h->value, nullptr);
        if (p == nullptr) throw "memory not enough!";
        h = h->next;
        p = p->next;
    }
    return *this;
}
template <class T>
LIST<T>::~LIST( )noexcept {
    NODE* m = head, * n;
    while (m != nullptr) {
        n = m->next;
        delete m;
        m = n;
    }
}
void main( ) { }
