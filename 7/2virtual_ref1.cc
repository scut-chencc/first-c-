#include <iostream>
using namespace std;

class base
{

	public:
		virtual void disp( ) 
		{

			cout << " hello,base"  << endl;
		} 
} ;

class child:public base
{

	public:
		void disp( ) 
		{

			cout << " hello,child"  << endl;
		} 
} ;

int main( ) 
{

	base obj_base;				
	base& rBase1 = obj_base;	
	rBase1.disp( ) ;				

	child obj_child;			
	base& rBase2 = obj_child;	
	rBase2.disp( ) ;				

	cout << endl;
	
	cout<<"the addr of rbase1=" <<&rBase1<<endl;
	//引用一经声明后，其调用的函数就不会再改变
	rBase1 = obj_child; //引用本身不可以改变, 这里是将obj_child赋值给
	cout<<"the addr of rbase1=" <<&rBase1<<endl;
	//了rBase1指向的obj_base，相当于obj_base = obj_child;
	rBase1.disp( ) ;      //还是调用原来的虚函数: 基类版本

	rBase2 = obj_base;  
	rBase2.disp( ) ;
	cout<<"the addr of rbase2" <<&rBase2<<endl;

	return 0;
} 
