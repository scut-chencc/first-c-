#include <iostream>
#include <memory>
#include <vector>
std::unique_ptr<int> getval( )
{
	 std::unique_ptr<int> up( new int( 80));
	 return up;
}
int main( void)
{
	 std::unique_ptr<int> api(new int( 88));
	 //std::unique_ptr<int> one( api);//无法复制操作；
	 std::cout<<"*api=" <<*api<<std::endl;
	 std::cout<<"api.get( )=" <<api.get( )<<std::endl;

	 std::unique_ptr<int> uptr=getval( );//getval( ) 为右值，调用移动复制函数，发生移动语义，
	 std::cout<<"uptr=" <<*uptr<<std::endl;

	 std::unique_ptr<int> up( new int( 88));
	 std::unique_ptr<int> uptr2=std::move( up);

	 std::unique_ptr<int> sp( new int( 99));
	 std::vector<std::unique_ptr<int>>vec;
	 //vec.push_back(sp);//sp是一个有名字的对象，是左值，调用被禁止的复制构造函数
	 vec.push_back(std::move( sp));//将sp转换成一个右值；
	 return 0;
}
