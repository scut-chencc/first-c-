#include <iostream>

class Computer
{
	public:
		Computer(int price,int const num)
			:price_(price),const_num_(num) 
		{
			 total_price+=price_;
			 //static_const_num_++;
			 std::cout<<"Computer()"<<std::endl;
		}
		Computer(const Computer &rhs )
			:price_(rhs.price_),const_num_(rhs.const_num_) 
		{
			 total_price+=price_;
			 std::cout<<"Computer(const &)"<<std::endl;
		}
		void print(void)
		{
			 std::cout<<"the total_price is " <<total_price<<std::endl;
			 std::cout<<"the const_num_ is " <<const_num_<<std::endl;
		}
		~Computer()
		{
			 total_price-=price_;
		}
	private:
		int price_;
		static int total_price;
		const int const_num_;
		static const int static_const_num_;
};

int Computer::total_price=0;
int static_const_num_=1;

int main( )
{
	 //int Computer::total_price=0;
	 Computer c1(2000,500);
	 c1.print( );
	 Computer c2( c1);
	 c2.print( );
	 c1.print( );
	 c2.~Computer( );
	 c1.print( );
}
