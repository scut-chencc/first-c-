#include <iostream>
#include <memory>

class Parent;
class Child;

typedef std::shared_ptr<Parent> parent_ptr;
typedef std::shared_ptr<Child> child_ptr;

class Child
{
	 public:
		 Child( )
		 {
			  std::cout<<"Child::Child( )" <<std::endl;
		 }
		 ~Child( )
		 {
			  std::cout<<"Child::~Child( )" <<std::endl;
		 }
		 parent_ptr parent_;
};
class Parent
{
	 public:
		 Parent( )
		 {
			  std::cout<<"Parent::parent( )" <<std::endl;
		 }
		 ~Parent( )
		 {
			  std::cout<<"parent::~parent( )" <<std::endl;
		 }
		 child_ptr child_;
};

int main( )
{
	//循环引用的时候发生内存泄露
	 parent_ptr parent(new Parent);
	 std::cout<<"parent.use_count( )" <<parent.use_count( )<<std::endl;
	 child_ptr child( new Child);
	 std::cout<<"child.use_count( )" <<child.use_count( )<<std::endl;
	 parent->child_=child;
	 child->parent_=parent;
	 std::cout<<"parent.use_count( )" <<parent.use_count( )<<std::endl;
	 std::cout<<"child.use_count( )" <<child.use_count( )<<std::endl;

	 
	 return 0;
}
