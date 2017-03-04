#include <iostream>
#include <vector>
#include <string.h>

class String
{public:
	String( );
	String( const char* pstr);
	String( const String& rhs);
	String( String && rhs);//移动构造函数；
	String &operator=(String && rhs);//移动复制函数；
	String &operator=(const String &rhs);
	~String( );
	 private:
		 char* pstr_;
};

String::String()
{
	 std::cout<<"String( )" <<std::endl;
	 pstr_=new char[ 1];
}
String::String(const char* pstr)
{
	 std::cout<<"String(const char* pstr)" <<std::endl;
	 pstr_=new char[strlen(pstr)+1];
	 strcpy(pstr_,pstr);
}
String::String(const String &rhs)
{
	std::cout<<"String( const String &rhs)" <<std::endl;
	 pstr_=new char[ strlen(rhs.pstr_)+1];
	 strcpy(pstr_,rhs.pstr_) ;
}
String::String(String && rhs)
{
	 std::cout<<" String(String && rhs)"<<std::endl;
	 pstr_=rhs.pstr_;
	 rhs.pstr_=NULL;
}
String& String::operator=(const String& rhs )
{
	std::cout<<"String& operator=( const String&)"<<std::endl;
	 if(this!=&rhs)
	 {
		  delete [ ]pstr_;
		  pstr_=new char[ strlen(rhs.pstr_)+1];
		  strcpy(pstr_,rhs.pstr_);
	 }
	 return *this;
}
String& String::operator=(String && rhs)
{
	std::cout<<"String& operator=(String && )" <<std::endl;
	 if( this!=&rhs)
	 {
		  delete [ ]pstr_;
		  pstr_=rhs.pstr_;
		  rhs.pstr_=NULL;
	 }
	 return *this;
}
String::~String( )
{
	 std::cout<<"~String( )" <<std::endl;
	 delete [ ]pstr_;
}
int main( )
{
	std::vector<String> vecstr;
	vecstr.push_back("hello" );
	return 0;
	 //String s2=s1+",world" ;
}
