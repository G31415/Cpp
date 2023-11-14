class POINT3D{
    int x, y, z;
    static int total;     //点的总个数
public:
    POINT3D( );
    POINT3D(int, int, int);
    static int number( ); //返回点的个数
    ~POINT3D( );
};
int POINT3D::total=0;
POINT3D::POINT3D( ): x(0), y(0), z(0){ POINT3D::total++; }
POINT3D::POINT3D(int x, int y, int z): x(x), y(y), z(z){ POINT3D::total++; }
int POINT3D::number( ){ return POINT3D::total; }
POINT3D::~POINT3D( ) { POINT3D::total--; }
