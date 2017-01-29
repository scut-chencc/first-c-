#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
	std::ofstream ofs("test1.txt",std::ios::app);
	if(!ofs.good())
	{
		std::cout<<"ofstream error"<<std::endl;
		return -1;
	}
	std::cout<<ofs.tellp()<<std::endl;
	ofs<<"that is a new"<<std::endl;
	ofs.close();
	return 0;
}
