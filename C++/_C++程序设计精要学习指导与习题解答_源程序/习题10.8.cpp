#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <exception>
using namespace std;
class  MEMEXCEPTION: public exception {
public:
    const char* what( ) const throw( ) { return "Memory not enough!"; }
};
class  FULLEXCEPTION : public exception {
public:
    const char* what( ) const throw( ) { return "Queue is full!"; }
};
class  EMPTYEXCEPTION : public exception {
public:
    const char* what( ) const throw( ) { return "Queue is empty!"; }
};
class QUEUE {
    int* queue;
    int  size, front, rear;
public:
    QUEUE(int sz) noexcept(false);
    QUEUE& push(int elem) noexcept(false);
    QUEUE& pop(int &elem) noexcept(false);
    ~QUEUE( )noexcept;
};
QUEUE::QUEUE(int sz)noexcept(false): queue(new int[sz]), size(queue?sz:0)
{   front=rear=0; if (!queue) throw MEMEXCEPTION( ); }
QUEUE::~QUEUE( )noexcept
{
    if (queue) {
        delete [ ] queue;
        queue = 0;
        front = rear = 0;
    }
}
QUEUE& QUEUE::push(int elem) noexcept(false)
{
    if ((rear + 1) % size == front) throw FULLEXCEPTION( );
    queue[rear] = elem;
    rear = (rear + 1) % size;
    return *this;
}
QUEUE& QUEUE::pop(int& elem) noexcept(false)
{
    if (rear == front) throw EMPTYEXCEPTION( );
    elem = queue[front];
    front = (front + 1) % size;
    return *this;
}
void main(void)
{
    try {
        int   a, b, c, d, e;
        QUEUE queue(20);
        queue.push(1).push(2).push(3).push(4).push(5);
        queue.pop(a).pop(b).pop(c).pop(d).pop(e);
    }
    catch (FULLEXCEPTION  f) {
        printf(f.what( ));
    }
    catch (EMPTYEXCEPTION  e) {
        printf(e.what( ));
    }
    catch (MEMEXCEPTION  m) {
        printf(m.what( ));
    }
}
