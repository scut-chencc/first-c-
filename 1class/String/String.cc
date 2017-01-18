#include "String.h" 

String::String()
{
	 pstr_=NULL;
	 //pstr_=new char[ 1];//如果有这句，delete和print就不用判断了；
	 std::cout<<"String()" <<std::endl;
}
String::String(const char* pstr)
{
	 std::cout<<"String(const char*)" <<std::endl;
     pstr_=new char[strlen(pstr)+1];
	 strcpy(pstr_,pstr);
}
String::String(const String& rhs)
{
	 std::cout<<"String(const String&)" <<std::endl;
	 pstr_=new char[strlen(rhs.pstr_)+1];
	 strcpy(pstr_,rhs.pstr_);
}
String& String::operator=(const String& rhs)
{
	 std::cout<<"String operator=(const String&)" <<std::endl;
	 if(this==&rhs)
	 {
		  return *this;
	 } 
	 delete []pstr_;
	 pstr_=new char[strlen(rhs.pstr_)+1];
	 strcpy(pstr_,rhs.pstr_);
	 return *this;
}
String::~String()
{
	 std::cout<<"~String()" <<std::endl;
	 if(pstr_)
		delete []pstr_;
}
void String::print()
{
	if(pstr_)
		std::cout<<"the pstr_ is " <<pstr_<<std::endl;//不能打印指针为空的字符串；
}
