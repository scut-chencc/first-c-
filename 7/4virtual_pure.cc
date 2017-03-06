
#include <iostream> 
using namespace std;

class A						
{

	public:
		virtual void disp( )  = 0;
} ;

class B:public A			
{

	public:
		virtual void disp( )		
		{

			cout << " This is from B"  << endl;
		} 
} ;

class C: public B			
{

	public:
		virtual void disp( ) 
		{

			cout << " This is from C"  << endl;
		} 
} ;

void display( A *a)				
{

	a->disp( ) ;
} 

int main( ) 
{
	B *pB = new B;			//正确。但如果删除B类中disp( ) 的定义就会编译出错, 因为删除后，B就还包含纯虚函数。
	C *pC = new C;			//正确。如果删除C类中的disp( ) 的定义，但保留B中的定义，依然正确，因为B中的disp( ) 不是纯虚函数了
	//但如果B, C类中都没有disp( ) 的定义，就会编译出错，因为C还是纯虚函数。

	display( pB) ;			//取决于为指针赋值的数据类型
	display( pC) ;

	return 0;
} 
