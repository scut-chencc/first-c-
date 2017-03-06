#include <iostream> 
#include <stdio.h>
using namespace std;

class Point					
{

	private:
		int x;
		int y;

	public:
		Point( int xp = 0, int yp = 0)	
		{

			x = xp;
			y = yp;
		} 

		void DispPoint( )		
		{

			printf( " Point ( %d, %d) \n" , x, y) ;
		} 

		void DispAddr()
		{
			cout<<"the addr is " << this<<endl;
		}
		int GetX( )					
		{

			return x;
		} 

		int GetY( )				
		{

			return y;
		}
} ;

class Point3D:public Point	
{

	private:					
		int z;

	public:
		Point3D( int xp = 1, int yp = 1, int zp = 1) :Point( xp, yp)	
	{

		z = zp;
	} 

		void Disp3DPoint( )		
		{

			printf( " Point3D ( %d, %d, %d) \n" , GetX( ) , GetY( ) , z) ;
		} 
} ;

int main( )						
{

	Point pt1( 1, 1) ;		
	pt1.DispPoint( ) ;		
	pt1.DispAddr( );

	Point3D pt2( 2, 3, 4) ;	
	pt2.Disp3DPoint( ) ;		
	pt2.DispAddr( );

	pt1 = pt2;				//派生类对象为基类对象赋值
	pt1.DispPoint( ) ;
	pt1.DispAddr( );//仅仅是赋值

	Point& rpt1 = pt2;		//派生类对象初始化基类对象引用
	rpt1.DispPoint( ) ;
	rpt1.DispAddr( );

	Point* ppt1 = &pt2;		//派生类对象地址为基类指针赋值
	ppt1->DispPoint( ) ;
	ppt1->DispAddr( );
	return 0;
} 
