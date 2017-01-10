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

Computer pc3("s" ,700);
pc3.print();

int main( )
{
	{
		 Computer pc1("dell" ,7000);
		pc1.print( );
		Computer* pc2=new Computer("mac" ,10000);
		pc2->print( );
	} 
	 return 0;
}
