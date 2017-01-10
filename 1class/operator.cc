#include <iostream>
#include <string.h>
class Computer
{
	public:
		Computer(const char* pBrand,float fPrice)
			:fPrice_( fPrice)
		{
			pBrand_=new char[ strlen(pBrand)+1];//为了\0;
			strcpy(pBrand_,pBrand);
			std::cout<<"Computer(const char*,float)" <<std::endl;
		}
		Computer(const Computer &rhs)//如果参数是对象，会出现无限递归的情况，从而导致栈溢出
			:fPrice_( rhs.fPrice_)//因为在类定义里面，可以通过对象.形式访问private;
		{
			 pBrand_=new char[strlen(rhs.pBrand_)+1];
		     strcpy(pBrand_,rhs.pBrand_);
			std::cout<<"Computer(const Computer &)" <<std::endl;
		}
		Computer&  operator=(const Computer &rhs)//这里后面的引用则减少开销，原始功能；
		{
			std::cout<<"Computer & operator=()" <<std::endl;
			if( this== &rhs)//防止自复制如：pc1=pc1;
			{
				 return *this;
			}
			delete []pBrand_;
			pBrand_=new char[strlen(rhs.pBrand_)+1];
			strcpy(pBrand_,rhs.pBrand_);
			fPrice_=rhs.fPrice_;
			//return *this;
		}
		~Computer()
		{
			std::cout<<"~Computer()" <<std::endl;
			delete []pBrand_;
		}
		void print( )
		{
			std::cout<<"pinpai:" <<pBrand_<<std::endl;
			std::cout<<"jiage:" <<fPrice_<<std::endl;
		}
	private:
		char* pBrand_;
		float fPrice_;
};

int main( )
{
	Computer pc1("dell" ,7000);
	pc1.print( );
	Computer pc2("dell" ,6500);
	pc2=pc1;
	pc2.print( );
	return 0;
}
