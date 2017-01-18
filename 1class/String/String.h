#include <string.h>
#include <iostream>

#ifndef _STRING_H_
#define _STRING_H_

class String
{
	public:
		String();
		String(const char* pstr);
		String(const String& rhs);
		String& operator=(const String& rhs);
		void print();
		~String();
	private:
		char* pstr_;
};
#endif
