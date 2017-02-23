#include <iostream>

class Complex
{
	public:
		Complex(double dreal=0.0,double dimag=0.0)
			:dreal_( dreal),dimag_(dimag)
		{
		}
		void display()
		{
			 std::cout<<dreal_<<"+" <<dimag_<<std::endl;
		}
	//private:
	public:
		double dreal_;
		double dimag_;
};
Complex operator+(const Complex &l,const Complex &r)
{
	 return Complex(l.dreal_+r.dreal_,l.dimag_+r.dimag_);
}

int main()
{
	 Complex c1(1,2),c2(3,4);
	 Complex c3=c1+c2;
	 c3.display( );
	 return 0;
}
