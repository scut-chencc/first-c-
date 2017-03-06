//10-4 使用虚基类解决共同基类带来的二义性问题
#include <iostream>
using namespace std;

class A		
{
	protected:		
		int x;
	public:
		A( int xp)	//构造函数，带缺省构造参数
			:x( xp)
		{
			cout<<"A( int xp=0)" <<endl;
		} 
		A()
		{
			 cout<<"A( )" <<endl;
		}
		void SetX( int xp)        
		{
			x = xp;
		} 
		void print( )	
		{
			cout << " this is x in A: "  << x << endl;
		} 
} ;

class B: virtual public A	//B由A虚基派生而来
{
	public:
		B(int z) :x(A(z))
	{
		 cout<<"B( int z)" <<endl;
	}
} ;

class C: virtual public  A	
{
} ;

class D:public B,public C	
{
	D( int z) :x( B(z))
	{
		 cout<<"D(int z)" <<endl;
	}
} ;

int main( ) 
{
	D d( 5);		
	//d.B::SetX( 5) ;		//SetX函数，因为virtual派生，在D中只有一个版本，不会二义
	//d.B::print( ) ;
	//d.C::print( );
	return 0;
} 
