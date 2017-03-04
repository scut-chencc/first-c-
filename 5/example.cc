#include <iostream> 
class SomeResource
{

};
class Example {

	SomeResource* p_;
	SomeResource* p2_;
	public:
	Example( )  :
		p_( new SomeResource( ) ) ,
		p2_( new SomeResource( ) )  {

			std::cout << " Creating Example, allocating SomeResource!"<<std::endl ;
		} 

	Example( const Example& other)  :
		p_( new SomeResource( *other.p_) ) ,
		p2_( new SomeResource( *other.p2_) )  {
		} 
	Example& operator=( const Example& other)  {

		//Self assignment?
		if ( this==&other) 
			return *this;

		*p_=*other.p_;
		*p2_=*other.p2_;
		return *this;
	} 
	~Example( )  {

		std::cout << " Deleting Example, freeing SomeResource!"<<std::endl ;
		delete p_;
		delete p2_;
	} 
} ;
int main(void )
{
	Example a;
	 return 0;
}
