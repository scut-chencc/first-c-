#include <iostream>

int main( )
{
	 int ival2=10;
	 int const *p3=&ival2;
	 std::cout<<"*p3=" <<*p3<<std::endl;//p3对应地址的值不是固定的吗？
	 //*p3=20;//错误的，*p3值是固定的；
	 int ival4=50;
	 p3=&ival4;
	 std::cout<<"*p3=" <<*p3<<std::endl;
	 return 0;
}
