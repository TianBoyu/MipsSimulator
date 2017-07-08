#ifndef READ_CPP
#define READ_CPP
#include "read.h"
#include <deque>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
string Read::JumpBegin(string the_line)
{
	int i = 0; string ans;
	while (the_line[i] == ' ' || the_line[i] == '\t') ++i;
	ans.assign(the_line, i, the_line.length() - i);
	return ans;
}

void Read::ReadText()
{
    ifstream input;
    input.open("builtin-5140519064-youyurong.s");
	char * storage = new char[100000];
	while (input.getline(storage, 10000))
	{
		string ans(storage);
		ans.push_back('\n');
		string Jans = JumpBegin(ans);
		if (Jans[0] == '\n' || Jans[0] == '#') continue;
		Simulator::GetSimulator().text.push_back(Jans);
	}
	delete[]storage;
}


#endif // !READ_CPP
