#include <iostream>
#include <math.h>

class Point
{
	friend float dis(const Point& l,const Point& r);
	public:
		Point( ):ix_( 0),iy_( 0)
		{
		}
		Point( int ix,int iy)
			:ix_( ix),iy_( iy)
		{
		}
		void print()
		{
			 std::cout<<ix_<<iy_<<std::endl;
		}
	private:
		int ix_;
		int iy_;
};

float dis(const Point &l,const Point& r)
{
	float d=sqrt(( l.ix_-r.ix_)*(l.ix_-r.ix_)+( l.iy_-r.iy_)*(l.iy_-r.iy_));	return d;
}

int main( )
{
	 Point p1(1,2 ),p2( 3,4);
	 p1.print( );
	 p2.print( );
	 std::cout<<" distance is " <<dis(p1,p2)<<std::endl;
	 return 0;
}
