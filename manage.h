#ifndef MANAGE_H
#define MANAGE_H
#include "read.h"
#include "struct_declare.hpp"
#include<deque>
#include<string>
using namespace std;

class Manage
{
public:
	bool isAssembly(string the_line);
	bool isLabel(string the_line);
	bool isInstruct(string the_line);
	void ManageLine(string the_line, int line_num);
	void ManageText();
	void ManageAddress(line & the_line);
	void ManageAscii(string & the_line, int line_num);
};


#endif
