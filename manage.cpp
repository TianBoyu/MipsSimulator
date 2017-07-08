#ifndef MANAGE_CPP
#define MANAGE_CPP
#include "manage.h"
#include "struct_declare.hpp"
#include <deque>
#include <string>
using namespace std;
bool Manage::isAssembly(string the_line)
{
	if (the_line[0] == '.') return true;
	return false;
}
bool Manage::isLabel(string the_line)
{
	int i = the_line.length() - 1;
	while (true)
	{
		if (the_line[i] == ' ' || the_line[i] == '\n' || the_line[i] == '\t')
		{
			--i; continue;
		}
		if (the_line[i] == ':') return true;
		else return false;
	}
	return false;
}
bool Manage::isInstruct(string the_line)
{
	return true;
}
void Manage::ManageLine(string the_line, int line_num)
{
	line sentence;
	if (isLabel(the_line))
	{
		sentence.mykind = label;
		string tmp; int i = 0, j = 0;
		while (i < the_line.length())
		{
			if (the_line[i] == '\n' || the_line[i] == '\#')
			{
				sentence.order[i] = "EndOfLine";
				Simulator::GetSimulator().paper.push_back(sentence);
				return;
			}
			for (; the_line[i] == ' ' || the_line[i] == '\t' || the_line[i] == ':'; ++i) {}
			if (the_line[i] == '\n' || the_line[i] == '#')
			{
				sentence.order[j] = "EndOfLine";
				Simulator::GetSimulator().paper.push_back(sentence);
				return;
			}
			for (; the_line[i] != ':'; ++i)
			{
				if (the_line[j] == '\n' || the_line[j] == '#') break;
				tmp.push_back(the_line[i]);
			}
			sentence.order[j++] = tmp;
			Simulator::GetSimulator().label_map.insert(pair<string, int>(tmp, line_num)); tmp.clear();
		}
	}
	else if (isAssembly(the_line))
	{
		sentence.mykind = assembly;
		int i = 0, j = 0;
		string tmp;
		while (j < the_line.length())
		{
			if (the_line[j] == '\n' || the_line[j] == '#')
			{
				sentence.order[i] = "EndOfLine";
				Simulator::GetSimulator().paper.push_back(sentence);
				return;
			}
			if (the_line[1] == 'a' && the_line[2] == 's')
			{
				ManageAscii(the_line, line_num); break;
			}
			for (; the_line[j] == ' ' || the_line[j] == '\t' || the_line[j] == ',' || the_line[j] == '.'; ++j) {}
			if (the_line[j] == '\n' || the_line[j] == '#')
			{
				sentence.order[i] = "EndOfLine";
				Simulator::GetSimulator().paper.push_back(sentence);
				return;
			}
			for (; the_line[j] != ' ' && the_line[j] != ',' && the_line[j] != '\t'; ++j)
			{
				if (the_line[j] == '\n' || the_line[j] == '#') break;
				tmp.push_back(the_line[j]);
			}
			sentence.order[i++] = tmp; tmp.clear();
		}
	}
	else //isInstruct
	{
		sentence.mykind = instruct;
		int i = 0, j = 0;
		string tmp;
		while (j < the_line.length())
		{
			if (the_line[j] == '\n' || the_line[j] == '#')
			{
				Simulator::GetSimulator().paper.push_back(sentence);
				return;
			}
			for (; the_line[j] == ' ' || the_line[j] == '\t' || the_line[j] == ','; ++j) {}
			if (the_line[j] == '\n' || the_line[j] == '#')
			{
				Simulator::GetSimulator().paper.push_back(sentence);
				return;
			}
			for (; the_line[j] != ' ' && the_line[j] != ',' && the_line[j] != '\t'; ++j)
			{
				if (the_line[j] == '\n' || the_line[j] == '#') break;
				tmp.push_back(the_line[j]);
			}
			sentence.order[i++] = tmp; tmp.clear();
		}
	}
}
void Manage::ManageAddress(line & the_line)
{
	if (the_line.mykind == instruct)
	{
		string tmp = the_line.order[0];
		if (tmp == "la" || tmp == "lb" || tmp == "lh" || tmp == "lw" || tmp == "sb" || tmp == "sh" || tmp == "sw")
		{
			if (the_line.order[2][0] == '-' || the_line.order[2][0] == '(' || (the_line.order[2][0] >= '0' && the_line.order[2][0] <= '9'))
			{
				string number, reg; int i = 0;
				number.push_back('0');
				for (i = 0; the_line.order[2][i] != '('; ++i)
				{
					if (i == 0) number.pop_back();
					number.push_back(the_line.order[2][i]);
				}
				++i;
				for (; the_line.order[2][i] == ' ' || the_line.order[2][i] == '\t' || the_line.order[2][i] == '('; ++i) {}
				for (; the_line.order[2][i] != ' ' && the_line.order[2][i] != ')'; ++i)
				{
					reg.push_back(the_line.order[2][i]);
				}
				the_line.order[2] = number;
				the_line.order[3] = reg;
			}
		}
	}
}
void Manage::ManageText()
{
	for (int i = 0; i < Simulator::GetSimulator().text.size(); ++i)
	{
		string tmp = Simulator::GetSimulator().text[i];
		if (tmp[0] == '\n') continue;
		Manage::ManageLine(tmp, i);
		Manage::ManageAddress(Simulator::GetSimulator().paper.back());
	}
}
void Manage::ManageAscii(string & the_line, int line_num)
{
	int j = 0, i = the_line.length() - 1; string tmp; line sentence;
	sentence.mykind = assembly;
	for (; the_line[j] == ' ' || the_line[j] == '\t' || the_line[j] == ',' || the_line[j] == '.'; ++j) {}
	for (; the_line[j] != ' ' && the_line[j] != ',' && the_line[j] != '\t'; ++j) 
	{
		tmp.push_back(the_line[j]);
	}
	sentence.order[0] = tmp;
	for (; the_line[j] != '"'; ++j) {}
	++j; tmp.clear();
	for (i = the_line.length() - 1; the_line[i] != '"'; --i) {}
	for (; j < i; ++j) {
		tmp.push_back(the_line[j]);
	}
	sentence.order[1] = tmp;
	Simulator::GetSimulator().paper.push_back(sentence);
}


#endif // !MANAGE_CPP
