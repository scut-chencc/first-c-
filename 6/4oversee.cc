#include <iostream>
using namespace std;
class CBase
{

	protected:
		int m_i;
	public:
		int Func( int i) 
		{

			return m_i;
		} 
} ;
class CDerived:public CBase
{

	public:
		int m_i;				//隐藏基类的m_i;
		int Func()					//隐藏基类的Func
		{

			m_i=9;				//访问自身的成员
			CBase::m_i=22;		//通过作用域解析符访问基类的成员
			return m_i;
		} 
} ;
int main(void ) 
{

	CDerived obj;
	obj.Func( ) ;
	//obj.Func( 3) ;			//错误！基类的Func被隐藏
	obj.CBase::Func( 3) ;		//正确，通过作用域解析符访问基类的成员
	return 0;
}

