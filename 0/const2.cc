#include <iostream>

void put(/*const*/ char* a)//若用const则把错误提前到编译期，否则运行时才会段错误；
{
	 std::cout<<"the pointer a is "<<a<<std::endl;
     *a='b';
}

int main( )
{
	 put("aaaa" );
	 return 0;
}
