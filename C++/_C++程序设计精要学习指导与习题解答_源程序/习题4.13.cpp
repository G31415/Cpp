class QUEUE{
    int *queue;
    int size, front, rear;
public:
    int insert(int elem);
    int remove(int &elem);
    int empty( );
    void clear( );
    QUEUE(int size);
    ~QUEUE( );
};
QUEUE::QUEUE(int sz): queue(new int[size=sz]), front(0), rear(0){ } 
QUEUE::~QUEUE( )
{
    if(queue){
        delete[ ] queue;
        queue=nullptr;
        front=rear=0;
    }
}
int QUEUE::insert(int elem)
{
    if((rear+1)%size==front) return 0;
    queue[rear]=elem; rear=(rear+1)%size;
    return 1;
}
int QUEUE::remove(int &elem)
{
    if(front==rear) return 0;
    elem=queue[front]; front=(front+1)%size;
    return 1;
}
int QUEUE::empty( )
{
    return  front==rear;
}
void QUEUE::clear( )
{
    front=rear=0;
}
void main(void){ QUEUE queue(20); }
