#include <iostream>
#include <memory>

int main( void)
{
	 double *pd=new double( 77.77);
	 std::auto_ptr<double> apd(pd);
	 std::cout<<"*apd=" <<*apd<<std::endl;
	 //std::cout<<"apd=" <<apd<<std::endl;//对于智能指针对象没有提供输出运算符
	 std::cout<<"apd.get( )" <<apd.get( )<<std::endl;
	 std::cout<<" pd" <<pd<<std::endl;

	 int* p1=new int( 7);
	 std::auto_ptr<int> api1( p1);
	 std::auto_ptr<int> api2( api1);
	 //std::cout<<"*api1" <<*api1<<std::endl;//段错误
	 std::cout<<"*api2" <<*api2<<std::endl;
	 
	 float* pf=new float(static_cast<float>( 0.77));
	 std::auto_ptr<float> apf;
	 apf.reset(pf);
	 std::cout<<"*apf=" <<*apf<<std::endl;
	 
	 return 0;
}
