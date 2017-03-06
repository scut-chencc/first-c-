//10-4 使用虚基类解决共同基类带来的二义性问题
#include <iostream>
using namespace std;

class A		
{
	protected:		
		int x;
	public:
		A( int xp = 0)	//构造函数，带缺省构造参数
		{
			x=xp;
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
} ;

class C: virtual protected A	
{
} ;

class D:public B,protected C	
{
} ;

int main( ) 
{
	D d;		
	d.SetX( 5) ;		//SetX函数，因为virtual派生，在D中只有一个版本，不会二义
	d.print( ) ;		//print函数，因为virtual派生，在D中只有一个版本，不会二义
	d.A::print( ) ;	//还可用类名显式说明调用函数的版本
	d.B::print( ) ;
	//d.C::print( ) ;
	return 0;
} 
