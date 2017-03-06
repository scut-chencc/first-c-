#include <iostream>
#include <string.h>
using namespace std;
class CBase
{

	protected:
		char *m_pszData1;
	public:
		CBase( ) 
		{
			this->m_pszData1 = new char[ 1] ;
			*( this->m_pszData1)  = '\0';
			cout<<"base( )" <<endl;
		} 
		CBase( const char *pszData) 
		{

			m_pszData1=new char[ strlen( pszData) +1] ;
			strcpy( m_pszData1,pszData) ;
			cout<<"base( char*)" <<endl;
		} 
		CBase( const CBase &base) 
		{

			m_pszData1=new char[ strlen( base.m_pszData1) +1] ;
			strcpy( m_pszData1,base.m_pszData1) ;
			cout<<"base( const base&)" <<endl;
		} 
		CBase &operator =( const CBase &base) 
		{

			if( this==&base) 
				return *this;
			delete [ ] this->m_pszData1;
			m_pszData1=new char[ strlen( base.m_pszData1) +1] ;
			strcpy( m_pszData1,base.m_pszData1) ;
			cout<<"base &operator=(const base&)" <<endl;
			return *this;
		}
		~CBase( ) {
			cout<<"~base( )" <<endl;
			delete [ ] m_pszData1;} 
} ;
class CDerived:public CBase
{

	private:
		char *m_pszData2;
	public:
		CDerived( ) 
		{

			cout<<"derived( )" <<endl;
		} 
		CDerived( const char *pszData1,const char *pszData2) :CBase( pszData1) 
	{

		m_pszData2=new char[ strlen( pszData2) +1] ;
		strcpy( m_pszData2,pszData2) ;
		cout<<"derived( const char*,const char*)" <<endl;
	} 
		CDerived( const CDerived &derived) 
			//: CBase( derived)   //显式调用
		{

			m_pszData2=new char[ strlen( derived.m_pszData2) +1] ;
			strcpy( m_pszData2,derived.m_pszData2) ;
			cout<<"derived(const derived&)" <<endl;
		} 
		CDerived &operator = ( const CDerived &derived) 
		{

			if( this == &derived) 
			{
				//CBase::operator=( derived) ; //显式调用
				delete []m_pszDdata2;
				m_pszData2=new char[strlen(derived.m_pszData2)+1];
				strcpy(m_pszData2,derived.m_pszData2);
			}
			cout<<"derived& operator=(const derived&)" <<endl;
			return *this;
		} 
		~CDerived( ) {
			cout<<"~derived( )" <<endl;
			delete [ ] m_pszData2;} 

} ;
int main( ) 
{

	CDerived d1( " Hello!" ," World!" ) ;
	CDerived d2=d1;		 //派生类调用用户自定义的拷贝构造函数、基类不调用拷贝构造函数
	d1=d2;		//派生类调用用户自定义的赋值操作，基类不调用重载的赋值运算符
	return 0;
} 
