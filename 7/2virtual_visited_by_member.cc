#include <iostream>
using namespace std;

class base		
{

	public:
		virtual void disp( )	       
		{

			cout<<" hello,base" <<endl;
		} 

		void call_base_1( ) 
		{

			this->disp( ) ;     //或直接用disp( )，效果一样 
		} 

		void call_base_2( ) 
		{

			base::disp( ) ;     //去掉base效果不一样
		} 
} ;

class child:public base	        
{

	public:
		void disp( )	        //对虚函数进行了覆盖定义
		{

			cout<<" hello,child" <<endl;
		} 

		void call_child_1( ) 
		{

			disp( ) ;	        //等价于this->disp( ) ;
		} 
} ;

int main( ) 
{

	base obj_Base;		
	child obj_Child;		
	obj_Base.call_base_1( ) ;	//基类对象调用非虚函数call_base_1( ) 
	obj_Child.call_child_1( ) ;       //派生类对象调用非虚函数call_child_1( ) 

	cout << endl;

	base* pBase = &obj_Base;     
	pBase->call_base_1( ) ;	
	pBase->call_base_2( ) ;	

	cout << endl;

	pBase = &obj_Child;	
	pBase->call_base_1( ) ;	
	pBase->call_base_2( ) ;

	return 0;
} 
