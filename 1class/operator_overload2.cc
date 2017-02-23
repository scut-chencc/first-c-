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
#if 0
		Complex operator+(const Complex &l)
		{
			return Complex(dreal_+l.dreal_,dimag_+l.dimag_);
		}
#endif
		Complex& operator+(const Complex &l)
		{
			 dreal_+=l.dreal_;
			 dimag_+=l.dimag_;
			 return *this;
		}
	private:
		double dreal_;
		double dimag_;
};

int main()
{
	Complex c1(1,2),c2(3,4);
	c1.display( );
	Complex c3=c1+c2;
	c3.display( );
	c1.display( );
	return 0;
}
