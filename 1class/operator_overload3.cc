#include <iostream>

class Complex
{
	friend Complex operator+(const Complex &,const Complex &);
	friend Complex & operator++(Complex& l);
	friend Complex operator++(Complex& l,int);
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
	Complex& operator+(const Complex &l)
	{
		dreal_+=l.dreal_;
		dimag_+=l.dimag_;
		return *this;
	}
#endif
#if 0
Complex & operator++()//qian置++
{
	 ++dreal_;
	 ++dimag_;
	 return *this;
}
Complex operator++(int){//hou置++
	std::cout<<" houzhijiajia" <<std::endl;
	Complex tmp(*this);
	++dreal_;
	++dimag_;
	return tmp;
}
#endif
	private:
	double dreal_;
	double dimag_;
};
Complex operator+(const Complex &l,const Complex &r)
{
	return Complex(l.dreal_+r.dreal_,l.dimag_+r.dimag_);
}

Complex & operator++(Complex& l)//qian置++
{
	 ++l.dreal_;
	 ++l.dimag_;
	 return l;
}
Complex operator++(Complex& l,int){//hou置++
	std::cout<<" houzhijiajia" <<std::endl;
	Complex tmp(l);
	++l.dreal_;
	++l.dimag_;
	return tmp;
}
int main()
{
	Complex c1(1,2),c2(3,4);
	c1.display( );
	Complex c3=c1+c2;
	c3.display( );
	c1.display( );
	(c3++).display( );
	c3.display( );
	(++c3).display( );
	c3.display( );
	return 0;
}
