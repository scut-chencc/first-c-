#include "String.h" 
//#include <string.h>
//#include <iostream>

int main( )
{
	 //String a=String("" );//diaoyong String();
	 String a=String();//diaoyong String(const char*);
	 a.print();
	 String b=String("hello");
	 b.print( );
	 String c(b);
	 c.print( );
	 String d=String("bb" );
	 c=d;
	 c.print( );
	 return 0;
}
