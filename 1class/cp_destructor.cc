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
		Computer(const Computer &rhs)
			:fPrice_( rhs.fPrice_)//因为在类定义里面，可以通过对象.形式访问private;
		{
			 pBrand_=new char[strlen(rhs.pBrand_)+1];
		     strcpy(pBrand_,rhs.pBrand_);
			std::cout<<"Computer(const Computer &)" <<std::endl;
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

Computer getComputer( )
{
	 Computer pca("Mac" ,6666);
	 return pca;//返回的时候会执行复制构造函数；
}
int main( )
{
	Computer pc1("dell" ,7000);
	pc1.print( );
	//Computer* pc2=new Computer("mac" ,10000);
	//pc2->print( );
	Computer pc2=pc1;
	pc2.print( );
	std::cout<<"the next is return type"<<std::endl;
	getComputer();
	return 0;
}
