#include <iostream>
#include <memory>

class X
{
	public:
		X( )  {
			std::cout << " construct X"  << std::endl;    } 
		~X( )  {
			std::cout << " ~destruct X"  << std::endl;    } 
		void Fun( ) 
		{

			std::cout << " Fun( )  "  << std::endl;
		} 
} ;
int main( void) 
{
	std::weak_ptr<X> p;
	{
		std::shared_ptr<X> p2( new X) ;
		std::cout << p2.use_count( )  << std::endl;
		
		p = p2;
		std::cout << " after p = p2"  << std::endl;
		std::cout << p2.use_count( )  << std::endl;

		std::shared_ptr<X> p3 = p.lock( ) ;//提升成功
		if( !p3) 
		{
			std::cout << " object is destroyed"  << std::endl;
		} 
		else
		{
			p3->Fun( ) ;
			std::cout << p3.use_count( )  << std::endl;
		} 
	} 
	//new X 已经被释放了
	std::shared_ptr<X> p4 = p.lock( ) ;//提升失败
	if( !p4) 
		std::cout << " object is destroyed 2"  << std::endl;
	else
		p4->Fun( ) ;
	return 0;
} 
