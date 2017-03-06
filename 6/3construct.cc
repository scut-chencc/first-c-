#include <iostream>
using namespace std;

class A					
{

	private:				
		int x;

	public:
		A( int xp=0)			
		{

			x = xp;
			cout << " A的构造函数被执行"  << endl;
		} 
} ;

class B					
{

	public:
		B( )					
		{

			cout << " B的构造函数被执行"  << endl;
		} 
} ;

class C:public A		
{

	private:
		int y;
		B b;

	public:
		C( int xp, int yp)  : b(),A()		//构造函数，基类构造函数在初始化表中调用
	{

		y = yp;
		cout << " C的构造函数被执行"  << endl;
	} 
} ;

int main( ) 
{

	C c( 1, 2) ;			
	return 0;
} 
