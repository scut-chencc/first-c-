#include <iostream>
using namespace std;
class Base
{

	public:
		virtual int func( int x) 
		{

			cout<<" This is Base class" ;
			return x;
		} 
} ;
class Subclass: public Base
{

	public:
		 int  func( int x)//省略了virtual也还是虚函数；   
		{

			cout<<" this is Sub class" ;
			float y = x;
			return y;
		}
} ;
void test( Base& x) 
{
	cout<<" x=" <<x.func( 5) <<endl;
}
int  main( ) 
{

	Base bc;
	Subclass sc;
	test( bc) ;
	test( sc) ;
	return 0;
} 
