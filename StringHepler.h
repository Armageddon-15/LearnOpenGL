#ifndef STRINGHELPER
#define STRINGHELPER

#include <iostream>

struct StringHelper {
	const char* p;
	StringHelper(const std::string& s) : p(s.c_str()) {}
	operator const char** () { return &p; }
};

#endif // !STRINGHELPER
