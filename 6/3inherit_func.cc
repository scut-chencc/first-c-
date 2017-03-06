#include <iostream>
using namespace std;
class Baseclass
{

	private :
		int a;
	public:
		//Baseclass()  //用于检测基类的缺省的无参构造函数是否被自动调用
		//	:a( 0)
		//{

		//	cout<<"Basclass()" <<endl;
		//}
		Baseclass( int i=0):a( i)
		{
			 cout<<"Baseclass( int)" <<endl;
		}
} ;
class Derivedclass : public Baseclass
{

	public:
		//Derivedclass( ) 
		//{

		//	cout<<" derivedclass( )" <<endl;
		//} 
		//Derivedclass( int i) 
		//{

		//	cout<<"derivedclass(int)" <<endl;
		//} 
} ;
int main( ) 
{

	Derivedclass x1 ;
	//Derivedclass x2;
	return 0;
} 
