#include <iostream>

class Singleton
{
	public:
		static Singleton* create(int x,int y)
		{
			 if(s1==NULL)
				 s1=new Singleton(x,y);
			 return s1;
		}
		void print(void)
		{
			 std::cout<<"x is " <<x_<<",y is "<<y_<<std::endl;
		}
	private:
		Singleton(int x,int y)
			:x_( x),y_( y)
		{
			 std::cout<<"singleton(int,int)" <<std::endl;
		}
	private:
		int x_;
		int y_;
		static Singleton* s1;
};

Singleton* Singleton::s1=NULL;

int main( )
{
	Singleton* a1=Singleton::create(1,2);
	a1->print( );
	Singleton* a2=Singleton::create(3,4);
	a2->print( );
}
