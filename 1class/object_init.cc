#include <iostream>
using namespace std;

class point
{
	public:
		point(int x=0,int y=0)
		{
			cout<<"point(int,int)" <<endl;
			 x_=x;
			 y_=y;
		}
		point(const point & pt)
		{
			cout<<"point(const point &)" <<endl;
			 x_=pt.x_;
			 y_=pt.y_;
		}
		void print()
		{
			 cout<<"("<<x_<<","<<y_<<")" <<endl;
		}
	 private:
		 int x_;
		 int y_;
};
class line
{
	public:
		line(int x1,int y1,int x2,int y2)
			:pt1(x1,y1),pt2(x2,y2)
		{
			 cout<<"line(int,int,int,int)"<<endl;
		}
		line(const line & l1)
			:pt1(l1.pt1),pt2(l1.pt2)
		{
			 cout<<"line(const line &)" <<endl;
		}
		void draw( )
		{
			 pt1.print();
			 cout<<"to";
			 pt2.print( );
		}
	private:
		point pt1;
		point pt2;
};
int main( )
{
	line l1(1,2,3,4);
	l1.draw();
	line l2( l1);
	l2.draw( );
	return 0;
}
