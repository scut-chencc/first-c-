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
		virtual  int   func(float  x)//省略了virtual也还是虚函数；   
		{

			cout<<" this is Sub class" ;
			float y = x;
			return y;
		}
} ;
class Subsubclass:public Subclass
{
	public:
		virtual int func(float x)
		{
			 cout<<"this is Subsub class" <<endl;
		}
};
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

	sc.func( 5);
	Base &ref=sc;
	ref.func( 5);

	Subsubclass ssc;
	Base& rref=ssc;
	rref.func( 5);
	Subclass& sc1=ssc;
	sc1.func( 5);
	return 0;
} 
