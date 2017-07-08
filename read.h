#ifndef READ_H
#define READ_H
#include "struct_declare.hpp"
#include "simulator.h"
#include <deque>
#include <string>
using namespace std;
class Read
{
public:
	void ReadText();
	string JumpBegin(string the_line);
};

#endif
