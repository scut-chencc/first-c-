//模拟的功能类似于std::unique_ptr
#include <iostream> 
#include "example_raii.h" 
class SomeResource
{

};
class Example {
	private:
	RAII<SomeResource> p_;
	RAII<SomeResource> p2_;
	public:
	Example( )  :
		p_( new SomeResource( ) ) ,
		p2_( new SomeResource( ) )  {

			std::cout << " Creating Example, allocating SomeResource!"<<std::endl ;
		} 

	Example( const Example& other)  :
		p_( new SomeResource( *other.p_) ) ,
		p2_( new SomeResource( *other.p2_) )
		//p_( new SomeResource(other.p_.get())),
		//p2_( new SomeResource(other.p2_.get()))
	{} 
	Example& operator=( const Example& other)  {

		//Self assignment?
		if ( this==&other) 
			return *this;

		*p_=*other.p_;
		*p2_=*other.p2_;
		//p1_.reset(other.p_.get( ));
		//p2_.reset( other.p2_.get( ));
		return *this;
	} 
#if 0
	~Example( )  {

		std::cout << " Deleting Example, freeing SomeResource!"<<std::endl ;
		delete p_;
		delete p2_;
	} 
#endif
} ;
int main(void )
{
	Example a;
	 return 0;
}
