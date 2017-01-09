#include <iostream>

class Point
{
	public:
		void print( )
		{
			std::cout<<"(" <<ix_<<"," <<iy_<<")" <<std::endl;		 
		}
	    void setPoint(int x,int y)
		{
			 ix_=x;
			 iy_=y;
		}
	 private:
		 int ix_;
		 int iy_;
};

int main( void)
{
	 Point p1;
	 //std::cout<<"p1.ix_ is" <<p1.ix_<<std::endl;//非法；
	 p1.setPoint(1,2);
	 p1.print();
	 return 0;
}
