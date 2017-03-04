#include <iostream>
template<typename T>
class RAII{
	public:
		explicit RAII( T* p)
			:p_( p){
				std::cout<<"RAII(T* p)"<<std::endl;  
			}
		~RAII()
		{
			std::cout<<"~RAII( )" <<std::endl;
			delete p_;
		}
		void reset( T* p)
		{
			delete p_;
			p_=p;
		}
		T* get( ) const
		{
			return p_;
		}
		T& operator*( ) const
		{
			return *p_;
		}
		void swap( RAII& other)
		{
			std::swap(p_,other.p_);
		}
	private:
		RAII(const RAII& other);
		RAII& operator=( const RAII& other);
	private:
		T* p_;
};
