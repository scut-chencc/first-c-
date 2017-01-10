#include <iostream>

class X
{
public:
	X(int ival):iy_(ival),ix_( iy_)
	{
		 std::cout<<"X(int ival)" <<std::endl;
	}
	void print()
	{
		 std::cout<<"ix_="<<ix_<<",iy_="<<iy_<<std::endl;
	}
private:
	int ix_;
	int iy_;
};
int main( )
{
	 X x(2);
	 x.print();
	 std::cout<<"the size of x is " <<sizeof(x)<<std::endl;
	 std::cout<<"the size of X is " <<sizeof(X)<<std::endl;
	 std::cout<<"the size of int is " <<sizeof(int)<<std::endl;
	 return 0;
}
