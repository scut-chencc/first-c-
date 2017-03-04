#include <iostream>
#include <string>
#include <stdio.h>

int main( )
{
	 std::string s1="hello,world";
	 std::string s2=s1;
	 std::string s3=s2;
	 std::cout<<s1<<std::endl;
	 std::cout<<s2<<std::endl;
	 std::cout<<s3<<std::endl;
	 std::cout<<s1.c_str( )<<std::endl;
	 std::cout<<s2.c_str( )<<std::endl;
	 std::cout<<s3.c_str( )<<std::endl;
	 printf("&s1 is %x\n" ,s1.c_str( ));
	 printf("&s2 is %x\n" ,s2.c_str( ));
	 printf("&s3 is %x\n" ,s3.c_str( ));
	 s1[ 1]='H';
	 printf("&s1 is %x\n" ,s1.c_str( ));
	 printf("&s2 is %x\n" ,s2.c_str( ));
	 printf("&s3 is %x\n" ,s3.c_str( ));
	 return 0;
}
