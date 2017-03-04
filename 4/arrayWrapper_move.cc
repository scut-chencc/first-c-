#include <iostream>
#include <string>

class MetaData
{
	public:
		MetaData( const std::string &name,int size)
			:name_( name),size_( size)
		{
			std::cout<<"MetaData( const)	 
		}
		MetaData(const MetaData & other)
			:name_( other.name_),size_( other.size_)
		{
			std::cout<<"MetaData( const Metadata&)" <<std::endl;
		}
		MetaData(MetaData &&rhs)
		{
			 
		}
}
