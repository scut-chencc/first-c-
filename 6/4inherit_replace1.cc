#include <iostream>
#include <string.h>
using namespace std;

class CBase
{

	protected:
		char *m_pszData;
	public:
		CBase( const char *pszData)                           
		{
			m_pszData=new char[ strlen( pszData) +1] ;
			strcpy( m_pszData,pszData) ;
		} 
		CBase( const CBase &base)                          
		{

			m_pszData=new char[ strlen( base.m_pszData) +1] ;
			strcpy( m_pszData,base.m_pszData) ;
		} 
		CBase &operator =( const CBase &base)                
		{

			if( this==&base) 
				return *this;
			delete [ ] this->m_pszData;
			m_pszData=new char[ strlen( base.m_pszData) +1] ;
			strcpy( m_pszData,base.m_pszData) ;
			return *this;
		}
		void print()
		{
			 cout<<"the string is " <<m_pszData<<endl;
		}
		~CBase( ) {
			delete [ ] m_pszData;} 
} ;
class CDerived:public CBase
{

	public:
		CDerived( const char *pszData) :CBase( pszData) {
		}
} ;
int  main( ) 
{

	CDerived d1( " Hello!" ) ;
	d1.print( );
	CDerived d2( " world" );
	d2.print( );
	CDerived d3=d1;		//派生类使用缺省的拷贝构造函数、基类调用用户定义的拷贝构造函数
	d3.print( );
	d1=d2;		//派生类使用缺省的赋值操作，基类调用用户重载的赋值运算符
	d1.print( );
	return 0;
} 
